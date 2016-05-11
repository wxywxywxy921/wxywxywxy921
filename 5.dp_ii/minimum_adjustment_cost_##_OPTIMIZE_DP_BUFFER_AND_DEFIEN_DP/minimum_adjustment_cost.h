#define MAX 100
#define MAX_VAL 0x7fff

int abs(int a)
{
  if(a >= 0)
    return a;
  else
    return -a;
}

int max(int a, int b)
{
  if(a > b)
    return a;
  else
    return b;
}

int min(int a, int b)
{
  if(a < b)
    return a;
  else
    return b;
}

class Solution {
public:
  /**
   * @param A: An integer array.
   * @param target: An integer.
   */
  int MinAdjustmentCost(vector<int> A, int target) {
    // write your code here
        
    int i, j, k;
    int range_min, range_max;
    int range_min_tmp, range_max_tmp;
    int a_size = A.size();
    short dp[2][MAX + 1];
    int book_min = MAX_VAL;
        
    if(!a_size)
      return 0;
            
    for(i = 0; i < a_size; i++)
    {
      for(j = 0; j <= MAX; j++)
      {
        dp[i%2][j] = MAX_VAL;
      }
    }
        
    for(i = 0; i <= MAX; i++)
    {
      dp[0][i] = abs(i - A[0]);
    }
        
    range_min = A[0] - target;
    range_max = A[0] + target;
            
    for(i = 1; i < a_size; i++)
    {
      range_min = max(0, range_min);
      range_max = min(MAX, range_max);
            
      for(j = 0; j <= MAX; j ++)
      {
        range_min_tmp = max((j - target), 0);
        range_max_tmp = min((j + target), MAX);
        dp[i%2][j] = MAX_VAL;
                
        for(k = range_min_tmp; k <= range_max_tmp; k++)
        {
          if(dp[(i - 1)%2][k] == MAX_VAL)
          {
            continue;
          }
                    
          if(dp[i%2][j] > abs(A[i] - j) + dp[(i - 1)%2][k])
          {
            dp[i%2][j] = abs(A[i] - j) + dp[(i - 1)%2][k];
          }
        }
      }
            
      range_min -= target;
      range_max += target;
    }
                
    for(i = 0; i <= MAX; i++)
    {
      if(book_min > dp[(a_size - 1)%2][i])
        book_min = dp[(a_size - 1)%2][i];
    }
        
    return book_min;
  }
};
