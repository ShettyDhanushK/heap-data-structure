

#define SIZE 10             //Number of elements you want to store in heap.          

typedef struct              //Declaring our heap structure
{
    int node[SIZE+1];       //Node of our heap
    int currSize;           //Points to the last element which has bee inserted.
} minHeap;