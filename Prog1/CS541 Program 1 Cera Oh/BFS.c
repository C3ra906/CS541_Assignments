//Cera Oh. Fall 2021 CS541 AI.
//Prog1 Best-First Search
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

typedef struct node{//Node representing each state
    int state[3][3];//holds 3x3 board state in integer variables, 9 = b.
    int f;//holds f(n) value
    struct node * parent;//ptr to previous node for queue and list traveling
    struct node * next;//ptr to next node in queue and list
    struct node * sol;//used to track solution path. Points to the parent node
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
}

void print_solution(Node * current, Node initial)//Prints solution for the puzzle in linear form
{
    Node * temp = current;
    int counter = 0;//counts paths

    while (temp->sol != NULL)//used to find out how many paths are in the solution
    {
        temp = temp->sol;
        counter++;
    }

    int array[counter][3][3];//stores paths in right order

    for (int c = counter - 1; c >= 0; c--)//used to store paths in the right order for printing
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
     for (int a = 0; a < 3; a++)//prints out initial state first
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

    for (int k = 0; k < counter; k++)//prints out rest of the solution paths in right order
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

void print_queue(Node * given)//Prints out queue and lists. Used for debugging
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
    child->sol = given;//keeps track of the parent node for solution
}

Node* copy_node(Node * given,int heuristic)//copies a node exactly except parent and next ptrs are sent to NULL
{
    Node * copy = NULL;
    copy = malloc(sizeof(Node));
    int f = 0;

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
    if (given == NULL)
        return true;
}

Node* pop(Node ** frontier)//pops the frontier priority queue
{
    if ((*frontier)->next == NULL)//Only one node in frontier priority queue
    {
        (*frontier) = NULL;
    }
    else
    {
        *frontier = (*frontier)->next;
        (*frontier)->parent = NULL;
    }
    return *frontier;
}

Node* addFrontier2(Node ** frontier, Node * to_add, int heuristic)//adds a node to frontier priority queue
{
    Node * hold = NULL;
    Node * temp = NULL;
    Node * current = *frontier;

    if (*frontier == NULL)
    {
        *frontier = copy_node(to_add, heuristic);
        (*frontier)->next = NULL;
        (*frontier)->parent = NULL;

        return *frontier;
    }
    else if (*frontier != NULL && (*frontier)->next == NULL)//1 node in the queue
    {
        temp = copy_node(to_add, heuristic);

        if(temp->f <= (*frontier)->f)
        {
            temp->next = *frontier;
            temp->parent = NULL;
            (*frontier)->parent = temp;
            return temp;
        }
        else
        {
            (*frontier)->next = temp;
            temp->parent = *frontier;
            temp->next = NULL;
            return *frontier;
        }
    }
    else if (*frontier != NULL && (*frontier)->next != NULL)//multiple nodes
    {
        temp = copy_node(to_add, heuristic);

        if (temp->f <= (*frontier)->f)//inserting before first node
        {
            temp->parent = NULL;
            temp->next = *frontier;
            (*frontier)->parent = temp;
            return temp;
        }
        while (temp->f > (*frontier)->f  && (*frontier)->next != NULL)
        {
            *frontier = (*frontier)->next;
        }

        if((*frontier)->next == NULL && temp->f > (*frontier)->f)//at last node and must insert at the end
        {
            (*frontier)->next = temp;
            temp->parent = *frontier;
            temp->next = NULL;
            return current;
        }
        else
        {
            temp->next = *frontier;
            temp->parent = (*frontier)->parent;
            (*frontier)->parent->next = temp;
            (*frontier)->parent = temp;
            return current;
        }
    }
    printf("Error...\n");
}

int search_reached(Node * reached, Node * compare)//Searches through reached list to see if the given state is already present
{
    Node * current = reached;
    int match = 0;

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

Node* addReached(Node * reached, Node * to_add, int heuristic)//add a node to reached list
{
    Node * added = reached;

    if (added == NULL)
    {
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

    create_child(current, new_state, heuristic);//creates exact copy of parent for updating into child state
    new_state->parent = current;
    val = new_state->state[row - 1][col];
    new_state->state[row - 1][col] = 9;
    new_state->state[row][col] = val;
    new_state->f = calc_f(new_state, heuristic);

    return new_state;
}

Node* action_D (Node * current, int row, int col, int heuristic)//Moves b down
{
    int val = 0;
    Node * new_state = NULL;
    new_state = malloc(sizeof(Node));

    create_child(current, new_state, heuristic);//creates exact copy of parent for updating into child state
    new_state->parent = current;
    val = new_state->state[row + 1][col];
    new_state->state[row + 1][col] = 9;
    new_state->state[row][col] = val;
    new_state->f = calc_f(new_state, heuristic);

    return new_state;
}

Node* action_R (Node * current, int row, int col, int heuristic)//Moves b right
{
    int val = 0;
    Node * new_state = NULL;
    new_state = malloc(sizeof(Node));

    create_child(current, new_state, heuristic);//creates exact copy of parent for updating into child state
    new_state->parent = current;
    val = new_state->state[row][col + 1];
    new_state->state[row][col + 1] = 9;
    new_state->state[row][col] = val;
    new_state->f = calc_f(new_state, heuristic);

    return new_state;
}

Node* action_L (Node * current, int row, int col, int heuristic)//Moves b left
{
    int val = 0;
    Node * new_state = NULL;
    new_state = malloc(sizeof(Node));

    create_child(current, new_state, heuristic);//creates exact copy of parent for updating
    new_state->parent = current;
    val = new_state->state[row][col - 1];
    new_state->state[row][col - 1] = 9;
    new_state->state[row][col] = val;
    new_state->f = calc_f(new_state, heuristic);

    return new_state;
}

void track_b(Node * current, int * row_col)//Tracks location of blank space, b
{
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

Node * expand (Node * current, Node * frontier, Node * reached, int heuristic)//expands current node to create frontier nodes
{
    Node * R = NULL;
    Node * L = NULL;
    Node * U = NULL;
    Node * D = NULL;
    int in_reached;
    int row_col[2];
    track_b(current, row_col);//finds b's location
    int row = row_col[0];
    int col = row_col[1];

   if(row == 0 && col == 0)//b is at [0][0]
   {
       R = action_R(current, row, col, heuristic);//expands to create a new node for state: move b to Right
       D = action_D(current, row, col, heuristic);//expands to create a new node for state: move b to Down
   }
   else if(row == 0 && col == 1)
   {
       R = action_R(current, row, col, heuristic);
       L = action_L(current, row, col, heuristic);
       D = action_D(current, row, col, heuristic);
   }
   else if(row == 0 && col == 2)
   {
       L = action_L(current, row, col, heuristic);
       D = action_D(current, row, col, heuristic);
   }
   else if(row == 1 && col == 0)
   {
       R = action_R(current, row, col, heuristic);
       D = action_D(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
   }
   else if(row == 1 && col == 1)
   {
       R = action_R(current, row, col, heuristic);
       L = action_L(current, row, col, heuristic);
       D = action_D(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
   }
   else if(row == 1 && col == 2)
   {
       L = action_L(current, row, col, heuristic);
       D = action_D(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
   }
   else if(row == 2 && col == 0)
   {
       R = action_R(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
   }
   else if(row == 2 && col == 1)
   {
       R = action_R(current, row, col, heuristic);
       L = action_L(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
   }
   else if(row == 2 && col == 2)
   {
       L = action_L(current, row, col, heuristic);
       U = action_U(current, row, col, heuristic);
   }

   if(R != NULL)//R exists
   {
       in_reached = search_reached(reached, R);//check to see if the state has been reached before
       if(in_reached == -1)//state is not in reached list
       {
          reached = addReached(reached, R, heuristic);//add to reached list
          frontier = addFrontier2(&frontier, R, heuristic);//add to frontier priority queue
       }
       else if(in_reached > R->f)//state is in reached list but current state has better f(n) value
       {
          reached = addReached(reached, R, heuristic);
          frontier = addFrontier2(&frontier, R, heuristic);
       }
   }
   if (L != NULL)
   {
       in_reached = search_reached(reached, L);
       if(in_reached == -1)
       {
          reached = addReached(reached, L, heuristic);
          frontier = addFrontier2(&frontier, L, heuristic);
       }
       else if(in_reached > L->f)
       {
          reached = addReached(reached, L, heuristic);
          frontier = addFrontier2(&frontier, L, heuristic);
       }

   }
   if (U != NULL)
   {
       in_reached = search_reached(reached, U);
       if(in_reached == -1)
       {
          reached = addReached(reached, U, heuristic);
          frontier = addFrontier2(&frontier, U, heuristic);
       }
       else if(in_reached > U->f)
       {
          reached = addReached(reached, U, heuristic);
          frontier = addFrontier2(&frontier, U, heuristic);
       }
   }
   if (D != NULL)
   {
       in_reached = search_reached(reached, D);
       if(in_reached == -1)
       {
          reached = addReached(reached, D, heuristic);
          frontier = addFrontier2(&frontier, D, heuristic);
       }
       else if(in_reached > D->f)
       {
          reached = addReached(reached, D, heuristic);
          frontier = addFrontier2(&frontier, D, heuristic);
       }
   }
   return frontier;

}

bool isGoal(Node * input)//Checks to see if goal state has been reached
{
    int wrong = 0;

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

int BFS(Node * ini, Node * frontier, Node * reached, int heuristic, Node initial)//Best-First-Search function
{
    Node * current = NULL;
    Node * popped = NULL;
    int counter = 0;//counts number of steps

    while (isEmpty(frontier) == false && counter != 10000)
    {
        counter++;
        popped = frontier;
        frontier = pop(&frontier);

        if (isGoal(popped) == true)
        {
            printf("Solution has been found: \n");
            print_solution(popped, initial);
            return counter;
        }
        frontier = expand(popped, frontier, reached, heuristic);
    }

    printf("Goal was not found\n");
    return counter;
}

int main ()
{
    int steps = 0;//Variable to save number of steps BFS func took
    Node initial;//initial state node created. Will be recycled for all 5 states.
    Node * head;//head node ptr pointing to initial node
    Node * frontier = NULL;//head of the frontier priority queue
    Node * reached = NULL;//head of the reached list
    int board[3][3];//sets 3x3 board to input initial state
    int heuristic = 3;//heuristic value chosen. Choices are 1, 2, and 3.
    printf("This program runs best-first search on a 8-puzzle.\n");
    printf("Initial State 1 is: 7 4 2 1 6 5 8 3 b \n");
    head = &initial;
    board[0][0] = 7;
    board[0][1] = 4;
    board[0][2] = 2;
    board[1][0] = 1;
    board[1][1] = 6;
    board[1][2] = 5;
    board[2][0] = 8;
    board[2][1] = 3;
    board[2][2] = 9;//9 is a placeholder for b
    fill_initial(head, board, heuristic);//fills the initial state node
    print_state(head);//prints out the state in 3x3 board format
    printf("Heuristic chosen is h(%d) and initial f(n) value is %d \n", heuristic, head->f);
    frontier = addFrontier2(&frontier, head, heuristic);//adds initial node to frontier
    reached = addReached(reached, head, heuristic);//adds initial node to reached
    steps = BFS(head, frontier, reached, heuristic, initial);//runs BFS and returns steps BFS took
    printf("It took %d steps to find the solution \n\n", steps);
    free(frontier);//frees frontier priority queue for recycling
    free(reached);//frees reached list for recycling
    free(head);//frees head pointer to initial for recycling
    frontier = NULL;//resets frontier priority queue head to point to NULL
    reached = NULL;//resets reached list head to point to NULL

    printf("Initial State 2 is: 8 1 3 4 b 2 7 6 5\n");
    head = &initial;
    board[0][0] = 8;
    board[0][1] = 1;
    board[0][2] = 3;
    board[1][0] = 4;
    board[1][1] = 9;//9 is a placeholder for b
    board[1][2] = 2;
    board[2][0] = 7;
    board[2][1] = 6;
    board[2][2] = 5;
    fill_initial(head, board, heuristic);
    print_state(head);
    printf("Heuristic is h%d and initial f(n) value is %d \n", heuristic, head->f);
    frontier = addFrontier2(&frontier, head, heuristic);
    reached = addReached(reached, head, heuristic);
    steps = BFS(head, frontier, reached, heuristic, initial);
    printf("It took %d steps to find the solution \n\n", steps);
    free(frontier);
    free(reached);
    free(head);
    frontier = NULL;
    reached = NULL;

    printf("Initial State 3 is: 2 3 8 7 1 4 b 6 5\n");
    head = &initial;
    board[0][0] = 2;
    board[0][1] = 3;
    board[0][2] = 8;
    board[1][0] = 7;
    board[1][1] = 1;
    board[1][2] = 4;
    board[2][0] = 9;//9 is a placeholder for b
    board[2][1] = 6;
    board[2][2] = 5;
    fill_initial(head, board, heuristic);//fills the initial state node
    print_state(head);//prints out the state in 3x3 board format
    printf("Heuristic is h%d and initial f(n) value is %d \n", heuristic, head->f);
    frontier = addFrontier2(&frontier, head, heuristic);
    reached = addReached(reached, head, heuristic);
    steps = BFS(head, frontier, reached, heuristic, initial);
    printf("It took %d steps to find the solution \n\n", steps);
    free(frontier);
    free(reached);
    free(head);
    frontier = NULL;
    reached = NULL;

    printf("Initial State 4 is: 7 2 4 5 b 6 8 3 1\n");
    head = &initial;
    board[0][0] = 7;
    board[0][1] = 2;
    board[0][2] = 4;
    board[1][0] = 5;
    board[1][1] = 9;//9 is a placeholder for b
    board[1][2] = 6;
    board[2][0] = 8;
    board[2][1] = 3;
    board[2][2] = 1;
    fill_initial(head, board, heuristic);
    print_state(head);
    printf("Heuristic is h%d and initial f(n) value is %d \n", heuristic, head->f);
    frontier = addFrontier2(&frontier, head, heuristic);
    reached = addReached(reached, head, heuristic);
    steps = BFS(head, frontier, reached, heuristic, initial);
    printf("It took %d steps to find the solution \n\n", steps);
    free(frontier);
    free(reached);
    free(head);
    frontier = NULL;
    reached = NULL;

    printf("Initial State 5 is: 5 2 3 7 b 8 6 1 4\n");
    head = &initial;
    board[0][0] = 5;
    board[0][1] = 2;
    board[0][2] = 3;
    board[1][0] = 7;
    board[1][1] = 9;//9 is a placeholder for b
    board[1][2] = 8;
    board[2][0] = 6;
    board[2][1] = 1;
    board[2][2] = 4;
    fill_initial(head, board, heuristic);
    print_state(head);
    printf("Heuristic is h%d and initial f(n) value is %d \n", heuristic, head->f);
    frontier = addFrontier2(&frontier, head, heuristic);
    reached = addReached(reached, head, heuristic);
    steps = BFS(head, frontier, reached, heuristic, initial);
    printf("It took %d steps to find the solution \n\n", steps);

    return (EXIT_SUCCESS);
}
