#ifndef LOGIN_H
#define LOGIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include "../include/buffer.h"
#include "../include/jsonsave.h"


int login() {

    char nome[50];
    char email[150];
    char senha[20];
    char cnpj[20];

 
    if (salvarInformacoes(nome, email, senha, cnpj)) {
        printf("Você já tem um acesso autorizado, verifique as suas informações de login:\n");
        return verificarInformacoes(email, senha) ? 0 : -1;
    } else {
        printf("Informações salvas com sucesso. Acesso concedido.\n");
        return 0;
    }
}


#endif /*LOGIN_H */
