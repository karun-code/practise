
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX(a, b) ((a) > (b)) ? a : b
#define MIN(a, b) ((a) < (b)) ? a : b

int display(int a[][100], int N, int M) {
    int i, j;
    
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            printf ("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int find_lowest(int a[][100], int N, int M, int *row, int *col){
    int i, j, lowest=101, index=-1;
    
    for (i=0; i<N; i++){
        for (j=0; j<M; j++){    
            if (a[i][j] !=-1 ){
                if ( a[i][j] < lowest ){
                    lowest = a[i][j];
                    *row = i;
                    *col = j;
                 }
             }
         }
    }
    return index;
}

int remove_lowest(int a[][100], int N, int M, int row, int column, int *remove_count){
    int i, cannot_remove=0;
    
    /* Check if can be removed rowwise */
    for (i=0; i<M; i++){
        if ( (a[row][i] != -1) && (a[row][i] != a[row][column]) ){
            cannot_remove = 1;
            break;
        }
    }
    
    if (!(cannot_remove)){
        /* Remove row */
        for (i=0; i<M; i++){
            if (a[row][i] !=-1){
                a[row][i] = -1;
                (*remove_count)++;
            }
        }
        return 1;
    }
    
    cannot_remove=0;
    /* Check if can be removed columnwise */
    for (i=0; i<N; i++){
        if ( (a[i][column] != -1) && (a[i][column] != a[row][column]) ){
            cannot_remove = 1;
            break;
        }
    }
    
    if (!(cannot_remove)){
        /*Remove Column*/
        for(i=0; i<N; i++){
            if (a[i][column] != -1){
                a[i][column] = -1;
                (*remove_count)++;
            }
        }
        return 1;
    }
    
    return 0;
}

int main(){

    int t, inputs, r_val;
    FILE *fp=NULL;
    
    fp = freopen( "input.in", "r", stdin );
    if (!fp){
        printf("Could not open input file\n");
        return 0;
    }
    
    scanf("%d\n", &inputs);

    for (t=1;t<=inputs;t++){
        int a[100][100];
        int N, M, i, j, no_flag=0, remove_count=0, row, col;
        
        memset(a, 0, 10000);
        
        printf ("Case #%d: ", t);
        scanf("%d %d\n", &N, &M);
        
        
        for (i=0; i<N; i++){
            for (j=0; j<M; j++){
                scanf("%d ", &a[i][j]);
            }
        }
        //display(a, N, M);
        
        if ( (M==1) || (N==1) ) {
            printf("YES\n");
            continue;
        }
        
        /* Check with row from top to bottom */
        while(remove_count<M*N){
            /* Find the lowest in array */
            find_lowest(a, N, M, &row, &col);
            
            /* Remove lowest */
            if (!(remove_lowest(a, N, M, row, col, &remove_count))){
                no_flag=1;
                break;
            }
        }

        if (no_flag) {
            printf ("NO\n");
        } else {
            printf ("YES\n");
        } 
    }
     
    return 0;
}

