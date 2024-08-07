#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

#define SCRIPT_PATH "scripts/user-login.mjs"
#define BUFFER_SIZE 1024

// Função para executar um comando no terminal
int executarComando(const char *comando) {
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    DWORD exitCode;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Cria o processo para executar o comando
    if (!CreateProcess(NULL, (LPSTR)comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "Erro ao criar o processo: %lu\n", GetLastError());
        return -1;
    }

    // Espera o processo terminar
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Obtém o código de saída do processo
    if (!GetExitCodeProcess(pi.hProcess, &exitCode)) {
        fprintf(stderr, "Erro ao obter o código de saída do processo: %lu\n", GetLastError());
        exitCode = -1;
    }

    // Fecha os handles do processo e do thread
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return exitCode;
}

// Função para salvar as informações do usuário usando o script Node.js
int salvarInformacoes(const char *nome, const char *email, const char *senha, const char *cnpj) {
    char comando[BUFFER_SIZE];
    snprintf(comando, sizeof(comando), "node \"%s\" salvar \"%s\" \"%s\" \"%s\" \"%s\"", SCRIPT_PATH, nome, email, senha, cnpj);
    return executarComando(comando) == 0;
}

// Função para verificar as informações do usuário usando o script Node.js
int verificarInformacoes(const char *email, const char *senha) {
    char comando[BUFFER_SIZE];
    snprintf(comando, sizeof(comando), "node \"%s\" verificar \"%s\" \"%s\"", SCRIPT_PATH, email, senha);
    return executarComando(comando) == 0;
}

void lerString(char *buffer, size_t tamanho, const char *mensagem) {
    printf("%s", mensagem);
    if (fgets(buffer, tamanho, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove o newline
    }
}

// Função para login do usuário
int login() {
    printf("\nLogin:\n");

    char nome[50];
    char email[150];
    char senha[20];
    char cnpj[20];

    // Solicita informações do usuário
    lerString(nome, sizeof(nome), "Digite seu nome: ");
    lerString(email, sizeof(email), "Digite seu e-mail: ");
    lerString(senha, sizeof(senha), "Digite sua senha: ");
    lerString(cnpj, sizeof(cnpj), "Digite seu CNPJ: ");

    // Salva informações no arquivo JSON
    if (salvarInformacoes(nome, email, senha, cnpj)) {
        printf("Você já tem um acesso autorizado, verifique as suas informações de login:\n");
        return verificarInformacoes(email, senha) ? 0 : -1;
    } else {
        printf("Informações salvas com sucesso. Acesso concedido.\n");
        return 0;
    }
}

// Função principal
int main() {
    setlocale(LC_CTYPE, "Portuguese_Brazil.1252");

    int codigo;
    float preco_custo;
    float preco_novo;
    float soma_preco_custo = 0.0;
    float soma_preco_novo = 0.0;
    int quantidade_produtos = 0;

    printf("Bem-Vindo ao sistema:\n");

    // Chama a função de login
    if (login() != 0) {
        printf("Falha no login. Saindo...\n");
        return 1;
    }

    printf("Digite o código e o preço de custo de cada produto (código negativo ou zero para encerrar):\n");

    while (1) {
        printf("Código do produto: ");
        if (scanf("%d", &codigo) != 1 || codigo <= 0) {
            if (codigo <= 0) break;
            fprintf(stderr, "Entrada inválida para o código do produto.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;
        }

        printf("Preço de custo: ");
        if (scanf("%f", &preco_custo) != 1) {
            fprintf(stderr, "Entrada inválida para o preço de custo.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;
        }

        preco_novo = preco_custo * 1.20;

        soma_preco_custo += preco_custo;
        soma_preco_novo += preco_novo;
        quantidade_produtos++;

        printf("Código: %d, Preço novo: %.2f\n", codigo, preco_novo);
    }

    if (quantidade_produtos > 0) {
        float media_preco_custo = soma_preco_custo / quantidade_produtos;
        float media_preco_novo = soma_preco_novo / quantidade_produtos;
        printf("\nA quantidade de produtos com preços alterados foram: %d\n", quantidade_produtos);
        printf("Média dos preços de custo: %.2f\n", media_preco_custo);
        printf("Média dos preços novos: %.2f\n", media_preco_novo);
    } else {
        printf("Nenhum produto foi inserido.\n");
    }

    return 0;
}



import fs from 'fs';
import path from 'path';
import { binary } from 'binary-id';
import { userSchema } from './schema/schemaUser.mjs';
import { verificarInformacoes } from './auth/authUser.mjs';

const JSON_FILE = 'data.json';
const DIR_DATA = '.data';

/**
 * Função para salvar informações no arquivo JSON.
 * @param {string} nome - Nome do usuário.
 * @param {string} email - Email do usuário.
 * @param {string} senha - Senha do usuário.
 * @param {string} cnpj - CNPJ do usuário.
 */
function salvarInformacoes(nome, email, senha, cnpj) {
    const jsonObject = {
        id: binary.UUID(),
        name: nome,
        email: email,
        password: senha,
        cnpj: cnpj
    };

    const { success, data, error } = userSchema.safeParse(jsonObject);

    if (!success) {
        console.error(`Erro na validação dos dados: ${error.errors.map(e => e.message).join(', ')}`);
        return;
    }

    if (!fs.existsSync(DIR_DATA)) {
        try {
            fs.mkdirSync(DIR_DATA, { recursive: true });
            console.log(`Diretório criado: ${DIR_DATA}`);
        } catch (err) {
            console.error(`Erro ao criar o diretório: ${err.message}`);
            return;
        }
    } else {
        console.log(`Diretório já existe: ${DIR_DATA}`);
    }

    const filePath = path.join(DIR_DATA, JSON_FILE);

    try {
        if (fs.existsSync(filePath)) {
            console.log(`O arquivo ${JSON_FILE} já existe.`);
            return;
        }

        fs.writeFileSync(filePath, JSON.stringify(data, null, 2));
        console.log('Informações salvas com sucesso no arquivo JSON.');
    } catch (err) {
        console.error(`Erro ao salvar informações no arquivo JSON: ${err.message}`);
    }

    return data;
}

const args = process.argv.slice(2);
const command = args[0];

if (command === 'salvar') {
    if (args.length < 5) {
        console.error('Número insuficiente de argumentos. Uso: node script.js salvar <nome> <email> <senha> <cnpj>');
        process.exit(1);
    }

    salvarInformacoes(args[1], args[2], args[3], args[4]);

} else if (command === 'verificar') {
    if (args.length < 4) {
        console.error('Número insuficiente de argumentos. Uso: node script.js verificar <email> <senha>');
        process.exit(1);
    }

    const data = salvarInformacoes(args[1], args[2], args[3], args[4]);
    if (data) {
        verificarInformacoes(args[1], args[2], data.id);
    }
} else {
    console.error('Comando desconhecido. Use "salvar" ou "verificar".');
    process.exit(1);
}


import fs from 'fs';
import { userSchema } from '../schema/schemaUser.mjs';

const JSON_FILE = 'data.json';

/**
 * Função para verificar as informações no arquivo JSON.
 * @param {string} email - Email do usuário.
 * @param {string} password - Senha do usuário.
 * @param {string} id - ID do usuário.
 * @returns {boolean} - Retorna verdadeiro se as informações estiverem corretas, caso contrário, falso.
 */
export function verificarInformacoes(email, password, id) {
    try {
        if (!fs.existsSync(JSON_FILE)) {
            console.error(`Arquivo ${JSON_FILE} não encontrado.`);
            return false;
        }

        const data = fs.readFileSync(JSON_FILE, 'utf8');
        const jsonObject = JSON.parse(data);

        const result = userSchema.safeParse(jsonObject);
        if (!result.success) {
            console.error(`Dados inválidos no arquivo JSON: ${result.error.errors.map(e => e.message).join(', ')}`);
            return false;
        }

        const { id: storedId, email: storedEmail, password: storedPassword } = result.data;

        if (storedId === id && storedEmail === email && storedPassword === password) {
            console.log('Informações corretas.');
            return true;
        } else {
            console.log('Informações incorretas. Verifique o ID, email ou senha.');
            return false;
        }

    } catch (err) {
        console.error('Erro ao abrir o arquivo para leitura ou analisar JSON:', err);
        return false;
    }
}


import z from 'zod';

// Definindo o esquema de validação do usuário usando zod
export const userSchema = z.object({
    id: z.string().uuid('ID deve ser um UUID válido'),
    name: z.string()
        .min(1, 'Nome deve ter pelo menos 1 caractere')
        .max(100, 'Nome deve ter no máximo 100 caracteres'),
    email: z.string()
        .email('Email deve ser um endereço de email válido'),
    password: z.string()
        .min(8, 'Senha deve ter pelo menos 8 caracteres')
        .max(128, 'Senha deve ter no máximo 128 caracteres'),
    cnpj: z.string()
        .length(14, 'CNPJ deve ter exatamente 14 caracteres')
});
