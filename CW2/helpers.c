#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "helpers.h"

// Function to handle the input
void handleInput(Maze *maze){
    printf("Enter an input: \n");
    char input[100];
    scanf("%s", input);
    
    // remove the new line character
    input[strcspn(input, "\n")] = 0;

    // lowercase first char
    input[0] = tolower(input[0]);

    // call the appropriate function based on the input
    if(strcmp(input, "w") == 0){
        // upwards need to increment the y value as flat array
        handleMove(maze, maze->playerX, maze->playerY - 1);
    } else if(strcmp(input, "a") == 0){
        handleMove(maze, maze->playerX - 1, maze->playerY);
    } else if(strcmp(input, "s") == 0){
        // downwards need to increment the y value as flat array
        handleMove(maze, maze->playerX, maze->playerY + 1);
    } else if(strcmp(input, "d") == 0){
        handleMove(maze, maze->playerX + 1, maze->playerY);
    } else if(strcmp(input, "m") == 0){
        displayMap((*maze));
    } else {
        printf("Error: Invalid move. Please try again\n");
    }
};

// checks if the user has reached the end of the maze
int checkGameOver(Maze maze){
    return maze.map[maze.playerY][maze.playerX] == 'E';
};

// prints the map to the console
void displayMap(Maze maze){
    printf("\n");
    for(int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.width; j++) {
            if(maze.playerX == j && maze.playerY == i){
                printf("X");
            } else {
                printf("%c", maze.map[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// handles the movement of the user
void handleMove(Maze *maze, int newX, int newY){
    // check if the new position is a wall
    if(maze->map[newY][newX] == '#'){
        printf("Error: Invalid move. Please try again\n");
        return;
    }

    // update the player position
    maze->playerX = newX;
    maze->playerY = newY;
};

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
        exit(3);
    }

    // search for starts and ends
    int sCount = 0;
    int eCount = 0;

    // make sure all rows are equal length
    unsigned long rowLength = strlen(maze.map[0]);
    bool rowLengthsEqual = true;
    bool invalidChar = false;

    for(int i = 0; i < maze.height; i++){
        // search for start and end
        for (int j = 0; j < maze.width; j++){
            // checks that the character is valid
            switch(maze.map[i][j]){
                case 'S':
                    sCount++;
                    break;
                case 'E':
                    eCount++;
                    break;
                case '#':
                case ' ':
                    break;
                default:
                    invalidChar = true;
                    break;
            }
        }
        // check if all rows are equal length
        if(strlen(maze.map[i]) != rowLength){
            rowLengthsEqual = false;
        }
    }

    // if there is not exactly one start and one end or the rows are not equal length
    if(sCount != 1 || eCount != 1 || !rowLengthsEqual || invalidChar){
        printf("Error: Invalid maze\n");
        exit(3);
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
        printf("Error: File not found\n");
        exit(2);
    }

    int bufferLength = 255;
    char buffer[bufferLength];

    int width = 0; // takes the largest width
    int height = 0;

    int playerX = 0;
    int playerY = 0;

    // max size of the map
    char **map = malloc(sizeof(char *) * bufferLength);

    while(fgets(buffer, bufferLength, file)) {
        map[height] = malloc(sizeof(char) * bufferLength);
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

    // free memory after use
    free(map);

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