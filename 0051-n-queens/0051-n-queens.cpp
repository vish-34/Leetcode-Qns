class Solution {
public:
    vector<vector<string>>ans;
    void backtrack(vector<string>& board, int row, vector<bool>&col, vector<bool>&diag1, vector<bool>&diag2){
        if(row == board.size()){
            ans.push_back(board);
            return;
        }

        int n = board.size();

        for(int c = 0; c < n; c++){
            if(col[c])
            continue;

            if(diag1[row - c + n -1])
            continue;

            if(diag2[row + c])
            continue;

            board[row][c] = 'Q';
            col[c] = true;
            diag1[row - c + n -1] = true;
            diag2[row + c] = true;

            backtrack(board, row + 1, col, diag1, diag2);
             board[row][c] = '.';
             col[c] = false;
            diag1[row - c + n -1] = false;
            diag2[row + c] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);

        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(board, 0, col, diag1, diag2);

        return ans;
    }
};