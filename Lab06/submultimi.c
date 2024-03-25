#include <stdio.h>
#include <math.h>
#define initval -1
#define max 1
#define val 1
#define lungsol 3


int validare(int s[], int i) {
    if(s[i] > max)
        return 0;
    else
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
    n = 3;
    
    backtracking(n);
    return 0;
}