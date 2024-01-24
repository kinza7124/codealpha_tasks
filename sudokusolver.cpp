#include<iostream>
using namespace std;
void print (int arr[9][9])
{
	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			cout<<arr[i][j]<<" ";

			
		}
		cout<<endl;
	}
}
bool issafe(int grid[9][9],int row, int cols, int num)
{
	for (int x=0;x<=8;x++)
	{
		if (grid[row][x]==num)
		{
			return false;	
		}
	}
	for (int x=0;x<=8;x++)
	{
		if (grid[x][cols]==num)
		{
			return false;	
		}
	}
	int startrow=row-row%3;
	int startcol=cols-cols%3;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			if (grid[i+startrow][j+startcol]==num)
			{
				return false;	
			}	
		}
	}
	return true;
}

bool solveSudoku(int grid[9][9],int row,int cols)
{
	
    if (row ==8 && cols == 9)
    {
	
        return true;
    }
 
    if (cols == 9) {
        row++;
        cols = 0;
    }
    if (grid[row][cols] > 0)
        return solveSudoku(grid, row, cols + 1);
         for (int num = 1; num <= 9; num++) 
    {
      
        if (issafe(grid, row, cols, num)) 
        {
             
            grid[row][cols] = num;
           
          
            if (solveSudoku(grid, row, cols + 1))
                return true;
        }
       
    
        grid[row][cols] = 0;
    }
    return false;
}

int main()
{
    // 0 means unassigned cells
    int grid[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
 
    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        cout << "no solution  exists " << endl;
 
    return 0;
  
}
