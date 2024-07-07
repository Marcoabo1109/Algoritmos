#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//O problema é que usa mais memória que o quick_sort

// Função para encontrar o valor mínimo no array
int find_min(int arr[], int n) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Função para encontrar o valor máximo no array
int find_max(int arr[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função Pigeonhole Sort
void pigeonhole_sort(int arr[], int n) {
    int min = find_min(arr, n);
    int max = find_max(arr, n);
    int range = max - min + 1;

    // Criação dos "pigeonholes"
    int *holes = (int *)calloc(range, sizeof(int));

    // Preencher os pigeonholes
    for (int i = 0; i < n; i++) {
        holes[arr[i] - min]++;
    }

    // Colocar os elementos de volta ao array original em ordem
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (holes[i]-- > 0) {
            arr[index++] = i + min;
        }
    }

    // Liberar a memória alocada para os pigeonholes
    free(holes);
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8, 3, 2, 7, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    pigeonhole_sort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}
