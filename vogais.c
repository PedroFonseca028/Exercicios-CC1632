#include <stdio.h>
#include <string.h>

int vogais(char c) {

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }
    else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1; 
    }
    // Se não for uma vogal, retorna 0
    else {
        return 0; // Não é uma vogal
    }
}

// Função para contar o número de vogais em uma string
int contarVogais(char *string) {
    int numVogais = 0;
    int i;
    // Itera sobre cada caractere na string
    for (i = 0; string[i] != '\0'; i++) {
        // Verifica se o caractere é uma vogal
        if (vogais(string[i])) {
            numVogais++;
        }
    }
    return numVogais;
}

int main() {
    char digitados[100];
    int numVogais;

    // Solicita ao usuário que insira uma string
    printf("Digite uma string: ");
    fgets(digitados, sizeof(digitados), stdin);

    // Chama a função para contar as vogais na string inserida pelo usuário
    numVogais = contarVogais(digitados);

    // Exibe o número de vogais na string
    printf("O numero de vogais na string sao: %d\n", numVogais);

    return 0;
}