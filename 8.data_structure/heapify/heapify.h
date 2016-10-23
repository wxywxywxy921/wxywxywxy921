class Solution {
public:
  /**
   * @param A: Given an integer array
   * @return: void
   */
  void heapify(vector<int> &A) {
    // write your code here
        
    int i = 0;
        
    for(i = (A.size() - 1) / 2; i >= 0; i --)
    {
      helper(A, i);
    }
  }
    
  void helper(vector<int> &A, int i)
  {
    int left, right, curr;
        
    if(i >= A.size())
    {
      return;
    }
        
    curr = A[i];
        
    if(i * 2 + 1 < A.size())
    {
      left = A[i * 2 + 1];
    }
    else
    {
      left = 9999999;
    }
        
    if(i * 2 + 2 < A.size())
    {
      right = A[i * 2 + 2];
    }
    else
    {
      right = 9999999;
    }
        
    if(curr < left && curr < right)
    {
      return;
    }
    else if(left > right)
    {
      swap(A, i, 2 * i + 2);
      helper(A, 2 * i + 2);
    }
    else
    {
      swap(A, i, 2 * i + 1);
      helper(A, 2 * i + 1);
    }
  }
    
  void swap(vector<int> &A, int idx_a, int idx_b)
  {
    int temp = A[idx_a];
    A[idx_a] = A[idx_b];
    A[idx_b] = temp;
    return;
  }
};
