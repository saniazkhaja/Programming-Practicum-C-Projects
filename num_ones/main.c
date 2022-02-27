// num_ones program
#include <stdio.h>

int main() {
    int n;
    int numOfOnes = 0;

    printf("Enter a non-negative integer: \n");
    // getting user input for number and checking if valid or not
    if (!scanf("%u", &n)) {
        printf("INVALID INPUT");
        return 0;
    }
    if (n < 0) {
        printf("INVALID INPUT");
        return 0;
    }
    int num = n;

    // binary number algorithm
    while (num > 0) {
        // determines if there would be a 1
        if (num % 2 == 1) {
            numOfOnes++;
            num --;
        }
        num = num / 2;
    }
    printf("That number has %i", numOfOnes);
    printf(" one(s) in its binary representation");

    return 0;
}
