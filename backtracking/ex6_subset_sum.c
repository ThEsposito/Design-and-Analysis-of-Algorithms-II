/*
15. SUBSET SUM - O PROBLEMA DO CHEQUES:
Suponha que p1, p2, ···, pn são os valores dos cheques que você emitiu durante o mês.
No fim do mês, o banco debita uma quantia C na sua conta. Você quer saber se algum
conjunto de cheques corresponde ao valor debitado. Considere que não temos cheques
com valores repetidos.

Generalização do problema: Dado um conjunto de números naturais P = {p1, p2, · · · , pn} e C,
decidir se existe um subconjunto X de {1, 2, · · · , n} tal que o somatório dos elementos P
relacionados em X é igual a C.

Exemplo1: P = {30, 40, 10, 15, 11, 60, 54} e C = 55, teríamos os subconjuntos
• X = {2, 4} p2 = 40 p4 = 15
• X = {1, 4, 5}, p1 = 30, p4 = 15, p5 = 10
*/

#include <stdio.h>
#include <stdbool.h>

// void binary_sequences(int solutions[], int n, int i){
//     if(i == n) {
//         print_arr(solutions, n);
//         return;
//     }
//
//     for(int j = 0; j<2; j++){
//         solutions[i] = j;
//         binary_sequences(solutions, n, i+1);
//     }
// }

void print_arr(int arr[], int n) {
    for(int i = 0; i<n; i++) printf("%d ", arr[i]);

    printf("\n");
}

bool subset_sum(int arr[], int mark[], int n, int target, int i) {
    if (i == n) {
        int sum = 0;
        for (int  j = 0; j < n; j++) {
            if (mark[j] == 1) sum += arr[j];
        }
        return sum == target;
    }

    for (int j = 0; j < 2; j++) {
        mark[i] = j;
        if (subset_sum(arr, mark, n, target, i+1)) return true;
    }
    
    return false;
}

int main() {
    int arr[] =  {30, 40, 10, 15, 11, 60, 54};
    int n = sizeof(arr)/sizeof(arr[0]);

    int mark[n];
    for (int i = 0; i < n; i++) mark[i] = 0;
    int found = subset_sum(arr, mark, n, 55, 0);
    if(found) {
        for(int i = 0; i < n; i++) {
            if(mark[i] == 1) {
                printf("%d ", arr[i]);
            }
        }
    } else printf("Not found!");
    return 0;
}
