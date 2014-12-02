#include <iostream> 
using namespace std; 

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
        void Debug_ShowStat();
        void Input(int Arr , int Ser , int All);
        void StoreAnswer(int index , int ServedIn , int DepTimeIn);
        void SetStatus(int index , int StatusIn);
        int DeQueueClient(int arrIn);
        int GetStatus(int index);
        int SearchByArr(int ArrIn);
        int GetArr(int index);
        int GetSer(int index);
        int GetAll(int index);
        void DumpAnswer(int index);
        ClientList();
};

ClientList::ClientList(void){
    count=0;
    for (int i = 1; i <=10; ++i)
    {
        Arr[i]=-1;
        Ser[i]=-1;
        All[i]=-1;
        Served[i]=-1;
        DepTime[i]=-1;
        Status[i]=-1;
    }
}
void ClientList::Debug_ShowStat(){
    cout << "======debug======\n";
    cout << "i , Served , DepTime , Status\n";
    for (int i = 1; i <= count; ++i){
        cout << i << "   " << Served[i] << "      " << DepTime[i] << "        " << Status[i] << "\n";
    }
    cout << "=================\n";
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
int ClientList::DeQueueClient(int arrIn){ //free and arr < arrIn

    for (int i = 1; i <= count; i++){
        if (Status[i]==0 && Arr[i]<=arrIn){
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
void ClientList::DumpAnswer(int index){
    if (Served[index]){
        cout << index << " Yes " << DepTime[index] << "\n";
    }else{
        cout << index << " No\n";
    }
}
//============implete client list.==========


//==========MyString========
int main() { 
    int clients;
    cout << "Welcome , how many clients? >>";
    cin >> clients;
    cout << "OK , let's starting input every client with space separated , Ex.:1 2 3\n";
    ClientList ClientList;
    for (int i = 1; i <= clients; i++){
        cout << "Please input No." << i << " Client's Arr,Ser,All: >>";
        int Arr,Ser,All;
        cin >> Arr >> Ser >> All;
        ClientList.Input(Arr,Ser,All);
    }


    // dual with first client;
    int ToQueue = 1;
    int ToQueue_Dep;
    ToQueue_Dep = ClientList.GetArr(ToQueue) + ClientList.GetSer(ToQueue);
    ClientList.SetStatus(ToQueue , 1);
    ClientList.StoreAnswer(ToQueue , 1 , ToQueue_Dep);
    while(1){
        int tmp[10];// store start from 0
        int tmp_count=0; 
        // ToQueue_Dep is 上次結束時間
        
        int newClient = ClientList.DeQueueClient(ToQueue_Dep);
        if (newClient==-1){
            break;
        }
        while(newClient != -1){
            int newClient_Arr = ClientList.GetArr(newClient); 
            int newClient_Ser = ClientList.GetSer(newClient);
            int newClient_All = ClientList.GetAll(newClient);

            if (tmp_count==0){ // queue empty

                if (newClient_Arr+newClient_All >= ToQueue_Dep){
                    // 可以等，進入 queue
                    ClientList.SetStatus(newClient ,1);
                    tmp[tmp_count] = newClient;
                    tmp_count++;

                }else{

                    // 不能等， queue 空了也無法插隊，拋棄
                    ClientList.SetStatus(newClient ,1);
                    ClientList.StoreAnswer(newClient , 0 , -1);
                }
            }else{
                int newClient_predict_start=ToQueue_Dep; // queue 裡面的人都完成 是幾時
                for (int i = 0; i < tmp_count; ++i){
                    newClient_predict_start+=ClientList.GetSer(tmp[i]);
                }

                if (newClient_predict_start - newClient_Arr < newClient_All){

                    // 可以等，進入 queue
                    // 要等 queue 裡面的人都完成
                    ClientList.SetStatus(newClient ,1);
                    tmp[tmp_count] = newClient;
                    tmp_count++;


                }else{

                    // 不能等，看看能不能插隊，要先判斷 EndOne 的資訊
                    int EndOneWhenStart=ToQueue_Dep; // EndOne 預計幾時輪到他
                    // 上次結束時間加上前面所有人的服務時間
                    for (int i = 0; i < tmp_count-1; i++){
                        EndOneWhenStart += ClientList.GetSer(tmp[i]);
                    }

                    int EndOneWillWait=EndOneWhenStart-ClientList.GetArr(tmp[tmp_count-1]); 
                    // EndOne 原本預計會等多久

                    if (EndOneWillWait-newClient_Ser >= 0){

                        // EndOne 可以忍受插隊後的等待
                        // => 原本預計需要等多久，大於newClient 的 ser time
                        // 插隊
                        // newClient 插在 EndOne 之前
                        ClientList.SetStatus(newClient ,1);
                        tmp[tmp_count]=tmp[tmp_count-1];
                        tmp[tmp_count-1]=newClient;
                        tmp_count++;


                    }else{

                        // 不能忍受，無法插隊，GG
                        ClientList.SetStatus(newClient ,1);
                        ClientList.StoreAnswer(newClient , 0 , -1);

                    }
                }

            }
            newClient = ClientList.DeQueueClient(ToQueue_Dep);

        }

        // 清除 Queue，獲得新的ToQueue_Dep

        for (int i = 0; i < tmp_count; ++i){
            ToQueue_Dep += ClientList.GetSer(tmp[i]);
            ClientList.StoreAnswer(tmp[i] ,1 ,ToQueue_Dep);
            //cout << tmp[i] << "完成了！結束時間是" << ToQueue_Dep << "\n";
        }
        tmp_count=0;


    }


    // cout << "最終結果：\n";
    for (int i = 1; i<= clients; i++){
        ClientList.DumpAnswer(i);
    }

    return 0; 
}



