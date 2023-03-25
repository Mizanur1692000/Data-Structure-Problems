#include <iostream>
using namespace std;

struct Node{
  int patientId;
  string patientName;
  string patientAddress;
  string patientCovid19TestReportDate;
  string listOfPreviousDiseases;
  struct Node *next;
};



struct Node* front = NULL;
struct Node* rear = NULL;
struct Node* temp;



void enQueue() {
  int patientId;
  string patientName;
  string patientAddress;
  string patientCovid19TestReportDate;
  string listOfPreviousDiseases;

  cout<<"Enter the patient id: ";
  cin>>patientId;
  cout<<"Enter the patient name: ";
  cin>>patientName;
  cout<<"Enter the patient address: ";
  cin>>patientAddress;
  cout<<"Enter the Covid-19 report date of the patient: ";
  cin>>patientCovid19TestReportDate;
  cout<<"Enter the list of previous diseases of patient: ";
  cin>>listOfPreviousDiseases;
   if (rear == NULL) {
      rear = (struct Node*)malloc(sizeof(struct Node));
      rear->next = NULL;

      rear->patientId = patientId;
      rear->patientName = patientName ;
      rear->patientAddress = patientAddress;
      rear->patientCovid19TestReportDate = patientCovid19TestReportDate;
      rear->listOfPreviousDiseases = listOfPreviousDiseases;
      front = rear;
   } else {
      temp=(struct Node *)malloc(sizeof(struct Node));
      rear->next = temp;

      temp->patientId = patientId;
      temp->patientName = patientName;
      temp->patientAddress = patientAddress;
      temp->patientCovid19TestReportDate = patientCovid19TestReportDate;
      temp->listOfPreviousDiseases = listOfPreviousDiseases;
      temp->next = NULL;
      rear = temp;
   }
}




void deQueue() {
   temp = front;
    int patientId;
     cout<<"Enter the id of the patient to delete: ";
     cin>>patientId;
   if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
   }
   else if (temp->next != NULL) {
      temp = temp->next;
      free(front);
      front = temp;
   } else {
      free(front);
      front = NULL;
      rear = NULL;
   }
}



void Display() {
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Queue list of patients record is empty!!!"<<endl;
      return;
   }
   while (temp != NULL) {
      cout<<"Patient Id : "<<temp->patientId<<endl<<"Patient name : "<<temp->patientName<<endl<<"Patient address : "<<temp->patientAddress<<endl<<"Covid-19 test report data : "<<temp->patientCovid19TestReportDate<<endl<<"List of pervious diseases : "<<temp->listOfPreviousDiseases<<endl<<endl;
      temp = temp->next;
   }
   cout<<endl;
}


int main() {
  int choice;
  while(1)
  {
   cout << "\n\t\tWelcome to the Record Book of Covid-19 patient using Queue: "
          "\n\n\tPress\n\t1 to "
                "insert a patient in a Queue\n\t2 to delete a patient record from Queue\n\t3 to view the Queue list of all patient "
                "record\n\t4 to Exit\n";
    cout << "\nEnter your Choice\n";
   cin>>choice;
   if(choice==1)
   {
     enQueue();
     cout<<endl<<"The information of the patient is inserted in a Queue!!!"<<endl;
   }

   else if(choice==2)
   {
     deQueue();
     cout<<"Record of the patient deleted!!!";
   }

    else if(choice==3)
   {
     cout<<"Records of the patients in a Queue are: "<<endl;
     Display();
   }
    else if(choice==4)
   {
     exit(0);
   }
   else
   {
     cout<<"Invalid choice!!!";
     cout<<"Try again!!!"<<endl;
   }
  }
  return 0;
}
