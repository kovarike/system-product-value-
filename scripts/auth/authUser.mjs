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
        // Verifica se o arquivo JSON existe
        if (!fs.existsSync(JSON_FILE)) {
            console.error(`Arquivo ${JSON_FILE} não encontrado.`);
            return false;
        }

        const data = fs.readFileSync(JSON_FILE, 'utf8');
        const jsonObject = JSON.parse(data);

        // Valida o JSON com o esquema
        const result = userSchema.safeParse(jsonObject);
        if (!result.success) {
            console.error(`Dados inválidos no arquivo JSON: ${result.error.errors.map(e => e.message).join(', ')}`);
            return false;
        }

        const { id: storedId, email: storedEmail, password: storedPassword } = result.data;

        // Verifica se todas as informações estão corretas
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
