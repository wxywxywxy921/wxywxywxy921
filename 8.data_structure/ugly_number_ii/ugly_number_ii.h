class Solution {
public:
  /*
   * @param n an integer
   * @return the nth prime number as description.
   */
  int nthUglyNumber(int n) {
    // write your code here
        
    int idx_2 = 0;
    int idx_3 = 0;
    int idx_5 = 0;
    int i = 0;
    int temp;
        
    vector<int> res(1, 1);
        
    for(i = 1; i < n; i++)
    {
      temp = min(res[idx_2] * 2, min(res[idx_3] * 3, res[idx_5] * 5));
            
      res.push_back(temp);
            
      if(temp == res[idx_2] * 2) idx_2 ++;
      if(temp == res[idx_3] * 3) idx_3 ++;
      if(temp == res[idx_5] * 5) idx_5 ++;
    }
        
    return res[n-1];
  }
};
