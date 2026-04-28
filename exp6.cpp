#include<iostream>
using namespace std;
class Queue
{
int front,rear;
int arr[5];  
public:
Queue()
{
front = 0;
rear = -1;
}    
void insert(int x)
{
if(rear == 4)
{
cout<<"Queue full"<<endl;
}
else
{
arr[++rear]=x;
cout<<x<<"inserted into queue"<<endl;
}
}
void remove() 
{
if(front>rear)
{
cout<<"Queue Empty"<<endl;
}
else
{
cout<<arr[front++]<<"removed from queue"<<endl;
}
}
};        
int main()
{
Queue q;
q.insert(10);
q.insert(20);
q.remove();
return 0;
}
