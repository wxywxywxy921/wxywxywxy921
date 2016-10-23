struct Node
{
  string word;
  int cnt;
    
Node(string a, int b): word(a), cnt(b) {}
    
  bool operator < (const Node &p) const
    {
      return cnt > p.cnt || cnt == p.cnt && word < p.word;
    }
};

class Solution {
public:
  /**
   * @param words an array of string
   * @param k an integer
   * @return an array of string
   */
  vector<string> topKFrequentWords(vector<string>& words, int k) {
    // Write your code here
        
    map<string, int> word_cnt;
    map<string, int>::iterator it;
    vector<Node> p;
    vector<string> result;
        
    int i;
        
    if(words.empty())
      return result;
        
    for(i = 0; i < words.size(); i++)
    {
      if(word_cnt.find(words[i]) == word_cnt.end())
      {
        word_cnt[words[i]] = 1;
      }
      else
      {
        word_cnt[words[i]] ++;
      }
    }
        
    for(it = word_cnt.begin(); it != word_cnt.end(); it++)
    {
      p.push_back(Node(it->first, it->second));
    }
        
    sort(p.begin(), p.end());
        
    for(i = 0; i < k && i < p.size(); i++)
    {
      result.push_back(p[i].word);
    }
        
    return result;
  }
};
