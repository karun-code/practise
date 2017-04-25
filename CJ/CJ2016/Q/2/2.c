
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void flip(char a[], int index) {
    int i=0;
    for (i=0; i<index; i++) {
        if (a[i] == '+') {
            a[i] = '-';
        } else {
            a[i] = '+';
        } 
    } 
}

int inspect(char a[], int index) {
    int i=0;
    for (i=0; i<index; i++) {
        if ('-' == a[i]) {
            return 0;
        }
    }
    return 1;
}

int process() {
    char S[101], flag = 0;
    int C=0, len=0, i=0;

    scanf("%s\n", S);
    len = strlen(S);

    while (1) {

        if ( inspect(S, len) ) {
            return C;
        }

        flag = S[0];
        for (i=1; i<len; i++) {
            if (S[i] != flag) {
                break;
            }
        }

        flip(S, i);
        C++;
    }
}

int main(){

    int i, t, r;

    scanf("%d\n", &t);

    for (i=1; i<=t; i++) {
		r = process();
		if (-1 == r) {
            printf ("Case #%d: INSOLVABLE\n", i);
		} else {
            printf ("Case #%d: %d\n", i, r);
    	}
    } 

    return 0;
}

