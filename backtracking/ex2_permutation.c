#include <stdio.h>
#define N 5

void print_arr(int arr[], int n) {
    for(int i = 0; i<n; i++) printf("%d ", arr[i]);

    printf("\n");
}

void permutation(int s[], int i, int v[], int n, int x[]) {
    if(i == n) {
        print_arr(s, n);
        return;
    }

    for(int j = 0; j < n; j++) {
        if(x[j] == 0) {
            x[j] = 1;
            s[i] = v[j];
            permutation(s, i+1, v, n, x);
            x[j] = 0;
        }
    }
}



int main() {
    int v[N] = {1,2,3,4,5}; // symbols
    int s[N]; // solutions
    int x[N]; // marks

    for(int i = 0; i<N; i++) x[i] = 0;

    permutation(s, 0, v, N, x);
}