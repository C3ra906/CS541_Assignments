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

int calc_fitness(int * position)//Calculates fitness of a member by subtracting 1 every time an attacking queen is found
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
            if (position[i] == 5)//Another Queen is at row 5
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
        printf("{%d, %d, %d, %d, %d, %d, %d, %d}", pop[i].position[0], pop[i].position[1], pop[i].position[2], pop[i].position[3], pop[i].position[4], pop[i].position[5], pop[i].position[6], pop[i].position[7]);
        printf(" fitness: %d \n", pop[i].fitness);
       i++;
    }
}

void print_indv (Member mem)//Prints individual member of pop
{
  printf("{%d, %d, %d, %d, %d, %d, %d, %d}", mem.position[0], mem.position[1], mem.position[2], mem.position[3], mem.position[4], mem.position[5], mem.position[6], mem.position[7]);
  printf(" fitness: %d \n", mem.fitness);
}

Member mutate (Member mem, int num)//mutates a chromosome
{
    int chosen;//Position chosen for mutation
    int change = -1;//randomly chosen value to mutate to
    int exclude;//used to stop mutation from changing the number to same number
    int size = 8;//Max range of numbers rand() will pick from
    int seed = 0;
    struct timeval seeder;

    gettimeofday (&seeder, NULL);
    seed = seeder.tv_usec + num;
    srand(seed);//seeds rand()

    chosen = rand() % size;
    printf("Position chosen: %d \n", chosen);
    exclude = mem.position[chosen];
    printf("Number to exclude: %d \n", exclude);
    while (change == -1 || change == exclude)
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

int * parent_selector (Member * mem, int pop_size, int * parents)//mutates a chromosome
{
    int chosen[2];
    int selected = -1;
    int seed = 0;
    int size = 100;
    struct timeval seeder;
    int i = 0;
    int j = 0;
    float math = 0;
    float math2 = 0;
    float selec_prob[8];
    int sum = 0;
    int exclude = -1;
    int looper = 0;

    //printf("In parent selector \n");

    while (i < pop_size)//Gets sum of all fitnesses in the population
    {
        sum = sum + mem[i].fitness;
        i++;
    }
   // printf("Sum of all fitness is: %d \n", sum);


    while (j < pop_size)
    {
        if (j == 0)
        {
            math = mem[j].fitness;
            selec_prob[j] = math/sum * 100;//Saves selection prob for each individual
           // printf("selec_prob: %f \n", selec_prob[j]);
        }
        else
        {
           math = mem[j].fitness;
           math2 = selec_prob[j-1];
           selec_prob[j] = math2 + ((math/sum) * 100);//Saves selection prob for each individual
          // printf("selec_prob: %f \n", selec_prob[j]);
        }
        j++;
    }

    gettimeofday (&seeder, NULL);
    seed = seeder.tv_usec;
    srand(seed);//seeds rand()

    selected = rand() % size;
   // printf("Chosen: %d \n", selected);
    for (int i = 0; i < pop_size; i++)//First parent need to be chosen
    {
        if (i == 0)
        {
            if (selected < selec_prob[i])
            {
                parents[0] = i;
                exclude = i;//remember this parent was chosen so we don't pick the same parent the second time
                break;
            }
        }
        else
        {
            if(selected < selec_prob[i] && selected >= selec_prob[i-1])
            {
                parents[0] = i;
                exclude = i;//remember this parent was chosen so we don't pick the same parent the second time
                break;
            }
        }
    }
    //printf ("Chosen 1st Parent is %d with fitness %d \n", parents[0], mem[parents[0]].fitness);


    while (looper == 0)
    {
       gettimeofday (&seeder, NULL);
       seed = seeder.tv_usec;
       srand(seed + 40);//seeds rand()
       selected = rand() % size;
       //printf("Chosen: %d \n", selected);
       for (int i = 0; i < pop_size; i++)//Second parent need to be chosen, excluding the first parent
       {
           if (i == 0)
           {
               if (selected < selec_prob[i])
               {
                   if (exclude != i)
                   {
                       parents[1] = i;
                       looper = 1;
                       break;
                   }
                   if (exclude == i)//re-roll
                   {
                       srand(seed + 2);//seeds rand()
                       selected = rand() % size;
                   }
               }
           }
           else
           {
               if(selected < selec_prob[i] && selected >= selec_prob[i-1])
               {
                   if (exclude != i)
                   {
                       parents[1] = i;
                       looper = 1;
                       break;
                   }
                   if (exclude == i)//re-roll
                   {
                        srand(seed + 3);//seeds rand()
                        selected = rand() % size;
                   }
               }
            }
        }
    }
    //printf ("Chosen 2nd Parent is %d with fitness %d\n", parents[1], mem[parents[1]].fitness);
    return parents;
}

Member * crossover (Member * mem, int pop_size)
{
    int * parents;
    int p1;
    int p2;
    struct timeval seeder;
    int seed = 0;
    int cross_pt;
    int x_size = 7;
    int m_chance = 100;
    int MutationPct;
    int hold = -1;

    parents = parent_selector (mem, pop_size, parents);
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

    for (int c = 1; c < 8; c++)//Crossover point between position 1 and 7
    {
       hold = mem[p2].position[c];
       mem[p2].position[c] = mem[p1].position[c];
       mem[p1].position[c] = hold;
    }
    printf("Crossover complete \n");
    mem[p1].fitness = calc_fitness(mem[p1].position);
    mem[p2].fitness = calc_fitness(mem[p2].position);
    printf("Child 1 replaces member %d: ", p1);
    print_indv(mem[p1]);
    printf("Child 2 replaces member %d: ", p2);
    print_indv(mem[p2]);

    gettimeofday(&seeder, NULL);
    seed = seeder.tv_usec + 100;
    srand(seed);//seeds rand()
    MutationPct = rand() % m_chance;
    printf("Child 1 MutationPct was %d \n", MutationPct);
    if (MutationPct < 5)//5% chance of mutation
    {
        printf("Child 1 will be mutated \n");
        mem[p1] = mutate(mem[p1], 0);
    }

    gettimeofday(&seeder, NULL);
    seed = seeder.tv_usec + 200;
    srand(seed);//seeds rand()
    MutationPct = rand() % m_chance;
    printf("Child 2 MutationPct was %d \n", MutationPct);
    if (MutationPct < 5)//5% chance of mutation
    {
        printf("Child 2 will be mutated \n");
        mem[p2] = mutate(mem[p2], 0);
    }
    return mem;
}

int main ()
{
    int PopulationSize = 50;//The size of the population
    int NumIterations = 1000;//The number of times to run the GA algorithm
    int gen_counter = 0;
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
       printf("%d Generation: \n", gen_counter);
       pop_ptr = crossover(pop_ptr, PopulationSize);
       print_pop(pop_ptr, PopulationSize);//test print entire population
        for (int i = 0; i < PopulationSize; i++)//Sets up initial population
        {
           avg_fitness = avg_fitness + pop_ptr[i].fitness;
           if (pop_ptr[i].fitness == 28)
           {
               printf("best fitness found in member %d!\n", i);
               best = 1;
           }
        }
        avg_fitness = avg_fitness/PopulationSize;
       printf("Average fitness is: %f \n", avg_fitness);
       avg_fitness = 0;
       NumIterations--;
    }
    printf("Initial avg fitness was: %f \n", initial_f);
    return (EXIT_SUCCESS);
}
