
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define FOR(i,n) for(i=0; i<n; i++) 

int process() {
    int N;
    scanf("%d\n", &N);

    int i;
    FOR(i, N) {

    }
    
}

int main() {

    int T, r;

    scanf("%d\n", &T);

    int i;
    FOR(i, T) {
		r = process();
		if (-1 == r) {
            printf ("Case #%d: INSOLVABLE\n", i);
		} else {
            printf ("Case #%d: %d\n", i, r);
    	}
    } 

    return 0;
}
