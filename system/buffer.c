#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void lerString(char *buffer, size_t tamanho, const char *mensagem) {
    printf("%s", mensagem);
    if (fgets(buffer, tamanho, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove o newline
    }
}