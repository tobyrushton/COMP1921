#include <stdio.h>
#include "helpers.h"

int main(int argc, char *argv[]) {
    printf("%s\n", argv[1]);
    checkMazeValid(argv[1]);

    // Create the maze struct and populate
    struct Maze maze;
    populateMaze(argv[1], &maze);

    // just so it doesn't loop forever while skeleton is still being built
    int whileSkeleton = 0;
    // Keep asking for input until the game is over
    while(checkGameOver() == 0 || whileSkeleton < 5){
        handleInput();
        whileSkeleton++;
    }

    printf("Congratulations you have solved the maze!\n");

    return 0;   
}