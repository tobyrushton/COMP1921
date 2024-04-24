# Coursework 2

## How to play
First run
```bash
make maze
```  
In order to build the game <br>
Then to play the game, run:

```bash
./maze <maze_input_file_path>
```

## Possible inputs
|  Input |  Explanation                                        |
|--------|-----------------------------------------------------|
| W/w    | Move 1 space up                                     |
| A/a    | Move 1 space left                                   |
| S/s    | Move 1 space down                                   |
| D/d    | Move 1 space right                                  |
| M/m    | Prints the maze, with the your position marked by X |

## The map
Example map output:
```
########################
#        ########      #
#        #     E#      #
#               #      #
#         ##############
#                      #
##########             #
#                      #
#       ################
#          #    X      #
#          #    ###### #
#          #    #   ## #
#          #    #   ## #
#          #    #   ## #
#          #    #   ## #
#                   ## #
###################### #
#                      #
#  #####################
#                     S#
########################
```

|Character    | Meaning                                                |
|-------------|--------------------------------------------------------|
| #           | A wall that you cannot pass through                    |
| ' ' (space) | An empty space which is what you are able to move into |
| E           | The exit point (finish)                                |
| S           | The start position                                     |
| X           | This is your position in the maze                      |

## What makes a maze valid
A maze is valid if all the following conditions are met
- Width and height are both >=5 and <=100
- Only consists of characters S, E, ' '(SPACE), #
- All rows and columns are of equal length/height
- There is only one start and one end marked by S and E respectively
