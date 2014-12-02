#include <iostream> 
using namespace std; 

//============implete a int Stack.==========
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
        cout << "intQueue is full.\n";
    }else{
        rear = (rear + 1) % 10;
        num[rear]=i;
    }
}
int intQueue::deQueue(){
    if(front==rear){
        cout << "intQueue is empty.\n";
        return -1;
    }
    front = (front + 1) % 10;
    return num[front];
}

//============implete a int Stack.==========

//==========MyString========
int main() { 

    intQueue A;
    A.Queue(1);
    A.Queue(5);
    A.Queue(4);
    A.Queue(3);
    cout << A.deQueue();
    A.Queue(2);
    cout << A.deQueue();
    cout << A.deQueue();
    A.Queue(1);
    A.Queue(5);
    A.Queue(4);
    A.Queue(3);
    cout << A.deQueue();
    A.Queue(2);
    cout << A.deQueue();
    cout << A.deQueue();
    A.Queue(1);
    A.Queue(5);
    A.Queue(4);
    A.Queue(3);
    cout << A.deQueue();
    A.Queue(2);
    cout << A.deQueue();
    cout << A.deQueue();
    A.Queue(1);
    A.Queue(5);
    A.Queue(4);
    A.Queue(3);
    cout << A.deQueue();
    A.Queue(2);
    cout << A.deQueue();
    cout << A.deQueue();
    return 0; 
}



