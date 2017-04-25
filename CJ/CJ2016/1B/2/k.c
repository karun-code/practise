
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int process() {
    char C[19], J[19];
    int i, l, vc=0, vj=0;
    scanf("%s %s", C, J);

    l = strlen(C);
    //printf("%s %s %d\n", C, J, l);
    i=0;
    while (i<l) {

        if ((C[i] == J[i]) && (C[i] == '?')) {
            if (vc == vj) {
               C[i] = '0'; 
               J[i] = '0'; 
            } else {
                if (vc > vj) {
                   C[i] = '0';
                   J[i] = '9';
                } else {
                   J[i] = '0';
                   C[i] = '9';
                }
            }
            i++;
            continue;
        }

        if (C[i] == '?') {
            if (vc == vj) {
                C[i] = J[i];
            } else {

            if (vc > vj) {
                C[i] = '0';
            } else {
                C[i] = '9';
            }
            }
            i++;
            continue;
        }

        if (J[i] == '?') {
            if (vc == vj) {
                J[i] = C[i];
            } else {
            if (vc > vj) {
                J[i] = '9';
            } else {
                J[i] = '0';
            }
            }
            i++;
            continue;
        }
        
        if ((vc == vj) && (C[i] != J[i])) {
            if (C[i] > J[i]) {
                vc = 1;
            } else {
                vj = 1;
            }
        }
        i++;
    }
    printf("%s %s", C, J);
}

int main() {

    int T, r;

    scanf("%d\n", &T);

    int i;
    for (i=1; i<=T; i++)  {
        printf ("Case #%d: ", i);
		process();
        printf ("\n");
    } 

    return 0;
}
