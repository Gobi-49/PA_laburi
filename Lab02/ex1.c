#include <stdio.h>
#include <stdlib.h>

void move(char a, char b) {
    printf("Mutam din %c in %c\n", a, b);
}

void hanoi(int n, char a, char b, char c)
{
    if (n > 0)
    {
        hanoi(n-1, a, c, b);
        move(a, b);
        hanoi(n-1, c, b, a);
    }
}

int main() {
    
    hanoi(3, 'A', 'B', 'C');

    return 0;
}