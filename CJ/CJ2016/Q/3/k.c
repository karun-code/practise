
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

unsigned long long base[11];
unsigned long long factor[11];

unsigned long long my_pow(unsigned long long base, int exp) {
    int i;
    unsigned long long result = 1;
    for (i=0; i<exp; i++) {
        result *= base;
    }
    return result;
}


unsigned long long _10_to_x(unsigned long long coin, int x) {
    int i = 0;
    unsigned long long basex=0;
    while (coin) {
        basex = basex + my_pow((unsigned long long)x, i)*(coin%(unsigned long long)10);
        coin = coin/(unsigned long long)10; 
        i++;
    }
    //printf("base%d: %llu\n", x, basex);
    return basex;
}

unsigned long long _2_to_10(unsigned long long base2) {
    int i=0;
    unsigned long long base10 = (unsigned long long)0;
    //printf("base2: %llu\n", base2);
    while (base2) {
        base10 += base2%(unsigned long long)2 * my_pow((unsigned long long)10, i);
        base2 = base2/(unsigned long long)2; 
        i++;
    }
    //printf("base10: %llu\n", base10);
    return base10;
}

double get_coin(int N) {
    unsigned long long coin = 0;
    coin = my_pow ((unsigned long long)10, (N-1)) + 1;
    //printf("Coin: %llu\n", coin);
    return coin;
}


unsigned long long get_next_coin(unsigned long long coin) {
    unsigned long long next_coin;
    next_coin = _10_to_x(coin, 2);
    next_coin += 2;
    next_coin = _2_to_10(next_coin);
    //printf("next_coin: %llu\n", next_coin);
    return next_coin;
}

int is_prime(unsigned long long base, int  baseof) {
    unsigned long long upper_limit = base/(unsigned long long)2;
    int i, is_prime = 1;
    for (i=2; i<upper_limit; i++) {
        if (0 == (base % (unsigned long long)i)) {
            is_prime = 0;
            factor[baseof] = i;
            break;
        } 
    }
    return is_prime;
}

int convert_base(unsigned long long coin) {
    int i, r_val = 1;
    for (i=2; i<=10; i++) {
        base[i] = _10_to_x(coin, i);
        if (is_prime(base[i], i)) {
            r_val = 0; 
            break;
        }
    }
    return r_val;
}


int process() {
    int N, J, i; 
    unsigned long long coin;
    scanf("%d\n", &N);
    scanf("%d\n", &J);

    printf("Case #1:\n");
    coin = get_coin(N);
    while (J) {
        if (convert_base(coin)) {
            printf("%llu", coin);
            for (i=2; i<=10; i++) {
                printf(" %llu", factor[i]);
            }
            printf("\n");
            J--;
        }
        coin = get_next_coin(coin);
    }
}

int main() {

    int i, t, r;

    scanf("%d\n", &t);

    for (i=1; i<=t; i++) {
		r = process();
    } 

    return 0;
}
