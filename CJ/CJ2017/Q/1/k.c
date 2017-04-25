
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char S[1001];
int K=0, len=0;
#define DONE 2000

int check(int pos) {
    while (pos<len) {
        if (S[pos] == '-') {
            if ((len - pos) < K) {
                return -1;
            } else {
                return pos;
            }
        }
        pos++;
    }
    return (DONE);
}

void flip(int pos) {
    int i;
    for (i=0; i<K; i++) {
        if (S[pos + i] == '-') {
            S[pos + i] = '+'; 
        }
        else {
            S[pos + i] = '-';
        }
    }
}

int process() {

    int pos=0, count=0;

    scanf("%s ", S);
    scanf("%d\n", &K);
    len = strlen(S);

    while (1) {
        pos = check(pos);
        if (pos == DONE) {
            return count;
        } 
        if (pos == -1) {
            return -1;
        }
        flip(pos);
        count++;
    }
}

int main() {

    int T, r;

    scanf("%d\n", &T);

    int i;
    for (i=1; i<=T; i++) {
		r = process();
		if (-1 == r) {
            printf ("Case #%d: IMPOSSIBLE\n", i);
		} else {
            printf ("Case #%d: %d\n", i, r);
    	}
    } 

    return 0;
}
