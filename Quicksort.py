# Técnica (DC):Dividir para conquistar
# Recursão
# Vaira de O(nlogn) até O(n2)

"""
Particionamento:
    um sub array contendo todos os números menores que o pivô
    o pivô
    um sub array contendo todos os númeroso maiores que o pivô

Utilização de Indução
"""

def quicksort(array):
    if len(array)<2:
        return array #Caso-base; arrays com 0 ou 1 elementos já estão ordenados
    else:
        pivo=array[0]
        menores=[i for i in array[1:] if i<=pivo]
        maiores=[i for i in array[1:] if i>pivo]
    return quicksort(menores)+[pivo]+quicksort(maiores) #Caso-recursivo;

array=[10,9,8,7,6,5,4,3,2,1,0]
print(quicksort(array))
