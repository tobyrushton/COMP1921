#ifndef HELPERS_H

void handleInput();

int checkGameOver();

void checkMazeValid(char *fileName);

void displayMap();

void handleMove();

// Define the struct for the maze
struct Maze {
    int width;
    int height;
    char **map;
};

#endif