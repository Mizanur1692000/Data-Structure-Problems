#include<iostream>

#define N 8

using namespace std;

struct Graph
{
   struct Node* vertices[N];
};


struct Node
{
    int dest, weight;
    struct Node* next;
};


struct Edge {
    int src, dest, weight;
};


struct Graph* createGraph(struct Edge edges[], int n)
{
    int i;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (i = 0; i < N; i++) {
        graph->vertices[i] = NULL;
    }
      for (i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->weight = weight;
        newNode->next = graph->vertices[src];
        graph->vertices[src] = newNode;
    }
    return graph;
}

void printGraph(struct Graph* graph)
{
  int i;
    for (i = 0; i < N; i++)
    {
      struct Node* ptr = graph->vertices[i];
        while (ptr != NULL)
        {
            cout<<" vertices["<<i<<"]:"<<ptr->dest<<" ("<<ptr->weight<<")";
            ptr = ptr->next;
        }
        cout<<endl;
    }
}
int main(void)
{
    struct Edge edges[] =
    {
      //A=1, B=2, C=3, D=4, E=5, F=6, G=7
        { 1, 7, 10 }, { 1, 4, 8 },{ 1, 2, 1 }, { 2, 7, 9 }, { 2, 4, 2 }, { 3, 6, 7},{ 3, 5, 5},  { 5, 6, 6}, { 7, 6, 3},{ 4, 5, 4 }, { 4, 3, 3 }
    };

      int n = 11;
    struct Graph *graph = createGraph(edges, n);
    printGraph(graph);
    return 0;
}
