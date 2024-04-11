# include <iostream>
# include "Heap.h"
using namespace std;


int main() {
    int arr[] = { 13, 12, 16, 5, 3, 7 };
    int N = 6;  //sizeof(arr) / sizeof(arr[0]);
    // Do max heap sort if you want to sort an array in ascending order
    Heap::maxHeapSort(arr, N);

    // Do min heap sort if you want to sort an array in descending order
    //Heap::minHeapSort(arr, N);

    cout << "The sorted array is: ";
    for (int i=0; i<N; i++)
        cout << arr[i] << " ";
    cout << "\n";
}