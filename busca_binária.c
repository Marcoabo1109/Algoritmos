#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *lista, int item, int tamanho) {
    int baixo = 0;
    int alto = tamanho - 1;

    while (baixo <= alto) {
        int meio = (baixo + alto) / 2;
        int chute = lista[meio];

        if (chute == item) {
            return meio;
        }
        if (chute > item) {
            alto = meio - 1;
        } else {
            baixo = meio + 1;
        }
    }
    return -1; // Retorna -1 se o item não for encontrado
}

int busca_simles(int*lista,int item,int tam){
    for(int i=0;i<tam;i++){
        if(lista[i]==item){
            return i;
        }
    }
}

/*
A diferença entre a busca binária para a simples está no tempo de execussão 
já que a busca simles O(n) e a binária é O(log2 n)
*/
int main() {
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};// Caso não estivesse ordenado deveria usar algum sort.
    int tamanho = sizeof(array) / sizeof(array[0]);
    int buscado = 0;
    int achado = 0;

    printf("Digite o número que desejas buscar: \n");
    scanf("%d", &buscado);

    achado = busca_binaria(array, buscado, tamanho);

    if (achado != -1) {
        printf("O número encontrado na lista: %d\nSua posição na lista: %d\n", array[achado], achado);
    } else {
        printf("Número não encontrado na lista.\n");
    }

    return 0;
}