/*
Dada uma sequência de números inteiros com n elementos, escreva uma função na linguagem C para determinar um segmento de soma máxima.
Exemplo: Na sequência 5 2 -2 -7 3 14 10 -3 9 -6 4 1, a soma do segmento é 33.
Qual é a complexidade da sua função ?
*/

#include <stdio.h>

int max_sum_segment(int v[], int n) { // O(n^2)
    int max_sum = v[0];

    for (int i = 0; i < n; i++) { // n
        int sum = 0;
        for (int j = i; j < n; j++) { // n
            sum += v[j];
            if (sum > max_sum) max_sum = sum;
        }
    }
    return max_sum;
}

int main() {
    int n1 = 8;
    int v1[] = {20,-30,15,-10,30,-20,-30,30};
    printf("Test #1 - Answer=35 \n");
    printf("Max Sum Segment #1 - O(n^2): %d\n", max_sum_segment(v1,n1) );


    int n2=12;
    int v2[] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1};
    printf("\n");
    printf("Test #2 - Answer=33 \n");
    printf("Max Sum Segment #1 - O(n^2): %d\n", max_sum_segment(v2,n2) );

    return 0;
}