/*
Considere uma partida de futebol entre duas equipes A × B, cujo placar final é m × n,
em que m e n são número de gols marcados por A e B, respectivamente. Escreva um
algoritmo recursivo que imprima todas as possíveis sucessões de gols marcados. Por
exemplo, para um placar final de 3 × 1, as possíveis sucessões de gols são “AAAB”,
“AABA”, “ABAA” e “BAAA”.
*/

#include <stdio.h>

void print_arr(char arr[], int n) {
    for(int i = 0; i<n; i++) printf("%c ", arr[i]);

    printf("\n");
}

void permuta_placar_generico(int gols[], int n_times, char simbolos[], int i, char solucoes[], int tam_solucoes){
    int total_gols = 0;
    
    for(int j = 0; j < n_times; j++) {
        total_gols += gols[j];
    }

    if(total_gols == 0) { // caso base: todas as decisões foram tomadas
        print_arr(solucoes, tam_solucoes);
        return;
    }
    
    for(int j = 0; j < n_times; j++) {
        if(gols[j] > 0) {
            solucoes[i] = simbolos[j];
            gols[j]--;
            permuta_placar_generico(gols, n_times, simbolos, i+1, solucoes, tam_solucoes);
            gols[j]++;
        }
    }
}


void permuta_placar(int m, int n, int i, char solucoes[], int tam){
    if(m == 0 && n == 0) {
        print_arr(solucoes, tam);
    }

    if(m > 0) {
        solucoes[i] = 'A';
        permuta_placar(m-1, n, i+1, solucoes, tam);
    }

    if(n > 0) {
        solucoes[i] = 'B';
        permuta_placar(m, n-1, i+1, solucoes, tam);
    }
}


int main() {
/*
    int m = 3;
    int n = 2;
    char solucoes[m+n];

    permuta_placar(m, n, 0, solucoes, m+n);

    return 0;
*/

    // Generalização:
    int numero_times = 5;
    char simbolos[] = {'A', 'B', 'C', 'D', 'E'};
    int gols[] = {1, 2, 3, 4, 5};

    int total_gols = 0;
    for(int i = 0; i < numero_times; i++) total_gols+= gols[i];
    char solucoes[total_gols];

    permuta_placar_generico(gols, numero_times, simbolos, 0, solucoes, total_gols);

    return 0;
}