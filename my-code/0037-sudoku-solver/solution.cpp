class Solution 
{
public:
	// determine the board is valid or not.
	bool isValid(vector<vector<char>>& board, int row , int column, char c) 
	{
		for (int i = 0; i < 9; ++i)
			if (board[row][i] == c) return false;
		for (int j = 0; j < 9; ++j)
			if (board[j][column] == c) return false;



        int smi=row/3*3;
        int smj=column/3*3;   
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (board[smi + i][smj + j] == c)
					return false;
		return true;
	}
	bool solve(vector<vector<char>>& board) 
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if ('.' == board[i][j]) 
				{
					for (int k = 0; k < 9; ++k)
					{
						if (isValid(board, i, j, '1' + k)) //char+int=char for 1 to 9;
						{
							board[i][j] = '1' + k;
							if (solve(board)) return true;  //imp check that agian by recursion is that ok can you solve rest suduko then if it give yes mean return true:
							else board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}
	void solveSudoku(vector<vector<char>>& board) 
	{
		solve(board);
	}
};
