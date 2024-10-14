class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> v;
        bool flip = false;

        // Convert the 2D board into a 1D array
        for (int i = n - 1; i >= 0; i--) {
            if (flip) {
                for (int j = n - 1; j >= 0; j--) {
                    v.push_back(board[i][j]);
                }
            } else {
                for (int j = 0; j < n; j++) {
                    v.push_back(board[i][j]);
                }
            }
            flip = !flip;
        }

        // BFS to find the shortest path
        queue<pair<int, int>> q; // pair of (current position, moves count)
        vector<bool> visited(n * n, false);
        q.push({0, 0}); // start at position 0 with 0 moves
        visited[0] = true;

        while (!q.empty()) {
            auto [pos, moves] = q.front();
            q.pop();

            if (pos == n * n - 1) {
                return moves; // Reached the last cell
            }

            for (int i = 1; i <= 6; i++) { // Simulate dice roll
                int next_pos = pos + i;
                if (next_pos >= n * n) {
                    continue; // Out of bounds
                }

                // Check for snake or ladder
                if (v[next_pos] != -1) {
                    next_pos = v[next_pos] - 1; // Move to the destination of ladder/snake
                }

                if (!visited[next_pos]) {
                    visited[next_pos] = true;
                    q.push({next_pos, moves + 1});
                }
            }
        }

        return -1; // If no solution is found
    }
};
