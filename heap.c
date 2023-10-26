#include <stdio.h>

#define SIZE 10

typedef struct
{
    int node[SIZE+1];
    int currSize;
} minHeap;

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

void swap(minHeap *heap, int a, int b)
{
    int temp = heap->node[a];
    heap->node[a] = heap->node[b];
    heap->node[b] = temp;
}

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

void bubble_down(minHeap *heap, int index)
{
    int c;
    int min_index;

    c = leftChild(index);
    min_index = index;

    for(int i = 0; i <= 1; i++)
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

int getMin(minHeap *heap)
{
    return heap->node[1];
}

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

int extractMin(minHeap *heap)
{
    int min = -1;

    if(heap->currSize <= 0)
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

void heapify(minHeap *heap, int arr[], int n)
{

    init(heap);

    for(int i = 0; i < n; i++)
    {
        insert(heap, arr[i]);
    }
}


int main()
{
    minHeap heap;
    int arr[] = {6, 4, 2, 10, 22, 0, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapify(&heap, arr, n);

    return 0;
}