#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        
        vector<vector<int> > output;
        vector<int> input;
        vector<int> record(nums.size(), 0);
        vector<int> curr;
    
        input = nums;

        sort(input.begin(), input.end());

        if(input.size())
        {
            do_work(input, output, curr, record, 0);
        }

        return output;
    }
    
    
    void do_work( vector<int> &input,
                                  vector<vector<int> > &output,
                                  vector<int> &curr,
                                  vector<int> &record,
                                  int step)
    {
      int i;

      if(step == input.size())
      {
        printf("found one\n");
        output.push_back(curr);
        return;
      }

      for(i = 0; i < input.size(); ++i)
      {
        if(i && 
           (input[i] == input[i-1] && !record[i-1]))
        {
          printf("skip one\n");
          continue;
        }

        if(!record[i])
        {
          curr.push_back(input[i]);
          printf("push: %3d @ %3d\n", input[i], step);
          record[i] = 1;
          do_work(input, output, curr, record, step+1);
          record[i] = 0;
          curr.pop_back();
        }
      }
    }
    
};
