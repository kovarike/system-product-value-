import fs from 'fs'
import path from 'path'
import { binary } from "binary-id"
import { verificarInformacoes } from './auth/authUser.mjs';
import { userSchema } from './schema/schemaUser.mjs';

const JSON_FILE = 'data.json';
const DIRETORY_DATA = '.data';


/**
 * @param {string} pathDir
 */
function Dir(pathDir){
    return new Promise((resolve, reject) => {
        // Simula um atraso de 3 segundos
        setTimeout(() => {
            if (!fs.existsSync(pathDir)) {
                fs.mkdir(pathDir, { recursive: true }, (err) => {
                    if (err) {
                        reject(`Erro ao criar o diretório: ${err.message}`);
                    } else {
                        console.log(`Diretório criado: ${pathDir}`);
                        resolve();
                    }
                });
            } else {
                console.log(`Diretório já existe: ${pathDir}`);
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
 */
function salvarInformacoes(nome, email, senha, cnpj) {
    const jsonObject = {
        id: binary.UUID(),
        nome: nome,
        email: email,
        senha: senha,
        cnpj: cnpj
    };
    const data = userSchema.safeParse(jsonObject);

    Dir(DIRETORY_DATA);
    const filePath = path.join(DIRETORY_DATA, JSON_FILE);
    return new Promise((resolve, reject) => {
        // Simula um atraso de 3 segundos
        setTimeout(() => {
            // Salva as informações no arquivo JSON
           if(fs.existsSync(filePath)){
            console.log("Error ao salvar as informações, você já tem um acesso autorizado, verifique as suas informações de login:");
           }else{
            fs.writeFile(filePath, JSON.stringify(jsonObject, null, 2), (err) => {
                if (err) {
                    reject(`Erro ao salvar informações no arquivo JSON: ${err.message}`);
                } else {
                    console.log('Informações salvas com sucesso no arquivo JSON.');
                    resolve();
                }
            });
           }
        }, 3000); // Atraso de 3 segundos
    });
}



const args = process.argv.slice(2);
const command = args[0];
if (command === 'salvar') {
    salvarInformacoes(args[1], args[2], args[3], args[4]);
} else if (command === 'verificar') {
    verificarInformacoes(args[1], args[2], args[3], args[4]);
}
