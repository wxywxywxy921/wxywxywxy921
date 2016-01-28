#define MAX 999999

class Solution {
public:
  /**
   * @param obstacleGrid: A list of lists of integers
   * @return: An integer
   */ 
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    // write your code here
        
    int m = obstacleGrid.size();
    int n = obstacleGrid.at(0).size();
        
    int a[m][n];
        
    int i,j;
        
    for(i = 0; i < m; i++)
    {
      for(j = 0; j < n; j++)
      {
        if(obstacleGrid.at(i).at(j) == 1)
        {
          a[i][j] = 0;
        }
        else
        {
          a[i][j] = MAX;
        }
      }
    }
        
    for(i = 1; i < m; i++)
    {
      if(a[i][0] == MAX)
      {
        if(a[i - 1][0] != 0)
        {
          a[i][0] = 1;
        }
        else
        {
          a[i][0] = 0;
        }
      }
    }
        
    for(i = 1; i < n; i++)
    {
      if(a[0][i] == MAX)
      {
        if(a[0][i - 1] != 0)
        {
          a[0][i] = 1;
        }
        else
        {
          a[0][i] = 0;
        }
      }
    }
        
    a[0][0] = 1;
        
    for(i = 1; i < m; i++)
    {
      for(j = 1; j < n; j++)
      {
        if(a[i][j])
        {
          a[i][j] = a[i-1][j] + a[i][j-1];
        }
      }
    }
        
    return a[m-1][n-1];
  }
};
