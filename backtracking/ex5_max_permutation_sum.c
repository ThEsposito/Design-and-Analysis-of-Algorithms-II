/*
14. (URI Online Judge | 1055) Soma Permutada Elegante
São disponibilizados a você n inteiros A1A2A3 · · · An. Encontre uma permutação destes
n inteiros de forma que a soma da diferença absoluta entre os elementos adjacentes seja
maximizada.

Supondo n = 4 e que os inteiros fornecidos sejam 4 2 1 5. A permutação 2 5 1 4 permite
a máxima soma. Para esta permutação, teríamos soma = abs(2-5) + abs(5-1) + abs(1-4) =
3+4+3 = 10. De todas as 24 permutações possíveis, você não vai obter qualquer soma cujo
valor exceda 10. Nós iremos chamar este valor 10, de soma permutada elegante.
Escreva uma função, usando Backtracking, que dado n inteiros encontre o valor da permutada elegante.
*/

#include <stdio.h>
#include <stdlib.h>

void print_arr(int arr[], int n) {
    for(int i = 0; i<n; i++) printf("%d ", arr[i]);
}

int abs_sum(int arr[] , int n);

int spe(int arr[], int sol[], int mark[], int n, int i, int max_sum) {
    if (i == n) {
        print_arr(sol, n);
        int sum = abs_sum(sol, n);
        printf(" = %d\n", sum);
        return sum;
    }

    for (int j = 0; j < n; j++) {
        if (mark[j] == 0) {
            mark[j] = 1;
            sol[i] = arr[j];

            int sum = spe(arr, sol, mark, n, i+1, max_sum);
            if (sum > max_sum) max_sum = sum;

            mark[j] = 0;
        }
    }

    return max_sum;
}

int abs_sum(int arr[] , int n) {
    int sum = 0;
    for (int i = 0; i < n-1; i++) {
        sum += abs(arr[i] - arr[i+1]);
    }
    return sum;
}


int main() {
    int arr[] = {4, 2, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int solutions[n];

    int mark[n];
    for (int i = 0; i < n; i++) mark[i] = 0;


    printf("%d", spe(arr, solutions, mark, n, 0, 0));
    return 0;
}