#include <iostream> 
using namespace std; 

//============implete a positive int Queue. with cut line==========
class intQueue{
    private:
        int num[10];
        int front;
        int rear;
    public:
        void Queue(int i);
        void QueueCut(int i);
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
void intQueue::QueueCut(int i){
    if(front==rear+1 || rear-10==front){
        // full.
    }else{
        num[front] = i;
        front = front - 1;
        if (front<0){
            front+=10;
        }
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
        int Served[10]; // store from 1 , store 1 or 0
        int DepTime[10]; // store from 1
        int Status[10]; // store from 1 , 0 for free , 1 for queued
    public:
        void Input(int Arr , int Ser , int All);
        void StoreAnswer(int index , int ServedIn , int DepTimeIn);
        void SetStatus(int index , int StatusIn);
        int DeQueueClient();
        int GetStatus(int index);
        int SearchByArr(int ArrIn);
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
    Status[count] = 0;
}
void ClientList::StoreAnswer(int index , int ServedIn , int DepTimeIn){
    Served[index] = ServedIn;
    DepTime[index] = DepTimeIn;
}
void ClientList::SetStatus(int index , int StatusIn){
    Status[index] = StatusIn;
}
int ClientList::DeQueueClient(){
    for (int i = 1; i <= count; i++){
        if (Status[i]==0)
        {
            return i;
        }
    }
    return -1;
}
int ClientList::GetStatus(int index){
    if (count<index){
        return -1;
    }
    return Status[index];
}

int ClientList::GetArr(int index){
    if (count<index){
        return -1;
    }
    return Arr[index];
}

int ClientList::GetSer(int index){
    if (count<index){
        return -1;
    }
    return Ser[index];
}

int ClientList::GetAll(int index){
    if (count<index){
        return -1;
    }
    return All[index];
}

int ClientList::SearchByArr(int ArrIn){
    for (int i = 1; i <= count; ++i){
        if (GetArr(i)==ArrIn){
            return i;
        }
    }
    return -1;
}
//============implete client list.==========

//==========MyString========
int main() { 
    int clients;
    cout << "Welcome , how many clients? >>";
    cin >> clients;
    cout << "OK , let's starting input every client with space separated , Ex.:1 2 3\n";
    intQueue intQueue;
    ClientList ClientList;
    for (int i = 1; i <= clients; i++){
        cout << "Please input No." << i << " Client's Arr,Ser,All: >>";
        int Arr,Ser,All;
        cin >> Arr >> Ser >> All;
        ClientList.Input(Arr,Ser,All);
    }

    cout << ClientList.GetArr(2);
    cout << ClientList.GetSer(2);
    cout << ClientList.GetAll(2);

    ClientList.StoreAnswer(1,0,2);
    return 0; 
}



