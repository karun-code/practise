
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int num[10];

void del(char *S, int l, char c) {
    for (int i=0; i<l; i++) {
        if (S[i] == c) {
            S[i] = 0;
            break;
        }
    }
}

find0(char *S, int l) {
    for (int i=0; i<l; i++) {
        if (S[i] == 'Z') {
            num[0]++;
            del(S, l, 'O');
        }
    }
}

find1(char *S, int l) {
    for (int i=0; i<l; i++) {
        if (S[i] == 'O') {
            num[1]++;
        }
    }
}

find2(char *S, int l) {
    for (int i=0; i<l; i++) {
        if (S[i] == 'W') {
            num[2]++;
            del(S, l, 'O');
        }
    }
}

find3(char *S, int l) {
    for (int i=0; i<l; i++) {
        if (S[i] == 'H') {
            num[3]++;
        }
    }
}

find4(char *S, int l) {
    for (int i=0; i<l; i++) {
        if (S[i] == 'U') {
            num[4]++;
            del(S, l, 'F');
            del(S, l, 'O');
        }
    }
}

find5(char *S, int l) {
    for (int i=0; i<l; i++) {
        if (S[i] == 'F') {
            num[5]++;
            del(S, l, 'I');
        }
    }
}

find6(char *S, int l) {
    for (int i=0; i<l; i++) {
        if (S[i] == 'X') {
            num[6]++;
            del(S, l, 'I');
            del(S, l, 'S');
        }
    }
}

find7(char *S, int l) {
    for (int i=0; i<l; i++) {
        if (S[i] == 'S') {
            num[7]++;
        }
    }
}

find8(char *S, int l) {
    for (int i=0; i<l; i++) {
        if (S[i] == 'G') {
            num[8]++;
            del(S, l, 'I');
            del(S, l, 'H');
        }
    }
}

find9(char *S, int l) {
    for (int i=0; i<l; i++) {
        if (S[i] == 'I') {
            num[9]++;
        }
    }
}

int process() {
    char S[2000];
    int i, l=0;
    scanf("%s\n", S);
    l = strlen(S);

    for (i=0; i<10; i++) {
        num[i] = 0;
    }

    find0(S, l);
    find2(S, l);
    find4(S, l);
    find6(S, l);
    find8(S, l);
    find1(S, l);
    find3(S, l);
    find5(S, l);
    find7(S, l);
    find9(S, l);

    for (i=0; i<10; i++) {
        if (num[i] > 0) {
            for (int j=0; j<num[i]; j++) {
                printf("%d", i);
            }
        }
    }
}

int main() {

    int T, r;

    scanf("%d\n", &T);

    for (int i=1; i<=T; i++) {
        printf ("Case #%d: ", i);
        process();
        printf ("\n");
    } 

    return 0;
}
