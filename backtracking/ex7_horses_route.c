/*
(PERCURSO DO CAVALO) Dado um tabuleiro com n × n posições, o cavalo movimenta-se
segundo as regras do xadrez. A partir de uma posição inicial (x0, y0), o problema consiste
em fazer o cavalo “visitar” todas as casas do tabuleiro, sem repetições.
Figura 1: Percurso do cavalo no tabuleiro de xadrez
Escreva um programa que selecione uma determinada posição do tabuleiro e verifique se
é possível realizar o percurso do cavalo no tabuleiro de xadrez.
*/

#include <stdio.h>
#include <stdbool.h>

#define N 8

typedef struct {
    int lin;
    int col;
} Point;

void generate_moves(Point moves[], Point ini) {
    moves[0].lin = ini.lin + 2;
    moves[0].col = ini.col + 1;

    moves[1].lin = ini.lin + 2;
    moves[1].col = ini.col - 1;

    moves[2].lin = ini.lin - 2;
    moves[2].col = ini.col + 1;

    moves[3].lin = ini.lin - 2;
    moves[3].col = ini.col - 1;

    moves[4].lin = ini.lin + 1;
    moves[4].col = ini.col + 2;

    moves[5].lin = ini.lin + 1;
    moves[5].col = ini.col - 2;

    moves[6].lin = ini.lin - 1;
    moves[6].col = ini.col + 2;

    moves[7].lin = ini.lin - 1;
    moves[7].col = ini.col - 2;
}

bool is_valid(Point p, int n) {
    return p.lin >= 0 && p.lin < n && p.col >= 0 && p.col < n;
}

bool hourses_route(int n, int marc[n][n], Point ini, int i) {
    if (i == n*n) return true;

    Point moves[8];
    generate_moves(moves, ini);

    for (int j = 0; j < 8; j++) {
        Point move = moves[j];
        if (is_valid(move, n) && marc[move.lin][move.col] == 0) {
            marc[move.lin][move.col] = 1;
            if (hourses_route(n, marc, move, i + 1)) return true;
            marc[move.lin][move.col] = 0;
        }
    }
    return false;
}

int main() {
    int marc[N][N] = {0};

    Point initial_pos = {0,0};
    marc[initial_pos.lin][initial_pos.col] = 1;
    printf("Is it possible?: %d\n", hourses_route(N, marc, initial_pos, 1));

}
