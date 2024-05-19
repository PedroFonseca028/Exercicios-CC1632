#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para alocar memória para uma matriz
int** alocar_matriz(int linhas, int colunas) {
    int** matriz = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }
    return matriz;
}

// Função para liberar memória de uma matriz
void liberar_matriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Função para multiplicar duas matrizes
int** multiplicar_matrizes(int** A, int linhasA, int colunasA, int** B, int linhasB, int colunasB) {
    if (colunasA != linhasB) {
        printf("Erro: As matrizes não podem ser multiplicadas.\n");
        return NULL;
    }
    int** C = alocar_matriz(linhasA, colunasB);
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colunasA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Função para transpor uma matriz
int** transpor_matriz(int** A, int linhas, int colunas) {
    int** T = alocar_matriz(colunas, linhas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            T[j][i] = A[i][j];
        }
    }
    return T;
}

// Função para imprimir uma matriz
void imprimir_matriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para ler uma matriz do usuário
void ler_matriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main() {
    // Dimensões das matrizes
    int linhasA, colunasA, linhasB, colunasB;
    
    // Medição de tempo
    clock_t inicio, fim;
    double tempo_decorrido;

    inicio = clock(); // Início da contagem de tempo

    // Leitura das dimensões das matrizes
    printf("Digite o número de linhas da matriz A: ");
    scanf("%d", &linhasA);
    printf("Digite o número de colunas da matriz A: ");
    scanf("%d", &colunasA);

    printf("Digite o número de linhas da matriz B: ");
    scanf("%d", &linhasB);
    printf("Digite o número de colunas da matriz B: ");
    scanf("%d", &colunasB);

    // Verificação se a multiplicação é possível
    if (colunasA != linhasB) {
        printf("Erro: As matrizes não podem ser multiplicadas. O número de colunas da matriz A deve ser igual ao número de linhas da matriz B.\n");
        return 1;
    }

    // Alocação das matrizes
    int** A = alocar_matriz(linhasA, colunasA);
    int** B = alocar_matriz(linhasB, colunasB);

    // Leitura das matrizes
    printf("Digite os elementos da matriz A:\n");
    ler_matriz(A, linhasA, colunasA);

    printf("Digite os elementos da matriz B:\n");
    ler_matriz(B, linhasB, colunasB);

    

    // Multiplicação das matrizes
    int** C = multiplicar_matrizes(A, linhasA, colunasA, B, linhasB, colunasB);
    if (C != NULL) {
        printf("Resultado da multiplicação:\n");
        imprimir_matriz(C, linhasA, colunasB);
        liberar_matriz(C, linhasA);
    }


    // Transposição da matriz A
    int** T = transpor_matriz(A, linhasA, colunasA);
    printf("Transposição da matriz A:\n");
    imprimir_matriz(T, colunasA, linhasA);

    // Liberação de memória
    liberar_matriz(A, linhasA);
    liberar_matriz(B, linhasB);
    liberar_matriz(T, colunasA);

    fim = clock(); // Fim da contagem de tempo

    // Cálculo do tempo decorrido em segundos
    tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo da execução do algoritmo: %.5f segundos\n", tempo_decorrido);

    return 0;
}

