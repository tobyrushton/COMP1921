#include <stdio.h>

// Function to handle the input
void handleInput(){
    printf("Enter an input: \n");
    char input[100];
    scanf("%s", input);
    printf("The input is: %s\n", input);
};

// checks if the user has reached the end of the maze
int checkGameOver(){
    return 1;
};

// prints the map to the console
void displayMap(){};

// handles the movement of the user
void handleMove(){};

// validates the maze 
void checkMazeValid(char *fileName){};

// populates the maze struct
void populateMaze(char *fileName, struct Maze *maze){};