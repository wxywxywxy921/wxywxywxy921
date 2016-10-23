class Solution {
public:
  /**
   * @param nums: A list of integers
   * @return an integer
   */
  int longestConsecutive(vector<int> &num) {
    // write you code here
        
    unordered_map<int, int> record;
    vector<bool> visit(num.size(), false);
        
    int length = 0;
    int max_length = 0;
    int i;
    int temp;
        
    if(num.empty())
    {
      return length;
    }
        
    for(i = 0; i < num.size(); i++)
    {
      if(record.find(num[i]) == record.end())
      {
        record[num[i]] = i;
      }
    }
        
    for(i = 0; i < num.size(); i++)
    {
      if(visit[i])
      {
        continue;
      }
      else
      {   
        temp = num[i];
        length = 1;
                
        while(record.find(--temp) != record.end())
        {
          length ++;
          visit[record[temp]] = true;
        }
                
        temp = num[i];
                
        while(record.find(++temp) != record.end())
        {
          length ++;
          visit[record[temp]] = true;
        }
                
        if(length > max_length)
        {
          max_length = length;
        }
      }
    }
        
    return max_length;
  }
};
