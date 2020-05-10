#include<iostream>
#include<time.h>
#include<queue>
#include<algorithm>

#define PRINT_ARRAY 1
using namespace std;

const int ARRAY_SIZE = 100;



// A class for Min Heap
class MinHeap
{
    public:
        MinHeap(int capacity);
        ~MinHeap();
        void push(int k); //insert
        int pop();//extractMin
        int peek() { return heap[1]; }
        void printHeap();
    private:
        int *heap; // pointer to array of elements in heap
        int capacity; // maximum possible size of min heap
        int currentSize; // Current number of elements in min heap      
        void MinHeapify(int index);
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i+1); }
        int right(int i) { return (2*i + 2); }
        void swap(int &x, int &y);
};
 
MinHeap::MinHeap(int cap)
{
    currentSize = 0;
    capacity = cap; 
    heap = new int[capacity];
}

MinHeap::~MinHeap()
{
    delete [] heap;
}
 
void MinHeap::push(int k){
    if(currentSize == capacity)
    {
        cout << "heap is full" << endl; 
    }
    else
    {
        int i = currentSize; 
        heap[i] = k; //appending to the end of the array (heap)

        while(i!=0 && heap[parent(i)]>heap[i])
        {
            swap(heap[i], heap[parent(i)]); 
            i = parent(i); 
        }
        currentSize++; 
    }
    
   
}
 
// for now, just return -1 if there's nothing to pop
int MinHeap::pop(){
    if(currentSize<=0 )
    {
        return -1; 
    }

    if(currentSize == 1)
    {
        currentSize--; 
        return heap[0];
    }

    int poppedVal = heap[0]; 
    heap[0] = heap[currentSize-1]; 
    currentSize--; 
    MinHeapify(0); 

    return poppedVal;


}
 
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i){

    int leftChild = left(i); 
    int rightChild = right(i); 
    int smallest = i; //index of smallest value 

    if(leftChild < currentSize && heap[leftChild] < heap[i])
    {
        smallest = leftChild;
    }

    if(rightChild < currentSize && heap[rightChild] < heap[smallest])
    {
        smallest = rightChild; 
    }

    if(smallest != i)
    {
        swap(heap[i], heap[smallest]); 
        MinHeapify(smallest); 
    }


}
 
void MinHeap::swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void MinHeap::printHeap() {
    cout << "The heap array is currently {";
    for (int i = 0; i < currentSize; i++) {
        cout << heap[i];
        if (i < currentSize-1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

void printArray(int a[], int size){
#if PRINT_ARRAY
    for( int i = 0; i < size; i ++ )
        cout << a[i] << " ";
#endif
}

int main(){

    ////////////////////////////////////////////////////////////////////////
    // CREAT A TEST ARRAY OF RANDOM INTEGERS
    int testArr[ARRAY_SIZE], arr[ARRAY_SIZE];
    for( int i = 0; i < ARRAY_SIZE; i++)
        testArr[i] = rand()%1000;


    cout << "the unsorted test array is: " << endl;

    printArray(testArr,ARRAY_SIZE);
   
    cout << "\n\n";

    int startTime, endTime;   
    double execTime;

    ////////////////////////////////////////////////////////////////////////
    // TEST BUBBLE SORT
    
    // Copy over test values
    for( int i = 0; i < ARRAY_SIZE; i ++ )
        arr[i] = testArr[i];
    
    
    startTime = clock();

    for ( int i = ARRAY_SIZE-1; i > 0; i-- ){
        for ( int j = 0; j < i; j++ )
            if ( arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
    }
    
    endTime = clock();

    execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;

    cout << "bubble execution time: " << execTime << endl;

    ////////////////////////////////////////////////////////////////////////
    // TEST HEAP SORT

    // Re-populate test array with random ints
    for( int i = 0; i < ARRAY_SIZE; i ++ )
        arr[i] = testArr[i];

    Minheap heap(ARRAY_SIZE); 

    for( int i = 0; i < ARRAY_SIZE; i ++ )
        heap.push(arr[i]);

    for( int i = 0; i < ARRAY_SIZE; i ++ )
        arr[i] = heap.pop();
    
    



    ////////////////////////////////////////////////////////////////////////
    // TEST Priority Queue from STL for sorting

    // Re-populate test array with random ints
    for( int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = testArr[i];



    ////////////////////////////////////////////////////////////////////////
    // TEST sort() from STL for sorting

    // Re-populate test array with random ints
    for( int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = testArr[i];



    return 0;
}