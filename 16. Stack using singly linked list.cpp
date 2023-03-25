/*
#include<iostream>
#include<cstdlib>
#define max 5
using namespace std;

struct node{
  int data;
  struct node*link;
};

void push(struct node**q, int no);
void display(struct node*q);
int pop(struct node**q);

int main()
{
  struct node*p=NULL;
  int ch,no,pe;
  do{
    cout<<"\n1 Push\n";
    cout<<"2 pop\n";
    cout<<"3 display\n";
    cout<<"4 exit\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
    cout<<"Push\nEnter the element: ";
    cin>>no;
    push(&p,no);
    break;
    case 2:
    pe=pop(&p);

    break;
    case 3:
    display(p);
    break;
    case 4:
    cout<<"Thank you!!";
    ch=0;
    break;
    default:
    cout<<"You enterd wrong choice!!!\nTry again!!!";
    }
  }while(ch);
}
int count(struct node*q)
{
  int c=0;
  while(q!=NULL)
  {
    q=q->link;
    c++;
  }
  return (c);
}

void push(struct node**q, int no)
{
  struct node*temp;
  if(count(*q)>=max)
  {
    cout<<"Overflow!!!";
    return ;
  }
  else
  {
    temp=(struct node*)malloc(sizeof(node));
    temp->data=no;
    temp->link=*q;
    *q=temp;
    cout<<"Push Successfully done!!!";
  }
}

void display(struct node*q)
{
  while(q!=NULL)
  {
    cout<<q->data<<" ";
     q=q->link;
  }

}
int pop(struct node**q)
{
  struct node*temp;
  int rd;
  if(*q==NULL)
  {
    cout<<"\nUnderFlow!!!";
    return (rd);
  }
  else
  {
    temp=*q;
    rd=temp->data;
    *q=temp->link;
     free(temp);
     return(rd);
  }
}
*/

#include<iostream>
#include<cstdlib>
#define max 5
using namespace std;

struct node{
  int data;
  struct node*link;
};
struct node* head=NULL;

void push(struct node**q, int no);
void display(struct node*q);
int pop(struct node**q);

int main()
{
  struct node*p=NULL;
  int ch,no,pe;
  do{
    cout<<"\n1 Push\n";
    cout<<"2 pop\n";
    cout<<"3 display\n";
    cout<<"4 exit\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
    cout<<"Push\nEnter the element: ";
    cin>>no;
    push(&p,no);
    break;
    case 2:
    pe=pop(&p);

    break;
    case 3:
    display(p);
    break;
    case 4:
    cout<<"Thank you!!";
    ch=0;
    break;
    default:
    cout<<"You enterd wrong choice!!!\nTry again!!!";
    }
  }while(ch);
}
int count(struct node*q)
{
  int c=0;
  while(q!=NULL)
  {
    q=q->link;
    c++;
  }
  return (c);
}

void push(struct node**q, int no)
{
  struct node*temp;
  if(count(*q)>=max)
  {
    cout<<"Overflow!!!";
    return ;
  }
  else
  {
    temp=(struct node*)malloc(sizeof(node));
    temp->data=no;
    temp->link=*q;
    *q=temp;
    cout<<"Push Successfully done!!!";
  }
}

void display(struct node*q)
{
  while(q!=NULL)
  {
    cout<<q->data<<" ";
     q=q->link;
  }

}
/*int pop(struct node**q)
{
  struct node*temp;
  int rd;
  if(*q==NULL)
  {
    cout<<"\nUnderFlow!!!";
    return (rd);
  }
  else
  {
    temp=*q;
    rd=temp->data;
    *q=temp->link;
     free(temp);
     return(rd);
  }
}
*/
void pop(struct node**q) {
  if(head != NULL) {
    if(head->link == NULL) {
      head = NULL;
    } else {
      node* temp = head;
      while(temp->link->link != NULL)
        temp = temp->link;

      //3. Change the next of the second
      //   last node to null and delete the
      //   last node
      node* lastNode = temp->link;
      temp->link = NULL;
      free(lastNode);
    }
  }
}
