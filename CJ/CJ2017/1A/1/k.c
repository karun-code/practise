
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;
//priority_queue<int> pq1;

char A[26][26];
int K[26];


int process() {
    int R=0, C=0, i=0, j=0, FR=-1;
    scanf ("%d %d\n", &R, &C);
    for (i=0; i<R; i++) {
        scanf("%s\n", A[i]);
        K[i] = -1; 
        for (j=0; j<C; j++) {
            if (A[i][j] != '?') {            
                K[i] = j;
                if (FR == -1) {
                    FR = i;
                }
                break;
            }
        } 
    }

    for (i=0; i<R; i++) {
        if (K[i] == -1) {
            if (FR < i) {
                memcpy(&A[i][0], &A[i-1][0], C);
            }
            continue;
        }
        for (j=0; j<C; j++) {
            if (A[i][j] != '?') {
                continue;
            }
            if (K[i] > j) {
                A[i][j] = A[i][K[i]];
            } else {
                A[i][j] = A[i][j-1]; 
            }
        }
    } 

    /* Fill top empty rows if any */
    for (i=0; i<FR; i++) {
        memcpy(&A[i][0], &A[FR][0], C);
    }

    /* Print Matrix */
    for (i=0; i<R; i++) {
        printf("%s\n", A[i]);
    }
}

int main() {

    int T, r;

    scanf("%d\n", &T);

    int i;
    for (i=1; i<=T; i++) {
        printf ("Case #%d:\n", i);
		r = process();
    } 

    return 0;
}
