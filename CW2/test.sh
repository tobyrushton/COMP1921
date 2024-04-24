#!/bin/bash

gcc maze.c helpers.c -o maze

echo -e "~~ Testing invalid mazes ~~"

# tests all edge cases
for i in {1..6}
do
    echo -e "\n~~ Testing mazes/invalid/invalid$i.txt ~~"
    ./maze "mazes/invalid/invalid$i.txt" | tee tmp;

    if grep -q "Error: Invalid maze" tmp; then
        echo "PASS"
    else
        echo "FAIL"
    fi
done

echo -e "\n~~ Testing valid mazes ~~"

for i in {1..7}
do
    echo -e "\n~~ Testing mazes/valid/valid$i.txt ~~"
    ./maze "mazes/valid/valid$i.txt" | tee tmp;

    if grep -q "Error: Invalid maze" tmp; then
        echo "FAIL"
    else
        echo "PASS"
    fi
done

echo -e "\n~~ Testing invalid moves ~~"

# go into wall
echo -e "\n~~ Testing mazes/valid/valid1.txt with invalid moves ~~"
cat inputs/move_left_invalid.txt | ./maze "mazes/valid/valid1.txt" > tmp;

if grep -q "Error: Invalid move. Please try again" tmp; then
    echo "PASS"
else
    echo "FAIL"
fi

# fall of the edge
echo -e "\n~~ Testing mazes/valid/valid7.txt with invalid moves ~~"
cat inputs/move_right_invalid.txt | ./maze "mazes/valid/valid7.txt" > tmp;

if grep -q "Error: Invalid move. Please try again" tmp; then
    echo "PASS"
else
    echo "FAIL"
fi

# go into wall
echo -e "\n~~ Testing mazes/valid/valid4.txt with invalid moves and display map ~~"
cat inputs/invalid_move_map.txt | ./maze "mazes/valid/valid4.txt" > tmp;
if grep -q "Error: Invalid move. Please try again" tmp; then
    if grep -q "#####" tmp; then
        if grep -q "#X  #" tmp; then
            if grep -q "### #" tmp; then
                if grep -q "#E  #" tmp; then
                    if grep -q "#####" tmp; then
                        echo "PASS"
                    else
                        echo "FAIL"
                    fi
                else
                    echo "FAIL"
                fi
            else
                echo "FAIL"
            fi
        else
            echo "FAIL"
        fi
    else
        echo "FAIL"
    fi
else
    echo "FAIL"
fi

# invalid character
echo -e "\n~~ Testing mazes/valid/valid4.txt with invalid character ~~"
cat inputs/invalid_character.txt | ./maze "mazes/valid/valid4.txt" > tmp;

if grep -q "Error: Invalid move. Please try again" tmp; then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "~~ Testing valid moves ~~"

echo -e "\n~~ Testing mazes/valid/valid4.txt with display map ~~"
cat inputs/display_map.txt | ./maze "mazes/valid/valid4.txt" > tmp;

if grep -q "#####" tmp; then
    if grep -q "#X  #" tmp; then
        if grep -q "### #" tmp; then
            if grep -q "#E  #" tmp; then
                if grep -q "#####" tmp; then
                    echo "PASS"
                else
                    echo "FAIL"
                fi
            else
                echo "FAIL"
            fi
        else
            echo "FAIL"
        fi
    else
        echo "FAIL"
    fi
else
    echo "FAIL"
fi

echo -e "\n~~ Testing mazes/valid/valid4.txt with valid moves and display map ~~"
cat inputs/display_map_valid_moves.txt | ./maze "mazes/valid/valid4.txt" > tmp;

if grep -q "#####" tmp; then
    if grep -q "#S X#" tmp; then
        if grep -q "### #" tmp; then
            if grep -q "#E  #" tmp; then
                if grep -q "#####" tmp; then
                    echo "PASS"
                else
                    echo "FAIL"
                fi
            else
                echo "FAIL"
            fi
        else
            echo "FAIL"
        fi
    else
        echo "FAIL"
    fi
else
    echo "FAIL"
fi

echo -e "\n~~ Testing mazes/valid/valid4.txt with valid move ~~"
cat inputs/valid_move.txt | ./maze "mazes/valid/valid4.txt" > tmp;

if grep -q "Error: Invalid move. Please try again" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

echo -e "\n~~ Testing mazes/valid/valid4.txt with valid solution ~~"
cat inputs/valid_solution.txt | ./maze "mazes/valid/valid4.txt" > tmp;

if grep -q "Congratulations you have solved the maze!" tmp; then
    echo "PASS"
else
    echo "FAIL"
fi

rm -f maze test tmp