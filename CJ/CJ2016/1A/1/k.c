
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define FOR(i,n) for(i=0; i<n; i++) 

int process() {
    int N, len, start, end, p, j;
    char S[1000+1], O[1000], c;

        scanf("%s\n", S);
        len = strlen(S);
        start = end = len/2;
        O[start] = S[0];
        for (j=1; j<len; j++) {
            c = S[j];
            if (c >= O[start]) {
                start = start--;
                if (start < 0) {
                    start = start + len;
                }
                p = start;
            } else {
                end++;
                if (end == len) {
                    end = 0;
                }
                p = end;
        
            }
            O[p] = c;
        }
        p = start;
        for (j=0; j<len; j++) {
            printf("%c", O[p]);
            p++;
            if (p == len) {
                p = 0;
            }
        }
        printf("\n");
}

int main() {

    int T, r;

    scanf("%d\n", &T);

    int i;
    for (i=1; i<=T; i++) {
        printf ("Case #%d: ", i);
		r = process();
    } 

    return 0;
}
