//EM DESENVOLVIMENTO!!!

#include <stdio.h>

void countingSort(int array[], int size) {
    int output[1000];

    // Find the largest element of the array
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
        max = array[i];
    }

    // The size of count must be at least (max+1) but
    // we cannot declare it as int count(max+1) in C as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int count[max];

    // Initialize count array with all zeros or use calloc or use memset 0
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }
    int j = 0;
    for(int i = 0; i < max;){
        while(count[i] > 0){
            array[j] = i;
            j++;
            count[i]--;
        }
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  int array[] = {4,8,7,9,8,5,2,1,2,8,7,4,1,2,5,4,8,9,3,1,4,7,2,1,4,2,3,23,56,98,784,54,21,654,77,124,785,354,147};
  int n = sizeof(array) / sizeof(array[0]);
  countingSort(array, n);
  printArray(array, n);
}
