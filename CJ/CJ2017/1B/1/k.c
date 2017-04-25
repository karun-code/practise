
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;
//priority_queue<int> pq1;

int process(int debug) {
    int N, i;
    double D, d[1000], s[1000], tmax=-1, t;
    scanf("%lf %d\n", &D, &N);
    if (debug) {
        printf("%f %d\n", D, N);
    }
    for (i=0; i<N; i++) {
        scanf("%lf %lf\n", &d[i], &s[i]);
        if (debug) {
            printf("%lf %lf\n", d[i], s[i]);
        }
        d[i] = D - d[i];
        t = d[i]/s[i];
        if (debug) {
            printf("%lf\n", t);
        }
        if ( (tmax == -1) || (tmax < t) ) {
            tmax = t;
        }
    }
    printf("%f\n", D/tmax);
}

int main() {

    int T, r;

    scanf("%d\n", &T);

    int i;
    for (i=1; i<=T; i++) {
        printf ("Case #%d: ", i);
		    r = process(0);
    } 

    return 0;
}
