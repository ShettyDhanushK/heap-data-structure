
#define SIZE 10          


//Structure Of The Heap

typedef struct
{
    int node[SIZE+1];
    int currSize;
} minHeap;


//getMin Operation
int getMin(minHeap *heap)
{
    return heap->node[1];
}