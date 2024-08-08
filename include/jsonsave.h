#ifndef JSONSAVE_H
#define JSONSAVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define SCRIPT_PATH "../scripts/user-login.mjs"
#define BUFFER_SIZE 1024

int executarComando(const char *comando) {
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    DWORD exitCode;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    
    if (!CreateProcess(NULL, (LPSTR)comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "Erro ao criar o processo: %lu\n", GetLastError());
        return -1;
    }

    // Espera o processo terminar
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Obtém o código de saída do processo
    if (!GetExitCodeProcess(pi.hProcess, &exitCode)) {
        fprintf(stderr, "Erro ao obter o código de saída do processo: %lu\n", GetLastError());
        exitCode = -1;
    }

    // Fecha os handles do processo e do thread
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return exitCode;
}

// Função para salvar as informações do usuário usando o script Node.js
int salvarInformacoes(const char *nome, const char *email, const char *senha, const char *cnpj) {
    char comando[BUFFER_SIZE];
    snprintf(comando, sizeof(comando), "node \"%s\" salvar \"%s\" \"%s\" \"%s\" \"%s\"", SCRIPT_PATH, nome, email, senha, cnpj);
    return executarComando(comando) == 0;
}

// Função para verificar as informações do usuário usando o script Node.js
int verificarInformacoes(const char *email, const char *senha) {
    char comando[BUFFER_SIZE];
    snprintf(comando, sizeof(comando), "node \"%s\" verificar \"%s\" \"%s\"", SCRIPT_PATH, email, senha);
    return executarComando(comando) == 0;
}



#endif /* JSONSAVE_H */
