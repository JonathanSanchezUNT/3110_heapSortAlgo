//
//  main.cpp
//  Assignment3
//
//  Created by Jonathan Sanchez on 3/20/20.
//  Copyright © 2020 Jonathan Sanchez. All rights reserved.
//
#include "Heap_Sort.hpp"

int main()
{
    string line;
    int amountOfNumbers;
    int numOfLines = 0;
    
     ifstream myfile ("data3.txt");
    ofstream outFile;
    outFile.open("output3.txt");
     if (myfile.is_open())
     {
       while ( getline (myfile,line))
       {
           amountOfNumbers = 0;
           double arr[100];
           stringstream ss(line);
           double value;
           numOfLines++;
           
           while (ss>>value)
           {
               arr[amountOfNumbers++] = value;
           }
         cout << "\nLine " << numOfLines << ": "<< line << '\n';
           
           heapSort(arr, amountOfNumbers);
           
           outFile << "(heap-sort) Sorted Line " << numOfLines << ": ";

           cout<<"(heap-sort) Sorted Line " << numOfLines << ": ";
           for (int i = 0; i < amountOfNumbers; i++)
           {
               outFile << arr[i] << ", ";
               cout<< arr[i]<<", ";
           }
       }
       myfile.close();
         cout << endl;
     }
     else cout << "Unable to open file";
    
    
}

