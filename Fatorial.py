def Fat(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * Fat(n - 1)

print("Digite um número para o cálculo de seu fatorial:")
a = int(input())
print(f"O fatorial de {a} é :{Fat(a)}")
