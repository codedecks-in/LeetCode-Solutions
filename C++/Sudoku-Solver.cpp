class Solution {
public:

	// to check whether num is valid in that row    
    bool isRowSafe(vector<vector<char>>& board, int row, char  num)
    {
        for(int col = 0;col<9;col++)
        {
            if(board[row][col] == num)
                return true;
        }
        return false;
    }
    
    // to check whether num is valid in that column
    bool isColumnSafe(vector<vector<char>>& board, int col , char  num)
    {
         for(int row = 0; row<9; row++)
        {
            if(board[row][col] == num)
                return true;
        }
        return false;
    }
    
    // to check whether num is valid in that 3*3 matrix grid 
    bool isBoxSafe(vector<vector<char>>& board, int row1, int col1 , char  num)
    {
         for(int row = 0;row<3;row++)
            {
                for(int col = 0;col<3;col++)
                    {
                         if(board[row1 + row][col1 + col] == num)
                            return true;
                    }
            }
        
        return false;
    }
    
    bool isSafe(vector<vector<char>>& board, int row, int col , char  num)
    {
        return !isRowSafe(board,row,num) && !isColumnSafe(board, col, num) && !isBoxSafe(board, row-row%3,col-col%3,num) && board[row][col] == '.';
    }
    
    
    bool findUnassignedLocation(vector<vector<char>>& board, int &row, int &col)
    {
        for(row = 0;row<9;row++)
            {
                for(col = 0;col<9;col++)
                    {
                        if(board[row][col] == '.')
                            return true;
                    
                }
        }
        return false;
    }
    
    
    
    bool solve(vector<vector<char>>& board)
    {
        int row,col;
        if(!findUnassignedLocation(board, row, col))
                return true;
        
            for(char i = '1' ; i<='9';i++)
            {
                if(isSafe(board,row,col,i))
                {
                    board[row][col] = i;
                    
                    if(solve(board))
                        return true;
                    
                    board[row][col] = '.';
                }
            }
        
        return false;
    }
    
	/* A utility function to print grid */
	void printGrid(vector<vector<char>>& board) 
	{ 
		for (int row = 0; row < 9; row++) { 
			for (int col = 0; col < 9; col++) 
				cout << board[row][col] << " "; 
			cout << endl; 
		} 
	} 
  
    
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
        printGrid(board);
        
    }
};

