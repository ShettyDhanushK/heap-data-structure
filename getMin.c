
#define SIZE 10             //Number of elements you want to store in heap.          

typedef struct              //Declaring our heap structure
{
    int node[SIZE+1];       //Node of our heap
    int currSize;           //Points to the last element which has bee inserted.
} minHeap;


//getMin Operation
int getMin(minHeap *heap)   //Takes minHeap stucture
{
    return heap->node[1];   //returns the root element of the heap
}