#ifndef BUFFER_H
#define BUFFER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para limpar o buffer de entrada
void lerString(char *buffer, size_t tamanho, const char *mensagem) {
    printf("%s", mensagem);
    if (fgets(buffer, tamanho, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove o newline
    }
}



#endif // BUFFER_H
