
#define SIZE 10          


//Structure Of The Heap

typedef struct
{
    int node[SIZE+1];
    int currSize;
} minHeap;



//Helper function
void bubble_up(minHeap *heap, int index)
{
    if(parent(index) == -1)
    {
        return;
    }
    if(heap->node[parent(index)] > heap->node[index])
    {
        swap(heap, index, parent(index));
        bubble_up(heap, parent(index));
    }
}


//Insertion Operation
void insert(minHeap *heap, int x)
{
    if (heap->currSize >= SIZE)
    {
        printf("Warning: Priority Queue Overflow!\n");
    }
    else
    {
        heap->currSize = (heap->currSize) + 1;
        heap->node[heap->currSize] = x;
        bubble_up(heap, heap->currSize); 
    }
}