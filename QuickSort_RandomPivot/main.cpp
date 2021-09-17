#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

// using LOMUTO Partitioning

void quicksort(int arr[], int low, int high);

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    printf("Sorted array: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int partition_r(int arr[], int left, int right){
    srand(time(NULL));
    int random = left + rand() % (right - left);

    swap(arr[random], arr[right]);

    int pivot = arr[right];

    int i = left - 1;
    for(int j = left; j <= right - 1; j++){
        if(arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quicksort(int arr[], int left, int right){
    if(left < right) {
        int pIndex = partition_r(arr, left, right);

        quicksort(arr, left, pIndex - 1);
        quicksort(arr, pIndex + 1, right);
    }
    return;
}
