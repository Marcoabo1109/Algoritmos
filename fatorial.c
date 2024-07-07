#include <stdio.h>
#include <stdlib.h>

int Fat(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * Fat(n - 1);
    }
}

int main() {
    int n = 0;
    printf("Digite um número para o cálculo de seu fatorial: \n");
    scanf("%d", &n);

    printf("O fatorial de %d é: %d\n", n, Fat(n));
    return 0;
}
