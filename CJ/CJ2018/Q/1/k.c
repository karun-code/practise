
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int process() {
    unsigned long d, total, damage[31], hacks=0;
    char S[31];
    int len = 0, i, charge;
    scanf("%ld %s\n", &d, S);

    len = strlen(S);

    memset(damage, 0, sizeof(damage));
    charge = 1;
    total = 0;
    for (i=0; i<len; i++) {
        if (S[i] == 'S') {
            damage[i] = charge;
        } else {
            charge = charge*2;
            damage[i] = 0;
        }
        total += damage[i];
    }

    if (total <= d) {
        printf("%d\n", hacks);
        return 0;
    }

    i = len-1;
    hacks = 0;
    while (i > 0) {
        if (damage[i-1] == 0) {
            damage[i-1] = damage[i]/2;
            damage[i] = 0;
            total -= damage[i-1];
            hacks++;

            if (total <= d) {
                printf("%d\n", hacks);
                return 0;
            }
            if ( (i + 1) <= (len - 1) ) {
                i = i + 1;
            } else {
                i = i - 1;
            }
        } else {
            i = i - 1; 
        }
    }

    printf("IMPOSSIBLE\n");
    return 0;
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
