#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3_func_estatisticas.c"

int main() {
    int tamanho;
    float mediana = 0, aux = 0;
    
    // Determina o tamanho do array
    printf("Insira o tamanho do array: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho deve ser maior que zero.\n");
        return 1; // Sinaliza um erro
    }

    int array[tamanho];
    int soma = 0;

    // Solicitando ao usuário inserir os numeros que serão calculados
    printf("Insira os numeros:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    // Somando os elementos do array
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    // Calculando a média como um float
    float media = (float)soma / tamanho;
    // Exibe o resultado da media
    printf("A media dos numeros : %.2f\n", media);

    encontrarModa(array, tamanho);

    calcularMediana(array, tamanho);
    return 0;
}