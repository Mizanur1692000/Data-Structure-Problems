//Basic linked list create
/*
#include<iostream>
using namespace std;

struct Node{
  string name;
  struct Node *next;
};

struct Node *head;

void print()
{
  struct Node *temp;
  temp=head;
while(temp!=NULL)
{
  cout<<temp->name<<" ";
  temp=temp->next;
}
}

int main()
{
  head=NULL;
  head=(struct Node*)malloc(sizeof(struct Node));
  head->name="Mizanur";
  head->next=(struct Node*)malloc(sizeof(struct Node));
  head->next->name="Rahman";
  head->next->next=NULL;
  print();
}
*/


//Insert node at the end
/*
#include<iostream>
using namespace std;

struct Node{
  string name;
  struct Node *next;
};
struct Node *head;

void print()
{
  struct Node *temp;
  temp=head;
  while(temp!=NULL)
  {
    cout<<temp->name<<endl;
    temp=temp->next;
  }
}

void insertAtBeginning(string name)
{
  struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
  temp->name=name;
  temp->next=head;
  head=temp;
}

void insertAtEnd(string name)
{
  struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
  temp->name=name;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
  }
  else
  {
    struct Node *tmp;
    tmp=head;
    while(tmp->next!=NULL)
    {
      tmp=tmp->next;
    }
    tmp->next=temp;
  }
}

int main()
{
  head=NULL;
  insertAtEnd("Mizanur");
  insertAtEnd("Rahman");
  insertAtBeginning("Rana");
  insertAtBeginning("Sohana");
  print();
  return 0;
}
*/

//Struct swap and add using pointer
/*
#include<iostream>
using namespace std;

struct complexNumber{
  float real,imag;
};

void add(struct complexNumber *x, struct complexNumber *y, struct complexNumber *z)
{
  z->real=x->real+y->real;
  z->imag=x->imag+y->imag;
}

void swap(struct complexNumber *a, struct complexNumber *b)
{
  struct complexNumber temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

int main()
{
  struct complexNumber a,b,c;
  cin>>a.real>>a.imag;
  cin>>b.real>>b.imag;
  add(&a,&b,&c);
  cout<<"Real = "<<c.real<<endl<<"Imag = "<<c.imag;

  swap(&a,&b);
  cout<<a.real<<a.imag<<endl<<b.real<<b.imag;

  return 0;
}
*/

//Dynamic memory allocation using malloc
//Malloc create memory block one by one
/*
#include<iostream>
using namespace std;

int main()
{
  int *ptr,n;
  cout<<"Enter the total number of values: ";
  cin>>n;
  ptr=(int *)malloc(n*sizeof(int ));

  if(ptr==NULL)
  {
    cout<<"Memory bloct not available or fail to allocate memory!!!";
  }
  else {
  cout<<"Enter "<<n<<" number of values: ";
  for(int i=0; i<n; i++)
  {
    cin>>ptr[i];
  }
  cout<<"The values are: ";
  for(int i=0; i<n; i++)
  {
    cout<<ptr[i]<<" ";
  }
  }
  return 0;
}
*/

//Dynamic memory allocation using calloc
//Calloc create n number memory block at a time
#include<iostream>
using namespace std;

int main()
{
  int *ptr,n;
  cout<<"Enter the total number of values: ";
  cin>>n;
  //ptr=(int *)malloc(n*sizeof(int ));
  ptr=(int *)calloc(n,sizeof(int));//here is the differnt between malloc and calloc
  if(ptr==NULL)
  {
    cout<<"Memory bloct not available or fail to allocate memory!!!";
  }
  else {
  cout<<"Enter "<<n<<" number of values: ";
  for(int i=0; i<n; i++)
  {
    cin>>ptr[i];
  }
  cout<<"The values are: ";
  for(int i=0; i<n; i++)
  {
    cout<<ptr[i]<<" ";
  }

  ptr=(int *)realloc(ptr,n*sizeof(int ));//realloc

  free(ptr);//in calloc variable should be free of rest of the memory block
  }
  return 0;
}
