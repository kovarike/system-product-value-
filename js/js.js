const fs = require('fs');
const path = require('path');

const JSON_FILE = 'data.json';
const DIRETORY_DATA = '.data';

/**
 * Função para criar um diretório se ele não existir.
 * @param {string} dirPath - Caminho do diretório.
 */
function ensureDirectoryExistence(dirPath) {
    if (!fs.existsSync(dirPath)) {
        fs.mkdirSync(dirPath, { recursive: true });
        console.log(`Diretório criado: ${dirPath}`);
    }
}

/**
 * Função para salvar informações no arquivo JSON.
 * @param {string} nome - Nome do usuário.
 * @param {string} email - Email do usuário.
 * @param {string} senha - Senha do usuário.
 * @param {string} cnpj - CNPJ do usuário.
 */
function salvarInformacoes(nome, email, senha, cnpj) {
    const jsonObject = {
        nome: nome,
        email: email,
        senha: senha,
        cnpj: cnpj
    };

    // Cria o diretório se necessário
    ensureDirectoryExistence(DIRETORY_DATA);

    // Define o caminho completo do arquivo
    const filePath = path.join(DIRETORY_DATA, JSON_FILE);

    // Salva as informações no arquivo JSON
    fs.writeFile(filePath, JSON.stringify(jsonObject, null, 2), (err) => {
        if (err) {
            console.error('Erro ao salvar informações no arquivo JSON:', err);
            return;
        }
        console.log('Informações salvas com sucesso no arquivo JSON.');
    });
}

// Exemplo de uso da função salvarInformacoes
salvarInformacoes('João da Silva', 'joao@example.com', 'senha123', '12345678901234');



const fs = require('fs');
const path = require('path');

const JSON_FILE = 'data.json';
const DIRETORY_DATA = '.data';

/**
 * Função para criar um diretório se ele não existir.
 * @param {string} dirPath - Caminho do diretório.
 * @returns {Promise} - Retorna uma Promise que resolve quando o diretório é criado.
 */
function ensureDirectoryExistence(dirPath) {
    return new Promise((resolve, reject) => {
        // Simula um atraso de 3 segundos
        setTimeout(() => {
            if (!fs.existsSync(dirPath)) {
                fs.mkdir(dirPath, { recursive: true }, (err) => {
                    if (err) {
                        reject(`Erro ao criar o diretório: ${err.message}`);
                    } else {
                        console.log(`Diretório criado: ${dirPath}`);
                        resolve();
                    }
                });
            } else {
                console.log(`Diretório já existe: ${dirPath}`);
                resolve(); // Diretório já existe
            }
        }, 3000); // Atraso de 3 segundos
    });
}

/**
 * Função para salvar informações no arquivo JSON.
 * @param {string} nome - Nome do usuário.
 * @param {string} email - Email do usuário.
 * @param {string} senha - Senha do usuário.
 * @param {string} cnpj - CNPJ do usuário.
 * @returns {Promise} - Retorna uma Promise que resolve quando as informações são salvas.
 */
function salvarInformacoes(nome, email, senha, cnpj) {
    const jsonObject = {
        nome: nome,
        email: email,
        senha: senha,
        cnpj: cnpj
    };

    // Define o caminho completo do arquivo
    const filePath = path.join(DIRETORY_DATA, JSON_FILE);

    return new Promise((resolve, reject) => {
        // Simula um atraso de 3 segundos
        setTimeout(() => {
            // Salva as informações no arquivo JSON
            fs.writeFile(filePath, JSON.stringify(jsonObject, null, 2), (err) => {
                if (err) {
                    reject(`Erro ao salvar informações no arquivo JSON: ${err.message}`);
                } else {
                    console.log('Informações salvas com sucesso no arquivo JSON.');
                    resolve();
                }
            });
        }, 3000); // Atraso de 3 segundos
    });
}

// Função principal assíncrona para executar o processo
async function executar() {
    try {
        await ensureDirectoryExistence(DIRETORY_DATA);
        await salvarInformacoes('João da Silva', 'joao@example.com', 'senha123', '12345678901234');
    } catch (error) {
        console.error(error);
    }
}

// Executa a função principal
executar();
