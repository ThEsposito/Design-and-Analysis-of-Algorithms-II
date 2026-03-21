//
// Created by thesposito on 20/03/2026.
//

#include <stdio.h>

void print_arr(int arr[], int n) {
    for (int i = 0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void ordena(int arr[], int sol[], int marc[], int n, int i) {
    if (i == n) {
        print_arr(sol, n);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (marc[j] == 0) {
            if (arr[j] >= sol[i-1]) {
                marc[j] = 1;
                sol[i] = arr[j];
                ordena(arr, sol, marc, n, i+1);
                marc[j] = 0;
            }
        }
    }
}

int main() {
    int arr[] = {2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int marc[n];
    int sol[n];
    for (int i=0; i<n; i++) marc[i] = 0;
    ordena(arr, sol, marc, n, 0);

    return 0;
}