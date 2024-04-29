#include <stdio.h>

int main() {
    int tamanho;
    
    // Determina o tamanho do array
    printf("Insira o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];
    int soma = 0;

    // Solicitando ao usuário inserir os numeros que seão calculados
    printf("Insira os numeros:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    // Somando os elementos do array
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }

    // Exibe o resultado da soma
    printf("A soma dos numeros : %d\n", soma);
    return 0;
}