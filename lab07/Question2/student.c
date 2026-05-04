#include <stdlib.h>

void merge(int arr[], int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int *leftArr = malloc(leftSize * sizeof(int));
    int *rightArr = malloc(rightSize * sizeof(int));

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

void mergeSortHelper(int arr[], int left, int right){
    if (left >= right){
        return;
    }
    
    int mid = left + (right - left)/ 2;
    
    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    
    merge(arr, left, mid ,right);
}

void mergeSort(int arr[], int size) {
    if (size <= 1){
        return;
    }
    
    mergeSortHelper(arr, 0, size - 1);
}

