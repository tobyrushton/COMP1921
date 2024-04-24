#ifndef HELPERS_H

// Define the struct for the maze
struct maze {
    int width;
    int height;
    char **map;
    int playerX;
    int playerY;
};
typedef struct maze Maze;

void handleInput();

int checkGameOver();

void checkMazeValid(Maze maze);

void displayMap();

void handleMove();

void populateMaze(char *fileName, Maze *maze);

int searchStringForChar(char *string, char c);

#endif