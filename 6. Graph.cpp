#include <iostream>
#define N 5
using namespace std;

struct Graph{
  struct Node *vertices[N];
};

struct Node{
  int dest;
  struct Node *next;
};

struct Edge{
  int src, dest;
};

struct Graph* createGraph(struct Edge edges[],int n){
  int i;
  struct Graph *graph = new Graph;
  for(i=0;i<N;i++){
    graph->vertices[i]=NULL;
  }
  for(i=0;i<n;i++){
    int src = edges[i].src;
    int dest = edges[i].dest;
    struct Node *newNode = new Node;
    newNode->dest=dest;
    newNode->next=graph->vertices[src];
    graph->vertices[src] = newNode;
  }
  return graph;
}

void printGraph(struct Graph *graph){
  for(int i=0;i<N;i++){
    struct Node *ptr = graph->vertices[i];
    while(ptr!=NULL){
      cout<<"vertices["<<i<<"]:"<<ptr->dest;
      ptr=ptr->next;
    }
    cout<<endl;

  }
}

int main() {
  struct Edge edges[]={
    {0,1},{1,2},{1,3},{3,4},{2,3},{4,0}
  };
  int n=5;
  struct Graph *graph = createGraph(edges,n);
  printGraph(graph);
}
