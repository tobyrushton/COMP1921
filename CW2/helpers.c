#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "helpers.h"

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

/*
 * @brief checks if the maze is valid
 * @param fileName the name of the file containing the maze
 * exits the program if not valid
*/
void checkMazeValid(Maze maze){
    if( // validates correct dimensions
        maze.width < 5 || 
        maze.height < 5 ||
        maze.height > 100 ||
        maze.width > 100
    ){
        printf("Error: Invalid maze\n");
        exit(1);
    }

    // search for starts and ends
    int sCount = 0;
    int eCount = 0;

    // make sure all rows are equal length
    unsigned long rowLength = strlen(maze.map[0]);
    bool rowLengthsEqual = true;

    for(int i = 0; i < maze.height; i++){
        // search for start and end
        int sIndex = searchStringForChar(maze.map[i], 'S');
        if(sIndex > -1) sCount++;
        int eIndex = searchStringForChar(maze.map[i], 'E');
        if(eIndex > -1) eCount++;

        // check if all rows are equal length
        if(strlen(maze.map[i]) != rowLength){
            rowLengthsEqual = false;
        }
    }

    // if there is not exactly one start and one end or the rows are not equal length
    if(sCount != 1 || eCount != 1 || !rowLengthsEqual){
        printf("Error: Invalid maze\n");
        exit(1);
    }
};

/*
* @brief populates the maze struct with the maze from the file
* @param fileName the name of the file containing the maze
* @param maze the maze struct to populate
*/
void populateMaze(char *fileName, Maze *maze){
    FILE *file = fopen(fileName, "r");
    if (file == NULL){
        printf("File not found\n");
        exit(1);
    }

    int bufferLength = 255;
    char buffer[bufferLength];

    int width = 0; // takes the largest width
    int height = 0;

    int playerX = 0;
    int playerY = 0;

    // max size of the map
    char map[bufferLength][bufferLength];

    while(fgets(buffer, bufferLength, file)) {
        int lineWidth = strlen(buffer);
        // 1 to ignore new line character
        if (lineWidth - 1 > width) width = lineWidth - 1;
        
        // remove new line character
        buffer[strcspn(buffer, "\n")] = 0;

        // checks if line has a starting position and sets player position if it does
        int startIndex = searchStringForChar(buffer, 'S');
        if(startIndex > 0) {
            playerX = startIndex;
            playerY = height;
        }

        strcpy(map[height++], buffer);
    }

    // allocate memory to and populate the map of the maze
    (*maze).map = malloc(sizeof(char *) * height);

    for(int i = 0; i < height; i++) {
        (*maze).map[i] = malloc(sizeof(char) * width);
        strcpy((*maze).map[i], map[i]);
    }

    // assign width and height to the maze struct
    (*maze).width = width;
    (*maze).height = height;

    // sets the players start position
    (*maze).playerX = playerX;
    (*maze).playerY = playerY;

    fclose(file);
};

/**
 * @brief Searches for a character in a given string.
 * 
 * @param string The string to search in.
 * @param c The character to search for.
 * @return The index of the first occurrence of the character in the string, or -1 if the character is not found.
 */
int searchStringForChar(char *string, char c){
    // iterate through ever character in the string
    for(unsigned long i = 0; i < strlen(string); i++){
        if(string[i] == c){
            return i;
        }
    }

    return -1;
}