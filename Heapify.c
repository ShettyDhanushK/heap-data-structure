

#define SIZE 10             //Number of elements you want to store in heap.          

typedef struct              //Declaring our heap structure
{
    int node[SIZE+1];       //Node of our heap
    int currSize;           //Points to the last element which has bee inserted.
} minHeap;


//Helper Functions

int parent(int i)           //takes the index as an argument
{
    if(i == 1)              //if the element is the root node
    {
        return -1;
    }
    return ((int) i/2);     //We know that children_index / 2 = parent index
};

int leftChild(int i)        //takes the index as an argument
{
    return 2*i;             //left_child = index*2
}

void init(minHeap *heap)    //just intitiates the heap by setting the currSize to the beginning of the heap
{
    heap->currSize = 0;
}

//Heapify Operation
void heapify(int arr[], int n)  //This operation takes an array and size of the array as argument and creates a heap from that elements.
{
    minHeap heap;               //Creating a new minHeap called heap

    init(&heap);                //initiating our heap

    for(int i = 0; i < n; i++)  //iterates over the array
    {
        insert(&heap, arr[i]);  //each element is inserted into the heap. Do not worry, minHeap property is maintained by insert operation.
    }
}