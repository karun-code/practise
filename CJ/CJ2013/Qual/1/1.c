
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(a, b) ((a) > (b)) ? a : b
#define MIN(a, b) ((a) < (b)) ? a : b

char a[4][6];
int uncomplete = 0;
size_t read, buf_len = 0;
char *buffer = NULL;

void display_game(){
    int j;
    for (j=0; j<4; j++){
        printf("%s", a[j]);
    }
    printf("\n");
}

void read_empty_line(){ 
        read = getline(&buffer, &buf_len, stdin);
        free(buffer);
        buffer = NULL;
}

int check_horizontal_vertical(int i) {
    int j, X_count_h=0, X_count_v=0, O_count_h=0, O_count_v=0;
    for (j=0; j<4; j++){
        switch (a[i][j]){
            case '.': uncomplete = 1; break;
            case 'X': X_count_h++; break;
            case 'O': O_count_h++; break;
            case 'T': X_count_h++; O_count_h++;
        }
        
        switch (a[j][i]){
            case '.': uncomplete = 1; break;
            case 'X': X_count_v++; break;
            case 'O': O_count_v++; break;
            case 'T': X_count_v++; O_count_v++;
        }
    }
    
    if (X_count_h==4 | X_count_v==4){
        printf("X won\n");
        return 1;
    }
    if (O_count_h==4 | O_count_v==4){
        printf("O won\n");
        return 1;
    }
    return 0;
}

int check_diagnols() {
    int j, X_count_rt=0, X_count_lt=0, O_count_rt=0, O_count_lt=0;
    for (j=0; j<4; j++){
        switch (a[j][j]){
            case '.': uncomplete = 1; break;
            case 'X': X_count_rt++; break;
            case 'O': O_count_rt++; break;
            case 'T': X_count_rt++; O_count_rt++;
        }
        
        switch (a[3-j][j]){
            case '.': uncomplete = 1; break;
            case 'X': X_count_lt++; break;
            case 'O': O_count_lt++; break;
            case 'T': X_count_lt++; O_count_lt++;
        }
    }
    
    if (X_count_rt==4 | X_count_lt==4){
        printf("X won\n");
        return 1;
    }
    if (O_count_rt==4 | O_count_lt==4){
        printf("O won\n");
        return 1;
    }
    return 0;
}


int main(){

    int i, j, inputs, rv;
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
    //printf("inputs - %d\n", inputs);

    for (i=1;i<=inputs;i++){
        int go_next=0;
        uncomplete = 0;
        
        printf ("Case #%d: ", i);
                
        /* Read 4 lines*/
        for (j=0; j<4; j++){
            read = getline(&buffer, &buf_len, stdin);
            memcpy((void *)a[j], (void *)buffer, 6);
            free(buffer);
            buffer = NULL;
        }
        
        //display_game();
        
        for (j=0; j<4; j++){
            if( check_horizontal_vertical(j) ) {
                go_next=1;
                break;
            }               
        }
        
        if (go_next) { 
            read_empty_line(); 
            continue;
        }
        
        if ( check_diagnols() ){ 
            read_empty_line(); 
            continue;
        }

        if (uncomplete){
            printf ("Game has not completed\n");
        } else {
            printf ("Draw\n");
        }
        
        read_empty_line();
                
    }
     
    return 0;
}

