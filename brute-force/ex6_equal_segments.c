/*
Dada a sequência a[1 . . n] de números inteiros, escreva um programa na linguagem C que
verifica se existem dois segmentos consecutivos iguais na sequência, isto é, se existem i e
m tais que:
a[i] a[i + 1] · · · a[i + m − 1] = a[i + m] a[i + m + 1] · · · a[i + 2m − 1]
Imprima, caso existam, os valores de i e m.
Exemplo: Na sequência 7 9 5 4 5 4 8 6 existem i = 3 e m = 2.
Qual é complexidade da sua função ?
*/

#include <stdio.h>

int compare(int seq[], int begin, int subseq_size) {
    for (int i = begin; i < begin + subseq_size; i++) {
        if (seq[i] != seq[i+subseq_size]) return 0;
    }
    return 1;
}

int verifySeq(int seq[], int n) {
    for (int subseq_size = 1; subseq_size < n/2; subseq_size++) {
        for (int i = 0; (i + subseq_size) <= n; i++) {
            if (compare(seq, i, subseq_size)) {
                printf("i: %d\n", i);
                printf("m: %d\n", subseq_size);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int seq[] = {7, 9, 5, 4, 5, 4, 8, 6};
    int n = sizeof(seq)/sizeof(seq[0]);

    printf("Exists?: %d", verifySeq(seq, n));

    return 0;
}