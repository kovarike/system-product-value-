import z from 'zod';

// Definindo o esquema de validação do usuário usando zod
export const userSchema = z.object({
    id: z.string().uuid('ID deve ser um UUID válido'), // Mensagem de erro personalizada para UUID
    name: z.string()
        .min(1, 'Nome deve ter pelo menos 1 caractere') // Mensagem de erro personalizada para o tamanho mínimo
        .max(100, 'Nome deve ter no máximo 100 caracteres'), // Mensagem de erro personalizada para o tamanho máximo
    email: z.string()
        .email('Email deve ser um endereço de email válido'), // Mensagem de erro personalizada para email inválido
    password: z.string()
        .min(8, 'Senha deve ter pelo menos 8 caracteres') // Mensagem de erro personalizada para o tamanho mínimo
        .max(128, 'Senha deve ter no máximo 128 caracteres'), // Mensagem de erro personalizada para o tamanho máximo
    cnpj: z.string()
        .length(14, 'CNPJ deve ter exatamente 14 caracteres') // Verifica se o CNPJ tem exatamente 14 caracteres
});
