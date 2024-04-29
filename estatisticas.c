#include <stdio.h>

int main() {
    int tamanho;
    
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

    //Calculando a moda
    int frequencia[tamanho] = {0}; // Para armazenar a frequência de cada elemento
    int moda[tamanho]; // Para armazenar as modas (pode haver mais de uma moda)
    int maxFrequencia = 0;
    int numModas = 0;

    // Calcula a frequência de cada elemento
    for (int i = 0; i < tamanho; i++) {
        frequencia[array[i]]++; // Incrementa a frequência do número lido
    }

    // Encontra a maior frequência
    for (int i = 0; i < tamanho; i++) {
        if (frequencia[array[i]] > maxFrequencia) {
            maxFrequencia = frequencia[array[i]];
        }
    }

    // Encontra todos os números com a maior frequência
    for (int i = 0; i < tamanho; i++) {
        if (frequencia[array[i]] == maxFrequencia) {
            // Verifica se o número já não está na lista de modas
            int j;
            for (j = 0; j < numModas; j++) {
                if (moda[j] == array[i]) {
                    break;
                }
            }
            if (j == numModas) { // Se não encontrado na lista, adiciona
                moda[numModas++] = array[i];
            }
        }
    }

    // Exibe o resultado das modas
    printf("Moda(s): \n");
    for (int i = 0; i < numModas; i++) {
        printf("%d ", moda[i]);
    }
    

    // Exibe o resultado da media
    printf("\n A media dos numeros : %.2f\n", media);
    return 0;


}