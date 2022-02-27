// stairs program
#include <stdio.h>

void upDownStairs(int n) {
    int steps = 1;
    int spaces = n - 1;
    printf("up-down:\n");

    // which step on the stair we are on
    for (int stairs = 0; stairs < n; stairs++) {
        // determines the spaces before the step
        for (int i = spaces; i > 0; i--) {
            printf(" ");
        }
        // determines how deep the step is
        for (int x = 1; x <= steps; x++) {
            printf("X");
            if (x != 1) {
                // compensating for both up and down
                printf("X");
            }
        }
        printf("\n");
        spaces--;
        steps++;
    }
    printf("\n");
}

void downTheStairs(int n) {
    int steps = 1;

    printf("down:\n");
    for (int stairs = 0; stairs < n; stairs++) {
        // determines how deep the step is
        for (int x = 1; x <= steps; x++) {
            printf("X");
        }
        printf("\n");
        steps++;
    }
    printf("\n");
}

void upTheStairs(int n) {
    int steps = 1;
    int spaces = n - 1;

    printf("up:\n");
    // which step on the stair we are on
    for (int stairs = 0; stairs < n; stairs++) {
        // determines the spaces before the step
        for (int i = spaces; i > 0; i--) {
            printf(" ");
        }
        // determines how deep the step is
        for (int x = 1; x <= steps; x++) {
            printf("X");
        }
        printf("\n");
        spaces--;
        steps++;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of stairs: \n");
    // getting user input for number of steps and checking if valid or not
    if (!scanf("%i", &n)) {
        printf("INVALID INPUT");
        return 0;
    }
    if (n < 0) {
        printf("INVALID INPUT");
        return 0;
    }
    upTheStairs(n);
    downTheStairs(n);
    upDownStairs(n);
    return 0;
}
