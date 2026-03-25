/*
12. (QUADRADO COM PALITOS DE FÓSFOROS) Dado um vetor de inteiros palitos_de_fosforos ,
onde o palitos_de_fosforos[i] é o tamanho do i-esimo palito de fósforo. Deseja-se usar
todos os palitos de fósforos para fazer um quadrado. Não é permitido quebrar nenhum
palito. Escreva uma função que devolva true se você pode construir um quadrado e falso
caso contrário.
Restrições:
• 1 ≤ len(palitos_de_fosforos) ≤ 15
• 1 ≤ palitos_de_fosforos[i] ≤ 108
*/

#include <stdio.h>
#include <stdbool.h>

int sum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i<n; i++) sum += arr[i];

    return sum;
}

int matchsticks_square(int sticks[], int mark[], int sol[], int n, int target, int i) {
    if (); // caso base

    for (int j = 0; j < 4; j++) { // Para cada lado

    }

}

bool can_form_square(int sticks[], int n) {
    if (n < 4) return false;

    int s = sum(sticks, n);
    if (s % 4 != 0) return false;

    int solutions[n];
    int mark[n];

    for (int i = 0; i < n; i++) mark[i] = 0;

    return matchsticks_square(sticks, mark, solutions, n, s/4, 0);
}

int main() {
    // Caso 1: possível (clássico)
    int t1[] = {1, 1, 2, 2, 2};
    printf("Test 1: %s\n", can_form_square(t1, 5) ? "true" : "false");
    // esperado: true

    // Caso 2: impossível (soma não divisível por 4)
    int t2[] = {3, 3, 3, 3, 4};
    printf("Test 2: %s\n", can_form_square(t2, 5) ? "true" : "false");
    // esperado: false

    // Caso 3: possível
    int t3[] = {5, 5, 5, 5};
    printf("Test 3: %s\n", can_form_square(t3, 4) ? "true" : "false");
    // esperado: true

    // Caso 4: impossível (não dá pra balancear)
    int t4[] = {1, 1, 1, 1, 1, 1, 1};
    printf("Test 4: %s\n", can_form_square(t4, 7) ? "true" : "false");
    // esperado: false

    // Caso 5: possível (mais complexo)
    int t5[] = {1, 1, 2, 2, 2, 2, 3, 3};
    printf("Test 5: %s\n", can_form_square(t5, 8) ? "true" : "false");
    // esperado: true

    // Caso 6: impossível (um palito muito grande)
    int t6[] = {10, 1, 1, 1, 1, 1, 1, 1};
    printf("Test 6: %s\n", can_form_square(t6, 8) ? "true" : "false");
    // esperado: false

}}