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

void handleInput(Maze *maze);

int checkGameOver(Maze maze);

void checkMazeValid(Maze maze);

void displayMap(Maze maze);

void handleMove(Maze *maze, int newX, int newY);

void populateMaze(char *fileName, Maze *maze);

int searchStringForChar(char *string, char c);

#endif