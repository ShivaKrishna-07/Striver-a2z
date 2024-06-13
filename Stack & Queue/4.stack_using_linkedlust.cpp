

// GFG - Implement queue using linkedlist

void stackPush(int x) {
    QueueNode *Temp;
    Temp = new QueueNode(value); 
    if (Temp == nullptr)  //When heap exhausted 
        return -1;
    else
    {
        if (Front == nullptr)
        {
            Front = Temp;
            Rare = Temp;
        } 
        else
        {
            Rare->next = Temp;
            Rare = Temp;
        }
    } 
  }
  int stackPop() {
    if (Front == nullptr) 
        return -1;
    else
    { 
        QueueNode *Temp = Front;
        Front = Front->next;
        delete Temp;
        size--;
    }  
  }