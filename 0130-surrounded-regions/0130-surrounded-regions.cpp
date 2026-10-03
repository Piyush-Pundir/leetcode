class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int, int>> q;

        for (int row = 0; row < rows; row++) {
            for (int col : {0, cols - 1}) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'Y';
                    q.push({row, col});
                }
            }
        }
 
        for (int col = 0; col < cols; col++) {
            for (int row : {0, rows - 1}) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'Y';
                    q.push({row, col});
                }
            }
        }

        vector<int> deltaRow = {-1, 1, 0, 0};
        vector<int> deltaCol = {0, 0, -1, 1};

        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
 
            for (int dir = 0; dir < 4; dir++) {
                int nextRow = cell.first + deltaRow[dir];
                int nextCol = cell.second + deltaCol[dir];
 
                if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                    if (board[nextRow][nextCol] == 'O') {
                        board[nextRow][nextCol] = 'Y';
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }

        for (int row=0; row<rows; row++) {
            for (int col=0; col<cols; col++) {
                if (board[row][col]=='Y') {
                    board[row][col]='O';
                } else if (board[row][col]=='O') {
                    board[row][col]='X';
                }
            }
        }
    }
};