#include <iostream>
using namespace std;
#define maxn 101;
int heap_size = 0;
int length = 0;
// 维护堆的过程
void maxHeapfity(int A[],int i)
{
    printf("maxHeapfity(A,%d)\n",i);
    for(int i = 0;i<=heap_size-1;i++)
        cout << A[i]<< " ";
    cout << endl;
    int left = 2*i+1;
    int right = 2*(i+1);
    int largest = i;
    if(left < heap_size && A[left]>A[i])
        largest = left;
    if(right < heap_size && A[right]>A[largest])
        largest = right;
    if(largest != i){
        printf("exchange %d with %d\n",A[i],A[largest]);
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapfity(A,largest);
    }
}
//建堆的过程
void buildMaxHeap(int *A)
{
    heap_size = length;
    for(int i = (length/2-1);i>=0;i--)
        maxHeapfity(A,i);
}

//排序算法

void heapSort(int *A)
{
    buildMaxHeap(A);
    for(int i = length-1;i>=1;i--){
        printf("the max is %d\n",A[0]);
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heap_size -= 1;
        maxHeapfity(A,0);
    }
}
int main() {
    int A[] = {0,16,14,10,8,59,1,5};
    length = sizeof(A)/sizeof(int);
    heapSort(A);
    for(int i =0;i<=length-1;i++){
        printf("%d ",A[i]);
    }
    return 0;
}