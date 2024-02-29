#!/bin/bash

gcc maze.c helpers.c -o maze

echo -e "~~ Testing invalid mazes ~~"

# tests all edge cases
for i in {1..6}
do
    echo -e "\n~~ Testing mazes/invalid/invalid$i.txt ~~"
    echo "mazes/invalid/invalid$i.txt" | ./maze > tmp

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
    echo "mazes/valid/valid$i.txt" | ./maze > tmp;

    if grep -q "Error: Invalid maze" tmp; then
        echo "FAIL"
    else
        echo "PASS"
    fi
done

echo -e "~~ Testing invalid moves ~~"

# go into wall
echo -e "\n~~ Testing mazes/valid/valid1.txt with invalid moves ~~"
echo -e "mazes/valid/valid1.txt\nA" > test
echo -e test | ./maze > tmp;

if grep -q "Error: Invalid move. Please try again" tmp; then
    echo "PASS"
else
    echo "FAIL"
fi

# fall of the edge
echo -e "\n~~ Testing mazes/valid/valid7.txt with invalid moves ~~"
echo -e "mazes/valid/valid7.txt\nD\nD\nD\nD" > test
cat test | ./maze > tmp;

if grep -q "Error: Invalid move. Please try again" tmp; then
    echo "PASS"
else
    echo "FAIL"
fi

# go into wall
echo -e "\n~~ Testing mazes/valid/valid4.txt with invalid moves and display map ~~"
echo -e "mazes/valid/valid4.txt\nA\nM" > test
cat test | ./maze > tmp;
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
echo -e "mazes/valid/valid4.txt\nZ" > test
cat test | ./maze > tmp;

if grep -q "Error: Invalid move. Please try again" tmp; then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "~~ Testing valid moves ~~"

echo -e "\n~~ Testing mazes/valid/valid4.txt with display map ~~"
echo -e "mazes/valid/valid4.txt\nM" > test
cat test | ./maze > tmp;

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
echo -e "mazes/valid/valid4.txt\nD\nD\nM" > test
cat test | ./maze > tmp;

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
echo -e "mazes/valid/valid4.txt\nD" > test
cat test | ./maze > tmp;
if grep -q "Error: Invalid move. Please try again" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

echo -e "\n~~ Testing mazes/valid/valid4.txt with valid solution ~~"
echo -e "mazes/valid/valid4.txt\nD\nD\nS\n\S\nA\nA" > test
cat test | ./maze > tmp;
if grep -q "Congratulations you have solved the maze" tmp; then
    echo "PASS"
else
    echo "FAIL"
fi

rm -f maze test tmp