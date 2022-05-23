//Cera Oh. Fall 2021 CS541 AI.
//Prog1 Best-First Search
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

typedef struct node{//Node representing each state
    int state[3][3];
    int f;
    struct node * parent;
    struct node * next;
    struct node * sol;
}Node;

void print_state(Node * current)//prints 3x3 board of the puzzle
{
    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int j = 0; j < 3; j++)
        {
            if (current->state[i][j] == 9)
            {
                printf(" b |");
            }
            else
            {
                printf(" %d |", current->state[i][j]);
            }
        }
        printf("\n");
        if (i != 2)
        {
            printf("------------- \n");
        }
    }
    printf("\n");
}

void print_solution(Node * current, Node initial)//prints 3x3 board of the puzzle
{
    Node * temp = current;
    int counter = 0;

    while (temp->sol != NULL)
    {
        temp = temp->sol;
        counter++;
    }

    int array[counter][3][3];

    for (int c = counter - 1; c >= 0; c--)
    {
       for (int i = 0; i < 3; i++)
       {
           for (int j = 0; j < 3; j++)
           {
               array[c][i][j] = current->state[i][j];
           }
       }
       current = current->sol;
    }

     printf("(");
     for (int a = 0; a < 3; a++)
     {
        for (int b = 0; b < 3; b++)
        {
           if (initial.state[a][b] == 9)
           {
                printf(" b ",initial.state[a][b]);
           }
           else
           {
                printf(" %d ",initial.state[a][b]);
           }
        }
     }
     printf(")");

    for (int k = 0; k < counter; k++)
    {
           printf("->(");

           for (int l = 0; l < 3; l++)
           {
               for (int m = 0; m < 3; m++)
               {
                   if (array[k][l][m] == 9)
                   {
                      printf(" b ");
                   }
                   else
                   {
                       printf(" %d ", array[k][l][m]);
                   }
               }
           }
           printf(")");
    }
    printf("\n");
}

void print_queue(Node * given)
{
    Node * current = given;
    while (current != NULL)
    {
        print_state(current);
        printf("f(n): %d \n", current->f);
        current = current->next;
    }
}

int calc_f (Node * given, int heuristic)//calculates f(n) for all 3 heuristics and returns the heuristics asked for
{
    int f = 0;
    int h1 = 0;
    int h2 = 0;
    int h3 = 0;

    if(given->state[0][0] == 1)
    {
        h1 = h1 + 0;
        h2 = h1 + 0;
        h3 = h1 + 0;
    }
    else if(given->state[0][0] == 2)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[0][0] == 3)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 2;
    }
    else if(given->state[0][0] == 4)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[0][0] == 5)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[0][0] == 6)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[0][0] == 7)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 2;
    }
    else if(given->state[0][0] == 8)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }

    if(given->state[0][1] == 1)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[0][1] == 2)
    {
        h1 = h1 + 0;
        h2 = h2 + 0;
        h3 = h3 + 0;
    }
    else if(given->state[0][1] == 3)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[0][1] == 4)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[0][1] == 5)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[0][1] == 6)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[0][1] == 7)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[0][1] == 8)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 2;
    }

    if(given->state[0][2] == 1)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 2;
    }
    else if(given->state[0][2] == 2)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[0][2] == 3)
    {
        h1 = h1 + 0;
        h2 = h2 + 0;
        h3 = h3 + 0;
    }
    else if(given->state[0][2] == 4)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[0][2] == 5)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[0][2] == 6)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[0][2] == 7)
    {
        h1 = h1 + 1;
        h2 = h2 + 4;
        h3 = h3 + 2;
    }
    else if(given->state[0][2] == 8)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }

    if(given->state[1][0] == 1)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[1][0] == 2)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[1][0] == 3)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[1][0] == 4)
    {
        h1 = h1 + 0;
        h2 = h2 + 0;
        h3 = h3 + 0;
    }
    else if(given->state[1][0] == 5)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[1][0] == 6)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 2;
    }
    else if(given->state[1][0] == 7)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[1][0] == 8)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }

    if(given->state[1][1] == 1)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[1][1] == 2)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[1][1] == 3)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[1][1] == 4)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[1][1] == 5)
    {
        h1 = h1 + 0;
        h2 = h2 + 0;
        h3 = h3 + 0;
    }
    else if(given->state[1][1] == 6)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[1][1] == 7)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[1][1] == 8)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }

    if(given->state[1][2] == 1)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[1][2] == 2)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[1][2] == 3)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[1][2] == 4)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 2;
    }
    else if(given->state[1][2] == 5)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[1][2] == 6)
    {
        h1 = h1 + 0;
        h2 = h2 + 0;
        h3 = h3 + 0;
    }
    else if(given->state[1][2] == 7)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[1][2] == 8)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }

    if(given->state[2][0] == 1)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 2;
    }
    else if(given->state[2][0] == 2)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[2][0] == 3)
    {
        h1 = h1 + 1;
        h2 = h2 + 4;
        h3 = h3 + 2;
    }
    else if(given->state[2][0] == 4)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[2][0] == 5)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[2][0] == 6)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[2][0] == 7)
    {
        h1 = h1 + 0;
        h2 = h2 + 0;
        h3 = h3 + 0;
    }
    else if(given->state[2][0] == 8)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }

    if(given->state[2][1] == 1)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[2][1] == 2)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 2;
    }
    else if(given->state[2][1] == 3)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[2][1] == 4)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[2][1] == 5)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[2][1] == 6)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[2][1] == 7)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[2][1] == 8)
    {
        h1 = h1 + 0;
        h2 = h2 + 0;
        h3 = h3 + 0;
    }

    if(given->state[2][2] == 1)
    {
        h1 = h1 + 1;
        h2 = h2 + 4;
        h3 = h3 + 2;
    }
    else if(given->state[2][2] == 2)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[2][2] == 3)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 2;
    }
    else if(given->state[2][2] == 4)
    {
        h1 = h1 + 1;
        h2 = h2 + 3;
        h3 = h3 + 2;
    }
    else if(given->state[2][2] == 5)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 1;
    }
    else if(given->state[2][2] == 6)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }
    else if(given->state[2][2] == 7)
    {
        h1 = h1 + 1;
        h2 = h2 + 2;
        h3 = h3 + 2;
    }
    else if(given->state[2][2] == 8)
    {
        h1 = h1 + 1;
        h2 = h2 + 1;
        h3 = h3 + 1;
    }

    if (heuristic == 1)
    {
        return h1;
    }
    if (heuristic == 2)
    {
        return h2;
    }
    if (heuristic == 3)
    {
        return h3;
    }
    else
    {
        printf("Error finding f \n");
        return -1;
    }
}

void fill_initial(Node * given, int num[3][3], int heuristic)//fills out initial 3x3 puzzle state (the starting state)
{
    int f = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
          given->state[i][j] = num[i][j];
        }
    }
    f = calc_f(given, heuristic);
    given->f = f;
    given->parent = NULL;
    given->next = NULL;
    given->sol = NULL;
}

void create_child(Node * given, Node * child, int heuristic)//creates children of the state
{
    int f = 0;
    printf("In create_child \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
          child->state[i][j] = given->state[i][j];
        }
    }
    f = calc_f(child, heuristic);
    child->f = f;
    child->parent = NULL;
    child->next = NULL;
    child->sol = given;

}

Node* copy_node(Node * given,int heuristic)//copies a node exactly except parent and next ptrs
{
    Node * copy = NULL;
    copy = malloc(sizeof(Node));
    int f = 0;

    printf("In copy_node \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
          copy->state[i][j] = given->state[i][j];
        }
    }
    copy->f = given->f;
    copy->parent = NULL;
    copy->next = NULL;
    copy->sol = given->sol;

    return copy;
}

bool isEmpty(Node * given)//checks whether Queue or List is empty
{
    printf("In isEmpty \n");
    if (given == NULL)
        return true;
}

Node* pop(Node ** frontier)//pops the priority queue
{
    printf("In pop \n");

    if ((*frontier)->next == NULL)//Only one node in frontier LLL
    {
        //printf("inside frontier->next NULL \n");
        (*frontier) = NULL;
    }
    else
    {
        *frontier = (*frontier)->next;
        (*frontier)->parent = NULL;
    }
    return *frontier;
}

Node* top(Node * frontier)//Peeks at the top of the priority queue without popping
{
    Node * top = NULL;
    top = frontier;

    return top;
}

Node* addFrontier2(Node ** frontier, Node * to_add, int heuristic)
{
    Node * hold = NULL;
    Node * temp = NULL;
    Node * current = *frontier;
    printf("In addFrontier \n");

    if (*frontier == NULL)
    {
        printf("In frontier == NULL \n");
        *frontier = copy_node(to_add, heuristic);
        printf("Returned \n");
        (*frontier)->next = NULL;
        (*frontier)->parent = NULL;

        return *frontier;
    }
    else
    {
        printf("In current != NULL \n");

        if ((*frontier)->parent = NULL && (*frontier)->next == NULL)//only one Node
        {
            if(to_add->f <= (*frontier)->f)
            {
                temp = copy_node(to_add, heuristic);
                temp->next = *frontier;
                (*frontier)->parent = temp;
                *frontier = temp;
                return *frontier;
            }
            else
            {
                temp = copy_node(to_add, heuristic);
                (*frontier)->next = temp;
                temp->parent = *frontier;
                temp->next = NULL;
                return *frontier;
            }
        }

        while ((*frontier)->next != NULL && to_add->f > (*frontier)->f)
        {
            printf("In while loop, to_add %d > frontier %d \n", to_add->f, (*frontier)->f);
            (*frontier) = (*frontier)->next;
        }
        //should be at last node
        if ((*frontier)->f < to_add->f)//last node is still bigger in f value than to_add
        {
            printf("In while loop, to_add %d > frontier %d \n", to_add->f, (*frontier)->f);
            temp = copy_node(to_add, heuristic);
            temp->next = (*frontier);
            temp->parent = (*frontier)->parent;
            (*frontier)->parent->next = temp;
            (*frontier)->parent = temp;
            return current;
        }
        else
        {
            temp = copy_node(to_add, heuristic);
            temp->next = *frontier;
            if ((*frontier)->parent == NULL)
            {
                temp->parent = NULL;
                (*frontier)->parent = temp;
                current = temp;
                return current;
            }
            else
            {
                temp->parent = (*frontier)->parent;
                (*frontier)->parent = temp;
                return current;
            }
        }
    }
    printf("Error...\n");
}

int search_reached(Node * reached, Node * compare)//Searches through reached list to see if the given state is already present
{
    Node * current = reached;
    int match = 0;
    printf("In search_reached \n");
    while (current != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (current->state[i][j] == compare->state[i][j])
                {
                    match++;
                }
            }
        }
        if (match == 9)
        {
            return current->f;
        }
        current = current->next;
        match = 0;
    }
    return -1;
}

Node* addReached(Node * reached, Node * to_add, int heuristic)
{
    Node * added = reached;
    printf("In addReached \n");
    if (added == NULL)
    {
        //printf("addReached: If \n");
        reached = copy_node(to_add, heuristic);
        reached->next = NULL;
        reached->parent = NULL;
        return reached;
    }
    else
    {

        while (added->next != NULL)
        {
            added = added->next;
        }
        added->next = copy_node(to_add, heuristic);
        added->next->parent = added;
        added->next->next = NULL;
        return reached;
    }

    printf("Error...\n");
}

Node* action_U (Node * current, int row, int col, int heuristic)//Moves b up
{
    int val = 0;
    Node * new_state = NULL;
    new_state = malloc(sizeof(Node));
    printf("In U: Blank space is at [%d][%d] \n", row, col);
    create_child(current, new_state, heuristic);//creates exact copy of parent
    new_state->parent = current;//updates parent of new_state
    val = new_state->state[row - 1][col];
    new_state->state[row - 1][col] = 9;
    new_state->state[row][col] = val;
    new_state->f = calc_f(new_state, heuristic);
    print_state(new_state);
    return new_state;
}

Node* action_D (Node * current, int row, int col, int heuristic)//Moves b down
{
    int val = 0;
    Node * new_state = NULL;
    new_state = malloc(sizeof(Node));
    printf("In D: Blank space is at [%d][%d] \n", row, col);
    create_child(current, new_state, heuristic);//creates exact copy of parent
    new_state->parent = current;//updates parent of new_state
    val = new_state->state[row + 1][col];
    new_state->state[row + 1][col] = 9;
    new_state->state[row][col] = val;
    new_state->f = calc_f(new_state, heuristic);
    print_state(new_state);

    return new_state;
}

Node* action_R (Node * current, int row, int col, int heuristic)//Moves b right
{
    int val = 0;
    Node * new_state = NULL;
    new_state = malloc(sizeof(Node));
    printf("In R: Blank space is at [%d][%d] \n", row, col);
    create_child(current, new_state, heuristic);//creates exact copy of parent
    new_state->parent = current;//updates parent of new_state
    val = new_state->state[row][col + 1];
    new_state->state[row][col + 1] = 9;
    new_state->state[row][col] = val;
    new_state->f = calc_f(new_state, heuristic);
    print_state(new_state);
    return new_state;
}

Node* action_L (Node * current, int row, int col, int heuristic)//Moves b left
{
    int val = 0;
    Node * new_state = NULL;
    new_state = malloc(sizeof(Node));
    printf("In L: Blank space is at [%d][%d] \n", row, col);
    create_child(current, new_state, heuristic);//creates exact copy of parent
    new_state->parent = current;//updates parent of new_state
    val = new_state->state[row][col - 1];
    new_state->state[row][col - 1] = 9;
    new_state->state[row][col] = val;
    new_state->f = calc_f(new_state, heuristic);
    print_state(new_state);

    return new_state;
}

void track_b(Node * current, int * row_col)
{
    printf("In track_b \n");
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if(current->state[i][j] == 9)
            {
                row_col[0] = i;
                row_col[1] = j;
            }
        }
    }
}

Node * expand (Node * current, Node * frontier, Node * reached, int heuristic)//Priority Queue
{
    Node * R = NULL;
    Node * L = NULL;
    Node * U = NULL;
    Node * D = NULL;
    int in_reached;
    int row_col[2];
    track_b(current, row_col);
    int row = row_col[0];
    int col = row_col[1];
    printf("In expand \n");
    printf("Row %d col %d \n", row, col);

   if(row == 0 && col == 0)//b is at [0][0]
   {
       R = action_R(current, row, col, heuristic);//expands to create a new node for state: move b to Right
       D = action_D(current, row, col, heuristic);//expands to create a new node for state: move b to Down
       printf("Result: \n");
       print_state(R);//test
       printf("R f(n) is: %d\n\n", R->f);//test
       print_state(D);//test
       printf("D f(n) is: %d\n\n", D->f);//test
   }
   else if(row == 0 && col == 1)
   {
       R = action_R(current, row, col, heuristic);
       L = action_L(current, row, col, heuristic);
       D = action_D(current, row, col, heuristic);
       printf("Result: \n");
       print_state(R);
       printf("R f(n) is: %d\n\n", R->f);
       print_state(D);
       printf("D f(n) is: %d\n\n", D->f);
       print_state(L);
       printf("L f(n) is: %d\n\n", L->f);
   }
   else if(row == 0 && col == 2)
   {
       L = action_L(current, row, col, heuristic);
       D = action_D(current, row, col, heuristic);
       printf("Result: \n");
       print_state(D);
       printf("D f(n) is: %d\n\n", D->f);
       print_state(L);
       printf("L f(n) is: %d\n\n", L->f);
   }
   else if(row == 1 && col == 0)
   {
       R = action_R(current, row, col, heuristic);
       D = action_D(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
       printf("Result: \n");
       print_state(R);
       printf("R f(n) is: %d\n\n", R->f);
       print_state(D);
       printf("D f(n) is: %d\n\n", D->f);
       print_state(U);
       printf("U f(n) is: %d\n", U->f);
   }
   else if(row == 1 && col == 1)
   {
       R = action_R(current, row, col, heuristic);
       L = action_L(current, row, col, heuristic);
       D = action_D(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
       printf("Result: \n");
       print_state(R);
       printf("R f(n) is: %d\n\n", R->f);
       print_state(D);
       printf("D f(n) is: %d\n\n", D->f);
       print_state(L);
       printf("L f(n) is: %d\n\n", L->f);
       print_state(U);
       printf("U f(n) is: %d\n\n", U->f);
   }
   else if(row == 1 && col == 2)
   {
       L = action_L(current, row, col, heuristic);
       D = action_D(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
       printf("Result: \n");
       print_state(U);
       printf("U f(n) is: %d\n\n", U->f);
       print_state(D);
       printf("D f(n) is: %d\n\n", D->f);
       print_state(L);
       printf("L f(n) is: %d\n\n", L->f);
   }
   else if(row == 2 && col == 0)
   {
       R = action_R(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
       printf("Result: \n");
       print_state(R);
       printf("R f(n) is: %d\n\n", R->f);
       print_state(U);
       printf("U f(n) is: %d\n\n", U->f);
   }
   else if(row == 2 && col == 1)
   {
       R = action_R(current, row, col, heuristic);
       L = action_L(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
       printf("Result: \n");
       print_state(R);
       printf("R f(n) is: %d\n\n", R->f);
       print_state(U);
       printf("U f(n) is: %d\n\n", U->f);
       print_state(L);
       printf("L f(n) is: %d\n\n", L->f);
   }
   else if(row == 2 && col == 2)
   {
       L = action_L(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
       printf("Result: \n");
       print_state(L);
       printf("L f(n) is: %d\n\n", L->f);
       print_state(U);
       printf("U f(n) is: %d\n\n", U->f);
   }
   printf("Before adding any children. Frontier: \n");
   print_queue(frontier);
   if(R != NULL)
   {
       printf("In R != NULL \n");
       in_reached = search_reached(reached, R);
       if(in_reached == -1)
       {
          reached = addReached(reached, R, heuristic);
          frontier = addFrontier2(&frontier, R, heuristic);
          printf("Added a R child. Frontier: \n");
       }
       else if(in_reached > R->f)
       {
          reached = addReached(reached, R, heuristic);
          frontier = addFrontier2(&frontier, R, heuristic);
          printf("Added a R child. Frontier: \n");
       }

       print_queue(frontier);
   }
   if (L != NULL)
   {
       printf("In L != NULL \n");
       in_reached = search_reached(reached, L);
       if(in_reached == -1)
       {
          reached = addReached(reached, L, heuristic);
          frontier = addFrontier2(&frontier, L, heuristic);
          printf("Added a L child. Frontier: \n");
       }
       else if(in_reached > L->f)
       {
          reached = addReached(reached, L, heuristic);
          frontier = addFrontier2(&frontier, L, heuristic);
          printf("Added a L child. Frontier: \n");
       }

       print_queue(frontier);
   }
   if (U != NULL)
   {
       printf("In U != NULL \n");
       in_reached = search_reached(reached, U);
       if(in_reached == -1)
       {
          reached = addReached(reached, U, heuristic);
          frontier = addFrontier2(&frontier, U, heuristic);
          printf("Added a U child. Frontier: \n");
       }
       else if(in_reached > U->f)
       {
          reached = addReached(reached, U, heuristic);
          frontier = addFrontier2(&frontier, U, heuristic);
          printf("Added a U child. Frontier: \n");
       }
       print_queue(frontier);
   }
   if (D != NULL)
   {
       printf("In D != NULL \n");
       in_reached = search_reached(reached, D);
       if(in_reached == -1)
       {
          reached = addReached(reached, D, heuristic);
          frontier = addFrontier2(&frontier, D, heuristic);
          printf("Added a D child. Frontier: \n");
       }
       else if(in_reached > D->f)
       {
          reached = addReached(reached, D, heuristic);
          frontier = addFrontier2(&frontier, D, heuristic);
          printf("Added a D child. Frontier: \n");
       }
       print_queue(frontier);
   }
   return frontier;

}

bool isGoal(Node * input)
{
    int wrong = 0;

    printf("In isGoal \n");
    if (input->state[0][0] != 1)
    {
        wrong++;
    }
    if (input->state[0][1] != 2)
    {
        wrong++;
    }
    if (input->state[0][2] != 3)
    {
        wrong++;
    }
    if (input->state[1][0] != 4)
    {
        wrong++;
    }
    if (input->state[1][1] != 5)
    {
        wrong++;
    }
    if (input->state[1][2] != 6)
    {
        wrong++;
    }
    if (input->state[2][0] != 7)
    {
        wrong++;
    }
    if (input->state[2][1] != 8)
    {
        wrong++;
    }
    if (input->state[2][2] != 9)
    {
        wrong++;
    }

    if (wrong == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int BFS(Node * ini, Node * frontier, Node * reached, int heuristic, Node initial)
{
    Node * current = NULL;
    Node * popped = NULL;
    int counter = 0;

    while (isEmpty(frontier) == false)
    {
        counter++;
        printf("isEmpty Frontier was false \n");
        popped = frontier;
        frontier = pop(&frontier);
        printf("Popped frontier: \n");
        print_state(popped);

        if (isGoal(popped) == true)
        {
            printf("Goal reached! \n");
            print_solution(popped, initial);
            return counter;
        }

        frontier = expand(popped, frontier, reached, heuristic);
        printf("Printing frontier queue: \n");
        print_queue(frontier);
        printf("Printing reached queue: \n");
        print_queue(reached);
    }

    printf("Goal was not found :( \n");
    return counter;
}

int main ()
{
    int steps = 0;
    Node initial;//initial state node created
    Node * head;//head of the search tree
    Node * frontier = NULL;//head of the frontier priority queue
    Node * reached = NULL;//head of the reached list
    int board[3][3];//sets 3x3 board to input initial state
    int heuristic = 1;//heuristic chosen
    printf("This program runs best-first search on a 8-puzzle.\n");
    printf("Initial State 1 is: 1 2 3 b 5 6 4 7 8 \n");
    head = &initial;
    board[0][0] = 1;
    board[0][1] = 2;
    board[0][2] = 3;
    board[1][0] = 9;//9 is a placeholder for b
    board[1][1] = 5;
    board[1][2] = 6;
    board[2][0] = 4;
    board[2][1] = 7;
    board[2][2] = 8;
    fill_initial(head, board, heuristic);//fills the initial state node
    print_state(head);//prints out the state in 3x3 board format
    printf("Heuristic is h%d and f(n) value is %d \n", heuristic, head->f);
    frontier = addFrontier2(&frontier, head, heuristic);
    print_queue(frontier);
    reached = addReached(reached, head, heuristic);
    steps = BFS(head, frontier, reached, heuristic, initial);
    printf("It took %d steps to find the solution \n", steps);
    free(frontier);
    free(reached);
    free(head);
    frontier = NULL;
    reached = NULL;
    printf("Initial State 1 is: 7 2 4 5 b 6 8 3 1 \n");
    head = &initial;
    board[0][0] = 7;
    board[0][1] = 2;
    board[0][2] = 4;
    board[1][0] = 5;//9 is a placeholder for b
    board[1][1] = 9;
    board[1][2] = 6;
    board[2][0] = 8;
    board[2][1] = 3;
    board[2][2] = 1;
    fill_initial(head, board, heuristic);//fills the initial state node
    print_state(head);//prints out the state in 3x3 board format
    printf("Heuristic is h%d and initial f(n) value is %d \n", heuristic, head->f);
    frontier = addFrontier2(&frontier, head, heuristic);
    print_queue(frontier);
    reached = addReached(reached, head, heuristic);
    steps = BFS(head, frontier, reached, heuristic, initial);
    printf("It took %d steps to find the solution \n", steps);
    return (EXIT_SUCCESS);
}
