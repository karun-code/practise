
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
        float r, litre, c=0;
        
        printf ("Case #%d: ", t);
        scanf("%f %f\n", &r, &litre);
        
        while (litre > 0){
            litre = (litre-(2*r+1));
            r+=2;
            if (litre >= 0){
                c++;
            } else {
                break;
            }
        }
        
        printf("%.0f\n", c);
 
    }
     
    return 0;
}

