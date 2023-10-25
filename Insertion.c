


#define SIZE 10             //Number of elements you want to store in heap.          

typedef struct              //Declaring our heap structure
{
    int node[SIZE+1];       //Node of our heap
    int currSize;           //Points to the last element which has bee inserted.
} minHeap;



//Helper function
void bubble_up(minHeap *heap, int index)                //Takes minHeap struc and index of the element to be bubbled up as argument
{
    if(parent(index) == -1)                             //If the current element is the root node, no need of bubbling up
    {
        return;
    }
    if(heap->node[parent(index)] > heap->node[index])   //If the parent of the element is greater than the current element
    {
        swap(heap, index, parent(index));               //swap current element with parent element
        bubble_up(heap, parent(index));                 //recursively calls bubble_up passing the structure and the current index of the element to be bubbled up
    }
}


//Insertion Operation
void insert(minHeap *heap, int x)                       //Takes minHeap struc and the element to be inserted
{
    if (heap->currSize >= SIZE)                         //Checks if heap is full
    {
        printf("Warning: Priority Queue Overflow!\n");  //If yes, no element is inserted and warning is print
    }
    else
    {
        heap->currSize = (heap->currSize) + 1;          //else currSize is incremented
        heap->node[heap->currSize] = x;                 //the inserting element is inserted at the last position of the heap
        bubble_up(heap, heap->currSize);                //bubble is called on the inserted element
    }
}