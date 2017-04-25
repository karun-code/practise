
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int process() {
	int i, N, m=1, c=0, digit, temp;
	int a[10] = {0,0,0,0,0,0,0,0,0,0};
	scanf("%d\n", &N);

	if (N == 0) {
		return (-1);
	}
	while (1) {
		temp = N*m;
		while (temp) {
			digit = temp % 10;
			if (!(a[digit])) {
				a[digit] = 1;
				c++;
				if (10 == c) {
					return m*N;
				}
			}
			temp = temp/10;
		}
		m++;
	}	
}

int main(){

    int i, t, r;

    scanf("%d\n", &t);

    for (i=1; i<=t; i++) {
		r = process();
		if (-1 == r) {
   		   	printf ("Case #%d: INSOMNIA\n", i);
		} else {
   			 printf ("Case #%d: %d\n", i, r);
    	}
    } 

    return 0;
}

