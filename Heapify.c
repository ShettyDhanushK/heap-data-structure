

#define SIZE 10          


//Structure Of The Heap

typedef struct
{
    int node[SIZE+1];
    int currSize;
} minHeap;


//Helper Functions

int parent(int i)
{
    if(i == 1)
    {
        return -1;
    }
    return ((int) i/2);
};

int leftChild(int i)
{
    return 2*i;
}

void init(minHeap *heap)
{
    heap->currSize = 0;
}

//Heapify Operation
void heapify(int arr[], int n)
{
    minHeap heap;

    init(&heap);

    for(int i = 0; i < n; i++)
    {
        insert(&heap, arr[i]);
    }
}