class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isValid = true;
        
        for (int i = 0; i < 9 && isValid; ++i) {
            for (int j = 0; j < 9 && isValid; ++j) {
                if (board[i][j] != '.') {
                    for (int k = j + 1; k < 9 && isValid; ++k) {
                        if (board[i][j] == board[i][k]) {
                            isValid = false;
                            break;
                        }
                    }
                    
                    for (int l = i + 1; l < 9 && isValid; ++l) {
                        if (board[i][j] == board[l][j]) {
                            isValid = false;
                            break;
                        }
                    }
                    
                    int m = (i / 3) * 3;
                    int n = (j / 3) * 3;
                    
                    for (int p = m; p <= m + 2 && isValid; ++p) {
                        for (int q = n; q <= n + 2 && isValid; ++q) {
                            if (p != i && q != j) {
                                if (board[p][q] == board[i][j]) {
                                    isValid = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        return isValid;
    }
};
