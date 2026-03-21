/*
Escreva uma função recursiva que apresente números binários de tamanho n.
• Exemplo: n = 3
Saída :
000
001
010
011
100
101
110
111
*/

#include <stdio.h>

void print_arr(int arr[], int n) {
    for(int i = 0; i<n; i++) printf("%d ", arr[i]);

    printf("\n");
}

void binary_sequences(int solutions[], int n, int i){
    if(i == n) {
        print_arr(solutions, n);
        return;
    }

    for(int j = 0; j<2; j++){
        solutions[i] = j;
        binary_sequences(solutions, n, i+1);
    }
}

int main() {
    int n = 5;
    int solutions[n];

    binary_sequences(solutions, n, 0);
}