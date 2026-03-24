/*
1. Uma maneira de encontrar maior divisor comum MDC de dois inteiros x e y é dado por
mdc(x, y) = {
    x, se x = y
    2 ∗ mdc(x/2,y/2), se x é par e y é par
    mdc(x/2, y), se x é par e y é ímpar
    mdc(x,y/2), se x é ímpar e y é par
    mdc((x−y/2), y), se x é ímpar e y é ímpar e x > y
    mdc(x,(y−x/2)), se x é ímpar e y é ímpar e x < y
}
(a) Escreva uma função recusiva para computar o mdc(x, y).
(b) Verifique suas funções para as seguintes entradas:
mdc(270,192) = 6
mdc(35,10) = 5
mdc(10,15) = 5
mdc(31,2) = 1
*/

#include <stdio.h>

int gcd(int x, int y) {
    if (x == y) return x;
    if (x % 2 == 0) {
        if (y % 2 == 0) return 2 * gcd(x/2,y/2);
        return gcd(x/2, y);
    }

    if (y % 2 == 0) return gcd(x, y/2);

    if (x>y) return gcd((x-y)/2, y);
    return gcd(x, (y-x)/2);
    }

int main() {
    printf("mdc(270,192) = %d\n", gcd(270, 192));
    printf("mdc(35,10) = %d\n", gcd(35, 10));
    printf("mdc(10,15) = %d\n", gcd(10,15));
    printf("mdc(31,2) = %d\n", gcd(31,2));

    return 0;
}