
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char S[20];
int len = 0;

void invert(int pos) {
    S[pos - 1]--;
    while (pos < len) {
        S[pos] = '9'; 
        pos++;
    }
}

int process() {
    int pos = 0;

    scanf("%s\n", S);
    len = strlen(S);

    if (len == 1) {
        printf("%s\n", S);
        return (0);
    }

    pos = len - 1;
    while (pos != 0) {
        if (S[pos] < S[pos -1]) {
            invert(pos);
        }
        pos--;
    }

    /* Trim leading 0s */
    while (S[pos] == '0') {
        pos++;
    }
    printf("%s\n", &S[pos]);
}

int main(){

    int i, t, r;

    scanf("%d\n", &t);

    for (i=1; i<=t; i++) {
        printf ("Case #%d: ", i);
		r = process();
    } 

    return 0;
}

