#include <stdio.h>

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Escolha o último elemento como pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi é o índice de partição, arr[pi] está no lugar certo
        int pi = partition(arr, low, high);

        // Separadamente ordena os elementos antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(array) / sizeof(array[0]);
    printf("Array antes de ordenar:\n");
    printArray(array, n);
    
    quickSort(array, 0, n - 1);
    
    printf("Array após ordenar:\n");
    printArray(array, n);
    return 0;
}
