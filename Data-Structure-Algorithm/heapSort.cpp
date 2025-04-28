#include <iostream>
using namespace std;
void buildMaxHeap(int heap[], int heapSize);
void maxHeapify(int heap[], int heapSize, int i);
void heapSort(int heap[], int heapSize);
void printF(int heap[], int heapSize);
int leftIndex(int i);
int rightIndex(int i);
int parentIndex(int i);

int main()
{
    int heap[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int heapSize = sizeof(heap) / sizeof(int);

    cout << "Heap Size: " << --heapSize << "\n";

    // Frist need to build max heap
    buildMaxHeap(heap, heapSize);
    printF(heap, heapSize);

    // now call heapsort
    heapSort(heap, heapSize);
    printF(heap, heapSize);

    return 0;
}

void heapSort(int heap[], int heapSize)
{
    int i, t;
    for (i = heapSize; i > 1; i--)
    {
        t = heap[1];
        heap[1] = heap[i];
        heap[i] = t;
        heapSize -= 1;
        maxHeapify(heap, heapSize, 1);
    }
}

void buildMaxHeap(int heap[], int heapSize)
{
    for (int i = heapSize / 2; i >= 1; i--)
    {
        // cout << "buildMaxHeap: " << i << "\n";
        maxHeapify(heap, heapSize, i);
    }
}

void maxHeapify(int heap[], int heapSize, int i)
{
    int l, r, largest, t;

    l = leftIndex(i);
    r = rightIndex(i);

    // cout << "iiii: " << i << "L:" << leftIndex(i) << "--- R: " << rightIndex(i) << "\n";

    if (l <= heapSize && heap[l] > heap[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if (r <= heapSize && heap[r] > heap[l])
    {
        largest = r;
    }
    // cout << " largest: " << largest << "\n";
    if (largest != i && largest <= heapSize)
    {

        // cout << "------------------";
        // cout << "Hi: " << heap[i] << "HL: " << heap[largest] << "\n";
        t = heap[i];
        heap[i] = heap[largest];
        heap[largest] = t;
        // cout << "Hi: " << heap[i] << "HL: " << heap[largest] << "\n";
        maxHeapify(heap, heapSize, largest);
    }
}

int leftIndex(int i)
{
    return i * 2;
}

int rightIndex(int i)
{
    return i * 2 + 1;
}

int parentIndex(int i)
{
    return i / 2;
}

void printF(int heap[], int heapSize)
{
    for (int i = 1; i < heapSize; i++)
    {
        cout << heap[i] << " ";
    }
    cout << "\n";
}