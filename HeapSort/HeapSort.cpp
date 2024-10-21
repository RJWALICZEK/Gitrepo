#include <iostream>

using namespace std;

 // left = i*2+1
// right = i*2+2

   void heapSort(int *array,int n);
    void buildHeap(int *array,int n);
    void heapify(int *array, int n, int i);



int main(){

    int size =10;
    int numbers[size] = {9,7,2,5,4,1,10,9,21,3};
  
    heapSort(numbers, size);
    cout << "\tindex\t  value"<< endl;;
    for (int i=0; i<size; i++)
    {
        cout << "\t " << i << "    ->    " << numbers[i] << endl;
    }

    cout << endl;
    system("pause"); 
    return 0;
}

   void heapSort(int *array,int n)
   {
        buildHeap(array,n);
        for(int i=n-1;i>=0;i--)
        {
            swap(array[0],array[i]);
             heapify(array, i, 0);
        }
   }

void buildHeap(int *array,int n)
{
    for (int i= ((n/2)-1); i>=0; i--)
    {
        heapify(array, n, i);
    }
}

void heapify(int *array,int n,int i)
{
    int left = i*2+1;
    int right = i*2+2;
    int largest = i;
    if(left<n && array[left]>array[i])
    {
        largest=left;
    }
    if(right<n && array[right]>array[largest])
    {
        largest=right;
    }
    if ( largest != i)
    {
        swap(array[i],array[largest]);
        heapify(array, n, largest);
    }
}
