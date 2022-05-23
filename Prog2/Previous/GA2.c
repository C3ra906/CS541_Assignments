//Cera Oh. Fall 2021 CS541 AI.
//Prog2 Genetic Algorithm for 8-Queens Problem
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

typedef struct member//Represents each individual in the population
{
    int position[8];//position of the Queen in 8 bit string
    int fitness;//fitness value of the member
}Member;

int calc_fitness(int * position)//Function that calculates fitness of a member by subtracting 1 every time an attacking queen is found
{
    int fitness = 28;//28 is max non-attacking queens

//Column 1
    if(position[0] == 1)//Column 1 Queen is at 1
    {
        for (int i = 1; i < 8; i++)//Check Queens on column 2-8
        {
            if (position[i] == 1)//Another Queen is in row 1
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 1)//Another Queen is in positive diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[0] == 2)//Column 1 Queen is at 2
    {
        for (int i = 1; i < 8; i++)
        {
            if (position[i] == 2)//Another Queen is in row 2
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 2)//Another Queen is in positive diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[1] == 1)//Column 2 Queen is at 1
        {
            fitness = fitness - 1;
        }
    }
    else if(position[0] == 3)//Column 1 Queen is at 3
    {
        for (int i = 1; i < 8; i++)
        {
            if (position[i] == 3)//Another Queen is in row 3
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 3)//Another Queen is in positive diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[1] == 2)//Column 2 Queen is at 2
        {
            fitness = fitness - 1;
        }
        if (position[2] == 1)//Column 3 Queen is at 3
        {
            fitness = fitness - 1;
        }
    }
    else if(position[0] == 4)//Column 1 Queen is at 4
    {
        for (int i = 1; i < 8; i++)
        {
            if (position[i] == 4)//Another Queen is at row 4
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 4)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 4 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[0] == 5)//Column 1 Queen is at 5
    {
        for (int i = 1; i < 8; i++)
        {
            if (position[i] == 5)//Another Queen is in row 5
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 5)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 5 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[0] == 6)//Column 1 Queen is at 6
    {
        for (int i = 1; i < 8; i++)
        {
            if (position[i] == 6)//Another Queen is at row 6
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 6)//Another Queen is in positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 6 - i)//Another Queen is in negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[0] == 7)//Column 1 Queen is at 7
    {
        for (int i = 1; i < 8; i++)
        {
            if (position[i] == 7)//Another Queen is at row 7
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 7)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 7 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[0] == 8)//Column 1 Queen is at 8
    {
        for (int i = 1; i < 8; i++)
        {
            if (position[i] == 8)//Another Queen is at row 8
            {
                fitness = fitness - 1;
            }
            if (position[i] == 8 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
//Column 2
    if(position[1] == 1)//Column 2 Queen is at 1
    {
        for (int i = 2; i < 8; i++)//Check Queens on column 3-8
        {
            if (position[i] == 1)//Another Queen is at row 1
            {
                fitness = fitness - 1;
            }
            if (position[i] == i)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[1] == 2)//Column 2 Queen is at 2
    {
        for (int i = 2; i < 8; i++)
        {
            if (position[i] == 2)//Another Queen is at row 2
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 1)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[2] == 1)//Column 3 Queen is at 1
        {
            fitness = fitness - 1;
        }
    }
    else if(position[1] == 3)//Column 2 Queen is at 3
    {
        for (int i = 2; i < 8; i++)
        {
            if (position[i] == 3)//Another Queen is at row 3
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 2)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[2] == 2)//Column 3 Queen is at 2
        {
            fitness = fitness - 1;
        }
        if (position[3] == 1)//Column 4 Queen is at 1
        {
            fitness = fitness - 1;
        }
    }
    else if(position[1] == 4)//Column 2 Queen is at 4
    {
        for (int i = 2; i < 8; i++)
        {
            if (position[i] == 4)//Another Queen is at row 4
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 3)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 5 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[1] == 5)//Column 2 Queen is at 5
    {
        for (int i = 2; i < 8; i++)
        {
            if (position[i] == 5)//Another Queen is at row 5
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 4)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 6 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[1] == 6)//Column 2 Queen is at 6
    {
        for (int i = 2; i < 8; i++)
        {
            if (position[i] == 6)//Another Queen is at row 6
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 5)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 7 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[1] == 7)//Column 2 Queen is at 7
    {
        for (int i = 2; i < 8; i++)
        {
            if (position[i] == 7)//Another Queen is at row 7
            {
                fitness = fitness - 1;
            }
            if (position[i] == 8 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[2] == 8)//Column 3 Queen is at 8
        {
            fitness = fitness - 1;
        }
    }
    else if(position[1] == 8)//Column 2 Queen is at 8
    {
        for (int i = 2; i < 8; i++)
        {
            if (position[i] == 8)//Another Queen is in row 8
            {
                fitness = fitness - 1;
            }
            if (position[i] == 9 - i)//Another Queen is in negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
//Column 3
    if(position[2] == 1)//Column 3 Queen is at 1
    {
        for (int i = 3; i < 8; i++)//Checks Queens at column 4-8
        {
            if (position[i] == 1)//Another Queen is at row 1
            {
                fitness = fitness - 1;
            }
        }
        for (int i = 3; i < 8; i++)//Another Queen is at positive diagonal
        {
           if (position[i] == i - 1)
           {
                fitness = fitness - 1;
           }
        }
    }
    else if(position[2] == 2)//Column 3 Queen is at 2
    {
        for (int i = 3; i < 8; i++)
        {
            if (position[i] == 2)//Another Queen is at row 2
            {
                fitness = fitness - 1;
            }
            if (position[i] == i)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[3] == 1)//Column 4 Queen is at 1
        {
            fitness = fitness - 1;
        }
    }
    else if(position[2] == 3)//Column 3 Queen is at 3
    {
        for (int i = 3; i < 8; i++)
        {
            if (position[i] == 3)//Another Queen is at row 3
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 1)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
       if (position[3] == 2)//Column 4 Queen is at 2
       {
           fitness = fitness - 1;
       }
       if (position[4] == 1)//Column 5 Queen is at 1
       {
           fitness = fitness - 1;
       }
    }
    else if(position[2] == 4)//Column 3 Queen is at 4
    {
        for (int i = 3; i < 8; i++)
        {
            if (position[i] == 4)//Another Queen is at row 4
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 2)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 6 - i)//Another Queen is at negative diagnoal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[2] == 5)//Column 3 Queen is at 5
    {
        for (int i = 3; i < 8; i++)
        {
            if (position[i] == 5)//Another Queen is at row 5
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 3)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 7 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[2] == 6)//Column 3 Queen is at 6
    {
        for (int i = 3; i < 8; i++)
        {
            if (position[i] == 6)//Another Queen is at row 6
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 4)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 8 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[2] == 7)//Column 3 Queen is at 7
    {
        for (int i = 3; i < 8; i++)
        {
            if (position[i] == 7)//Another Queen is at row 7
            {
                fitness = fitness - 1;
            }
            if (position[i] == 9 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[3] == 8)//Col 4 Queen is at 8
        {
            fitness = fitness - 1;
        }
    }
    else if(position[2] == 8)//Column 3 Queen is at 8
    {
        for (int i = 3; i < 8; i++)
        {
            if (position[i] == 8)//Another Queen is at 8
            {
                fitness = fitness - 1;
            }
        }
        for (int i = 3; i < 8; i++)
        {
           if (position[i] == 10 - i)//Another Queen is at negative diagonal
           {
                fitness = fitness - 1;
           }
        }
    }
//Column 4
    if(position[3] == 1)//Column 4 Queen is at 1
    {
        for (int i = 4; i < 8; i++)//Check Queens on col 5-8
        {
            if (position[i] == 1)//Another Queen is at row 1
            {
                fitness = fitness - 1;
            }
            if (position[i] == i - 2)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[3] == 2)//Column 4 Queen is at 2
    {
        for (int i = 4; i < 8; i++)
        {
            if (position[i] == 2)//Another Queen is at row 2
            {
                fitness = fitness - 1;
            }
            if (position[i] == i - 1)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[4] == 1)//Col 5 Queen is at 1
        {
            fitness = fitness - 1;
        }
    }
    else if(position[3] == 3)//Column 4 Queen is at 3
    {
        for (int i = 4; i < 8; i++)
        {
            if (position[i] == 3)//Another Queen is at row 3
            {
                fitness = fitness - 1;
            }
            if (position[i] == i)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[4] == 2)//Col 5 Queen is at 2
        {
           fitness = fitness - 1;
        }
        if (position[5] == 1)//Col 6 Queen is at 1
        {
           fitness = fitness - 1;
        }
    }
    else if(position[3] == 4)//Column 4 Queen is at 4
    {
        for (int i = 4; i < 8; i++)
        {
            if (position[i] == 4)//Another Queen is at row 4
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 1)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 7 - i)//ANother Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[3] == 5)//Column 4 Queen is at 5
    {
        for (int i = 4; i < 8; i++)
        {
            if (position[i] == 5)//Another Queen is at row 5
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 2)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 8 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[3] == 6)//Column 4 Queen is at 6
    {
        for (int i = 4; i < 8; i++)
        {
            if (position[i] == 6)//Another Queen is at row 6
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 3)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 9 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[3] == 7)//Column 4 Queen is at 7
    {
        for (int i = 4; i < 8; i++)
        {
            if (position[i] == 7)//Another Queen is at row 7
            {
                fitness = fitness - 1;
            }
            if (position[i] == 10 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[4] == 8)//Col 5 Queen is at 8
        {
            fitness = fitness - 1;
        }
    }
    else if(position[3] == 8)//Column 4 Queen is at 8
    {
        for (int i = 4; i < 8; i++)
        {
            if (position[i] == 8)//Another Queen is at row 8
            {
                fitness = fitness - 1;
            }
            if (position[i] == 11 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
//Column 5
    if(position[4] == 1)//Column 5 Queen is at 1
    {
        for (int i = 5; i < 8; i++)
        {
            if (position[i] == 1)//Another Queen is at row 1
            {
                fitness = fitness - 1;
            }
            if (position[i] == i - 3)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[4] == 2)//Column 5 Queen is at 2
    {
        for (int i = 5; i < 8; i++)
        {
            if (position[i] == 2)//Another Queen is at row 2
            {
                fitness = fitness - 1;
            }
            if (position[i] == i - 2)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[5] == 1)//Col 6 Queen is at 1
        {
            fitness = fitness - 1;
        }
    }
    else if(position[4] == 3)//Column 5 Queen is at 3
    {
        for (int i = 5; i < 8; i++)
        {
            if (position[i] == 3)//Another Queen is at row 3
            {
                fitness = fitness - 1;
            }
            if (position[i] == i - 1)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[5] == 2)//Col 6 Queen is at 2
        {
            fitness = fitness - 1;
        }
        if (position[6] == 1)//Col 7 Queen is at 1
        {
            fitness = fitness - 1;
        }
    }
    else if(position[4] == 4)//Column 5 Queen is at 4
    {
        for (int i = 5; i < 8; i++)
        {
            if (position[i] == 4)//Another Queen is in row 4
            {
                fitness = fitness - 1;
            }
            if (position[i] == i)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 8 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[4] == 5)//Column 5 Queen is at 5
    {
        for (int i = 5; i < 8; i++)
        {
            if (position[i] == 5)//Another Queen is at row 5
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 1)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 9 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[4] == 6)//Column 5 Queen is at 6
    {
        for (int i = 5; i < 8; i++)
        {
            if (position[i] == 6)//Another Queen is at row 6
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 2)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 10 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[4] == 7)//Column 5 Queen is at 7
    {
        for (int i = 5; i < 8; i++)
        {
            if (position[i] == 7)//Another Queen is at row 7
            {
                fitness = fitness - 1;
            }
            if (position[i] == 11 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[5] == 8)//Col 6 Queen is at 8
        {
            fitness = fitness - 1;
        }
    }
    else if(position[4] == 8)//Column 5 Queen is at 8
    {
        for (int i = 5; i < 8; i++)
        {
            if (position[i] == 8)//Another Queen is at row 8
            {
                fitness = fitness - 1;
            }
            if (position[i] == 12 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
//Column 6
    if(position[5] == 1)//Column 6 Queen is at 1
    {
        for (int i = 6; i < 8; i++)
        {
            if (position[i] == 1)//Another Queen is at row 1
            {
                fitness = fitness - 1;
            }
            if (position[i] == i - 4)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[5] == 2)//Column 6 Queen is at 2
    {
        for (int i = 6; i < 8; i++)
        {
            if (position[i] == 2)//Another Queen is at row 2
            {
                fitness = fitness - 1;
            }
            if (position[i] == i - 3)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[6] == 1)//Col 7 Queen is at 1
        {
            fitness = fitness - 1;
        }
    }
    else if(position[5] == 3)//Column 6 Queen is at 3
    {
        for (int i = 6; i < 8; i++)
        {
            if (position[i] == 3)//Another Queen is at row 3
            {
                fitness = fitness - 1;
            }
            if (position[i] == i - 2)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 8 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[5] == 4)//Column 6 Queen is at 4
    {
        for (int i = 6; i < 8; i++)
        {
            if (position[i] == 4)//Another Queen is at row 4
            {
                fitness = fitness - 1;
            }
            if (position[i] == i - 1)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 9 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[5] == 5)//Column 6 Queen is at 5
    {
         for (int i = 6; i < 8; i++)
        {
            if (position[i] == 5)//Another Queen is at row 5
            {
                fitness = fitness - 1;
            }
            if (position[i] == i)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 10 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[5] == 6)//Column 6 Queen is at 6
    {
        for (int i = 6; i < 8; i++)
        {
            if (position[i] == 6)//Another Queen is at row 6
            {
                fitness = fitness - 1;
            }
            if (position[i] == i + 1)//Another Queen is at positive diagonal
            {
                fitness = fitness - 1;
            }
            if (position[i] == 11 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
    else if(position[5] == 7)//Column 6 Queen is at 7
    {
        for (int i = 6; i < 8; i++)
        {
            if (position[i] == 7)//Another Queen is at row 7
            {
                fitness = fitness - 1;
            }
            if (position[i] == 12 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
        if (position[6] == 8)//Col 7 Queen is at 8
        {
            fitness = fitness - 1;
        }
    }
    else if(position[5] == 8)//Column 6 Queen is at 8
    {
        for (int i = 6; i < 8; i++)
        {
            if (position[i] == 8)//Another Queen is at row 8
            {
                fitness = fitness - 1;
            }
            if (position[i] == 13 - i)//Another Queen is at negative diagonal
            {
                fitness = fitness - 1;
            }
        }
    }
//Column 7
    if(position[6] == 1)//Column 7 Queen is at 1
    {
        if (position[7] == 1 || position[7] == 2)//Col 8 Queen is at 1 or 2
        {
            fitness = fitness - 1;
        }
    }
    else if(position[6] == 2)//Column 7 Queen is at 2
    {
        if (position[7] == 1 || position[7] == 2 || position[7] == 3)//Col 8 Queen is at 1, 2, or 3
        {
            fitness = fitness - 1;
        }
    }
    else if(position[6] == 3)//Column 7 Queen is at 3
    {
        if (position[7] == 2 || position[7] == 3 || position[7] == 4)//Col 8 Queen is at 2, 3, or 4
        {
            fitness = fitness - 1;
        }
    }
    else if(position[6] == 4)//Column 7 Queen is at 4
    {
        if (position[7] == 3 || position[7] == 4 || position[7] == 5)//Col 8 Queen is at 3, 4, or 5
        {
            fitness = fitness - 1;
        }
    }
    else if(position[6] == 5)//Column 7 Queen is at 5
    {
        if (position[7] == 4 || position[7] == 5 || position[7] == 6)//Col 8 Queen is at 4, 5, or 6
        {
            fitness = fitness - 1;
        }
    }
    else if(position[6] == 6)//Column 7 Queen is at 6
    {
        if (position[7] == 5 || position[7] == 6 || position[7] == 7)//Col 8 Queen is at 5, 6, or 7
        {
            fitness = fitness - 1;
        }
    }
    else if(position[6] == 7)//Column 7 Queen is at 7
    {
        if (position[7] == 6 || position[7] == 7 || position[7] == 8)//Col 8 Queen is at 6, 7, or 8
        {
            fitness = fitness - 1;
        }
    }
    else if(position[6] == 8)//Column 7 Queen is at 8
    {
        if (position[7] == 7 || position[7] == 8)//Col 8 Queen is at 7 or 8
        {
            fitness = fitness - 1;
        }
    }

    return fitness;
}

Member create_mem (Member mem, int num)//creates random 8 string member for initial population
{
    int chosen;//Number generated by rand()
    int size = 8;//Max range of numbers rand() will pick from
    struct timeval seeder;

    gettimeofday (&seeder, NULL);
    srand(seeder.tv_usec + num);//seeds rand()

    for (int i = 0; i < 8; i++)
    {
        chosen = rand() % size;
        chosen = chosen + 1;
        mem.position[i] = chosen;
    }

    mem.fitness = calc_fitness(mem.position);
    return mem;
}

void print_pop (Member * pop, int size)//Prints entire population
{
    int i = 0;
    while (i < size)
    {
        printf("Member[%d]: {%d, %d, %d, %d, %d, %d, %d, %d}", i, pop[i].position[0], pop[i].position[1], pop[i].position[2], pop[i].position[3], pop[i].position[4], pop[i].position[5], pop[i].position[6], pop[i].position[7]);
        printf(" fitness: %d \n", pop[i].fitness);
       i++;
    }
}

void print_indv (Member mem)//Prints individual member of pop
{
  printf("{%d, %d, %d, %d, %d, %d, %d, %d}", mem.position[0], mem.position[1], mem.position[2], mem.position[3], mem.position[4], mem.position[5], mem.position[6], mem.position[7]);
  printf(" fitness: %d \n", mem.fitness);
}

Member mutate (Member mem, int num)//Function that mutates a given member at a random position
{
    int chosen;//Position chosen for mutation
    int change = -1;//randomly chosen value to mutate to
    int exclude = -2;//used to stop mutation from changing the number to same number
    int size = 8;//Max range of numbers rand() will pick from 0-7
    int seed = 0;//For rand()
    struct timeval seeder;

    gettimeofday (&seeder, NULL);
    seed = seeder.tv_usec + num;
    srand(seed);//seeds rand()

    chosen = rand() % size;

    printf("Position chosen: %d \n", chosen);
    exclude = mem.position[chosen];
    printf("Number to exclude: %d \n", exclude);
    while (change == -1 || change == exclude - 1)
    {
        srand(seed++);
        change = rand() % size;
    }
    change = change + 1;
    mem.position[chosen] = change;
    printf("Mutated to: %d \n", change);
    mem.fitness = calc_fitness(mem.position);
    print_indv(mem);

    return mem;
}

int * parent_selector (Member * mem, int pop_size, int * parents)//Function to select the parents to reproduce
{
    int chosen[2] = {0, 0};//Variable to keep track of which parent indices are chosen
    int selected = -1;//The random number rand() picks
    int seed = 0;//For seeding timer for srand()
    int size = 100;//Range for rand() is 0 to 99
    struct timeval seeder;//For seeding rand()
    int i = 0;//For looping
    int j = 0;//For looping
    float math = 0;//Used for calculating probability ranges for each member
    float math2 = 0;//Used for calculating probability ranges for each member
    float selec_prob[pop_size];//Stores the ranges for each member, mapped by index number
    int sum = 0;//Sum of all fitnesses in the population
    int exclude = -1;//Used to prevent picking the same parent as own partner
    int looper = 0;//For looping

    while (i < pop_size)//Gets sum of all fitnesses in the population
    {
        sum = sum + mem[i].fitness;
        i++;
    }
   //printf("Sum of all fitness is: %d \n", sum);

    while (j < pop_size)
    {
        if (j == 0)
        {
            math = mem[j].fitness;
            selec_prob[j] = math/sum * 100;//Saves selection prob for each individual
            //printf("math: %f ", math);
            //printf("selec_prob [%d]: %f \n",j, selec_prob[j]);
        }
        else
        {
           math = mem[j].fitness;
           math2 = selec_prob[j-1];
           //printf("math: %f ", math);
           //printf("math2: %f ", math2);
           selec_prob[j] = math2 + ((math/sum) * 100);//Saves selection prob for each individual
           //printf("selec_prob [%d]: %f \n",j, selec_prob[j]);
        }
        j++;
    }

    gettimeofday (&seeder, NULL);
    seed = seeder.tv_usec;
    srand(seed);//seeds rand()
    selected = rand() % size;

   // printf("Chosen: %d \n", selected);

    for (int k = 0; k < pop_size; k++)//First parent need to be chosen
    {
        //printf("In for loop...");
        if (k == 0)
        {
            //printf("in k == 0 if loop...");
            if (selected < selec_prob[k])
            {
             // printf("In sel < prob loop ");
              // printf("Before assignment");
                chosen[0] = k;
               //printf("Assignment worked");
                exclude = k;//remember this parent was chosen so we don't pick the same parent the second time
                break;
            }
        }
        else
        {
          //printf("in else loop for k != 0");
            if(selected < selec_prob[k] && selected >= selec_prob[k-1])
            {
               // printf("Before assignment");
                chosen[0] = k;
              // printf("Assignment worked");
                exclude = k;//remember this parent was chosen so we don't pick the same parent the second time
                break;
            }
        }
    }
    parents[0] = chosen[0];
    //printf ("Chosen 1st Parent is %d with fitness %d \n", parents[0], mem[parents[0]].fitness);


    while (looper == 0)
    {
       gettimeofday (&seeder, NULL);
       seed = seeder.tv_usec;
       srand(seed + 40);//seeds rand()
       selected = rand() % size;
       //printf("Chosen: %d \n", selected);
       for (int m = 0; m < pop_size; m++)//Second parent need to be chosen, excluding the first parent
       {
           if (m == 0)
           {
               if (selected < selec_prob[m])
               {
                   if (exclude != m)
                   {
                       chosen[1] = m;
                       looper = 1;
                       break;
                   }
                   if (exclude == m)//re-roll
                   {
                       srand(seed + 2);//seeds rand()
                       selected = rand() % size;
                   }
               }
           }
           else
           {
               if(selected < selec_prob[m] && selected >= selec_prob[m-1])
               {
                   if (exclude != m)
                   {
                       chosen[1] = m;
                       looper = 1;
                       break;
                   }
                   if (exclude == m)//re-roll
                   {
                        srand(seed + 3);//seeds rand()
                        selected = rand() % size;
                   }
               }
            }
        }
    }
    parents[1] = chosen[1];
    //printf ("Chosen 2nd Parent is %d with fitness %d\n", parents[1], mem[parents[1]].fitness);
    return parents;
}

Member * Genetic_Algorithm(Member * mem, int pop_size)//Function for Genetic Algorithm. Produces children by crossing over and mutating
{
    int MutationPct = 5;//Probability for mutation. Feel free to change numbers. Ex. 5% = 5.
    int * parents;//To keep indices of parents chosen
    int p1;//Used for first parent's index
    int p2;//Used for second parent's index
    struct timeval seeder;//for seeding rand()
    int seed = 0;//for rand()
    int cross_pt;//Variable to store which index point to cross over
    int x_size = 7;//Range for crossing over. We don't want to include index 0.
    int m_chance = 100;//Range for mutation chance, 0 to 99
    int mute_chance = 0;//Variable for what rand() chose for mutation
    int counter = 0;//Count number of children produced
    Member children[pop_size];//Member array of children produced. Copied into population at the end.

    parents = malloc(2*sizeof(int));

    while (counter < pop_size)//Keeps looping until all children produced to replace the population
    {
       parents = parent_selector(mem, pop_size, parents);
       p1 = parents[0];
       p2 = parents[1];
       printf("Parent 1 is member %d: ", p1);
       print_indv(mem[p1]);
       printf("Parent 2 is member %d: ", p2);
       print_indv(mem[p2]);

       gettimeofday(&seeder, NULL);
       seed = seeder.tv_usec + 100;
       srand(seed);//seeds rand()
       cross_pt = (rand() % x_size) + 1;
       printf("Crossover point is %d \n", cross_pt);

       for (int c = 0; c < cross_pt; c++)
       {
           children[counter].position[c] = mem[p1].position[c];
           children[counter + 1].position[c] = mem[p2].position[c];
       }
       for (int c = cross_pt; c < 8; c++)//Crossover point between position 1 and 7
       {
          children[counter].position[c] = mem[p2].position[c];
          children[counter + 1].position[c] = mem[p1].position[c];
       }
       printf("Crossover complete \n");
       children[counter].fitness = calc_fitness(children[counter].position);
       children[counter + 1].fitness = calc_fitness(children[counter + 1].position);
       printf("Child %d: ", counter);
       print_indv(children[counter]);
       printf("Child %d ", counter + 1);
       print_indv(children[counter+1]);

       gettimeofday(&seeder, NULL);
       seed = seeder.tv_usec + 100;
       srand(seed);//seeds rand()
       mute_chance = rand() % m_chance;
       printf("Child %d mutation number was %d...", counter, mute_chance);
       if (mute_chance < MutationPct)//5% chance of mutation
       {
           printf("Child %d will be mutated \n", counter);
           children[counter] = mutate(children[counter], 0);
       }
       else
       {
           printf("Child %d wasn't mutated \n", counter);
       }

       gettimeofday(&seeder, NULL);
       seed = seeder.tv_usec + 200;
       srand(seed);//seeds rand()
       mute_chance = rand() % m_chance;
       printf("Child %d mutation number was %d...", counter + 1, mute_chance);
       if (mute_chance < MutationPct)//5% chance of mutation
       {
           printf("Child %d will be mutated \n", counter + 1);
           children[counter + 1] = mutate(children[counter + 1], 0);
       }
       else
       {
           printf("Child %d wasn't mutated \n", counter + 1);
       }
       counter = counter + 2;
    }

    for (int i = 0; i < pop_size; i++)//Copies children over into population as the new generation
    {
        for (int j = 0; j < 8; j++)
        {
            mem[i].position[j] = children[i].position[j];
        }
        mem[i].fitness = children[i].fitness;
    }
    free(parents);
    return mem;
}

int main ()
{
    int PopulationSize = 200;//The size of the population
    int NumIterations = 1000;//The number of times to run the GA algorithm
    int gen_counter = 0;//Counts number of generations passed
    int best = 0;
    float avg_fitness = 0;
    float initial_f = 0;
    Member population[PopulationSize];//Array of members to represent population
    Member * pop_ptr = NULL;
    pop_ptr = population;
    int num = 0;
    for (int i = 0; i < PopulationSize; i++)//Sets up initial population
    {
        population[i] = create_mem(population[i], num);
        num++;
    }
    printf("Initial Population: \n");
    print_pop(population, PopulationSize);//test print entire population
    for (int i = 0; i < PopulationSize; i++)//Sets up initial population
    {
       avg_fitness = avg_fitness + pop_ptr[i].fitness;
    }
    avg_fitness = avg_fitness/PopulationSize;
    printf("Average fitness is: %f \n", avg_fitness);
    initial_f = avg_fitness;
    avg_fitness = 0;

    while (NumIterations != 0 && best == 0)//Runs GA NumIterations times
    {
       gen_counter++;
       printf("\n%d Generation: \n", gen_counter);
       pop_ptr = Genetic_Algorithm(pop_ptr, PopulationSize);
       print_pop(pop_ptr, PopulationSize);//test print entire population
        for (int i = 0; i < PopulationSize; i++)//Sets up initial population
        {
           avg_fitness = avg_fitness + pop_ptr[i].fitness;
           if (pop_ptr[i].fitness == 28)
           {
               printf("Generation %d: solution found in member %d!\n",gen_counter, i);
               print_indv(pop_ptr[i]);
               best = 1;
           }
        }
        avg_fitness = avg_fitness/PopulationSize;
       printf("Generation %d Average fitness is: %f \n", gen_counter, avg_fitness);
       avg_fitness = 0;
       NumIterations--;
    }
    printf("Initial avg fitness was: %f \n", initial_f);

    return (EXIT_SUCCESS);
}
