#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o índice do menor elemento no array
int buscaMenor(int *arr, int tam) {
    int menor = arr[0];
    int menor_indice = 0;

    for (int i = 1; i < tam; i++) {
        if (arr[i] < menor) {
            menor = arr[i];
            menor_indice = i;
        }
    }
    return menor_indice;
}

// Função de ordenação por seleção que cria um novo array ordenado
int* ordenacaoSelecao(int *arr, int tam) {
    int* novoArr = (int*)malloc(tam * sizeof(int));
    if (!novoArr) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < tam; i++) {
        int menor_indice = buscaMenor(arr, tam - i);
        novoArr[i] = arr[menor_indice];

        // Remove o menor elemento movendo os elementos para a esquerda
        for (int j = menor_indice; j < tam - i - 1; j++) {
            arr[j] = arr[j + 1];
        }
    }
    return novoArr;
}

int main() {
    int array[] = {5, 3, 6, 2, 10};
    int tam = sizeof(array) / sizeof(array[0]);

    int* novoArr = ordenacaoSelecao(array, tam);

    printf("Array ordenado:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", novoArr[i]);
    }
    printf("\n");

    free(novoArr);
    return 0;
}
