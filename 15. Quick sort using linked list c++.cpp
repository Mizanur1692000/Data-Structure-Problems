//Quick sort using linked list
#include <cstdio>
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* link;
};


void pushData(struct Node** headRef, int newData)
{
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data=newData;
   newNode->link=NULL;
   struct Node*last=*headRef;
  if(*headRef==NULL)
  {
    *headRef=newNode;
  }
  else
  {
    while(last->link!=NULL)
    {
      last=last->link;
    }
    last->link=newNode;
  }
}

void printList(struct Node* node)
{
    while (node != NULL) {
        cout<<node->data<<" ";
        node = node->link;
    }
    cout<<endl;
}

struct Node* getLast(struct Node* current)
{
    while (current != NULL && current->link!= NULL)
        current = current->link;
    return current;
}

struct Node* partition(struct Node* head, struct Node* end,
      struct Node** newHead,
      struct Node** newEnd)
{
    struct Node* p = end;
    struct Node *prev = NULL, *current = head, *last = p;
     while (current != p) {
        if (current->data < p->data) {
            if ((*newHead) == NULL)
                (*newHead) = current;

            prev = current;
            current = current->link;
        }
        else
        {
            if (prev)
                prev->link = current->link;
            struct Node* tmp = current->link;
            current->link = NULL;
            last->link = current;
            last = current;
            current = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = p;
        (*newEnd) = last;
        return p;
}

struct Node* quickSortRecursively(struct Node* head,
  struct Node* end)
{
    if (!head || head == end)
        return head;

    Node *newHead = NULL, *newEnd = NULL;

    struct Node* p
        = partition(head, end, &newHead, &newEnd);


    if (newHead != p) {
        struct Node* temp = newHead;
        while (temp->link != p)
            temp = temp->link;
        temp->link = NULL;

        newHead = quickSortRecursively(newHead, temp);

        temp = getLast(newHead);
        temp->link = p;
    }

    p->link = quickSortRecursively(p->link, newEnd);

    return newHead;
}

void quickSort(struct Node** headRef)
{
    (*headRef)= quickSortRecursively(*headRef, getLast(*headRef));
    return;
}

int main()
{
    struct Node* start = NULL;
    pushData(&start, 55);
    pushData(&start, 27);
    pushData(&start, 46);
    pushData(&start, 38);
    pushData(&start, 50);
    pushData(&start, 25);
    pushData(&start, 67);


    cout << "Linked List before quick sorting: "<<endl;
    printList(start);

    quickSort(&start);
    cout << "Linked List after quick sorting: "<<endl;
    printList(start);
    return 0;
}
