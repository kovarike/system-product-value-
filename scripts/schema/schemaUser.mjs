import z from "zod";


export const userSchema = z.object({
    id: z.string().uuid(),
    name: z.string().min(15),
    email: z.string().email(),
    password: z.string().min(10),
    cnpj: z.string().min(14).max(14)

});