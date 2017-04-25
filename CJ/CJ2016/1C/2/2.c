
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmpFunc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

void sort(int A[], int n) {
    qsort (A, n, sizeof(int), cmpFunc);
}

void process() {

    int N, i;

    scanf("%d\n", &N);

    for (i=0; i<N; i++) {

    }
    
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
