
#define SIZE 10             //Number of elements you want to store in heap.          

typedef struct              //Declaring our heap structure
{
    int node[SIZE+1];       //Node of our heap
    int currSize;           //Points to the last element which has bee inserted.
} minHeap;

//Helper Function
void bubble_down(minHeap *heap, int index)              //Takes minHeap struc and index of the element to be bubbled down
{
    int c;                                              //left_child
    int min_index;                                      //index of the minimum element found.

    c = leftChild(index);                               //index of the left child is assigned
    min_index = index;                                  //At the beginning, current element is the minimum element we know

    for(int i = 0; i <= 1; i++)                          //Loops 2 times, one for the left_child and other for the right_child
    {
        if((c+i) <= heap->currSize)                     //checks if left_child or right_child (depending upon i) exists
        {
            if(heap->node[c+i] < heap->node[min_index]) //If yes, checks if left or right child (depending upon i) is less than the current known minimum element
            {
                min_index = c+i;                        //If yes, min_index is updated to the new minimum element
            }
        }
    }

    if(min_index != index)                              //If min_index does not contain our current element
    {
        swap(heap, index, min_index);                   //swap the current element with the smallest of it's child
        bubble_down(heap, min_index);                   //bubble down is recursively applied to our current element in it's current position.
    }
}


//extractMin Operation
int extractMin(minHeap *heap)                           //Takes minHeap structure
{
    int min = -1;                                       //At first minHeap is set to -1

    if(heap->currSize <= 0)                             //Check if heap is empty
    {
        printf("Warning: Priority Queue Underflow!\n"); //If yes, no element is returned
    }
    else
    {
        min = heap->node[1];                            //min is updated with the root element of the heap
        heap->node[1] = heap->node[heap->currSize];     //the root element is replaced with the last element of the heap
        heap->currSize = (heap->currSize) - 1;          //currSize is decremented by 1
        bubble_down(heap, 1);                           //bubble_down is called on the root index
    }
    return min;                                         //minimum element is returned
}