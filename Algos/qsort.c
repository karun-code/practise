#include <stdio.h>
#include <stdlib.h>

void PA(int A[], int len) {
    int i;
    for (i=0; i<len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int cmpFunc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int i, A[] = {10, 45, 30, 100};
    
    printf("Input:\n");
    PA(A, 4);
    
    qsort(A, 4, sizeof(int), cmpFunc);
    
    printf("Output:\n");
    PA(A, 4);
}
