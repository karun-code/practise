
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int process() {
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

