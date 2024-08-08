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
            // Se deseja atualizar o arquivo existente, remova o bloco abaixo.
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
    if (args.length < 5) {
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
