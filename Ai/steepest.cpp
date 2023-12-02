#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the number of misplaced tiles
int misplaced_tiles(const vector<vector<int>> &state, const vector<vector<int>> &goal_state)
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
vector<vector<vector<int>>> get_next_states(const vector<vector<int>> &state)
{
    int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Define possible moves (right, left, down, up)
    int zero_row = -1, zero_col = -1;

    // Find the position of the empty (0) tile
    for (int i = 0; i < 3 && zero_row == -1; i++) // Iterate over rows
    {
        for (int j = 0; j < 3; j++) // Iterate over columns
        {
            if (state[i][j] == 0) // Check if the element is 0 (empty tile)
            {
                zero_row = i; // Store the row index of the empty tile
                zero_col = j; // Store the column index of the empty tile
                break;
            }
        }
    }

    vector<vector<vector<int>>> next_states; // Initialize vector to store next possible states

    // Generate next states by swapping the empty tile with its neighbors
    for (int i = 0; i < 4; i++) // Iterate over possible moves
    {
        int new_row = zero_row + moves[i][0]; // Calculate new row index after the move
        int new_col = zero_col + moves[i][1]; // Calculate new column index after the move

        // Check if the move is within the boundaries of the puzzle
        if (new_row >= 0 && new_row < 3 && new_col >= 0 && new_col < 3)
        {
            vector<vector<int>> new_state = state; // Create a copy of the current state
            swap(new_state[zero_row][zero_col], new_state[new_row][new_col]); // Swap the empty tile with its neighbor
            next_states.push_back(new_state); // Add the new state to the vector of next possible states
        }
    }
    return next_states; // Return the vector of next possible states
}

// Function to calculate the heuristic value f(x)
int calculate_f(const vector<vector<int>> &state, const vector<vector<int>> &goal_state, int a)
{
    return a + misplaced_tiles(state, goal_state); // Return the sum of constant a and the count of misplaced tiles
}

int main()
{
    // Define the initial and goal states
    const vector<vector<int>> initial_state = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}};

    const vector<vector<int>> goal_state = {
        {1, 2, 3},
        {4, 8, 5},
        {0, 7, 6}};

    // Set a constant value for a
    int a = 0;

    // Calculate and store the initial heuristic value
    int initial_f = calculate_f(initial_state, goal_state, a);

    // Generate next possible states
    vector<vector<vector<int>>> next_states = get_next_states(initial_state);

    // Initialize variables to store the best state and its heuristic value
    vector<vector<int>> best_state;
    int best_f = initial_f;

    // Print the initial state and its heuristic value
    cout << "Initial State:" << endl;
    for (int i = 0; i < 3; i++) // Iterate over rows
    {
        for (int j = 0; j < 3; j++) // Iterate over columns
        {
            cout << initial_state[i][j] << " "; // Print each element of the initial state
        }
        cout << endl; // Move to the next line after printing a row
    }
    cout << "f(x) = " << initial_f << endl; // Print the initial heuristic value

    // Print the possible next states and their heuristic values
    cout << "\nPossible Next Moves and their f(x) values:" << endl;
    for (size_t k = 0; k < next_states.size(); k++) // Iterate over next possible states
    {
        int f_value = calculate_f(next_states[k], goal_state, a); // Calculate the heuristic value for the current state
        cout << "f(x) = " << f_value << endl; // Print the heuristic value

        // Print the state
        for (int i = 0; i < 3; i++) // Iterate over rows
        {
            for (int j = 0; j < 3; j++) // Iterate over columns
            {
                cout << next_states[k][i][j] << " "; // Print each element of the current state
            }
            cout << endl; // Move to the next line after printing a row
        }
        cout << "----------" << endl; // Print a separator between states

        // Update the best state if a better one is found
        if (f_value < best_f)
        {
            best_f = f_value; // Update the best heuristic value
            best_state = next_states[k]; // Update the best state
        }
    }

    // Print the best state and its heuristic value if a better state is found
    if (!best_state.empty() && best_f < initial_f)
    {
        cout << "\nBetter Initial State:" << endl;
        for (int i = 0; i < 3; i++) // Iterate over rows
        {
            for (int j = 0; j < 3; j++) // Iterate over columns
            {
                cout << best_state[i][j] << " "; // Print each element of the best state
            }
            cout << endl; // Move to the next line after printing a row
        }
        cout << "f(x) of Best Next State: " << best_f << endl; // Print the best heuristic value
    }
    else
    {
        cout << "\nNo better state found." << endl; // Print a message if no better state is found
    }

    return 0;
}
