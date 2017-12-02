#include <iostream>
#include <vector>
#include <map>

void dfs(int grid[][5], int row, int col, int i, int j)
{
    if(i < 0 || j < 0 || i >= row || j >= col)
        return;
    if (grid[i][j] == 1)
    {
        grid[i][j] = 0;
        dfs(grid, row, col, i-1, j);
        dfs(grid, row, col, i+1, j);
        dfs(grid, row, col, i, j-1);
        dfs(grid, row, col, i, j+1);
    }

}

int numIslands(int grid[][5], int row, int col)
{
    // write your code here
    if (row == 0 || col == 0)
        return 0;

    int cnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(grid, row, col, i, j);
                cnt ++;
            }
        }
    }
    return cnt;

}


// k size()
int dfs1(int grid[][5], int row, int col, int i, int j)
{
    if (i < 0 || j < 0 || i >= row || j >= col)
        return 0;
    int cnt = 0;
    if (grid[i][j] == 1)
    {
        cnt ++;
        grid[i][j] = 0;
        cnt += dfs1(grid, row, col, i-1, j);
        cnt += dfs1(grid, row, col, i+1, j);
        cnt += dfs1(grid, row, col, i, j-1);
        cnt += dfs1(grid, row, col, i, j+1);
    }
    return cnt;

}

int numsofIsland1(int grid[][5], int row, int col, int k)
{
    // Write your code here
    if (row == 0 || col == 0)
        return 0;

    int cnt = 0;
    // for
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                if (dfs1(grid, row, col, i, j) > k)
                    cnt ++;
            }


        }
    }
    return cnt;

}

int main(int argc, char** argv)
{
    int a[5][5] ={{1, 1, 0, 0, 0},
                  {0, 1, 0, 0, 1},
                  {0, 0, 0, 1, 1},
                  {0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 1}};

//    std::cout << "Islands number: " << numIslands(a, 5, 5) << std::endl;
    std::cout << "Islands number > k: " << numsofIsland1(a, 5, 5, 2) << std::endl;
    return 0;
}
