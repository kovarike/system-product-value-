#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "../include/buffer.h"
#include "../include/jsonsave.h"


int login() {
    setlocale(LC_CTYPE, "Portuguese_Brazil.1252");
    printf("\nLogin:\n");

    char nome[50];
    char email[150];
    char senha[20];
    char cnpj[20];

    // Solicita informações do usuário
    lerString(nome, sizeof(nome), "Digite seu nome: ");
    lerString(email, sizeof(email), "Digite seu e-mail: ");
    lerString(senha, sizeof(senha), "Digite sua senha: ");
    lerString(cnpj, sizeof(cnpj), "Digite seu CNPJ: ");

    // Salva informações no arquivo JSON
    if (salvarInformacoes(nome, email, senha, cnpj)) {
        printf("Você já tem um acesso autorizado, verifique as suas informações de login:\n");
        return verificarInformacoes(email, senha) ? 0 : -1;
    } else {
        printf("Informações salvas com sucesso. Acesso concedido.\n");
        return 0;
    }
}