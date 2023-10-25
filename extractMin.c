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


//extractMin Operation
int extractMin(minHeap *heap)
{
    int min = -1;

    if(heap->currSize == 0)
    {
        printf("Warning: Priority Queue Underflow!\n");
    }
    else
    {
        min = heap->node[1];
        heap->node[1] = heap->node[heap->currSize];
        heap->currSize = (heap->currSize) - 1;
        bubble_down(heap, 1);
    }
    return min;
}