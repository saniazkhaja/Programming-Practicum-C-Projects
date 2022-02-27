// median3 program
#include <stdio.h>

int main() {
    // array to store user input
    int userNumbers[3];

    // in order to get three numbers from user input
    for (int i = 0; i < 3; i++) {
        printf("Enter an integer: \n");
        // checking if user input was an integer number or not
        if (!scanf("%i", &userNumbers[i])) {
            printf("INVALID INPUT");
            return 0;
        }
    }

    // printing the numbers the user put in
    printf("The median of %d", userNumbers[0]);
    printf(", %d", userNumbers[1]);
    printf(", %d", userNumbers[2]);

    // sorting in ascending order
    for (int x = 0; x < 3; x++) {
        for (int y = x + 1; y < 3; y++) {
            // current number is greater than next number
            if (userNumbers[x] > userNumbers[y]) {
                int temp = userNumbers[x];
                userNumbers[x] = userNumbers[y];
                userNumbers[y] = temp;
            }
        }
    }
    // printing median number by using the number in the middle of the sorted array
    printf(" is %d", userNumbers[1]);

    return 0;
}
