
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX(a, b) ((a) > (b)) ? a : b
#define MIN(a, b) ((a) < (b)) ? a : b

size_t read, buf_len = 0;
char *buffer = NULL;

int check_fair(char *str, int len){
    int start=0, end=len-1;
    while(start<end){
        if (str[start] != str[end]) {
            return 0;
        }
        start++; end--;
    }
    return 1;
}

int main(){

    int t, inputs, r_val;
    FILE *fp=NULL;
    
    fp = freopen( "input.in", "r", stdin );
    if (!fp){
        printf("Could not open input file\n");
        return 0;
    }
    
    read = getline(&buffer, &buf_len, stdin);
    sscanf(buffer, "%d\n", &inputs);
    free(buffer);
    buffer = NULL;

    for (t=1;t<=inputs;t++){
        double min, max, sq_rt;
        int ld; 
        unsigned long count=0;
        
        printf ("Case #%d: ", t, read, buffer);
        read = getline(&buffer, &buf_len, stdin);
        //printf("%s", buffer);
        sscanf(buffer, "%lf %lf", &min, &max);
        //printf("min-%.0lf, max-%.0lf\n", min, max);
        
        while(min <= max){
            char text[200];
            int len;
            
            sprintf(text, "%.0lf", min);
            //printf("%s\n", text);
            len = strlen(text);
            
            if (check_fair(text, len)){
            
                ld = text[len-1] - '0';
                if (ld == 0 || ld==1 || ld==4 || ld==5 || ld==6 || ld==9) {
                
                    sq_rt = sqrt(min);
                    if (!(sq_rt - round(sq_rt))) {
                        sprintf(text, "%.0lf", sq_rt);
                        len = strlen(text);
                        if (check_fair(text, len)){
                            //printf(">>%lf, %s\n", min, text);
                            count++;
                        }
                    }                
                }
            }  
            min+=1;
        }
        
        printf("%lu\n", count);
        
        free(buffer);
        buffer = NULL;
    }
     
    return 0;
}

