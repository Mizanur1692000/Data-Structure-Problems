#include<iostream>
using namespace std;
struct Struct{
  string name;
  int age;
  double height;
};

int main()
{
  struct Struct s;
  struct Struct s1;
  s.name="Mizanur Rahman";
  s.age=10;
  s.height=5.5;
  s1.name="Rana";
  s1.age=20;
  s1.height=5.2;
  cout<<"First man name= "<<s.name<<endl;
  cout<<"First man age= "<<s.age<<endl;
  cout<<"First man height= "<<s.height<<endl;
  cout<<"Second man name= "<<s1.name<<endl;
  cout<<"Second man age= "<<s1.age<<endl;
  cout<<"Second man height= "<<s1.height<<endl;
  return 0;
}
