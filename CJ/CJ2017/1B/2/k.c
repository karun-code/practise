
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;
//priority_queue<int> pq1;

int process() {
    int N, R, O, Y, G, B, V, i;
    char C[3];
    int L[3];
    int Z[3];
    scanf("%d %d %d %d %d %d %d", &N, &R, &O, &Y, &G, &B, &V);
    if ((R>=Y) && (R>=B)) {
        C[0] ='R';
        L[0] = R;
        if (Y>=B) {
            C[1]='Y';
            L[1] = Y;
            C[2]='B';
            L[2] = B;
       } else {
            C[1]='B';
            L[1] = B;
            C[2]='Y';
            L[2] = Y;
       }
    } else {
        if ((Y>=R) && (Y>=B)) {
            C[0] = 'Y';
            L[0] = Y;
            if (B>=R) {
                C[1] = 'B';
                L[1] = B;
                C[2] = 'R';
                L[2] = R;
            } else {
                C[1] = 'R';
                L[1] = R;
                C[2] = 'B';
                L[2] = B;
            }
        } else {
            C[0] = 'B';
            L[0] = B;
            if (Y>=R) {
                C[1] = 'Y';
                L[1] = Y;
                C[2] = 'R';
                L[2] = R;
            } else {
                C[1] = 'R';
                L[1] = R;
                C[2] = 'Y';
                L[2] = Y;
            }
        }
    }
    
    Z[0] = L[2];
    Z[1] = L[1] - L[2];
    Z[2] = L[0] - Z[1] - Z[0];
    if (Z[2] >= Z[0]) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for (i=0; i<Z[0]; i++) {
        printf("%c%c%c", C[1], C[0], C[2]);
        if (Z[2]) {
            printf("%c", C[0]);
            Z[2]--;
        }
    }
    for (i=0; i<Z[1]; i++) {
        printf("%c%c", C[1],C[0]);
    }

    printf("\n"); 

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
