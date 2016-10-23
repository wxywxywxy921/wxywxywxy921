struct Node
{
  int val;
  Node *next;
    
Node(int a): val(a) {};
};

class Queue {
private:    
  Node *head;
  Node *curr;
    
public:
  Queue() {
    // do initialize if necessary
    head = curr = NULL;
  }

  void enqueue(int item) {
    // Write your code here
    if(head == NULL)
    {
      head = curr = new Node(item);
      curr->next = NULL;
    }
    else
    {
      curr->next = new Node(item);
      curr = curr->next;
      curr->next = NULL;
    }
        
  }

  int dequeue() {
    // Write your code here
    int ret = 0;
        
    if(head)
    {
      Node *temp = head;
      ret = temp->val;
            
      if(head->next)
      {
        head = temp->next;
        delete[] temp;
      }
      else
      {
        delete[] head;
        head = curr = NULL;
      }
    }
        
    return ret;
  }
};
	
