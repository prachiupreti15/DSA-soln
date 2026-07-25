class Solution {
public:

    vector<int> dir = {-1, 0, 1, 0, -1};

    void dfs(vector<vector<char>>& board, int i, int j) {

        int m = board.size();
        int n = board[0].size();

        board[i][j] = 'A';

        for (int k = 0; k < 4; k++) {
            int nr = i + dir[k];
            int nc = j + dir[k + 1];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                board[nr][nc] == 'O') {

                dfs(board, nr, nc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
};