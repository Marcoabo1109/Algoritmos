#include <stdio.h>
#include <stdlib.h>

// Função para mesclar duas metades
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criação de arrays temporários
    int L[n1], R[n2];

    // Copiar dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclar os arrays temporários de volta para arr[l..r]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = l; // Índice inicial do array mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal que implementa Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ordenar a primeira e a segunda metade
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mesclar as metades ordenadas
        merge(arr, l, m, r);
    }
}

// Função para imprimir um array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Função principal para testar o código
int main() {
    int arr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nArray ordenado: \n");
    printArray(arr, arr_size);
    return 0;
}
