#include <iostream>
#include <cstdlib>

using namespace std;

struct Student{
  int id;
  string name;
  double marks;
  struct Student* next;
};

void insertStudent(struct Student **headRef)
{
  int id;
  string name;
  double mark;
  struct Student* newStudent=(struct Student*)malloc(sizeof(struct Student));
   cout<<"Enter student id: ";
  cin>>id;
  cout<<"Enter student name: ";
  cin>>name;
  cout<<"Enter student marks: ";
  cin>>mark;
  struct Student *last=*headRef;

  newStudent->id=id;
  newStudent->name=name;
  newStudent->marks=mark;
  newStudent->next=NULL;
  if(*headRef==NULL)
  {
    *headRef=newStudent;
  }
  else
  {
    while(last->next!=NULL)
    {
      last=last->next;
    }
    last->next=newStudent;
  }
}





void deleteStudent(struct Student** head,int key){
  struct Student *temp = *head,*prev;
  if(temp!=NULL && temp->id == key){
    *head = temp->next;
    free(temp);
    return;
  }

  while(temp !=NULL && temp->id !=key){
    prev = temp;
    temp = temp->next;
  }
  if(temp==NULL)
    return;

  prev->next = temp->next;
  free(temp);

}


int searchStudent(struct Student** headRef, int key)
{
  struct Student *current=*headRef;
  while(current!=NULL)
  {
    if(current->id==key)
    {
      cout<<"Student record found!!!"<<endl;
      cout<<"After searching id is: "<<current->id<<endl<<"Name is: "<<current->name<<endl<<"Mark is: "<<current->marks<<endl;
    }
    return 1;
    current=current->next;
  }
  return 0;
}


void output(struct Student* head){
  cout<<endl;
  while(head!=NULL){
    cout<<"Id = "<<head->id<<endl<<"Name = "<<head->name<<endl<<"Marks = "<<head->marks<<endl<<endl;
    head=head->next;
  }
  cout<<endl;
}



int main() {


  int key,i,choice;
  struct Student* start = NULL;
  //insert(&head,5);
  //insert(&head,4);
  //insert(&head,33);
  //insert(&head,2);
  //insert(&head,1);
  //output(head);

  while(true)
  {
    cout << "\n\t\tWelcome to Student Record "
                "Management System\n\n\tPress\n\t1 to "
                "create a new Record\n\t2 to delete a "
                "student record\n\t3 to Search a Student "
                "Record\n\t4 to view all students "
                "record\n\t5 to Exit\n";
    cout << "\nEnter your Choice\n";
   cin>>choice;
   if(choice==1)
   {
      insertStudent(&start);
   }
   else if(choice==2)
   {
    cout<<"Enter the student to delete: ";
    cin>>i;
    deleteStudent(&start, i);
   }
   else if(choice==3)
   {
     cout<<"Enter the id to search: ";
     cin>>key;
     searchStudent(&start, key);
   }
   else if(choice==4)
   {
     cout<<"Record of the student is: ";
     output(start);
   }
   else if(choice==5)
   {
     exit(0);
   }
   else
   {
     cout<<"Invalid choice!!!";
     cout<<"Try again!!!"<<endl;
   }
  }

  /*
  insertStudent(&start);

  cout<<endl<<endl;



  if(searchStudent(&start, key)){
  cout<<"Data item found!!!"<<endl;

}
  else
  cout<<"Data item not found!!!"<<endl;


  cout<<"After deletion update list is: "<<endl;

  output(start);


  //deleteNode(&head, 88);
  //output(head);
  */


}
