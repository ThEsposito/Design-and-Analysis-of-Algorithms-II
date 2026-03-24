/*
2. Um bitonic array é um vetor de números que é organizado em duas partes. A primeira parte que consiste de elementos
na ordem crescente e a segunda parte consiste de elementos em ordem decrescente. Mais precisamente,
uma vetor A[1 . . n] é bitonic se e somente se existe um índice i, 1 ≤ i ≤ n, tal que A[1 . . i] é estritamente crescente,
e A[i . . n] é estritamente decrescente. Por exemplo, o vetor {2, 5, 8, 7, 3} é bitonic, com i = 3. Faça uma
função, utilizando a técnica de divisão e conquista que encontre o máximo elemento de um bitonic array (assuma que todos
os elementos são distintos).
 */

#include <stdio.h>
int bitonic_max(int arr[], int start, int end) {
    if (start == end) return arr[start];

    int middle = start + (end - start) / 2;

    if (arr[middle] < arr[middle + 1]) return bitonic_max(arr, middle + 1, end);
    return bitonic_max(arr, start, middle);
}

int main() {
    int arr[] = {1,2,5,8,7,3,-1,-2};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Max: %d", bitonic_max(arr, 0, n));

    return 0;
}