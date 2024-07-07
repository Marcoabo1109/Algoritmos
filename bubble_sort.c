#include <stdio.h>
#include <stdlib.h>

void swap(int *,int *);
void bubble_sort(int *,int);

int main(){
    printf("Digite o tamanho de sua lista:");
    int tam;
    scanf("%d",&tam);
    int *n;
    n=(int *)calloc(tam,sizeof(int));
    printf("Digite o números a serem ordenados\n");
    for (int i=0;i<tam;i++){
        scanf("%d", &n[i]);
    }
    printf("Seus números são: \n");
    for(int i =0;i<tam;i++){
        printf("%d ", n[i]);
    }
    printf("\n");
    printf("Seus números ordenados são:\n");
    bubble_sort(n,tam);
    for(int i =0;i<tam;i++){
        printf("%d ", n[i]);
    }
    printf("\n");

    free(n);
    return 0;
}


void bubble_sort(int *n,int tam){

    for(int j=0;j<tam-1;j++){
     for(int i=0;i<tam - 1 - j;i++){
        if(n[i]>n[i+1]){
            swap(&n[i],&n[i+1]);
          }
    }  
  }
}
void swap(int *a,int *b){
    int aux=0;
    aux=*a;
    *a=*b;
    *b=aux;

}