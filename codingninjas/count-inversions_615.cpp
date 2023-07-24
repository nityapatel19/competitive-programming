#include <bits/stdc++.h> 

long long merge(long long array[], int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
    long long count = 0;
 
    // Create temp arrays
    auto *leftArray = new long long[subArrayOne],
         *rightArray = new long long[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            count += (subArrayOne-indexOfSubArrayOne);
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
    return count;
}
long long mergeSort(long long array[], int const begin, int const end)
{
    if (begin >= end)
        return 0;

    int count = 0;
    int mid = begin + (end - begin) / 2;
    count += mergeSort(array, begin, mid);
    count += mergeSort(array, mid + 1, end);
    count += merge(array, begin, mid, end);
    return count;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr, 0, n-1);
}
