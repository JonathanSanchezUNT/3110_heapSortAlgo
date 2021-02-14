//
//  Heap_Sort.cpp
//  Assignment3
//
//  Created by Jonathan Sanchez on 3/20/20.
//  Copyright © 2020 Jonathan Sanchez. All rights reserved.
//

#include "Heap_Sort.hpp"


void heapify(double *arr, int n, int root)
{
    int largest = root; //root is always the largest node
    int left = (2*root)+1;
    int right = (2*root)+2;
    
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest!=root)
    {
        //swap root and largest
        swap(arr[root], arr[largest]);
        //recursive heapify sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(double *arr, int n)
{
    for(int i = n/2 - 1;i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    
    for(int i = n-1; i>=0; i--)
    {
        //swap current root to end
        swap(arr[0], arr[i]);
        //call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
