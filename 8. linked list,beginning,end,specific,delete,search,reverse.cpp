/*
#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node* next;//self referencial pointer
};

void insertAtBeginner(struct Node** headRef,int data)
{10
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=data;
  newNode->next=*headRef;
  *headRef=newNode;
}

void insertAtEnd(struct Node** headRef, int data)
{
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  struct Node* last=*headRef;
  newNode->data=data;
  newNode->next=NULL;
  if(*headRef==NULL)
  {
    *headRef=newNode;
  }
  else
  {
    while(last->next!=NULL)
    {
      last=last->next;
    }
    last->next=newNode;
  }
}

void insertAtAnyPosition(struct Node* prevNode,int data)
{
  if(prevNode==NULL)
  {
    cout<<"The list is empty!!!";
  }
  else
  {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=prevNode->next;
    prevNode->next=newNode;
  }
}

int search(struct Node** headRef,int key)
{
  struct Node* current=*headRef;
  while(current!=NULL)
  {
    if(current->data==key)
    return 1;
    current=current->next;
  }
  return 0;
}

void deleteNode(struct Node** headRef,int key)
{
  struct Node*temp=*headRef,*prev;
  if(temp!=NULL && temp->data==key)
  {
    *headRef=temp->next;
    free(temp);
    return;
  }

  while(temp!=NULL && temp->data!=key)
  {
    prev=temp;
    temp=temp->next;
  }
  if(temp==NULL)
  {
    return;
  }
  prev->next=temp->next;
  free(temp);
}


void print(struct Node* temp)
{
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

void reverse(struct Node **headRef) {
    struct Node *temp = NULL;
    struct Node *prev = NULL;
    struct Node *current = (*headRef);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*headRef) = prev;
}





void deleteNode1(struct Node** headRef,int key)
{
  struct Node*temp=*headRef,*prev;
  if(temp!=NULL && temp->data==key)
  {
    *headRef=temp->next;
    free(temp);
    return;
  }
  while(temp!=NULL && temp->data==key)
  {
    prev=temp;
    temp=temp->next;
  }
  if(temp==NULL)
  return;
  prev->next=temp->next;
  free(temp);
}

int main()
{
  struct Node* head=NULL;
  struct Node* head2=NULL;
  insertAtBeginner(&head,4);
  insertAtBeginner(&head,3);
  insertAtBeginner(&head,2);
  insertAtBeginner(&head,1);
  cout<<"Insert at beginning: ";
  print(head);
  cout<<endl;

  cout<<"Insert at endl: ";
  insertAtEnd(&head,7);
  insertAtEnd(&head,8);
  insertAtEnd(&head,9);
  insertAtEnd(&head,10);
  print(head);
  cout<<endl;

  cout<<"Insert at any position: ";
  insertAtAnyPosition(head->next->next->next,6);
  insertAtAnyPosition(head->next->next->next,5);
  print(head);
  cout<<endl;

  int key,k,i;
  cout<<"Enter the item to search: ";
  cin>>key;

  if(search(&head,key))
  cout<<"The item found!!!";
  else
  cout<<"The item is no found!!!";
  cout<<endl;

  cout<<"Reversely presented linked list: ";
  reverse(&head);
  print(head);
  cout<<endl;

  cout<<"Enter the item to delete: ";
  cin>>k;
  deleteNode(&head,k);
  cout<<"After deletion update linked list is: ";
  print(head);
  cout<<endl;

  cout<<"Enter the item to delete again: ";
  cin>>i;
  deleteNode1(&head,i);
  cout<<"After deletion again update liked list is: ";
  print(head);
  cout<<endl;
}
*/

#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node* next;//self referencial pointer
};

void insertAtBeginner(struct Node** headRef,int data)
{
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=data;
  newNode->next=*headRef;
  *headRef=newNode;
}

void insertAtEnd(struct Node** headRef, int data)
{
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  struct Node* last=*headRef;
  newNode->data=data;
  newNode->next=NULL;
  if(*headRef==NULL)
  {
    *headRef=newNode;
  }
  else
  {
    while(last->next!=NULL)
    {
      last=last->next;
    }
    last->next=newNode;
  }
}

void insertAtAnyPosition(struct Node* prevNode,int data)
{
  if(prevNode==NULL)
  {
    cout<<"The list is empty!!!";
  }
  else
  {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=prevNode->next;
    prevNode->next=newNode;
  }
}

int search(struct Node** headRef,int key)
{
  struct Node* current=*headRef;
  while(current!=NULL)
  {
    if(current->data==key)
    return 1;
    current=current->next;
  }
  return 0;
}

void deleteNode(struct Node** headRef,int key)
{
  struct Node*temp=*headRef,*prev;
  if(temp!=NULL && temp->data==key)
  {
    *headRef=temp->next;
    free(temp);
    return;
  }

  while(temp!=NULL && temp->data!=key)
  {
    prev=temp;
    temp=temp->next;
  }
  if(temp==NULL)
  {
    return;
  }
  prev->next=temp->next;
  free(temp);
}

  void insertPosition(struct Node**headRef,int pos, int value)
  {
    Node *pre=new Node;
    Node *cur=new Node;
    Node *temp=new Node;
    cur=*headRef;
    for(int i=1;i<pos;i++)
    {
      pre=cur;
      cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;
    temp->next=cur;
  }


void print(struct Node* temp)
{
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

void reverse(struct Node **headRef) {
    struct Node *temp = NULL;
    struct Node *prev = NULL;
    struct Node *current = (*headRef);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*headRef) = prev;
}

int main()
{
  struct Node* head=NULL;
  struct Node* head2=NULL;
  insertAtBeginner(&head,4);
  insertAtBeginner(&head,3);
  insertAtBeginner(&head,2);
  insertAtBeginner(&head,1);
  cout<<"Insert at beginning: ";
  print(head);
  cout<<endl;

  cout<<"Insert at endl: ";
  insertAtEnd(&head,7);
  insertAtEnd(&head,8);
  insertAtEnd(&head,9);
  insertAtEnd(&head,10);
  print(head);
  cout<<endl;

  cout<<"Insert at any position: ";
  insertAtAnyPosition(head->next->next->next,6);
  insertAtAnyPosition(head->next->next->next,5);
  print(head);
  cout<<endl;

  cout<<"Insert at specific postion: "<<endl;
  int position,value;
  cout<<"Enter the postion where you want to insert a value: ";
  cin>>position;
  cout<<"Enter the value: ";
  cin>>value;
  insertPosition(&head, position, value);
  print(head);
  cout<<endl;

  int key,k,i;
  cout<<"Enter the item to search: ";
  cin>>key;

  if(search(&head,key))
  cout<<"The item found!!!";
  else
  cout<<"The item is no found!!!";
  cout<<endl;

  cout<<"Reversely presented linked list: ";
  reverse(&head);
  print(head);
  cout<<endl;

  cout<<"Enter the item to delete: ";
  cin>>k;
  deleteNode(&head,k);
  cout<<"After deletion update linked list is: ";
  print(head);
  cout<<endl;
}

