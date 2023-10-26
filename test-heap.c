#include <stdio.h>

#define SIZE 10

typedef struct
{
    int node[SIZE+1];
    int currSize;
} minHeap;

int parent (int i);
int leftChild (int i);
void init (minHeap * heap);
void swap (minHeap *heap, int a, int b);
void bubble_up (minHeap *heap, int index);
void bubble_down (minHeap *heap, int index);
void printArray (int arr[], int n);
void printHeap (minHeap *heap);
int getMin (minHeap *heap);
void insert (minHeap *heap, int x);
void delete (minHeap * heap, int x);
int extractMin (minHeap *heap);
void heapify (minHeap *heap, int arr[], int n);
void testHeap(minHeap *heap, int arr[], int n);



int main()
{
    minHeap heap;
    int arr[] = {6, 4, 2, 10, 22, 0, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    testHeap(&heap, arr, n);

    return 0;
}


void testHeap(minHeap *heap, int arr[], int n)
{
    printf("Array before heapify --> ");
    printArray(arr, n);
    heapify(heap, arr, n);
    printf("MIN-HEAP created after heapify operation--> ");
    printHeap(heap);
    
    printf("\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|  Parent        |      Left-Child           |  Right-Child |\n");
    printf("|----------------|---------------------------|--------------|\n");
    for(int i = 1; i <= 4; i++)
    {
        if(i != 4)
        {
            printf("|   %d            |         ", (heap->node[i]));
            printf("%d                 |    ", (heap->node[leftChild(i)]));
            printf("      %d   |\n", ((heap->node[leftChild(i)+1])));
        }
        else
        {
            printf("|   %d            |         ", (heap->node[i]));
            printf("%d                |    ", (heap->node[leftChild(i)]));
            printf("      -   |\n");
        }
    }
    printf("|-----------------------------------------------------------|\n");

    printf("\n");
    printf("Let's test Insertion ------------------------------->\n");
    printf("We insert 5 to our heap and our heap becomes --> insert(heap, 5) ---------> ");
    insert(heap, 5);
    printHeap(heap);
    printf("Now let's insert -1 to our heap ------> insert(heap, -1) ----------------> ");
    insert(heap, -1);
    printHeap(heap);
    printf("Let's add 30 to our --------> insert(heap, 30) --------------------> ");
    insert(heap, 30);

    printf("\n");
    printf("Now let's test our delete operation -------------------------------->\n");
    printf("Hmmmmmmmmmmmm, let's delete 1 from heap ---------> delete(heap, 5) -------------------> ");
    delete(heap, 5);
    printHeap(heap);
    printf("Now let's delete 4 from heap ---------> delete(heap, 6) -------------------> ");
    delete(heap, 6);
    printHeap(heap);
    printf("\n");
    printf("Our main operations are working :)\n");
    printf("\n");
    printf("Now let's try getMin() -----------------> %d", getMin(heap));
    printf("\nLet's try it again getMin() -----------------> %d", getMin(heap));
    printf("\nNote that getMin() only prints the root element of the min-heap. It does not change the root node.\n\n");
    printf("Moving to the last operation, we have extractMin() ----------------> %d\n", extractMin(heap));
    printf("Now the heap is --------------------> ");
    printHeap(heap);
    printf("\n\n That's it!! All of our heap operations and heap are working as intended!!!!!\n\n\n");
    printf("WANNA CHALLENGE YOURSELF! THEN WRITE THE MAX_HEAP STRUCTURE AND IMPLEMENT THE SAME OPERATION AND MAKE IT WORK. I DARE YOU!!!!\n");

}


void printHeap(minHeap *heap)
{
    for(int i = 1; i <= heap->currSize; i++)
    {
        printf("%i ", heap->node[i]);
    }
    printf("\n");
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

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


