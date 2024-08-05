#include <stdio.h>
#include <stdlib.h>


// Função para limpar o buffer de entrada
void limparBuffer() {
    fflush(stdin); // Funciona com GCC no Windows
}