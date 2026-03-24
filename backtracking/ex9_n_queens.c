//
// Created by thesposito on 24/03/2026.
//
#include <stdio.h>
#include <stdbool.h>
#define n 5

typedef struct {
    int lin;
    int col;
} Point;


// bool kills_someone(int marc[][n], int lin, int col) {
//     int directions[] = {0, 1, -1};
//
//     for (int i = 1; i < n; i++) { // O(N)
//         for (int j = 0; j < 3; j ++) { // O(9) = O(1)
//             for (int k = 0; k < 3; k++) {
//                 if (j == 0 && k == 0) continue; // Não compara uma posição com si mesma
//
//                 int lin_to_check = lin + directions[j] ;
//                 int col_to_check = col + directions[k];
//                 if (lin_to_check >= 0 && lin_to_check < n && col_to_check >= 0 && col_to_check < n)
//                     if (marc[lin_to_check][col_to_check] == 1) return true;
//             }
//         }
//     }
//     return false;
// }

bool kills_someone(int marc[][n], int lin, int col) {
    for (int i_col = 0; i_col < n; i_col++) { // Horizontal
        if (i_col != col && marc[lin][i_col] == 1) return true;
    }

    for (int i_lin = 0; i_lin < n; i_lin++) { // Vertical
        if (i_lin != lin && marc[i_lin][col] == 1) return true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (marc[i][j] == 1) {
                int x = i + 1;
                int y = j + 1;
                while (x < n && y < n) {
                    if (marc[x][y] == 1) return true;
                    x++;
                    y++;
                }
            }
        }
    }

    return false;
}

void print_matrix(int mat[][n]) {
    for (int  i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
}

void n_queens(int marc[n][n], int count_queens) {
    if (count_queens == n) {
            print_matrix(marc);
            printf("\n\n");
        return;
    }

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (marc[j][k] == 0 && !kills_someone(marc, j, k)) {
                marc[j][k] = 1;
                n_queens(marc, count_queens+1);
                marc[j][k] = 0;
            }
        }
    }
}


int main() {
    int marc[n][n] = {0};
    n_queens(marc, 0);
    return 0;
}