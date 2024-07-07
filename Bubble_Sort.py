# Lógica de swap com 2 loops O(n2)

def bubble_sort(elements):
    # Loop do último índice até o primeiro índice
    for end in range(len(elements)-1, 0, -1):
        swapped = False
        for i in range(end):
            if elements[i] > elements[i + 1]:
                # Trocando os elementos se estiverem na ordem errada
                elements[i], elements[i + 1] = elements[i + 1], elements[i]
                swapped = True
        if not swapped:
            # Sai da função se nenhum elemento foi trocado (a lista está ordenada)
            break

elements = [39, 12, 18, 85, 72, 10, 2, 18]

print("Lista não ordenada:")
print(elements)
bubble_sort(elements)
print("Lista ordenada:")
print(elements)
