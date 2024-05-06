#include <stdio.h>
#include <stdlib.h> // Para usar a função malloc

// Função para inverter o array de caracteres
char* inverterArray(char *array, int tamanho) {
    // Aloca espaço para o array invertido
    char *arrayInvertido = (char*)malloc((tamanho + 1) * sizeof(char));
    // Aponta o ponteiro para o final do array
    char *ponteiroInvertido = arrayInvertido;
    for (int i = tamanho - 1; i >= 0; i--) {
        *ponteiroInvertido = array[i]; // Copia os caracteres invertidos
        ponteiroInvertido++; // Move o ponteiro para o próximo elemento do array
    }
    *ponteiroInvertido = '\0'; // Adiciona o caractere nulo para indicar o fim da string

    return arrayInvertido;
}

int main() {
    char frase[100];

    printf("Insira uma frase: ");
    scanf("%[^\n]", frase);

    // Obtém o tamanho da frase
    int tamanho = 0;
    while (frase[tamanho] != '\0') {
        tamanho++;
    }

    // Chama a função para inverter o array
    char *fraseInvertida = inverterArray(frase, tamanho);
    
    printf("Frase invertida: %s\n", fraseInvertida);

    // Libera a memória alocada para o array invertido
    free(fraseInvertida);

    return 0;
}