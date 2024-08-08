#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include "include/jsonsave.h"
#include "include/buffer.h"
#include "include/login.h"

int main() {
   setlocale(LC_ALL, "Portuguese");

    int codigo;
    float preco_custo;
    float preco_novo;
    float soma_preco_custo = 0.0;
    float soma_preco_novo = 0.0;
    int quantidade_produtos = 0;

    printf("Bem-Vindo ao sistema:\n");

    // Chama a função de login
    // if (login() != 0) {
    //     printf("Falha no login. Saindo...\n");
    //     return 1;
    // }
    login();

    printf("Digite o código e o preço de custo de cada produto (código negativo ou zero para encerrar):\n");

    while (1) {
        printf("Código do produto: ");
        if (scanf("%d", &codigo) != 1 || codigo <= 0) {
            if (codigo <= 0) break;
            fprintf(stderr, "Entrada inválida para o código do produto.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;
        }

        printf("Preço de custo: ");
        if (scanf("%f", &preco_custo) != 1) {
            fprintf(stderr, "Entrada inválida para o preço de custo.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;
        }

        preco_novo = preco_custo * 1.20;

        soma_preco_custo += preco_custo;
        soma_preco_novo += preco_novo;
        quantidade_produtos++;

        printf("Código: %d, Preço novo: %.2f\n", codigo, preco_novo);
    }

    if (quantidade_produtos > 0) {
        float media_preco_custo = soma_preco_custo / quantidade_produtos;
        float media_preco_novo = soma_preco_novo / quantidade_produtos;
        printf("\nA quantidade de produtos com preços alterados foram: %d\n", quantidade_produtos);
        printf("Média dos preços de custo: %.2f\n", media_preco_custo);
        printf("Média dos preços novos: %.2f\n", media_preco_novo);
    } else {
        printf("Nenhum produto foi inserido.\n");
    }

    return 0;
}

