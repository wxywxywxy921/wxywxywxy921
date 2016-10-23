struct comparator 
{
  bool operator()(int i, int j) 
    {
      return i > j;
    }
};


class Solution {
private:
  priority_queue<int, std::vector<int>, comparator> min_heap;
  int heap_size;
    
public:
  Solution(int k) {
    // initialize your data structure here.
        
    heap_size = k;
  }

  void add(int num) {
    // Write your code here
        
    if(min_heap.size() < heap_size)
    {
      min_heap.push(num);
    }
    else
    {
      if(num > min_heap.top())
      {
        min_heap.pop();
        min_heap.push(num);
      }
    }
  }

  vector<int> topk() {
    // Write your code here
        
    vector<int> ret;
    priority_queue<int, std::vector<int>, comparator> copy = min_heap;
    int i;
        
    while(copy.size())
    {
      ret.push_back(copy.top());
      copy.pop();
    }
        
    sort(ret.rbegin(), ret.rend());
        
    return ret;
  }
};
