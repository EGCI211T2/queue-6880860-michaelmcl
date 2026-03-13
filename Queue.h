
#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};



void Queue::enqueue(int x){

  NodePtr new_node= new NODE(x);
if(new_node){ 
    /* Add head and tail for me please */
       if(size==0) headPtr=new_node;
       else tailPtr->set_next(new_node);
       tailPtr=new_node;
       size++;
 }
}



int Queue::dequeue(){
  if(size>0){
     NodePtr t=headPtr;
     headPtr=headPtr->get_next();
     int v=t->get_value(); 
     if(headPtr==NULL) tailPtr=NULL;
     delete t;
     --size;
     return v;

  }
  cout<<"Empty queue"<<endl;
  return -1;
}



Queue::Queue(){
    //initialize Queue
    size=0;
    headPtr=NULL;
    tailPtr=NULL;
}



Queue::~Queue(){
    cout<<"Clearing queue"<<endl;
    while(size>0)
    {
      cout<<"dequeing";
      dequeue();
    }
}


#endif
