#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
#ifndef _HEAP_H
#define _HEAP_H
// In the header file Heap.h
//#ifdef __cplusplus

// https://www.geeksforgeeks.org/heap-sort/

// Heap is a complete Binary Tree
class Heap{
    public:
        static void maxHeapSort(int arr[], int N);
        static void maxHeapify(int arr[], int N, int i);
        static void minHeapSort(int arr[], int N);
        static void minHeapify(int arr[], int N, int i);
};


void Heap::maxHeapify(int arr[], int N, int i) {
    // Let i be the index of target node of this heap (subheap) which might be swapped with its child
    // and N be the total number of this heap (subheap)

    int leftChild = i * 2 + 1;
    int rightChild = i * 2 + 2;

    // Assume the target node is the largest element
    int max_i = i;

    if (leftChild < N && arr[leftChild] > arr[max_i]) {
        max_i = leftChild;
    }

    if (rightChild < N && arr[rightChild] > arr[max_i]) {
        max_i = rightChild;
    }

    // If the target node's child (children) is/are larger than it, swap them
    if (max_i != i) {
        swap(arr[i], arr[max_i]);

        // Continue doing max heapify
        // Now the target node's index becomes max_i
        maxHeapify(arr, N, max_i);
    }

}

void Heap::maxHeapSort(int arr[], int N) {
    // Build a max heap - rearrange array so that root is the larest, and each leaf node is smaller or equal to its parent
    // We start from N/2-1 (Max degree-1 th layer) e.g. N=7 -> Start from 2
    for (int i=N/2-1; i>=0; i--) {
        maxHeapify(arr, N, i);
    }

    // Extract maximum element from heap one by one
    for (int i=N-1; i>0; i--) {
        // Remove the root element (largest element) from the heap - swap root and current last node
        swap(arr[0], arr[i]);
        // Do max heapify
        maxHeapify(arr, i, 0);
    }
}


void Heap::minHeapify(int arr[], int N, int i) {
    // Let i be the index of target node of this heap (subheap) which might be swapped with its child
    // and N be the total number of this heap (subheap)

    int leftChild = i * 2 + 1;
    int rightChild = i * 2 + 2;

    // Assume the target node is the smallest element
    int min_i = i;

    if (leftChild < N && arr[leftChild] < arr[min_i]) {
        min_i = leftChild;
    }

    if (rightChild < N && arr[rightChild] < arr[min_i]) {
        min_i = rightChild;
    }

    // If the target node's child (children) is/are larger than it, swap them
    if (min_i != i) {
        swap(arr[i], arr[min_i]);

        // Continue doing max heapify
        // Now the target node's index becomes min_i
        minHeapify(arr, N, min_i);
    }

}

void Heap::minHeapSort(int arr[], int N) {
    // Build a min heap - rearrange array so that root is the smallest, and each leaf node is larger or equal to its parent
    // We start from N/2-1 (Max degree-1 th layer) e.g. N=7 -> Start from 2
    for (int i=N/2-1; i>=0; i--) {
        minHeapify(arr, N, i);
    }

    // Extract minimum element from heap one by one
    for (int i=N-1; i>0; i--) {
        // Remove the root element (smallest element) from the heap - swap root and current last node
        swap(arr[0], arr[i]);
        // Do min heapify
        minHeapify(arr, i, 0);
    }
}


#endif
