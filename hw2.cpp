#include <iostream> 
using namespace std; 

//============implete a positive int Queue.==========
class intQueue{
    private:
        int num[10];
        int front;
        int rear;
    public:
        void Queue(int i);
        int deQueue();
        intQueue();
};

intQueue::intQueue(void){
    front=0;
    rear=0;
}

void intQueue::Queue(int i){
    if(front==rear+1 || rear-10==front){
        return -1;
    }else{
        rear = (rear + 1) % 10;
        num[rear]=i;
    }
}
int intQueue::deQueue(){
    if(front==rear){
        return -1;
    }
    front = (front + 1) % 10;
    return num[front];
}

//============implete a positive int Queue.==========

//==========MyString========
int main() { 



    return 0; 
}



