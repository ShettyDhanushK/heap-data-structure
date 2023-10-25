
#define SIZE 10          


//Structure Of The Heap

typedef struct
{
    int node[SIZE+1];
    int currSize;
} minHeap;

//Helper Function
void bubble_down(minHeap *heap, int index)
{
    int c;
    int min_index;

    c = leftChild(index);
    min_index = index;

    for(int i = 0; i < 1; i++)
    {
        if((c+i) <= heap->currSize)
        {
            if(heap->node[c+i] < heap->node[min_index])
            {
                min_index = c+i;
            }
        }
    }

    if(min_index != index)
    {
        swap(heap, index, min_index);
        bubble_down(heap, min_index);
    }
}

//Deletion Operation
void delete(minHeap *heap, int x)
{
    if(heap->currSize == 0)
    {
        printf("Warning: Priority Queue Underflow!\n");
    }
    else
    {
        heap->node[x] = heap->node[heap->currSize];
        heap->currSize = (heap->currSize) - 1;
        bubble_down(heap, x);
    }
}