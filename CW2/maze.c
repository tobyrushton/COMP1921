#include <stdio.h>
#include "helpers.h"

int main() {
    // Get the file name from the user
    char fileName[100];
    printf("Enter the file name: \n");
    scanf("%s", fileName);
    printf("The file name is: %s\n", fileName);

    checkMazeValid(fileName);

    // Create the maze struct
    struct Maze maze;
    populateMaze(fileName, &maze);

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