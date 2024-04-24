#ifndef HELPERS_H

void handleInput();

int checkGameOver();

void checkMazeValid(char *fileName);

void displayMap();

void handleMove();

void populateMaze(char *fileName, struct Maze *maze);

// Define the struct for the maze
struct Maze {
    int width;
    int height;
    char **map;
};

#endif