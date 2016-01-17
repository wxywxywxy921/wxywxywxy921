class Solution {
public:
  /**
   * @param matrix: A list of lists of integers
   * @param target: An integer you want to search in matrix
   * @return: An integer indicate the total occurrence of target in the given matrix
   */
  int searchMatrix(vector<vector<int> > &matrix, int target) {
    // write your code here
        
    int x, y, occur;
        
    x = 0;
    y = matrix.size() - 1;
    occur = 0;
        
    if(!matrix.size())
      return occur;
        
    while(1)
    {
      if(matrix.at(y).at(x) < target)
      {
        if(x < matrix.front().size() - 1)
          x ++;
        else 
          break;
      }
      else if(matrix.at(y).at(x) > target)
      {
        if(y > 0)
          y --;
        else
          break;
      }
      else
      {
        occur ++;
                
        if(x < matrix.front().size() - 1)
          x ++;
        else 
          break;
      }
    }
        
    return occur;
  }
};
