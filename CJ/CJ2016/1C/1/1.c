
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

int cmpFunc(const void *a, const void *b) {
    return (strlen ((char *)b) - strlen((char *)a));
}

int sort(char A[][1001], int N) {
    int i;

    qsort (A, N, 1001, cmpFunc);
    for (i=N-1; i>=0; i--) {
        if (strlen(A[i]) == 0) {
            N--;
        } else {
            break;
        }
    }
    return N;
}

void dump(char S[][1001], int l) {
    int i;
    printf("\nDumping S\n");
    for (i=0; i<l; i++) {
        printf("%s\n", S[i]);
    }
} 

void process() {

    int N, i;
    char S[30][1001];
    
    memset(S, 0, sizeof(S));
    scanf("%d\n", &N);
    
    int num=0;
    char c='A';    
    for (i=0; i<N; i++) {
        scanf("%d ", &num);
        memset(S[i], c, num);
        c++;
    }
    
    int l=N;
    //dump(S, l);
    int l1=0, l2=0, l3=0;
    l = sort(S, l);
    do {
        l = sort(S, l);
        //printf("%d\n", l);
        //sleep(1);
        if (l >= 2) {
            l1 = strlen(S[0]);
            l2 = strlen(S[1]);
            l3 = strlen(S[2]);
            if ( (l==3) && (l1==l2) && (l1==l3) && (l1==1) ) { 
                    printf("%c ", S[0][l1-1]);
                    S[0][l1-1] = 0;
            } else {
                if ((l1 - l2) >= 2) {
                    printf("%c%c ", S[0][l1-1], S[0][l1-2]);
                    S[0][l1-1] = 0;
                    S[0][l1-2] = 0;
                } else {
                        printf("%c%c ", S[0][l1-1], S[1][l2-1]);
                        S[0][l1-1] = 0;
                        S[1][l2-1] = 0;
                }
            }
        }
    } while (l!=0) ;
    printf("\n");
}

int main() {

    int T, i;

    scanf("%d\n", &T);

    for (i=1; i<=T; i++) {
        printf ("Case #%d: ", i);
        process();
    } 

    return 0;
}
