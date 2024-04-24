#include <stdio.h>
#include "helpers.h"

int main(int argc, char *argv[]) {
    // Create the maze struct and populate
    Maze maze;
    populateMaze(argv[1], &maze);

    // Check if the maze is valid will exit if not
    checkMazeValid(maze);

    // Keep asking for input until the game is over
    while(checkGameOver(maze) == 0){
        handleInput(&maze);
    }

    printf("Congratulations you have solved the maze!\n");

    return 0;   
}