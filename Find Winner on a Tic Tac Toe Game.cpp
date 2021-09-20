class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        char board[3][3];
        bool A = true;
        for(auto &vec : moves) {
            board[vec[0]][vec[1]] = A ? 'X' : 'O';
            A = !A;
        }
        
        //check row
        for(int row = 0; row<3; row++) {
            if(board[row][0] == 'X' && board[row][1] == 'X' && board[row][2] == 'X') return "A";
            if(board[row][0] == 'O' && board[row][1] == 'O' && board[row][2] == 'O') return "B";
        }
        
        //check col
        for(int col = 0; col<3; col++) {
            if(board[0][col] == 'X' && board[1][col] == 'X' && board[2][col] == 'X') return "A";
            if(board[0][col] == 'O' && board[1][col] == 'O' && board[2][col] == 'O') return "B";
        }
        
        //check diag and antidiag
        if((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
           (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
            return "A";
        
        if((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
           (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
            return "B";
        
        if(moves.size() == 9) return "Draw";
        return "Pending";
    }
};
