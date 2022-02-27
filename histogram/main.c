// histogram program
#include <stdio.h>

// prints histogram and uses the data numbers
void printHistogram(int largestNum, int A, int B, int C, int D) {
    for (int i = largestNum; i > 0; i--) {
        if (A >= i) {
            printf(" X ");
        } else { // printing space if X is not needed
            printf("   ");
        }

        if (B >= i) {
            printf("X ");
        } else {
            printf("  ");
        }

        if (C >= i) {
            printf("X ");
        } else {
            printf("  ");
        }

        if (D >= i) {
            printf("X ");
        } else {
            printf("  ");
        }

        printf("\n");
    }
}

int main() {
    int largestNum, A, B, C, D;

    printf("A: ");
    // getting user input for number and checking if valid or not
    if (!scanf("%u", &A) || A < 0) {
        printf("INVALID INPUT");
        return 0;
    }

    printf("B: ");
    // getting user input for number and checking if valid or not
    if (!scanf("%u", &B) || B < 0) {
        printf("INVALID INPUT");
        return 0;
    }

    printf("C: ");
    // getting user input for number and checking if valid or not
    if (!scanf("%u", &C) || C < 0) {
        printf("INVALID INPUT");
        return 0;
    }

    printf("D: ");
    // getting user input for number and checking if valid or not
    if (!scanf("%u", &D) || D < 0) {
        printf("INVALID INPUT");
        return 0;
    }

    // figures out the largest number from A, B, C and D
//    largestNum = largestNumber(A, B, C, D);
    if (A >= B && A >= C && A >= D) {
        largestNum = A;
    } else if (B >= A && B >= C && B >= D) {
        largestNum = B;
    } else if (C >= A && C >= B && C >= D) {
        largestNum = C;
    } else {
        largestNum = D;
    }
    // prints the data
    printf("\n");
    printHistogram(largestNum, A, B, C, D);
    printf("---------\n A B C D ");
}
