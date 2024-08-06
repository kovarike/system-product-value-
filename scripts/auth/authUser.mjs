import fs from "fs"
import { userSchema } from "../schema/schemaUser.mjs";


/**
 * Função para verificar as informações no arquivo JSON.
 * @param {string} name - Nome do usuário.
 * @param {string} email - Email do usuário.
 * @param {string} password - password do usuário.
 * @param {string} cnpj - CNPJ do usuário.
 * @param {string} id - CNPJ do usuário.
 * @returns {void} - Retorna verdadeiro se as informações estiverem corretas, caso contrário, falso.
 */
export function verificarInformacoes(name, email, password, cnpj, id) {
    try {
        const data = fs.readFileSync(JSON_FILE, 'utf8');
        const jsonObject = JSON.parse(data);

        const info = userSchema.parse(jsonObject);

        if(info.id !== id && info.name !== name || info.password !== password){
            console.log(`Informações incorretas. id: ${id}, ou password: ${password}, não estão corretos.`);
        }else{
            console.log('Informações corretas.');
            return info;
        }
       
    } catch (err) {
        console.error('Erro ao abrir o arquivo para leitura ou analisar JSON:', err);
        return err;
    }
}