#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the number of misplaced tiles
int misplaced_tiles(vector<vector<int>> &state, vector<vector<int>> &goal_state)
{
    int misplaced_count = 0;
    for (int i = 0; i < 3; i++) // Iterate over rows
    {
        for (int j = 0; j < 3; j++) // Iterate over columns
        {
            if (state[i][j] != goal_state[i][j]) // Compare elements of state and goal_state
            {
                misplaced_count++; // Increment count for misplaced tiles
            }
        }
    }
    return misplaced_count; // Return the total count of misplaced tiles
}

// Function to generate next possible states by swapping empty tile with neighbors
void get_next_states(vector<vector<int>> &state, vector<vector<vector<int>>> &next_states)
{
    int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Define possible moves (right, left, down, up)
    int zero_row, zero_col;

    // Find the position of the empty (0) tile
    for (int i = 0; i < 3; i++) // Iterate over rows
    {
        for (int j = 0; j < 3; j++) // Iterate over columns
        {
            if (state[i][j] == 0) // Check if the element is 0 (empty tile)
            {
                zero_row = i; // Store the row index of the empty tile
                zero_col = j; // Store the column index of the empty tile
            }
        }
    }

    // Generate next states by swapping the empty tile with its neighbors
    for (int i = 0; i < 4; i++) // Iterate over possible moves
    {
        int new_row = zero_row + moves[i][0]; // Calculate new row index after the move
        int new_col = zero_col + moves[i][1]; // Calculate new column index after the move

        // Check if the move is within the boundaries of the puzzle
        if (new_row >= 0 && new_row < 3 && new_col >= 0 && new_col < 3)
        {
            // Create a copy of the current state
            vector<vector<int>> new_state = state;

            // Swap the empty tile with the neighbor
            swap(new_state[zero_row][zero_col], new_state[new_row][new_col]);

            next_states.push_back(new_state); // Add the new state to the vector of next possible states
        }
    }
}

// Function to calculate the heuristic value f(x)
int calculate_f(vector<vector<int>> &state, vector<vector<int>> &goal_state)
{
    return misplaced_tiles(state, goal_state); // Return the count of misplaced tiles as the heuristic value
}

int main()
{
    vector<vector<int>> initial_state = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}};

    vector<vector<int>> goal_state = {
        {1, 2, 3},
        {4, 8, 5},
        {0, 7, 6}};

    cout << "Initial State:" << endl;
    for (int i = 0; i < 3; i++) // Iterate over rows
    {
        for (int j = 0; j < 3; j++) // Iterate over columns
        {
            cout << initial_state[i][j] << " "; // Print each element of the initial state
        }
        cout << endl; // Move to the next line after printing a row
    }

    int initial_f = calculate_f(initial_state, goal_state); // Calculate and store the initial heuristic value
    cout << "f(x) = " << initial_f << endl; // Print the initial heuristic value

    vector<vector<vector<int>>> next_states; // Initialize vector to store next possible states
    get_next_states(initial_state, next_states); // Generate next possible states

    int best_f = initial_f; // Initialize variable to store the best heuristic value
    int best_index = -1; // Initialize variable to store the index of the best state

    cout << "\nBest Next State:" << endl;
    for (int i = 0; i < next_states.size(); i++) // Iterate over next possible states
    {
        int f = calculate_f(next_states[i], goal_state); // Calculate the heuristic value for the current state

        // Update the best state if a better one is found
        if (f < best_f)
        {
            best_f = f; // Update the best heuristic value
            best_index = i; // Update the index of the best state
        }
    }

    if (best_index != -1) // Check if a better state is found
    {
        for (int i = 0; i < 3; i++) // Iterate over rows
        {
            for (int j = 0; j < 3; j++) // Iterate over columns
            {
                cout << next_states[best_index][i][j] << " "; // Print each element of the best state
            }
            cout << endl; // Move to the next line after printing a row
        }
        cout << "f(x) of Best Next State: " << best_f << endl; // Print the best heuristic value
    }
    else
    {
        cout << "No better state found." << endl; // Print a message if no better state is found
    }

    return 0;
}
