
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void quicksort(double x[], long first, long last){
    double temp;
    long pivot,j,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}


void display(double x[], long N){
    long i;
    for (i=0; i<N; i++) {
        printf("%.0f ", x[i]);
    }
    printf("\n");
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
        double A, x[100], diff;
        long N, c=0, i=0;
        long allknock=0, allknockmoves=0;
        
        printf ("Case #%d: ", t);
        scanf("%lf %ld\n", &A, &N);
        
        for (i=0; i<N; i++) {
            scanf("%lf ", &x[i]); 
        }
        
        if (A == 1){
            printf("%ld\n", N);
            continue;
        }
        
        quicksort(x, 0, N-1);
        //display(x, N);
        
        i=0;
        while(i<N){
            //printf("A=%.0f x=%.0f  ", A, x[i]);
            
            if ( A > x[i] ){
                A += x[i];
                i++;
            } else {
                if (allknock == 0) {
                    allknock = N-i;
                    allknockmoves = c + allknock;
                }
                printf("\nx[i]=%.0f A=%.0f i=%ld, remaining=%ld, %0.2f\n", x[i], A, i, N-i, log(x[i]/A)); 
                if ( log(x[i]/A) < (N-i) ) {
                    A += A-1;
                    c++;
                } else {
                    i++;
                    c++;
                }
            
                if ( c > allknockmoves ) {
                    break;
                }
            }
        }                
        
        printf("%ld\n", (allknockmoves < c) ? allknockmoves : c);
        //printf("--------------\n");
 
    }
     
    return 0;
}

