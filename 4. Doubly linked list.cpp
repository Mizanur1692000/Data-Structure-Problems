#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node*next;
  struct Node*prev;
};

void addAtEnd(struct Node**headRef,int value)
{
 struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
 newNode->data=value;
 newNode->next=NULL;

  if(*headRef==NULL)
  {
    newNode->prev=NULL;
    *headRef=newNode;
    return;
  }
  else
  {
    struct Node*last=*headRef;
    while(last->next!=NULL)
    {
      last=last->next;
    }
    last->next=newNode;
    newNode->prev=last;
  }
}

void addAfter(struct Node*prevNode,int location, int value)
{
  struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
  for(int i=1; i<location; i++)
  {
    prevNode=prevNode->next;
    if(prevNode==NULL)
    {
       cout<<"There are less then "<<location<<" elements.";
   return;
    }
  }
   newNode->data = value;
   newNode->prev = prevNode;
   newNode->next=prevNode->next;
   prevNode->next->prev=newNode;
   prevNode->next = newNode;
}
void addAtBeginning(struct Node**headRef,int value)
{
  struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;

   newNode->next = (*headRef);
   newNode->prev = NULL;
   if ((*headRef) != NULL)
   (*headRef)->prev = newNode;

   (*headRef) = newNode;
}


void display(struct Node*temp)
{
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }

}
void reverselyDisplay(struct Node*temp)
{
  while(temp->next!=NULL)
  temp=temp->next;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->prev;
  }

}
int count(struct Node*temp)
{
  int i=0;
  while(temp!=NULL)
  {
    i++;
    temp=temp->next;
  }
return i;
}

int main()
{
  struct Node*head=NULL;
  int choice,no,location;
  struct Node*head1=NULL;
  struct Node*last=NULL;
  do{
    cout<<"\n\n==Doubly linked list menu==\n";
    cout<<"1. Add at the end\n";
    cout<<"2. Add after a given location\n";
    cout<<"3. Count total number of nodes\n";
    cout<<"4. Add at beginning\n";
    cout<<"5. Delete\n";
    cout<<"6. Display\n";
    cout<<"7. Reversely display\n";
    cout<<"8. Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1:
      {
        cout<<"Enter a new value: ";
        cin>>no;
        addAtEnd(&head,no);
        break;
      }
      case 2:
      {
        cout<<"Enter the location number after which you want to insert: ";
        cin>>location;
        cout<<"Enter the value: ";
        cin>>no;
        addAfter(head,location,no);
        break;
      }
      case 3:
      {
        cout<<"Total number of node is: "<<count(head);
        break;
      }
      case 4:
      {
      cout<<"Enter a new value: ";
      cin>>no;
      addAtBeginning(&head,no);
      break;
      }
      case 5:
      {
        cout<<"Enter the position of the value to delete: ";
        cin>>no;
        deleteNode(head, no);
        break;
      }
      case 6:
      {
        display(head);
        break;
      }
      case 7:
      {
        reverselyDisplay(head);
        break;
      }
      case 8:
      {
        exit(0);
      }
      default:
      {
      cout<<"Invalid choice!!!";
      cout<<"\nTry again!!!";
      }
    }
  }while(choice);
}
