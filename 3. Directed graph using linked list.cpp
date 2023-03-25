#include<iostream>

#define N 6

using namespace std;

struct Graph
{

    struct Node* vertices[N];
};


struct Node
{
    int dest;
    struct Node* next;
};

struct Edge {
    int src, dest;
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


        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;


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
            cout<<" vertices["<<i<<"]:"<<ptr->dest;
            ptr = ptr->next;
        }

      cout<<endl;
    }
}


int main(void)
{

    struct Edge edges[] =
    {
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 }, { 3, 2 }, { 4, 5 }, { 5, 4 }
    };


    int n = 7;


    struct Graph *graph = createGraph(edges, n);


    printGraph(graph);

    return 0;
}


