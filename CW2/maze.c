#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main(int argc, char *argv[]) {
    // validate that an arguement has been passed
    if(argc != 2){
        printf("Please provide a maze file as an arguement\n");
        return 1;
    }
    
    // Create the maze struct and populate
    Maze *maze = malloc(sizeof(Maze));
    populateMaze(argv[1], maze);

    // Check if the maze is valid will exit if not
    checkMazeValid((*maze));

    // Keep asking for input until the game is over
    while(checkGameOver((*maze)) == 0){
        handleInput(maze);
    }

    printf("Congratulations you have solved the maze!\n");

    return 0;   
}