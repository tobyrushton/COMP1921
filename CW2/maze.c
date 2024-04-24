#include <stdio.h>
#include "helpers.h"

int main(int argc, char *argv[]) {
    // Create the maze struct and populate
    Maze maze;
    populateMaze(argv[1], &maze);

    // Check if the maze is valid will exit if not
    checkMazeValid(maze);

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