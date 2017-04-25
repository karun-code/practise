
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define FOR(i,n) for(i=0; i<n; i++) 

int process() {
    int N, h, i, j;
    int C[2501];

    memset(C, 0, sizeof(C));
    scanf("%d\n", &N);
    for (i=0; i<(2*N -1); i++) {
        for (j=0; j<N; j++) {
            scanf("%d\n", &h); 
            C[h]++;
        } 
    }
    /*
    printf("\n");
    for (i=1; i<10; i++) {
        printf("%d: %d\n", i, C[i]);
    }
    */
    for (i=1; i<=2500; i++) {
        if ( (C[i] !=0 ) && (C[i] % 2 == 1)) {
            printf(" %d", i);
        }
    }
    printf("\n");
}

int main() {

    int T, r;

    scanf("%d\n", &T);

    int i;
    for (i=1; i<=T; i++) {
        printf ("Case #%d:", i);
		r = process();
    } 

    return 0;
}
