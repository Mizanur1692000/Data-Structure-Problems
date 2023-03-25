//Merge sort using linked list
#include <iostream>
#include<cstdlib>
using namespace std;

struct Node {
    int item;
    struct Node* link;
};
struct Node* SortedMerge(struct Node* x,struct Node* y);
void FrontBackSplit(struct Node* source,
struct Node** frontRef, struct Node** backRef);

void MergeSort(struct Node** headRef)
{
    Node* head = *headRef;
    Node* x;
    Node* y;
     if ((head == NULL) || (head->link == NULL)) {
        return;
    }

    FrontBackSplit(head, &x, &y);

    MergeSort(&x);
    MergeSort(&y);

    *headRef = SortedMerge(x, y);
}

struct Node* SortedMerge(struct Node* x, struct Node* y)
{
    Node* result = NULL;

    if (x == NULL)
        return (y);
    else if (y == NULL)
        return (x);

    if (x->item <= y->item) {
        result = x;
        result->link = SortedMerge(x->link, y);
    }
    else {
        result = y;
        result->link = SortedMerge(x, y->link);
    }
    return (result);
}
void FrontBackSplit(Node* source,
  Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->link;

    while (fast != NULL) {
        fast = fast->link;
        if (fast != NULL) {
            slow = slow->link;
            fast = fast->link;
        }
    }

    *frontRef = source;
    *backRef = slow->link;
    slow->link = NULL;
}

void printList(struct Node* node)
{
    while (node != NULL) {
        cout << node->item << " ";
        node = node->link;
    }
}

void push(struct Node** headRef, int newData)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->item=newData;
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

int main()
{
    struct Node* start = NULL;
    push(&start, 50);
    push(&start, 30);
    push(&start, 52);
    push(&start, 27);
    push(&start, 36);
    push(&start, 80);
    push(&start, 60);
    push(&start, 44);

    cout<<"Before merge sort Linked List is: "<<endl;
    printList(start);

    MergeSort(&start);
    cout <<endl<< "After merge sort Linked List is: "<<endl;
    printList(start);
    return 0;
}
