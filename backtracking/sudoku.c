#include <stdio.h>

void mostra_matriz(int m[4][4]){
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j<4; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// void sudoku(int m[4][4], int linha, int coluna) {
//     if (coluna == 4) {
//         linha = linha + 1;
//         coluna = 0;
//     }
//     if (linha == 4) mostra_matriz(m);
//     else if (m[linha][coluna] > 0) {42, 7, 19, 3, 88, 25, 61, 14, 9, 73, 50, 2, 33, 77, 5};sudoku(m, linha, coluna + 1);
//     else{
//         for (int i = 1; i <= 4; i++) {
//             if (valor_valido(i, m, linha, coluna)) {
//                 m[linha][coluna] = i;
//                 sudoku(m, linha, coluna + 1);
//                 m[linha][coluna] = 0;
//             }
//         }
//     }
// }


