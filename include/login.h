#ifndef LOGIN_H
#define LOGIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/buffer.h"


//char *name[] = {"Apple", "Banana", "Cherry"};
//char *name[] = {"Apple", "Banana", "Cherry"};






// #define SCRIPT_PATH "path/to/js/user-login.js"




// int executarComando(const char *comando) {
//     PROCESS_INFORMATION pi;
//     STARTUPINFO si;
//     DWORD exitCode;

//     ZeroMemory(&si, sizeof(si));
//     si.cb = sizeof(si);
//     ZeroMemory(&pi, sizeof(pi));

//     // Cria o processo para executar o comando
//     if (!CreateProcess(NULL, (LPSTR)comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
//         fprintf(stderr, "Erro ao criar o processo: %lu\n", GetLastError());
//         return -1;
//     }

//     // Espera o processo terminar
//     WaitForSingleObject(pi.hProcess, INFINITE);

//     // Obtém o código de saída do processo
//     if (!GetExitCodeProcess(pi.hProcess, &exitCode)) {
//         fprintf(stderr, "Erro ao obter o código de saída do processo: %lu\n", GetLastError());
//         exitCode = -1;
//     }

//     // Fecha os handles do processo e do thread
//     CloseHandle(pi.hProcess);
//     CloseHandle(pi.hThread);

//     return exitCode;
// }


// void salvarInformacoes(const char *nome, const char *email, const char *senha, const char *cnpj) {
//     char comando[1024];
//     snprintf(comando, sizeof(comando), "node \"%s\" salvar \"%s\" \"%s\" \"%s\" \"%s\"", SCRIPT_PATH, nome, email, senha, cnpj);
//     executarComando(comando);
// }

// int verificarInformacoes(const char *nome, const char *email, const char *senha, const char *cnpj) {
//     char comando[1024];
//     snprintf(comando, sizeof(comando), "node \"%s\" verificar \"%s\" \"%s\" \"%s\" \"%s\"", SCRIPT_PATH, nome, email, senha, cnpj);
//     int resultado = executarComando(comando);
//     return resultado == 0 ? 1 : 0;
// }



// int login(){
//     return 0;
// };


// #ifndef LOGIN_H
// #define LOGIN_H

int login();
int executarComando(const char *comando);
void salvarInformacoes(const char *nome, const char *email, const char *senha, const char *cnpj);
int verificarInformacoes(const char *nome, const char *email, const char *senha, const char *cnpj);

// #endif // LOGIN_H


#endif /*LOGIN_H */
