#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  /**
   * @param nums: A list of integers.
   * @return: A list of permutations.
   */
  vector<vector<int> > permute(vector<int> nums) {
    // write your code here
        
    vector<vector<int> > output;
    vector<int> input;
    vector<int> cur;
    vector<int> record(nums.size(), 0);
        
    input = nums;
        
    sort(input.begin(), input.end());
        
    if(input.size())
    {
      do_work(input, cur, output, record, 0); 
    }
        
    return output;
  }
    
  void do_work(vector<int> &input, 
               vector<int> &cur, 
               vector<vector<int> > &output,
               vector<int> &record,
               int step)
  {
    int i;
        
    if(step == input.size())
    {
      output.push_back(cur);
      return;
    }
        
    for(i = 0; i < input.size(); i++)
    {
      if(!record[i])
      {
        record[i] = 1;
        cur.push_back(input[i]);
        do_work(input, cur, output, record, step+1);
        cur.pop_back();
        record[i] = 0;
      }
    }
  }
};
