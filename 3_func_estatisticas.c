#include <stdio.h>


void encontrarModa(int array[], int tamanho) {
    int frequencia[tamanho]; // Para armazenar a frequência de cada elemento
    int moda[tamanho]; 
    int maxFrequencia = 0;
    int numModas = 0;

    // Inicializa os arrays com zeros
    for (int i = 0; i < tamanho; i++) {
        frequencia[i] = 0;
        moda[i] = 0;
    }

    // Calcula a frequência de cada elemento
    for (int i = 0; i < tamanho; i++) {
        frequencia[array[i]]++; // Incrementa a frequência do número lido
    }

    // Encontra a maior frequência
    for (int i = 0; i < tamanho; i++) {
        if (frequencia[i] > maxFrequencia) {
            maxFrequencia = frequencia[i];
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
    for (int i = 0; i < numModas; i++) {
        printf("Moda: %d \n", moda[i]);
    }
}


void calcularMediana(int array[], int tamanho) {
    float aux, mediana;

    // Ordenar o vetor em ordem crescente usando o algoritmo de ordenação "bubble sort"
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = i + 1; j < tamanho; j++) {
            if(array[i] > array[j]) {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
    
    // Calcular a mediana
    if(tamanho % 2) {
        mediana = array[tamanho / 2];
    } else {
        mediana = (array[tamanho / 2 - 1] + array[tamanho / 2]) / 2.0;
    }
    
    // Imprimir a mediana
    printf("Mediana: %.1f\n", mediana);
}