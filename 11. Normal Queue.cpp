#include<iostream>
using namespace std;

int n=100,queue[100],front=-1,rear=-1;

void enQueue(int x)
{
  if(rear==n-1)
  {
    cout<<"Overflow!!!";
  }
  else if(front==-1 && rear==-1)
  {
    front=rear=0;
    queue [rear]=x;
  }
  else
  {
    rear++;
    queue [rear]=x;
  }
}

void deQueue()
{
  if(front==-1 && rear==-1)
  {
    cout<<"Queue is empty!!!";
  }
  else if(front==rear)
  {
    cout<<queue [rear];
    front=rear-1;
  }
  else
  {
    cout<<queue[front];
    front++;
  }
}

void display()
{
  if(front==-1 && rear==-1)
  {
    cout<<"Queue is empty!!!";
  }
    else
    for(int i=front; i<=rear; i++)
    {
      cout<<queue[i]<<" ";
    }
}

int main()
{
  cout<<"Queue list: ";
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);
  display();
  cout<<"List after dequeue: ";
  deQueue();
  deQueue();
}
