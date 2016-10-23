class Solution {
public:
  /**
   * @param start, a string
   * @param end, a string
   * @param dict, a set of string
   * @return an integer
   */
      
  int checkDiff(string A, string B)
  {
    int i;
    int ret = 0;
        
        
    for(i = 0; i < A.size(); i ++)
    {
      if(A[i] != B[i])
      {
        ret ++;
      }
    }
        
    return ret;
  }
    
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    // write your code here
        
    // [xywu] using BFS for the problem related to the shortest path
        
    unordered_map<string, int> record;
    queue<string> fifo_q;
    string temp;
    int depth = 0;
    int curr_size;
    int i, j;
        
    record[start] = 1;
    fifo_q.push(start);
        
    if(start == end)
    {
      return depth;
    }
    else
    {
      depth ++;
    }
        
    while(1)
    {
      curr_size = fifo_q.size();
            
      //printf("size=%d\n", curr_size);
            
      for(i = 0; i < curr_size; i ++)
      {
        temp = fifo_q.front();
        fifo_q.pop();
                
        if(checkDiff(temp, end) == 1)
        {
          //cout<<temp<<" "<<end<<endl;
          depth ++;
          return depth;
        }
        else
        {
          for(auto ite = dict.begin(); ite != dict.end(); ++ite)
          {
            if(record.find(*ite) == record.end()
               && checkDiff(*ite, temp) == 1)
            {
              //cout<<*ite<<endl;
              fifo_q.push(*ite);
              record[*ite] = 1;
            }
          }
        }
      }
            
      depth ++;
    }
  }
};
