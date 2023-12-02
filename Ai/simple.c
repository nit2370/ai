#include <stdio.h>

// Function to calculate the number of misplaced tiles
int misplaced_tiles(int state[3][3], int goal_state[3][3])
{
    int misplaced_count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (state[i][j] != goal_state[i][j])
            {
                misplaced_count++;
            }
        }
    }
    return misplaced_count;
}

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to get next possible states
void get_next_states(int state[3][3], int next_states[4][3][3])
{
    int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int zero_row, zero_col;

    // Find the position of the empty (0) tile
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (state[i][j] == 0)
            {
                zero_row = i;
                zero_col = j;
            }
        }
    }

    // Generate next states by swapping the empty tile with its neighbors
    for (int i = 0; i < 4; i++)
    {
        int new_row = zero_row + moves[i][0];
        int new_col = zero_col + moves[i][1];

        if (new_row >= 0 && new_row < 3 && new_col >= 0 && new_col < 3)
        {
            // Create a copy of the current state
            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    next_states[i][r][c] = state[r][c];
                }
            }

            // Swap the empty tile with the neighbor
            swap(&next_states[i][zero_row][zero_col], &next_states[i][new_row][new_col]);
        }
    }
}

int calculate_f(int state[3][3], int goal_state[3][3])
{
    return misplaced_tiles(state, goal_state);
}

int main()
{
    int initial_state[3][3];
    int goal_state[3][3];

    printf("Enter initial state:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &initial_state[i][j]);
        }
    }

    printf("Enter goal state:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &goal_state[i][j]);
        }
    }

    printf("Initial State:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", initial_state[i][j]);
        }
        printf("\n");
    }

    int initial_f = calculate_f(initial_state, goal_state);
    printf("f(x) = %d\n", initial_f);

    int next_states[4][3][3]; //4 3x3 matrixes can be stored
    get_next_states(initial_state, next_states);

    int best_f = initial_f;
    int best_index = -1;

    printf("\nBest Next State:\n");
    for (int i = 0; i < 4; i++)
    {
        int f = calculate_f(next_states[i], goal_state);
        if (f < best_f)
        {
            best_f = f;
            best_index = i;
        }
    }

    if (best_index != -1)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", next_states[best_index][i][j]);
            }
            printf("\n");
        }
        printf("f(x) of Best Next State: %d\n", best_f);
    }
    else
    {
        printf("No better state found.\n");
    }

    return 0;
}