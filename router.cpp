#include<iostream>
using namespace std;
# include <queue>
class Node{
    public:
    int data;
    int*next;
    
    Node(int d){
        this->data=d;
        next=NULL; //Here instead of a node we have a pointer to the final output address i.e arr[address port]
    }
};
pair<int,int> start(int n,int m,int*arr){
    int d;
    cout<<"Enter the data of the data packet: ";  //DATA PACKET INPUT
    cin>>d;
    
    int o;
    cout<<"Enter the output port for this data packet: ";  //REQUIRED OUTPUT PORT INPUT
    cin>>o;
    if(o>=m){
        cout<<"Incorrect outport port!"; //If the port doesn't exist then -1
        return{d,-1};
    }
    return {d,o};

}
bool check(Node*&head,int arr[],queue<int>&output,int m){
    if(arr[output.front()]==-1){
        head->next=&arr[output.front()]; 
        
        return true;
    }
   
    return false;
}
void final(Node*&head,int arr[],queue<int>&output,int m){
    if(arr[output.front()]==-1){
        arr[output.front()]=head->data;
    }
    return;
}
int main(){
    int n,m;
    cout<<"Enter the no. of data packets: "; //Total data packets
    cin>>n;
    cout<<endl<<"Enter the total no. of output ports that exist: "; //Total output ports
    cin>>m;
    int *arr=new int[m]; //initial value of ports is -1(no incoming data packet at the beginning)
    for(int i=0;i<m;i++){
        arr[i]=-1;
    }
    queue<Node*>temp; //temp queue of data packets  for flow 
    queue<int>outputs; //output ports of data packets arranged on the basis of priority
    cout<<endl<<"the output ports which are available: "; //Available ports
    for(int i=0;i<m;i++){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    while(n>0){
        pair<int,int>p=start(n,m,arr);  //Start input of each data packet
        if(p.second==-1){
            return 0; //break if output port is wrong
        }
        Node*packet=new Node(p.first); //create a packet
        temp.push(packet);  
        outputs.push(p.second);  //create a queue of output ports in order of each packet
        n--;
    }
    queue<Node*>flow;
    while(!temp.empty()){ //one by one iteration of temp queue of packets
        Node*head=temp.front();
        if(check(head,arr,outputs,m)){ //if packet doesn't exist in output port 
            cout<<"OK!"<<endl;
        }
        else{
            cout<<"Already occupied!"<<endl; //Already some packet is there on the output port
        }
        flow.push(head);
        final(head,arr,outputs,m);  //fially add in the outport port
        outputs.pop();
        temp.pop();
    }
    for(int i=0;i<m;i++){ //Packets and address as seen by any user
        cout<<"Data packet: "<<arr[i]<<", Output port: "<<i<<endl;
    }
   

    while(!flow.empty()){
        cout<<"Data: "<<flow.front()->data<<" "<<flow.front()->next<<endl; //Packets and Actual address 
        flow.pop();
    }
    cout<<endl<<"Processing done!!!"<<endl;
    // Call Stack:-

    // main()---Start
    //start()---->INPUT
    //check()----check for congestion
    //final()----finally transfer the packet


}