/*
#include<iostream>
using namespace std;

int adj[100][100];//If 2d matrix define globally the primary elements remain 0 by default for undirected graph

int main()
{
  int node,edge,n1,n2;
  cout<<"Enter the number of node: ";
  cin>>node;
  cout<<"Enter the number of edge: ";
  cin>>edge;
  for(int i=0; i<edge; i++)
  {
    cin>>n1>>n2;
    adj[n1][n2]=1;
    adj[n2][n1]=1;
  }
  for(int i=0; i<node; i++)
  {
    for(int j=0; j<node; j++)
    {
      cout<<adj[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
*/

#include<iostream>
#define v 5
using namespace std;

void init(int arr[][v])
{
  for(int i=0; i<v; i++)
    for(int j=0; j<v; j++)
    arr[i][j]=0;
}

void addElement(int arr[][v], int src, int dest)
{
  arr[src][dest]=1;
}

void printAdjMatrix(int arr[][v]){
  for(int i=0;i<v;i++)
  {
    for(int j=0;j<v;j++){
      cout<<" "<<arr[i][j];
    }
    cout<<endl;
  }
}

int main()
{
  int adjMatrix[v][v];
  init(adjMatrix);
  addElement(adjMatrix,0,1);
  addElement(adjMatrix,2,0);
  addElement(adjMatrix,2,1);
  addElement(adjMatrix,1,3);
  addElement(adjMatrix,3,4);
  addElement(adjMatrix,1,4);
  printAdjMatrix(adjMatrix);
}
