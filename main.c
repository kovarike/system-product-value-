#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "./include/login.h"

// int main() {
//     int codigo;
//     float preco_custo;
//     float preco_novo;
//     float soma_preco_custo = 0.0;
//     float soma_preco_novo = 0.0;
//     int quantidade_produtos = 0;
//     printf("Bem-Vindo ao sistema:\n");

//    login();
//     printf("Digite o código e o preço de custo de cada produto (código negativo ou zero para encerrar):\n");

//     while (1) {

//         printf("Código do produto: ");
//         scanf("%d", &codigo);
//         if (codigo <= 0) {
//             break;
//         }

//         printf("Preço de custo: ");
//         scanf("%f", &preco_custo);


//         preco_novo = preco_custo * 1.20;


//         soma_preco_custo += preco_custo;
//         soma_preco_novo += preco_novo;
//         quantidade_produtos++;


//         printf("Código: %d, Preço novo: %.2f\n", codigo, preco_novo);
//     }


//     if (quantidade_produtos > 0) {
//         float media_preco_custo = soma_preco_custo / quantidade_produtos;
//         float media_preco_novo = soma_preco_novo / quantidade_produtos;
//         printf("\nA quantidade de produtos com preço alterados foram: %d\n", quantidade_produtos);

//         printf("\nMédia dos preços de custo: %.2f\n", media_preco_custo);
//         printf("\nMédia dos preços novos: %.2f\n", media_preco_novo);
//     } else {
//         printf("Nenhum produto foi inserido.\n");
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
 #include <windows.h>
 #include <locale.h>
// #include "../include/login.h"

// #define SCRIPT_PATH "./js/user-login.js"

// int executarComando(const char *comando) {
//     PROCESS_INFORMATION pi;
//     STARTUPINFO si;
//     DWORD exitCode;

//     ZeroMemory(&si, sizeof(si));
//     si.cb = sizeof(si);
//     ZeroMemory(&pi, sizeof(pi));

//     // Cria o processo para executar o comando
//     if (!CreateProcess(NULL, (LPSTR)comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
//         fprintf(stderr, "Erro ao criar o processo: %lu\n", GetLastError());
//         return -1;
//     }

//     // Espera o processo terminar
//     WaitForSingleObject(pi.hProcess, INFINITE);

//     // Obtém o código de saída do processo
//     if (!GetExitCodeProcess(pi.hProcess, &exitCode)) {
//         fprintf(stderr, "Erro ao obter o código de saída do processo: %lu\n", GetLastError());
//         exitCode = -1;
//     }

//     // Fecha os handles do processo e do thread
//     CloseHandle(pi.hProcess);
//     CloseHandle(pi.hThread);

//     return exitCode;
// }

// void salvarInformacoes(const char *nome, const char *email, const char *senha, const char *cnpj) {
//     char comando[1024];
//     snprintf(comando, sizeof(comando), "node \"%s\" salvar \"%s\" \"%s\" \"%s\" \"%s\"", SCRIPT_PATH, nome, email, senha, cnpj);
//     executarComando(comando);
// }

// int verificarInformacoes(const char *nome, const char *email, const char *senha, const char *cnpj) {
//     char comando[1024];
//     snprintf(comando, sizeof(comando), "node \"%s\" verificar \"%s\" \"%s\" \"%s\" \"%s\"", SCRIPT_PATH, nome, email, senha, cnpj);
//     int resultado = executarComando(comando);
//     return resultado == 0 ? 1 : 0;
// }

// int login() {
//     printf("\nLogin:\n");

//     char nome[50];
//     char email[150];
//     char senha[20];
//     char cnpj[20];

//     // Solicita informações do usuário
//     printf("Digite seu nome: ");
//     fgets(nome, sizeof(nome), stdin);
//     nome[strcspn(nome, "\n")] = '\0';  // Remove o newline

//     printf("Digite seu e-mail: ");
//     fgets(email, sizeof(email), stdin);
//     email[strcspn(email, "\n")] = '\0';  // Remove o newline

//     printf("Digite sua senha: ");
//     fgets(senha, sizeof(senha), stdin);
//     senha[strcspn(senha, "\n")] = '\0';  // Remove o newline

//     printf("Digite seu CNPJ: ");
//     fgets(cnpj, sizeof(cnpj), stdin);
//     cnpj[strcspn(cnpj, "\n")] = '\0';  // Remove o newline

//     // Salva informações no arquivo JSON
//     salvarInformacoes(nome, email, senha, cnpj);

//     // Verifica se as informações estão corretas
//     printf("\nVerificando informações...\n");
//     int r = verificarInformacoes(nome, email, senha, cnpj);
//     if (r == 1) {
//         printf("Informações corretas!\n");
//     } else {
//         printf("Informações incorretas!\n");
        
//     }

//     return 0;
// }

// int main() {
//     int codigo;
//     float preco_custo;
//     float preco_novo;
//     float soma_preco_custo = 0.0;
//     float soma_preco_novo = 0.0;
//     int quantidade_produtos = 0;
//     printf("Bem-Vindo ao sistema:\n");
    

//     login();

//     printf("Digite o código e o preço de custo de cada produto (código negativo ou zero para encerrar):\n");

//     while (1) {
//         printf("Código do produto: ");
//         scanf("%d", &codigo);
//         if (codigo <= 0) {
//             break;
//         }

//         printf("Preço de custo: ");
//         scanf("%f", &preco_custo);

//         preco_novo = preco_custo * 1.20;

//         soma_preco_custo += preco_custo;
//         soma_preco_novo += preco_novo;
//         quantidade_produtos++;

//         printf("Código: %d, Preço novo: %.2f\n", codigo, preco_novo);
//     }

//     if (quantidade_produtos > 0) {
//         float media_preco_custo = soma_preco_custo / quantidade_produtos;
//         float media_preco_novo = soma_preco_novo / quantidade_produtos;
//         printf("\nA quantidade de produtos com preço alterados foram: %d\n", quantidade_produtos);

//         printf("\nMédia dos preços de custo: %.2f\n", media_preco_custo);
//         printf("\nMédia dos preços novos: %.2f\n", media_preco_novo);
//     } else {
//         printf("Nenhum produto foi inserido.\n");
//     }

//     return 0;


// }



#define SCRIPT_PATH "scripts/user-login.mjs"

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
void salvarInformacoes(const char *nome, const char *email, const char *senha, const char *cnpj) {
    char comando[1024];
    snprintf(comando, sizeof(comando), "node \"%s\" salvar \"%s\" \"%s\" \"%s\" \"%s\"", SCRIPT_PATH, nome, email, senha, cnpj);
    executarComando(comando);
}

// Função para verificar as informações do usuário usando o script Node.js
// int verificarInformacoes(const char *nome, const char *email, const char *senha, const char *cnpj) {
//     char comando[1024];
//     snprintf(comando, sizeof(comando), "node \"%s\" verificar \"%s\" \"%s\" \"%s\" \"%s\"", SCRIPT_PATH, nome, email, senha, cnpj);
//     int resultado = executarComando(comando);
//     return resultado == 0 ? 1 : 0;
// }

// Função de login do usuário
int login() {
    printf("\nLogin:\n");

    char nome[50];
    char email[150];
    char senha[20];
    char cnpj[20];

    // Solicita informações do usuário
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';  // Remove o newline

    printf("Digite seu e-mail: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';  // Remove o newline

    printf("Digite sua senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';  // Remove o newline

    printf("Digite seu CNPJ: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    cnpj[strcspn(cnpj, "\n")] = '\0';  // Remove o newline

    // Salva informações no arquivo JSON
    salvarInformacoes(nome, email, senha, cnpj);

    // int resultado = verificarInformacoes(nome, email, senha, cnpj);

    // // Mensagens de feedback mais detalhadas
    // if (resultado == 0) {
    //     printf("Informações incorretas! Verifique os dados e tente novamente.\n");
    //     return -1;  // Indica falha no login
    // }

    printf("Informações corretas! Acesso concedido.\n");

    return 0;  // Indica sucesso no login
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
        if (scanf("%d", &codigo) != 1) {
            fprintf(stderr, "Entrada inválida para o código do produto.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;
        }
        if (codigo <= 0) {
            break;
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

