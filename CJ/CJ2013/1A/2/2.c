
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    int t, inputs, r_val;
#if 0
    FILE *fp=NULL;
    
    fp = freopen( "input.in", "r", stdin );
    if (!fp){
        printf("Could not open input file\n");
        return 0;
    }
    
#endif
    scanf("%d\n", &inputs);

    for (t=1;t<=inputs;t++){
        double E, R, v, highest=0, gain=0;
        long i, N;
        
        printf ("Case #%d: ", t);
        scanf("%lf %lf %ld\n", &E, &R, &N);
        
        if(R>E){
            R=E;
        }
        
        for(i=0; i<N; i++) {
            scanf("%lf ", &v);
            if (v>highest){
                highest = v;
            }
            gain += v*R;
        }
        
        if (R<E){
            gain -= highest*R;
            gain += highest*E;
        }
                
        printf("%.0lf\n", gain);
 
    }
     
    return 0;
}

