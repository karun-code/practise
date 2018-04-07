
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trouble_sort(long L[], int N) {
    int i, done = 0;
    while (!done) {
        done = 1;
        for (i=0; i<N-2; i++) {
            if (L[i] > L[i+2]) {
                long temp;
                done = 0;
                temp = L[i];
                L[i] = L[i+2];
                L[i+2] = temp;
            }
        }
    }
}

int process() {
    int N, i;
    long L[100000];

    scanf("%d\n", &N);
    for (i=0; i<N; i++) {
        scanf("%d ", &L[i]);
    }

    trouble_sort(L, N);
    for (i=0; i<N-1; i++) {
        if (L[i] > L[i+1]) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("OK\n");
    return 0;
}

int main() {

    int T, r;

    scanf("%d\n", &T);

    int i;
    for (i=1; i<=T; i++) {
        printf ("Case #%d: ", i);
		r = process();
    }

    return 0;
}
