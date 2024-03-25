#include <stdio.h>
#include <math.h>
#define initval 0
#define max 4
#define val 1
#define lungsol 4


int validare(int s[], int i) {
    for(int j = 1; j < i; j++)
        if(i-j == fabs(s[i] - s[j]) || s[i] == s[j]) {
            return 0;
        }
    return 1;
}

void backtracking(int n) {
    int s[n+1];
    int i = 1, valid;
    for(int j = 1; j <= n; j++) {
        s[j] = initval;
    }
    while (i) {
        valid = 0;
        while(!valid & s[i] <= max) {
            s[i] = s[i] + val;
            valid = validare(s, i);
        }
        if(s[i] <= max) {
            if(i == lungsol) {
                for(int j=1; j <= n; j++) {
                    printf("%d ", s[j]);
                } 
                printf("\n");
            } else {
                i++;
            }
        } else {
            s[i] = initval;
            i--;
        }
    }
}


int main() {
    int n;
    n = 4;
    
    backtracking(n);
    return 0;
}