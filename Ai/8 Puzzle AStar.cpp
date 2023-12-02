#include <bits/stdc++.h>
using namespace std;

void findZero(vector<vector<int>> board, int &x, int &y)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == 0)
            {
                x = i;
                y = j;
                return;
            }
        }
    }
}

void printBoard(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isGoalState(vector<vector<int>> &board, vector<vector<int>> &goal)
{
    return board == goal;
}

int findMisplacedTiles(vector<vector<int>> &board, vector<vector<int>> &goal)
{
    int count = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] != goal[i][j])
                count++;
        }
    }
    return count;
}


void aStar(vector<vector<int>> &board, vector<vector<int>> &goal, int depth, int x, int y)
{
priority_queue<
    pair<pair<int, int>, vector<vector<int>>>, // Element type
    vector<pair<pair<int, int>, vector<vector<int>>>>, // Container type
    greater<pair<pair<int, int>, vector<vector<int>>>>> // Comparison function
    pq;

    //The inner pair represents the cost information (g + h and g values), 
    //and the 2D vector represents the state of the puzzle.

int g = depth; // Initialize the cost value g with the current depth
int h = findMisplacedTiles(board, goal); // Calculate the heuristic cost h using the misplaced tiles function
pq.push({{(g + h), g}, board}); // Push the initial state with its cost information into the priority queue

while (!pq.empty()) // Loop until the priority queue is empty
{
    vector<vector<int>> curr = pq.top().second; // Retrieve the current state from the top of the priority queue
    int curr_d = pq.top().first.second; // Extract the g value from the cost information
    pq.pop(); // Remove the current state from the priority queue

    printBoard(curr); // Print the current state

    int x, y;
    findZero(curr, x, y); // Find the position of the zero tile in the current state

    if (isGoalState(curr, goal)) // Check if the current state is the goal state
    {
        cout << "Goal State Reached" << endl; // Print a message if the goal state is reached
        return; // Return from the function
    }

    int dx[] = {0, 0, -1, 1}; // Offsets for moving in the x direction....dx[0] = 0, dy[0] = 1: Move right (no change in x, increase y by 1)
    int dy[] = {1, -1, 0, 0}; // Offsets for moving in the y direction

    for (int i = 0; i < 4; i++) // Loop through possible moves (up, down, left, right)
    {
        int newX = x + dx[i]; // Calculate the new x position after the move
        int newY = y + dy[i]; // Calculate the new y position after the move

        if (newX >= 0 && newX < curr.size() && newY >= 0 && newY < curr.size()) // Check if the move is within the puzzle boundaries
        {
            swap(curr[x][y], curr[newX][newY]); // Perform the move by swapping the zero tile with its neighbor
            int curr_h = findMisplacedTiles(curr, goal); // Calculate the new heuristic cost
            pq.push({{(curr_d + curr_h), curr_d}, curr}); // Push the new state with its cost information into the priority queue
            swap(curr[x][y], curr[newX][newY]); // Undo the move to backtrack for the next iteration
        }
    }
}

// The function returns if the goal state is not reached after exploring all possible states
return;
}

int main()
{
    vector<vector<int>> initial = {
        {2, 8, 3},
        {1, 6, 4},
        {7, 5, 0}};
    vector<vector<int>> goal = {
        {1, 2, 3},
        {8, 0, 4},
        {7, 6, 5}};
    int x, y;
    findZero(initial, x, y);

    aStar(initial, goal, 0, x, y);
    return 0;
}

// Implementation:
// Initialize a priority queue to store states with their cost information.
// Calculate the heuristic cost (h) using the findMisplacedTiles function.
// Push the initial state and its cost into the priority queue.
// Iterate while the priority queue is not empty:
// Pop the state with the lowest cost from the priority queue.
// Print the current state.
// Check if the current state is the goal state. If yes, print a message and return.
// Generate successor states by moving the zero tile in all possible directions.
// Calculate the cost of each successor state and push it into the priority queue.
// Continue until the goal state is reached or all possible states are explored.