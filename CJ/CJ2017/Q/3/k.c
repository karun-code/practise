
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

int process() {

    unsigned long long int N, K, W;
    priority_queue<unsigned long long int> pq1;

    scanf("%llu ", &N);
    scanf("%llu\n", &K);

    pq1.push(N);
    while (K) {
        W = pq1.top();
        pq1.pop();
        if (W%2) {
            pq1.push(W/2);
            pq1.push(W/2);
        } else {
            pq1.push(W/2);
            pq1.push(W/2 - 1);
        }
        K--;
    }
    if (W%2) {
        printf("%llu ", W/2);
        printf("%llu\n", W/2);
    } else {
        printf("%llu ", W/2);
        printf("%llu\n", W/2 - 1);
    }
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
