download - setup MinGW - https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/
and, config extansion in vs code.
settigs,json - {
    "C_Cpp.default.compilerPath": "C:\\msys64\\ucrt64\\bin\\gcc.exe"
}

tasks.json - {
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "C/C++: gcc.exe build active file",
			"command": "C:\\msys64\\ucrt64\\bin\\gcc.exe",
			"args": [
				"-fdiagnostics-color=always",
				"-g",
				"${file}",
				"-o",
				"${fileWorkspaceFolderBasename}" // 	"${fileDirname}${workspaceFolderBasename}" //${fileWorkspaceFolderBasename}.exe
			],
			"options": {
				"cwd": "C:\\msys64\\ucrt64\\bin"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": "build",
			"detail": "compiler: C:\\msys64\\ucrt64\\bin\\gcc.exe"
		}
	]
}

gcc -o meu_programa meu_programa.c -I<path_para_cabecalhos> -L<path_para_biblioteca> -ljson-c
gcc -o test test.c -IC:\\msys64\\mingw64\\include -IC:\\msys64\\mingw64\\include\\json-c -LC:\\msys64\\mingw64\\lib -ljson-c

node js/user-login.js salvar "Nome" "email@example.com" "senha123" "12345678901234"
./programa
gcc -o programa main.c -lws2_32