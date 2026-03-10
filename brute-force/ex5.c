/*
5) Dada uma sequência de números inteiros com n elementos, determinar quantas
subsequências de números iguais consecutivos compõem essa sequência.
Exemplos:
a) A sequência 5 2 2 3 4 4 4 4 4 1 1, é composta por 5 subsequências:
(5), (2,2), (3), (4, 4, 4, 4, 4), (1,1);
b) A sequência: 3 3 -1 -1 -1 12 12 12 3 3 é composta por 4 subsequências:
(3,3), (-1, -1, -1), (12, 12, 12), (3,3);

Escreva uma função na linguagem C que determina a quantidade de
subsequências em sequência dada.
Qual é complexidade da sua função ?
*/

#include <stdio.h>

int conta_sequencia(int seq[], int n){ // O(N) 
    int counter = 0;

    int i = 0;
    
    while(i < n){
        int j = i+1;

        while(j < n && seq[j] == seq[i]) j++;

        counter++;
        i = j;
    }
    return counter;
}

int main() {
    int seq[] = {3, 3, -1, -1, -1, 12, 12,12, 3, 3};
    int n = sizeof(seq)/sizeof(seq[0]);

    printf("Qtde de sequências: %d", conta_sequencia(seq, n));

    return 0;
}