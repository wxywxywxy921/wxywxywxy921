#define MAX 99999

class Solution {
public:
  /**
   * @param n, m: positive integer (1 <= n ,m <= 100)
   * @return an integer
   */
  int uniquePaths(int m, int n) {
    // wirte your code here
        
    int a[m][n];
    int i = 0;
    int j = 0;
        
    for(i = 0; i < m; i++)
    {
      for(j = 0; j < n; j++)
      {
        a[i][j] = MAX;
      }
    }
        
    for(i = 0; i < m; i++)
    {
      a[i][0] = 1;
    }
        
    for(i = 0; i < n; i++)
    {
      a[0][i] = 1;
    }
        
    for(i = 1; i < m; i++)
    {
      for(j = 1; j < n; j++)
      {
        a[i][j] = a[i][j - 1] + a[i - 1][j];
      }
    }
        
    return a[m -1][n - 1];
  }
};
