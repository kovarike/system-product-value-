const fs = require('fs');

const JSON_FILE = 'usuarios.json';

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

    fs.writeFile(JSON_FILE, JSON.stringify(jsonObject, null, 2), (err) => {
        if (err) {
            console.error('Erro ao abrir o arquivo para escrita:', err);
            return;
        }
        console.log('Informações salvas com sucesso no arquivo JSON.');
    });
}

/**
 * Função para verificar as informações no arquivo JSON.
 * @param {string} nome - Nome do usuário.
 * @param {string} email - Email do usuário.
 * @param {string} senha - Senha do usuário.
 * @param {string} cnpj - CNPJ do usuário.
 * @returns {boolean} - Retorna verdadeiro se as informações estiverem corretas, caso contrário, falso.
 */
function verificarInformacoes(nome, email, senha, cnpj) {
    try {
        const data = fs.readFileSync(JSON_FILE, 'utf8');
        const jsonObject = JSON.parse(data);

        const info = jsonObject.nome === nome &&
            jsonObject.email === email &&
            jsonObject.senha === senha &&
            jsonObject.cnpj === cnpj;

        console.log(info ? 'Informações corretas.' : 'Informações incorretas.');
        return info;
    } catch (err) {
        console.error('Erro ao abrir o arquivo para leitura ou analisar JSON:', err);
        return false;
    }
}

const args = process.argv.slice(2);
const command = args[0];
if (command === 'salvar') {
    salvarInformacoes(args[1], args[2], args[3], args[4]);
} else if (command === 'verificar') {
    verificarInformacoes(args[1], args[2], args[3], args[4]);
}
