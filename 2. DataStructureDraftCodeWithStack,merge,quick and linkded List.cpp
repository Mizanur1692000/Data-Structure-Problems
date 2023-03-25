#include<iostream>
#include<cstdlib>
#include<fstream>
#define max 2600//Total 2600 beds are available in the hospital. So, 2600 patients can be added in tha list
using namespace std;

struct Patient{
  int patientId;
  string patientName;
  string patientAddress;
  string patientCovid19TestReportDate;
  string listOfPreviousDiseases;
  string bloodGroup;
  struct Patient *next;//self referenial pointer
};
//Hospital information
void hospitalInformation(string hospitalName, string hospitalLocation,int establishedYear, int worldRanking, int totalBed, string totalDoctor)
{
  cout<<"Hospital name: "<<hospitalName<<endl<<"Location: "<<hospitalLocation<<endl<<"Eshtablished year: "<<establishedYear<<endl<<"World Ranking: "<<worldRanking<<endl<<"Total beds: "<<totalBed<<endl<<"Total number of doctors: "<<totalDoctor<<endl;
}
//function for insert a new patient's information which take patient id,name,address,covid-19 test report and list of previous diseases of the patient using stack
int count(struct Patient*temp)//Checking overflow or not function
{
  int c=0;
  while(temp!=NULL)
  {
    temp=temp->next;
    c++;
  }
  return (c);
}

void insertPatient(struct Patient**q)
{
  int patientId;
  string patientName;
  string patientAddress;
  string patientCovid19TestReportDate;
  string listOfPreviousDiseases;
  string bloodGroup;
  struct Patient*temp;
  if(count(*q)>=max)
  {
    cout<<"Overflow!!!";
    return ;
  }
  else
  {
  cout<<"Enter the patient id: ";
  cin>>patientId;
  cout<<"Enter the patient name: ";
  cin>>patientName;
  cout<<"Enter the patient address: ";
  cin>>patientAddress;
  cout<<"Enter the Covid-19 test report date of the patient: ";
  cin>>patientCovid19TestReportDate;
  cout<<"Enter the list of previous diseases of patient: ";
  cin>>listOfPreviousDiseases;
  cout<<"Enter the blood group of patient: ";
  cin>>bloodGroup;
    temp=(struct Patient*)malloc(sizeof(Patient));

    temp->patientId=patientId;
    temp->patientName=patientName;
    temp->patientAddress=patientAddress;
    temp->patientCovid19TestReportDate=patientCovid19TestReportDate;
    temp->listOfPreviousDiseases=listOfPreviousDiseases;
    temp->bloodGroup=bloodGroup;
    temp->next=*q;
    *q=temp;
    cout<<"Patient information successfully inserted at the beginning of the list!!!";
  }
}



int searchById(struct Patient** headRef, int patientId)//search the patient's information by id if found then it will porvide the patient's name,address,covid-19 test report and list of previous diseases
{
  struct Patient *current=*headRef;
  while(current!=NULL)
  {
    if(current->patientId==patientId)
    {
      cout<<"Patient record found!!!"<<endl;
      cout<<"After searching patient's name is: "<<current->patientName<<endl<<"Address: "<<current->patientAddress<<endl<<"Covid-19 test report date: "<<current->patientCovid19TestReportDate<<endl<<"Previous diseases: "<<current->listOfPreviousDiseases<<endl<<"Blood group: "<<current->bloodGroup<<endl;
      return 1;

    }
    current=current->next;
  }
  return 0;
}

int searchByName(struct Patient** headRef, string patientName)//search the patient's information by name if found then it will porvide the patient's id,address,covid-19 test report and list of previous diseases
{
  struct Patient *current=*headRef;
  while(current!=NULL)
  {
    if(current->patientName==patientName)
    {
      cout<<"Patient record found!!!"<<endl;
      cout<<"After searching patient id is: "<<current->patientId<<endl<<"Address: "<<current->patientAddress<<endl<<"Covid-19 test report date: "<<current->patientCovid19TestReportDate<<endl<<"Previous diseases: "<<current->listOfPreviousDiseases<<endl<<"Blood group: "<<current->bloodGroup<<endl;
      return 1;

    }
    current=current->next;
  }
  return 0;
}
int searchByAddress(struct Patient** headRef, string patientAddress)//search the patient's information by name if found then it will porvide the patient's id,address,covid-19 test report and list of previous diseases
{
  struct Patient *current=*headRef;
  while(current!=NULL)
  {
    if(current->patientAddress==patientAddress)
    {
      cout<<"Patient record found!!!"<<endl;
      cout<<"After searching patient id is: "<<current->patientId<<endl<<"Name: "<<current->patientName<<endl<<"Covid-19 test report date: "<<current->patientCovid19TestReportDate<<endl<<"Previous diseases: "<<current->listOfPreviousDiseases<<endl<<"Blood group: "<<current->bloodGroup<<endl;
      return 1;

    }
    current=current->next;
  }
  return 0;
}

int searchByDiseases(struct Patient** headRef, string listOfPreviousDiseases)//search the patient's information by previous disease if found then it will porvide the patient's id, name,address and covid-19 tese report date
{
  struct Patient *current=*headRef;
  while(current!=NULL)
  {
    if
(current->listOfPreviousDiseases==listOfPreviousDiseases)
    {
      cout<<"Patient record found!!!"<<endl;
      cout<<"After searching patient id is: "<<current->patientId<<endl<<"Name is: "<<current->patientName<<endl<<"Address: "<<current->patientAddress<<endl<<"Covid-19 test report date: "<<current->patientCovid19TestReportDate<<endl<<"Blood group: "<<current->bloodGroup<<endl;
      return 1;
    }

    current=current->next;
  }
  return 0;
}

void deleteDiedPatient(struct Patient** head,string name)//delete function....User can delete any petient's record from record book by using patient's name
{
  struct Patient *temp = *head,*prev;
  if(temp!=NULL && temp->patientName == name){
    *head = temp->next;
    free(temp);
    return;
  }

  while(temp !=NULL && temp->patientName !=name){
    prev = temp;
    temp = temp->next;
  }
  if(temp==NULL)
    return;

  prev->next = temp->next;
  free(temp);
}
void deleteRecoveryPatient(struct Patient** head,string name)//delete function....User can delete any petient's record from record book by using patient's name
{
  struct Patient *temp = *head,*prev;
  if(temp!=NULL && temp->patientName == name){
    *head = temp->next;
    free(temp);
    return;
  }

  while(temp !=NULL && temp->patientName !=name){
    prev = temp;
    temp = temp->next;
  }
  if(temp==NULL)
    return;

  prev->next = temp->next;
  free(temp);
}
void updatePatientId(struct Patient**headRef,int id,int updateId)//update funcition by address...user can update any patient's address by using the previous address
{
  if(*headRef==NULL)
  {
    cout<<"Patient record file is empty!!!";
  }
  struct Patient *current=*headRef;
  while(current!=NULL)
  {
    if(current->patientId==id)
    {
      current->patientId=updateId;
      cout<<endl<<id<<" found and replaced with "<<updateId<<endl;
    }
    current=current->next;
  }
}
void updatePatientName(struct Patient**headRef,string name,string updateName)//update funcition by address...user can update any patient's address by using the previous address
{
  if(*headRef==NULL)
  {
    cout<<"Patient record file is empty!!!";
  }
  struct Patient *current=*headRef;
  while(current!=NULL)
  {
    if(current->patientName==name)
    {
      current->patientName=updateName;
      cout<<endl<<name<<" found and replaced with "<<updateName<<endl;
    }
    current=current->next;
  }
}
void updatePatientAddress(struct Patient**headRef,string address,string updatePatientAddress)//update funcition by address...user can update any patient's address by using the previous address
{
  if(*headRef==NULL)
  {
    cout<<"Patient record file is empty!!!";
  }
  struct Patient *current=*headRef;
  while(current!=NULL)
  {
    if(current->patientAddress==address)
    {
      current->patientAddress=updatePatientAddress;
      cout<<endl<<address<<" found and replaced with "<<updatePatientAddress<<endl;
    }
    current=current->next;
  }
}

void updateCovid19TestReportDate(struct Patient**headRef,string covid19TestReportDate,string updateCovid19TestReportDate)//update funcition by covid-19 test report date...user can update any patient's covid-19 test report date by using the previous covid-19 test report date
{
  if(*headRef==NULL)
  {
    cout<<"Patient record file is empty!!!";
  }
  struct Patient *current=*headRef;
  while(current!=NULL)
  {
    if(current->patientCovid19TestReportDate==covid19TestReportDate)
    {
      current->patientCovid19TestReportDate=updateCovid19TestReportDate;
      cout<<endl<<covid19TestReportDate<<" found and replaced with "<<updateCovid19TestReportDate<<endl;
    }
    current=current->next;
  }
}
//Merge sort function for getting the patient information in accending order
Patient* mergeList(Patient* split1,Patient* split2){
    //merging two sorted list
    Patient* newhead=NULL;
    //base cases
    if(split1==NULL)
    return split2;
    if(split2==NULL)
    return split1;
    //recursively merge
    if(split1->patientId<=split2->patientId){
        newhead=split1;
        newhead->next=mergeList(split1->next,split2);
    }
    else{
        newhead=split2;
        newhead->next=mergeList(split1,split2->next);
    }

    return newhead;

}
//Merge sort funciton
void splitList(Patient* head,Patient** split1,Patient** split2){
    //similar to flyod's tortoise algorithm
    Patient* slow=head;
    Patient* fast=head->next;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }

    *split1=head;
    *split2=slow->next;
    //spliting
    slow->next=NULL;
}
//Merge sort
void mergeSort(Patient** refToHead){
    Patient* head=*refToHead;
    Patient* split1,*split2;
    //base case
    if(head==NULL || head->next==NULL){
        return;
    }
    //split the list in two halves
    splitList(head,&split1,&split2);
    //recursively sort the two halves
    mergeSort(&split1);
    mergeSort(&split2);
    //merge two sorted list
    *refToHead=mergeList(split1,split2);

    return;

}
//Quick sort
struct Patient* getLast(struct Patient* current)
{
    while (current != NULL && current->next!= NULL)
        current = current->next;
    return current;
}

struct Patient* partition(struct Patient* head, struct Patient* end, struct Patient** newHead, struct Patient** newEnd)
{
    struct Patient* p = end;
    struct Patient *prev = NULL, *current = head, *last = p;
     while (current != p) {
        if (current->patientId < p->patientId) {
            if ((*newHead) == NULL)
                (*newHead) = current;

            prev = current;
            current = current->next;
        }
        else
        {
            if (prev)
                prev->next = current->next;
            struct Patient* tmp = current->next;
            current->next = NULL;
            last->next = current;
            last = current;
            current = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = p;
        (*newEnd) = last;
        return p;
}

struct Patient* quickSortRecursively(struct Patient* head,
  struct Patient* end)
{
    if (!head || head == end)
        return head;

    Patient *newHead = NULL, *newEnd = NULL;

    struct Patient* p
        = partition(head, end, &newHead, &newEnd);


    if (newHead != p) {
        struct Patient* temp = newHead;
        while (temp->next != p)
            temp = temp->next;
        temp->next = NULL;

        newHead = quickSortRecursively(newHead, temp);

        temp = getLast(newHead);
        temp->next = p;
    }

    p->next = quickSortRecursively(p->next, newEnd);

    return newHead;
}

void quickSort(struct Patient** headRef)
{
    (*headRef)= quickSortRecursively(*headRef, getLast(*headRef));
    return;
}

void display(struct Patient *head)//display functio which display the record book of patients after inserting the patients information properly
{
  //NodePtr p = head;
  cout<<endl;
  while(head!=NULL){
    cout<<"\tPatient Id = "<<head->patientId<<endl<<"\tPatient name = "<<head->patientName<<endl<<"\tPatient address = "<<head->patientAddress<<endl<<"\tCovid-19 test report data = "<<head->patientCovid19TestReportDate<<endl<<"\tList of pervious diseases = "<<head->listOfPreviousDiseases<<endl<<"\tBlood group = "<<head->bloodGroup<<endl<<endl;
    head=head->next;
  }
  cout<<endl;
}
//Reversely displaying the patient records by id
void reverseDisplay(struct Patient* head){
	if(head){
		//recursive call to display in reverse order
		reverseDisplay(head->next);
    cout<<"\tPatient Id = "<<head->patientId<<endl<<"\tPatient name = "<<head->patientName<<endl<<"\tPatient address = "<<head->patientAddress<<endl<<"\tCovid-19 test report data = "<<head->patientCovid19TestReportDate<<endl<<"\tList of pervious diseases = "<<head->listOfPreviousDiseases<<endl<<"\tBlood group= "<<head->bloodGroup<<endl<<endl;
	}
}
//File handling part
typedef Patient* NodePtr;
class LinkedList{
  private:
    NodePtr head;
  public:
    LinkedList(){
      head = NULL;
    }
    NodePtr& addLinkedList(NodePtr& head,int patientId,string patientName, string patientAddress, string patientCovid19TestReportDate, string listOfPreviousDiseases, string bloodGroup){
      NodePtr NewPtr = new Patient();
      NewPtr->patientId = patientId;
      NewPtr->patientName = patientName;
      NewPtr->patientAddress = patientAddress;
      NewPtr->patientCovid19TestReportDate = patientCovid19TestReportDate;
      NewPtr->listOfPreviousDiseases = listOfPreviousDiseases;
      NewPtr->bloodGroup=bloodGroup;

      NewPtr->next = NULL;

      NodePtr p = head;

      if(p == NULL)
        head = NewPtr;
      else
      {
          while(p->next != NULL)
            p = p->next;
          p->next = NewPtr;
      }
      return head;
    }

    void fileWrite(NodePtr& head){
      ofstream os("linkedList.txt", ios::out | ios::app);
      for (NodePtr p = head; p != NULL; p = p->next){
          cout <<endl<<"Patient id: "<< p->patientId<<endl <<"Patient name: "<<p->patientName<<endl<<"Patient address: "<<p->patientAddress<<endl<<"Patient Coved-19 tese report date: "<<p->patientCovid19TestReportDate<<endl<<"List of previous diseases of patient: "<<p->listOfPreviousDiseases<<endl<<"Blood group: "<<p->bloodGroup<<endl;
          os <<endl<<"Patient id: "<<p->patientId <<endl<<"Patient name: "<<p->patientName<<endl<<"Patient address: "<<p->patientAddress<<endl<<"Patient Coved-19 tese report date: "<<p->patientCovid19TestReportDate<<endl<<"List of previous diseases of patient: "<<p->listOfPreviousDiseases<<endl<<"Blood group: "<<p->bloodGroup<<endl;
      }
      os.close();
    }
};

int main()//main function....all the fuction is called from this function...user can choice 1 to 8 options for the patient record book....if used choice 9 the program will exit otherwise user take any other choice(without 1 t0 9) the program will show invalid choice!!! try again...then user can choice any option again from 1 to 8....
{
  int choice;
  string name,previousDisease;
  struct Patient* patient=NULL;
  struct Patient hospitalName, hospitalLocation, establishedYear, worldRanking, totalBed, totalDoctor;
  LinkedList k;
  NodePtr head;
  while(true)
  {
   cout << "\n\t\tWelcome to the Record Book of Covid-19 patient of Dhaka Medical College: "
          "\n\n\t\t Press\n\t\t 1 to see hospital information\n\t\t 2 to "
                "insert a patient\n\t\t 3 to search a "
                "patient record by id\n\t\t 3 to search a patient record by name\n\t\t 5 to search a patient record by address\n\t\t 6 to search a patient record by previous diseases\n\t\t 7 to remove a died patient's record\n\t\t 8 to remove a recovery patient's record\n\t\t 9 to update patient id\n\t\t10 to update patient name\n\t\t11 to update patient address\n\t\t12 to update Covid-19 test report date\n\t\t13 to view the records of all patient\n\t\t14 to view the records in ascending order(Merge sort)\n\t\t15 to view the records in reverse order\n\t\t16 to view the records acceding order(Quick sort)\n\t\t17 to save patient information permanently. If you save all information, you can not add any information\n\t\t18 to Exit\n";
    cout << "\n\tEnter your Choice\n";
   cin>>choice;
    if(choice==1)
   {
     /*cout<<"Hospital name: Dhaka Medical College and Hospital."<<endl<<"Location: Dhaka, Bangladesh."<<"Eshtablished: 1946"<<endl<<"World Ranking: 10763"<<endl<<"Total beds: 2600"<<endl<<"Total number of doctors: 594 (199 female and 395 male)"<<endl;*/
     hospitalInformation("Dhaka Medical College and Hospital.","Dhaka, Bangladesh.", 1946, 10763, 2600, "594 (199 female and 395 male)");
     }
   else if(choice==2)
   {
     insertPatient(&patient);
     cout<<endl<<"The information of the patient is inserted and saved in the file!!!"<<endl;
   }
   else if(choice==3)
   {
     int id;
     cout<<"Enter the id of the patient to search: ";
     cin>>id;
     if(searchById(&patient,id))
     cout<<"Record of the patient showed!!!";
     else
     cout<<"Record of the patient not found!!!";
   }
   else if(choice==4)
   {
     string name;
     cout<<"Enter the name of the patient to search: ";
     cin>>name;
     if(searchByName(&patient,name))
     cout<<"Record of the patient showed!!!";
     else
     cout<<"Record of the patient not found!!!";
   }
      else if(choice==5)
   {
     string address;
     cout<<"Enter the address of the patient to search: ";
     cin>>address;
     if(searchByAddress(&patient,address))
     cout<<"Record of the patient showed!!!";
     else
     cout<<"Record of the patient not found!!!";
   }
   else if(choice==6)
   {
     string previousDiseases;
     cout<<"Enter the previous diseases of the patient to search: ";
     cin>>previousDiseases;
     if(searchByDiseases(&patient,previousDiseases))
     cout<<"Record of the patient showed!!!";
     else
     cout<<"Record of the patient not found!!!";
   }
   else if(choice==7)
   {
     string name;
     cout<<"Enter the name of the died patient to delete: ";
     cin>>name;
     deleteDiedPatient(&patient,name);
     cout<<"The record of the died patient named"<<name<<" deleted!!!"<<endl;
   }
    else if(choice==8)
   {
     string name;
     cout<<"Enter the name of the recovery patient to delete: ";
     cin>>name;
     deleteRecoveryPatient(&patient,name);
     cout<<"The record of the recovery patient named "<<name<<" deleted!!!"<<endl;
   }
    else if(choice==9)
   {
     int id,updateId;
     cout<<"Enter the id of the patient to update: ";
     cin>>id;
     cout<<"Enter the update id: ";
     cin>>updateId;
     updatePatientId(&patient,id,updateId);
     cout<<"Patient id updated!!!";
   }
    else if(choice==10)
   {
     string name,updateName;
     cout<<"Enter the name of the patient to update: ";
     cin>>name;
     cout<<"Enter the update name: ";
     cin>>updateName;
     updatePatientName(&patient,name,updateName);
     cout<<"Patient id updated!!!";
   }
   else if(choice==11)
   {
     string address,updateAddress;
     cout<<"Enter the address of the patient to update: ";
     cin>>address;
     cout<<"Enter the update address: ";
     cin>>updateAddress;
     updatePatientAddress(&patient,address,updateAddress);
     cout<<"Patient address updated!!!";
   }
   else if(choice==12)
   {
     string covid19TestReportDate, updateCovid19TestReport;
     cout<<"Enter the Covid-19 test report date of the patient to update: ";
     cin>>covid19TestReportDate;
     cout<<"Enter the update Covid-19 test report date: ";
     cin>>updateCovid19TestReport;
     updateCovid19TestReportDate(&patient,covid19TestReportDate,updateCovid19TestReport);
     cout<<"Patient Covid-19 test report date updated!!!";
   }
    else if(choice==13)
   {
     cout<<"Records of the patients are: ";
     display(patient);
   }
       else if(choice==14)
   {
     cout<<"Records of the patients after Merge sort are: ";
     mergeSort(&patient);
     display(patient);
   }
        else if(choice==15)
   {
     cout<<"Records of the patients in normal reverse order: "<<endl;
    reverseDisplay(patient);
   }
        else if(choice==16)
   {
     cout<<"Records of the patients after Quick sort are: ";
     quickSort(&patient);
     display(patient);
   }
        else if(choice==17)
   {
     k.fileWrite(patient);
     display(patient);
     cout<<"The information of the patients are saved permanently and program end!!!";
     exit(0);
   }
    else if(choice==18)
   {
     exit(0);
   }
   else
   {
     cout<<"Invalid choice!!!";
     cout<<"Try again!!!"<<endl;
   }
  }
}
