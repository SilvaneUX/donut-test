class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row, int col, char val)
    {
        for(int i=0;i<9;i++)
        {
            if(i!=col && board[row][i]==val)
                return false;

            if(i!=row && board[i][col]==val)
                return false;
            
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if ((subRow != row || subCol != col) && board[subRow][subCol] == val)
            {
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(!issafe(board, i,j,board[i][j]))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
