#include<stdio.h>  
// Function to swap two elements 
void swapElements(int* x, int* y) 
{ 
int temp = *x; 
*x = *y; 
*y = temp; 
}   
// Partition function
int partition (int arr[], int lowIndex, int highIndex) 
{ 
int pivotElement = arr[highIndex];
int i = (lowIndex - 1); 
for (int j = lowIndex; j <= highIndex- 1; j++) 
{ 
if (arr[j] <= pivotElement) 
{ 
i++; 
swapElements(&arr[i], &arr[j]); 
} 
} 
swapElements(&arr[i + 1], &arr[highIndex]); 
return (i + 1); 
}   
// QuickSort Function
void quickSort(int arr[], int lowIndex, int highIndex) 
{ 
if (lowIndex < highIndex) 
{ 
int pivot = partition(arr, lowIndex, highIndex); 
// Separately sort elements before & after partition 
quickSort(arr, lowIndex, pivot - 1); 
quickSort(arr, pivot + 1, highIndex); 
} 
}   
// Function to print array
void printArray(int arr[], int size) 
{ 
int i; 
for (i=0; i < size; i++) 
printf("%d ", arr[i]); 
}   
// Main Function 
int main() 
{ 
int arr[] = {81, 27, 38, 99, 51, 5}; 
int n = sizeof(arr)/sizeof(arr[0]); 
quickSort(arr, 0, n-1); 
printf("Sorted array: "); 
printArray(arr, n); 
return 0; 
}
