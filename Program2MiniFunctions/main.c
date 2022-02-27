
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "prog2.h"



/**
*
*  Function "stubs" for Assignment 2 exercises.
*
*  See prog2.h for specifications of function behavior.
*
*/



/***********************************************
*                                             **
*   MATRIX FUNCTIONS                          **
*                                             **
*   NOTE:  parameter n ALWAYS expresses the   **
*     dimensions of the square matrix in      **
*     question.                               **
*                                             **
***********************************************/

/**
* Function:  alloc_square_mtx
* Description:  Dynamically allocates a square nxn 2D
*       matrix of characters.  The individual matrix
*       elements need not be initialized.
*
*       The matrix is returned as a char **
*
* Estimated Difficulty:  LEVEL-1
*/
char ** alloc_square_mtx(int n) {
    // allocates memory for rows and amount of memory char takes up
    // n allocates multiple rows
    char** m = malloc(n * sizeof(char *));
    // going through each row
    for (int i = 0; i < n; i++) {
        // allocating each row some memory and the row points to the column allocation
        m[i] = malloc(sizeof(char) * n);
    }
    return m;
}

/**
* Function:  free_square_mtx
        * Description:  deallocates all dyanamically allocated
*       components of a matrix previously produced by
        *       alloc_square_mtx.
*
* Estimated Difficulty:  LEVEL-1
*/
void free_square_mtx(char **m, int n) {
    for(int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

/**
* Function:  pop_mtx_alpha
* Description:  populates square matrix of characters
*		with random, lower-case letters a..z
*
*		TIP:  srand() and rand() might be handy
*
* Estimated Difficulty:  LEVEL-1
*/
void pop_mtx_alpha(char **m, int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // first choosing ASCII num and then converting that into char
            m[i][j] = (char) ('a' + (rand() % ('z' - 'a' + 1)));
        }
    }
}

/**
* Function:  display_mtx
* Description:  prints given square matrix row-by-row (printing
*		a newline after each row).
*
* Estimated Difficulty:  LEVEL-1
*
* TIPS:  putchar or the %c specifier in printf might be handy
*
* Comments:  don't overthink this; just print each char
*    one by one.  Don't worry about what those chars are.
*
*/
void display_mtx(char **m, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }
}

/**
* Function:  swap_rows
* Description:  swaps the contents of rows r1 and r2 of
*               square matrix m.  Ordering of characters
*		        within rows are preserved.
*
*               If r1 or r2 is out of range no modifications
*		        are made.
*
* Estimated Difficulty:  LEVEL-2
*/
// assuming user input can start from 1 to size of matrix
void swap_rows(char **m, int n, int r1, int r2){
    if ((r1 <= n && r1 > 0) && (r2 <= n && r2 > 0)) {
        char* temp;
        temp = m[r1 - 1];
        m[r1 - 1] = m[r2 - 1];
        m[r2 - 1] = temp;
    }
}

/**
* Function:  swap_cols
* Description:  swaps the contents of column c1 and c2 of
*               square matrix m.  Ordering of characters
*		        within rows are preserved.
*
*               If c1 or c2 is out of range no modifications
*		        are made.
*
* Estimated Difficulty:  LEVEL-2
*/
// assuming user input can start from 1 to size of matrix
void swap_cols(char **m, int n, int c1, int c2){
    if ((c1 <= n && c1 > 0) && (c2 <= n && c2 > 0)) {
        for (int i = 0; i < n; i++) {
            char temp;
            temp = m[i][c1 - 1];
            m[i][c1 - 1] = m[i][c2 - 1];
            m[i][c2 - 1] = temp;
        }
    }
}

/**
* Function:  rotate_right
* Description:  "rotates" square matrix m 90 degrees right
*		(clockwise).
*
*		Example:  consider the 3x3 matrix below:
*
			abc
			def
			hij
*
*		After one rotation, the matrix contents are:
*
*			hda
*			ieb
*			jfc
*
* Estimated Difficulty:  LEVEL-3
*
*/
void rotate_right(char **m, int n) {
    char temp1;
    char temp2;
    char temp3;
    int row = 0; // checking which swirl we are on
    int squareSide = n;

    // going through each square and swirling it
    while (squareSide > 1) {
        for (int i = row; i < n - row - 1; i++) {
            // moving top first row to the right column
            temp1 = m[i][n - row - 1];
            m[i][n - row - 1] = m[row][i];

            // moving right column to bottom row
            temp2 = m[n - row - 1][n - i - 1];
            m[n - row - 1][n - i - 1] = temp1;

            // moving bottom row to left col
            temp3 = m[n - i - 1][row];
            m[n - i - 1][row] = temp2;

            // moving left col to top row
            m[row][i] = temp3;
        }
        row++;
        squareSide = squareSide - 2;
    }
}


/**
* Function:  floating_boulders
*
* Parameters:  m - the matrix to populate
*              nb - the number of boulders to place.
*
* Description:  popluates the given matrix with with the specified
*		number of  "boulders" randomly placed.
*		All other matrix entries are set to "air"
*
*		A boulder is represented by the character '#'
*		"Air" is represented by the character '.'
*
*		As long as the matrix is made up of nb boulders and
*		N*N-m air symbols, the result is valid.
*
*		If nb is negative, the result will be the same as
*		when nb==0 (all air)
*
*		If nb>N*N (too big), the result should be same as
*		when nb==N*N (all boulders)

* Estimated Difficulty:  LEVEL-1.5
*
* Examples:
*
*     possible configuration for 4x4 with nb==5

       .#..
       ....
       #.##
       ..#.

*     possible configuration for 4x4 with nb==10

       .#.#
       ###.
       #.##
       .##.
*
*/
void floating_boulders(char **m, int n, int nb){
    srand(time(NULL));
    int bouldersCount = 0;
    // too many boulders for board
    if (nb > (n * n)) {
        nb = n * n;
    }
    // too less boulders
    if (nb < 0) {
        nb = 0;
    }
    // choosing randomly where to put boulders
    while (bouldersCount != nb) {
        int randomRow = rand() % n;
        int randomCol = rand() % n;
        if (m[randomRow][randomCol] != '#') {
            m[randomRow][randomCol] = '#';
            bouldersCount++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] != '#') {
                m[i][j] = '.';
            }
        }
    }
}

/**
* Function:  mountains
* Description:  populates the given matrix with a random ASCII
*		"landscape"
*
*		- Air is represented by just periods '.'
*		- Land is represnted by pound-symbols '#' (boulders?)
*		- "Air" is always above "Land", so each column of
*		   the image from bottom-to-top has some number of
*		   Land symbols above which is just air.
*		- As long as these rules are followed, the matrix
*		  is valid.
*
* Estimated Difficulty:  LEVEL 2
*
* Examples (6x6):
*
        ......
        ...#..
        ..##..
        #.##..
        ####.#
        ######

        #.....
        #.....
        #.....
        #..#..
        ##.#.#
        ##.#.#


  Notice that a column may be all "land" (no air); similarly, a column
  can be all air (no land).  This means that even the following are
  valid configurations (don't try to prevent them):

        ######
        ######
        ######
        ######
        ######
        ######

        ......
        ......
        ......
        ......
        ......
        ......

  These might be improbable, but the point is that you don't have
  to "prevent" them somehow.

*/
void mountains(char **m, int n) {
    srand(time(NULL));
    int landAmount = rand() % (n * n);
    int landCount = 0;


    while (landCount != landAmount) {
        int randomRow = rand() % n;
        int randomCol = rand() % n;

        int tempCount = 0;
        //  keeping count of potential land that would be added in this scenario
        for (int i = randomRow; i < n; i++) {
            if (m[i][randomCol] != '#') {
                tempCount++;
            }
        }
        // checking to make sure the land would work
        if ((landCount + tempCount) <= landAmount) {
            for (int i = randomRow; i < n; i++) {
                if (m[i][randomCol] != '#') {
                    m[i][randomCol] = '#';
                    landCount++;
                } else {
                    break;
                }
            }
        }
    }
    // dealing with the air and adding that to the board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] != '#') {
                m[i][j] = '.';
            }
        }
    }
}

/**
* Function:  sink
* Description:  "sinks" the given matrix/image by one layer and introduces
*               "air" as a new top layer.
*
*               Air is represented by the '.' character as in the mountains
*               function.
*
*               In other words:  the contents row 0 "sink" to row 1;
*               row 1 sinks to row 2 and so on.
*               Row N-1 "disappears"
*               Row 0 becomes "Air"
*
* Estimated Difficulty:  LEVEL 2.5
*
* Example:
*
    Before sink:

        ......
        ...#..
        ..##..
        #.##..
        ####.#
        ######

    After sink:

        ......
        ......
        ...#..
        ..##..
        #.##..
        ####.#
*
*  Note:  the example above is based on a result of the mountains
*         function, but the operation is still well-defined for any
*         matrix of characters.  For example, consider the 3x3
*	  example below:

  Before sink:

       abc
       def
       hij

  After sink

       ...
       abc
       def

*/

void sink(char **m, int n){
    // starting on bottom row and going up
    for (int i = n - 1; i >= 0; i--) {
        // each column
        for (int j = 0; j < n; j++) {
            if (i != 0) {
                // assigning current row and col to upwards row and col
                // creates sinking effect
                m[i][j] = m[i - 1][j];
            } else {
                m[i][j] = '.';
            }
        }
    }
}

/**
* Function:  gravity
* Description:  "compacts" the matrix/image downward according to the
*		following rules:
*
*		- The character '.' represents Air
*		- All other characters are assumed to be "heavier than air" --
*			i.e., they will fall when the force of gravity is
*			applied.
*			Let's call them "blocks"
*		- All blocks fall as far as possible as you might expect...
*
* Estimated Difficulty:  LEVEL 3
*
* Example

         Before Gravity:

            .^..8.
            .^##..
            #....#
            #.#@.$
            &###.#
            ..##*.

         After Gravity:
            ......
            ......
            ..##..
            #^#@.#
            #^##8$
            &###*#

*/

void gravity(char **m, int n){
    // starting on col
    for (int i = 0; i < n; i++) {
        // going through each row
        for (int j = 0; j < n; j++) {
            // when air found, air needs to be moved all the way up to top
            if (m[j][i] == '.') {
                // air found and being moved to the top in column
                for (int g = j; g > 0; g--) {
                    char temp = m[g][i];
                    m[g][i] = m[g - 1][i];
                    m[g - 1][i] = temp;
                }
            }
        }
    }
}




/***********************************************
*                                             **
*   STRING FUNCTIONS                          **
*                                             **
***********************************************/

/**
* Function:  str_trim
*
* Description:  effectively removes all leading and trailing
*               whitespace from the given string s.
*
*		Examples:
*
*                    BEFORE        AFTER
*
*                 "  abc"                "abc"
*                 "  abc  "              "abc"
*                 "  hello there  "      "hello there"
*                 "       a   b   "      "a   b"
*
* Estimated Difficulty:  LEVEL 3
*
* NOTES/COMMENTS:
*
*	Notice that "internal" whitespace is not removed!
*       Modifications are made to the given string -- you are
*          not creating a new string.
*	         Use the library function isspace to test if a character
*          is whitespace or not.  While the usual space character
*	   ' ' is whitespace, it is not the only whitespace char;
*	   the tab character '\t' for example is considered
*	   whitespace.  Let the isspace function figure this out
*	   for you.
*/

void str_trim(char *s) {
    int indexEndStart = 0;
    int begOrEnd = 1;
    int i = 0;
    int isEnd = 0;

    // going until end of string
    while (s[i] != '\0') {
        // looking to see where ending is
        if (isspace(s[i]) != 0) {
            indexEndStart = i;
            isEnd = 1;
        } else {
            isEnd = 0;
        }
        // space found in the beginning
        if (isspace(s[i]) != 0 && begOrEnd == 1) {
            // shifting rest of array of characters to get rid of white space
            for (int j = i; j < s[j] !='\0'; j++) {
                s[j] = s[j + 1];
            }
        } else {
            i++;
            begOrEnd = 0;
        }
    }

    // not a space anymore. Trying to remove trailing whitespace
    while (isspace(s[indexEndStart]) != 0 && isEnd == 1) {
        // will shift array back until no more white space
        s[indexEndStart] = s[indexEndStart + 1];
        indexEndStart--;
    }
}

/**
* FUNCTION:  str_search
*
* DESCRIPTION:  takes two C strings:  a "source string" s[] and
*               a "pattern string" and determines if the given
*               pattern is a substring of s.
*
*               If the pattern is a substring of s, the index into s where
*		the first match occurs is returned (note that the
*		pattern may occur multiple times in s).
*
*		Otherwise, -1 is returned (note that a match could
*		start at index 0, so we can't use 0 for "false").
*
* Estimated Difficulty:  LEVEL 3
*
*		Examples:
*
*                  source string s         pattern      return-value
*
*                  "abcd"                  "ab"             0
*                  "abcd"                  "aa"             -1
*                  "abc bc d"              "bc"             1
*                  "abcd"                  "bcd"            1
*                  "abcd"                  "bcd"            1
*                  "abracadabra"           "dab"            6
*                  "abc"                   "abc"            0
*                  "abc"                   "abcd"           -1
*
*   NOTES:
*		- every string is a substring of itself
*		- if the pattern is longer than the source string,
*		   of course there can be no match.
*		- remember there may be multiple matches - you want
*		   the index of the first match.
*
*   RULES:  You may use the strlen library function (but you don't
	    really need it) but all other library functions
	    operating on strings are off limits!
*/
int str_search(char *s, char *pattern) {
    int substringIndex = -1;
    int match = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        for (int j = 0; pattern[j] != '\0'; j++) {
            // making sure will not go past array
            // checking to see if characters match
            if (s[i + j] != '\0' && s[i + j] == pattern[j]) {
                match = 1;
            } else {
                match = 0;
                break;
            }
        }
        if (match == 1) {
            substringIndex = i;
            break;
        }
    }
    return substringIndex;
}





#ifndef _LIB  // DO NOT REMOVE THIS LINE!!!
// IT DOESN"T CHANGE HOW YOUR PROGRAM
// WORKS, BUT IT GIVES US A WAY TO CALL
// YOUR FUNCTIONS FROM OUR CODE FOR
// TESTING

/**
* Write a test driver in main below to exercise and
*   your function implementations.
*
* Think carefully about your test cases!
*/


int main(){
    // test driver
//    char **m;
//    int n = 5;
//
//    m = alloc_square_mtx(n);

//    pop_mtx_alpha(m, n);
//    display_mtx(m, n);
//    printf("\n");

//    swap_rows(m, n, 1, 8);
//    display_mtx(m, n);
//    printf("\n");

//    swap_cols(m, n, 1, 8);
//    display_mtx(m, n);
//    printf("\n");

//    rotate_right(m, n);
//    display_mtx(m, n);
//    printf("\n");

//    floating_boulders(m, n, 20);
//    display_mtx(m, n);
//    printf("\n");

//    mountains(m, n);
//    display_mtx(m, n);
//    printf("\n");

//    sink(m, n);
//    display_mtx(m, n);
//    printf("\n");

//    gravity(m, n);
//    display_mtx(m, n);
//    printf("\n");

//    free_square_mtx(m, n);

//    char str1[12] = "abc";
//    char str2[12] = "abcd";
//    str_trim(str1);
//    printf("%s\n", str1);

//    printf("%i\n", str_search(str1, str2));
}


#endif        // DO NOT REMOVE THIS LINE!!!
