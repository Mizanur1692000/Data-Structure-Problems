/*
#include <iostream>

using namespace std;

int stack[100], n=100, top=-1;

int a[5];

void push(int val){
  if(top>=n-1){
    cout<<"Stack Overflow"<<endl;
  }else{
    top++;
    stack[top]=val;
  }
}

void pop(){
  if(top<=-1){
    cout<<"Stack Underflow"<<endl;
  }else{
    cout<<"Popped element is "<<stack[top]<<endl;
    top--;
  }
}

void display(){
  if(top>=0){
    cout<<"Stack elements: ";
    for(int i=top;i>=0;i--){
      cout<<stack[i]<<" ";
      cout<<endl;
    }
  }else{
    cout<<"Stack is empty";
  }
}


int main() {
  push(5);
  push(6);
  push(9);
  cout<<endl;
  display();
  pop();
  pop();
  display();
}
*/

#include<iostream>
using namespace std;

int stack[100],top=-1,x,maxTop=100;

void push()
{
  if(top==maxTop-1)
  {
    cout<<"Over Flow!";
  }
  else
  {
    cout<<"Enter the element to push: ";
    cin>>x;
    top++;
    stack[top]=x;
  }
}

void pop()
{
  if(top==-1)
  {
    cout<<"Under Flow!";
  }
  else
  {
    cout<<endl<<"Poped element is: "<<stack[top];
    top--;
  }
}

void display()
{
  if(top==-1)
  {
    cout<<"Stack is empty!";
  }
  else
  {
    for(int i=0; i<=top; i++)
    {
      cout<<stack[i]<<" ";
    }
  }
}

int main()
{
  push();
  push();
  push();
  push();
  push();
  push();
  cout<<"After pushing elements stack is: ";
  display();
  pop();
  pop();
  pop();
  cout<<endl<<"After poping elements of the stack are: ";
  display();
  return 0;
}
