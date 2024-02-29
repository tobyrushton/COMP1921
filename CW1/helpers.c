#include <stdio.h>

void handleInput(){
    printf("Enter an input: \n");
    char input[100];
    scanf("%s", input);
    printf("The input is: %s\n", input);
};

int checkGameOver(){
    return 1;
};

void checkMazeValid(char *fileName){};