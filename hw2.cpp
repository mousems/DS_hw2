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
        // full.
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
//============implete client list.==========
class ClientList{
    private:
        int count; //default 0
        int Arr[10]; // store from 1
        int Ser[10]; // store from 1
        int All[10]; // store from 1
    public:
        void Input(int Arr , int Ser , int All);
        int GetArr(int index);
        int GetSer(int index);
        int GetAll(int index);
        ClientList();
};

ClientList::ClientList(void){
    count=0;
}

void ClientList::Input(int ArrIn , int SerIn , int AllIn){
    count++;
    Arr[count] = ArrIn;
    Ser[count] = SerIn;
    All[count] = AllIn;
}
int ClientList::GetArr(int index){
    if (count<index)
    {
        return -1;
    }
    return Arr[index];
}

int ClientList::GetSer(int index){
    if (count<index)
    {
        return -1;
    }
    return Ser[index];
}

int ClientList::GetAll(int index){
    if (count<index)
    {
        return -1;
    }
    return All[index];
}
//============implete client list.==========

//==========MyString========
int main() { 
    int clients;
    cout << "Welcome , how many clients? >>";
    cin >> clients;
    cout << "OK , let's starting input every client with space separated , Ex.:1 2 3\n";

    ClientList ClientList;
    for (int i = 1; i <= clients; i++)
    {
        cout << "Please input No." << i << " Client's Arr,Ser,All: >>";
        int Arr,Ser,All;
        cin >> Arr >> Ser >> All;
        ClientList.Input(Arr,Ser,All);
    }

    cout << ClientList.GetArr(2);
    cout << ClientList.GetSer(2);
    cout << ClientList.GetAll(2);


    return 0; 
}



