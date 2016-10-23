class Solution {
public:
  /**
   * @param A: an integer array.
   * @param k: a positive integer (k <= length(A))
   * @param target: a integer
   * @return a list of lists of integer 
   */
  vector<vector<int> > kSumII(vector<int> A, int k, int target) {
    // write your code here
        
    vector<vector<int> > ret;
    vector<int> curr;
        
    helper(A, k, target, ret, curr, 0);
        
    return ret;
  }
    
  void helper(vector<int> A, int k, int target, vector<vector<int> > &ret, vector<int> &curr, int idx)
  {
    if(curr.size() == k && target == 0)
    {
      ret.push_back(curr);
    }
    else if(curr.size() < k)
    {
      int i;
            
      for(i = idx; i < A.size(); i ++)
      {
        if(A[i] <= target)
        {
          curr.push_back(A[i]);
          helper(A, k, target - A[i], ret, curr, i + 1);
          curr.pop_back();
        }
      }
    }
  }
};
