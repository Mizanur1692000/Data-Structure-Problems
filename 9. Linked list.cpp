//Basic linked list
/*
#include<iostream>
using namespace std;

struct Node{
  string name;
  struct Node *link;//self referential pointer
};

int main()
{
  struct Node *n1, *n2, *n3;

  n1=(struct Node*)malloc(sizeof(struct Node));
  n2=(struct Node*)malloc(sizeof(struct Node));
  n3=(struct Node*)malloc(sizeof(struct Node));

  n1->name="Mizanur";
  n1->link=n2;

  n2->name="Rahman";
  n2->link=n3;

  n3->name="Mizanur";
  n3->link=NULL;

  struct Node *t;
  t=n1;

  while(t!=NULL)
  {
    cout<<t->name<<" ";
    t=t->link;
  }
  return 0;
}
*/


#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};



void insertAtBeginning(struct Node **headRef, int dataItem)
{
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=dataItem;
  newNode->next=*headRef;
  *headRef=newNode;
}

void insertAtEnd(struct Node **headRef, int dataItem)
{
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  struct Node *last=*headRef;
  newNode->data=dataItem;
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

void insertAfter(struct Node *prevNode, int dataItem)
{

  if(prevNode==NULL)
  {
    cout<<"The node is impty!!!";
  }
  else{
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=dataItem;
  newNode->next=prevNode->next;
  prevNode->next=newNode;
  }
}


int searchNode(struct Node** headRef, int key)
{
  struct Node *current=*headRef;
  while(current!=NULL)
  {
    if(current->data==key)
    return 1;
    current=current->next;
  }
  return 0;
}

void printList(struct Node* node)
{
  while(node!=NULL)
  {
    cout<<node->data<<" ";
    node=node->next;
  }
}

int main()
{
  struct Node *head1=NULL;
  struct Node *head2=NULL;
  cout<<"Insert at beginnig: "<<endl;
  insertAtBeginning(&head1, 2);
  insertAtBeginning(&head1, 1);
  printList(head1);
  cout<<endl;

  cout<<"Insert at end: "<<endl;
  insertAtEnd(&head2, 1);
  insertAtEnd(&head2, 2);
  insertAtEnd(&head2, 3);
  insertAtEnd(&head2, 4);
  insertAtEnd(&head2, 5);
  insertAtEnd(&head2, 6);
  printList(head2);
  cout<<endl;

  cout<<"Insert at after: "<<endl;
  insertAfter(head2->next->next, 10);
  printList(head2);
  cout<<endl;
  int key;
  cout<<"Enter the key: ";
  cin>>key;

  if(searchNode(&head2, 4)){
  cout<<"Data item found!!!"<<endl;
  insertAfter(head2->next->next->next->next, 20);
  printList(head2);
}
  else
  cout<<"Data item not found!!!";

  return 0;
}
