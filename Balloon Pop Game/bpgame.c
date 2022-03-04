/* CS211 - Program 3 Balloon Pop
 * Author: Sania Khaja and Christina Wong
 * NetID: saniak2, cwong49
 * UIC, Spring 2022
 * Program: App that creates the Balloon Pop game
 * Filename: bpgame.c
 * Behavior: A collection of functions using bpgame struct that when called
 *           will essentially animate/create the balloon pop game.
 *           User will be able to put in coordinates on the board to pop
 *           a "balloon" and user's score will update accordingly.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "bpgame.h"
#include "simpleio.h"

#define CAPACITY 128000
typedef struct stack_struct *StackPtr;
typedef struct stack_struct StackStruct;

struct bpgame {
    char **board;
    char **temp;
    int numOfRows;
    int numOfCols;
    int score;
    int counter;
    StackPtr s;
};

// stack struct to append each board onto for undoing
struct stack_struct {
    int top;
    char **stackBoard[CAPACITY];
    int stackScore[CAPACITY];
};

StackPtr stk_create() {
    StackPtr s = malloc(sizeof(struct stack_struct));
    s->top = -1;
    return s;
}

int stk_push(StackPtr s, int score, char** board, int nrows, int ncols) {
    if(s->top == CAPACITY - 1) {
        return 0; // stack is full
    }
    s->top++;
    BPGame *game = bp_create(nrows, ncols);

    // copy the current board onto a temp onto the stack
    for (int row = 0; row < nrows; row++) {
        for (int col = 0; col < ncols; col++) {
            game -> temp[row][col] = board[row][col];
        }
    }
    s->stackBoard[s->top] = game -> temp;
    s->stackScore[s->top] = score;
    return 1; // stack successfully updated
}

char **stk_popBoard(StackPtr s) {
    if(s->top == -1) {
        return 0; // stack is empty
    }
    return s->stackBoard[s->top + 1];
}

int stk_popScore(StackPtr s) {
    if(s->top == -1) { // stack is empty
        return 0;
    }
    s->top--;
    int data = s->stackScore[s->top + 1];
    return data;
}

BPGame * bp_create(int nrows, int ncols) {
    if (nrows > 40 || ncols > 40 || ncols < 1|| nrows < 1) {
        return NULL;
    }
    BPGame *gameBoard;
    gameBoard = malloc(sizeof(BPGame));
    gameBoard -> numOfRows = nrows;
    gameBoard -> numOfCols = ncols;
    gameBoard -> score = 0;
    gameBoard -> board = malloc(nrows * sizeof(char*));
    gameBoard -> temp = malloc(nrows * sizeof(char*));
    gameBoard -> s = stk_create();

    // going through each row
    for (int i = 0; i < nrows; i++) {
        // allocating each row some memory and the row points to the column allocation
        gameBoard -> board[i] = malloc(ncols * sizeof(char));
        gameBoard -> temp[i] = malloc(ncols * sizeof(char*));
    }
    return gameBoard;
}

BPGame * bp_create_from_mtx(char mtx[][MAX_COLS], int nrows, int ncols) {
    if (nrows > 40 || ncols > 40 || ncols < 1 || nrows < 1) {
        fprintf(stderr, "Error");
        return NULL;
    }
    BPGame *game = bp_create(nrows, ncols);
    game->s = stk_create();
    for (int row = 0; row < nrows; row++) {
        for (int col = 0; col < ncols; col++) {
            game -> board[row][col] = mtx[row][col];
        }
    }
    return game;
}

void bp_destroy(BPGame * b) {
    for (int row = 0; row < b -> numOfRows; row++) {
        free(b -> board[row]);
    }
    free(b -> board);
    free(b);
}

void bp_display_STD(BPGame *b) {
    for(int r = 0; r < b->numOfRows; r++) {
        for(int c = 0; c < b->numOfCols; c++) {
            printf("%c", b->board[r][c]);
        }
        printf("\n");
    }
}

// printing game board
void bp_display(BPGame * b) {
    printf("   +");
    for (int i = 0; i < b -> numOfCols * 2 + 1; i++) {
        printf("-");
    }
    printf("+\n");
    for (int row = 0; row < b -> numOfRows; row++) {
        if (row < 10) {
            printf("%i  |", row);
        } else {
            printf("%i |", row);
        }

        for (int col = 0; col < b -> numOfCols; col++) {
            printf(" %c", b -> board[row][col]);
        }
        printf(" |\n");
    }
    printf("   +");
    for (int i = 0; i < b -> numOfCols * 2 + 1; i++) {
        printf("-");
    }
    printf("+\n    ");
    int digit = 0;
    for (int num = 0; num < b -> numOfCols; num++) {
        if (num % (b->numOfCols - 1) == 0 && num != 0) {
            digit++;
        }
        printf(" %i", digit);
    }
    printf("\n    ");
    for (int num = 0; num < b -> numOfCols; num++) {
        if (num >= (b->numOfCols - 1)) {
            printf(" %i", num % (b->numOfCols - 1));
        } else {
            printf(" %i", num);
        }
    }
    printf("\n");
}

// recursive helper function for bp_pop
// takes in a specific coordinate, checks for bounds
// then checks all neighbors recursively
int makePop(BPGame * b, int r, int c, char current) {
    if(r < 0 || r > (b->numOfRows - 1) || c < 0 || c > (b->numOfCols - 1)) {
        return 0;
    }
    if(b->board[r][c] == current) { // if balloon is wanted balloon
        b->board[r][c] = None;
        makePop(b, r - 1, c, current);
        makePop(b, r, c + 1, current);
        makePop(b, r + 1, c, current);
        makePop(b, r, c - 1, current);
        ++b->counter;
    }
    return 0;
}

int bp_pop(BPGame * b, int r, int c) {
    b->counter = 0; // resetting counter for number of balloons bopped
    if (r >= b->numOfRows - 1 || c >= b->numOfCols || r < 0 || c < 0) {
        fprintf(stderr, "Error");
        return NULL;
    }
    if(b->board[r][c] == None) { // means balloon wanting to be popped is air, not valid
        return NULL;
    }
    stk_push(b->s, b->score, b->board, b-> numOfRows, b-> numOfCols); // appending previous board
    char current = b->board[r][c];
    makePop(b, r, c, current);
    b->score += b->counter * (b->counter - 1); // updating score
    return b->counter;
}

int bp_is_compact(BPGame * b) {
    int compact = 1;
    int counter = 0;

    for(int c = 0; c < b->numOfCols; c++) {
        for(int r = 1; r < b->numOfRows; r++) {
            if(b->board[r][c] != None && b->board[r - 1][c] == None) {
                // there is air above a balloon, return after
                compact = 0;
                return compact;
            }
            else {
                counter++;
            }
        }
    }
    // if there is no instance of air above balloon for all chars in the board
    // board is compact, return 1
    if(counter == (b->numOfCols * b->numOfRows)) {
        compact = 1;
    }
    return compact;
}

void bp_float_one_step(BPGame * b) {
    // will look a row on top
    for (int r = 1; r < b -> numOfRows; r++) {
        for (int c = 0; c < b -> numOfCols; c++) {
            // balloon is floating, swap
            if (b -> board [r][c] != None && b -> board [r - 1][c] == None) {
                b -> board [r - 1][c] = b -> board [r][c];
                b-> board[r][c] = None;
            }
        }
    }
}

int bp_score(BPGame * b) {
    return b -> score;
}

int bp_get_balloon(BPGame * b, int r, int c) {
    if (r >= b-> numOfRows || c >= b -> numOfCols || r < 0 || c < 0) {
        return -1;
    }
    return b -> board[r][c];
}

int bp_can_pop(BPGame * b) {
    int countBalloons = 0;
    int canPop = 0;
    for (int r = 0; r < b -> numOfRows; r++) {
        for (int c = 0; c < b->numOfCols; c++) {
            if (b->board[r][c] != None) {
                countBalloons++;
                break;
            }
        }
    }
    // checks there is at least two balloons being popped
    if (countBalloons < 1) {
        return 0;
    }

    char top = None;
    char bottom = None;
    char left = None;
    char right = None;
    char color = None;
    for (int r = 0; r < b -> numOfRows; r++) {
        for (int c = 0; c < b -> numOfCols; c++) {
            // there is a balloon
            if (b -> board[r][c] != None) {
                color = b -> board[r][c];
            }
            // next four if statements making sure will not check out of bounds
            if (r != 0) {
                top = b -> board[r - 1][c];
            }
            if (r != ((b->numOfRows) - 1)) {
                bottom = b -> board[r + 1][c];
            }
            if (c != 0) {
                left = b -> board[r][c - 1];
            }
            if (c != ((b->numOfCols) - 1)) {
                right = b -> board[r][c + 1];
            }
            // some match popping was found
            if (color == top || color == bottom || color == right || color == left) {
                canPop = 1;
            }
        }
        if (canPop == 1) {
            break;
        }
    }
    return canPop;
}

int bp_undo(BPGame * b) {
    if(b->s->top == -1) { // stack is empty, cannot undo
        return 0;
    }
    stk_popScore(b->s); // pop latest score + board
    b->score = b->s->stackScore[b->s->top + 1]; // updating score

    stk_popBoard(b->s);
    // updating board by copying over from stack
    for (int row = 0; row < b -> numOfRows; row++) {
        for (int col = 0; col < b -> numOfCols;col++) {
            b -> board[row][col] = b -> s->stackBoard[b->s->top + 1][row][col];
        }
    }
    return 1; // successfully undo
}

/*** IMPLEMENTATION OF bp_XXXX FUNCTIONS HERE  ****/