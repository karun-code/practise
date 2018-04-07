
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char M[1001][1001];

int check(int x, int y) {

    if (M[x][y-1]   &&
        M[x][y]     &&         
        M[x][y+1]   &&         
        M[x+1][y-1] &&
        M[x+1][y]   &&
        M[x+1][y+1] &&
        M[x-1][y-1] &&
        M[x-1][y]   &&
        M[x-1][y+1]) {
        return 1;
        //fprintf(stderr, "SUCESS %d, %d\n", x, y);
        //fflush(stderr);
    }
    return 0;
}

int process() {
    int A, x, y, x1, y1, i, n;

    memset(M, 0, sizeof(M));
    scanf("%d", &A);

    n = A/9 + 1;
    for (i=0; i<n; i++) {
        y = 2 + 3*i;
        x = 2;
    
        while (!check(x, y)) {
            printf("%d %d\n", x, y);
            fflush(stdout);
            scanf("%d %d", &x1, &y1);
            if ((0 == x1) && (0 == y1)) {
                break;
            }
            M[x1][y1] = '1';
        }
    }
}

int main() {

    int T, r;

    scanf("%d", &T);

    int i;
    for (i=1; i<=T; i++) {
        //printf ("Case #%d: ", i);
		r = process();
    }

    return 0;
}
