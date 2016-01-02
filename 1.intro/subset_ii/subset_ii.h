using namespace std;

class Solution {
public:
  /**
   * @param S: A set of numbers.
   * @return: A list of lists. All valid subsets.
   */
    
  void do_work(const vector<int> &src, 
               int step,
               vector<int> &output, 
               vector<vector<int> > &res)
  {
    int i;
        
    for(i = step; i < src.size(); ++i)
    {
      output.push_back(src[i]);
      res.push_back(output);
            
      if(i < src.size() - 1)
      {
        do_work(src, i + 1, output, res);
      }
            
      output.pop_back();
            
      while((i < src.size() - 1)&&(src[i] == src[i+1]))
      {
        i++;
      }
    }
  }
     
  vector<vector<int> > subsetsWithDup(const vector<int> &S) {
    // write your code here
        
    vector<vector<int> > res;
    vector<int> output, input;
        
    input = S;
    sort(input.begin(), input.end());
        
    res.push_back(output);
        
    do_work(input, 0, output, res);
        
    return res;
  }
};

class Solution2 {
public:
  /**
   * @param S: A set of numbers.
   * @return: A list of lists. All valid subsets.
   */
  vector<vector<int> > subsetsWithDup(const vector<int> &S) {
    // write your code here
        
    vector<vector<int> > output(1);
    vector<int> input = S;
    int i, j, cur_size, prev_size, tmp, found_dup, start;
        
    sort(input.begin(), input.end());
        
    for(i = 0; i < input.size(); ++i)
    {
      if(i)
      {
        if(input[i] == tmp)
        {
          found_dup = 1;
        }
        else
        {
          found_dup = 0;
        }
      }
            
      tmp = input[i];
            
      cur_size = output.size();
            
      start = found_dup ? prev_size : 0;
            
      for(j = start; j < cur_size; ++j)
      {
        output.push_back(output[j]);
        output.back().push_back(input[i]);
      }
            
      prev_size = cur_size;
    }
        
    return output;
  }
};
