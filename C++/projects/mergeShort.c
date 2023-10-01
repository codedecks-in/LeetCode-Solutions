#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 5

void merge_sort(int, int);
void merge_array(int, int, int, int);

int arr_sort[MAX_SIZE];

int main() {
  int i;

  printf("Simple Merge Sort Example - Functions and Array\n");
  printf("\nEnter %d Elements for Sorting\n", MAX_SIZE);
  for (i = 0; i < MAX_SIZE; i++)
    scanf("%d", &arr_sort[i]);

  printf("\nYour Data   :");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", arr_sort[i]);
  }

  merge_sort(0, MAX_SIZE - 1);

  printf("\n\nSorted Data :");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", arr_sort[i]);
  }
  getch();

}

void merge_sort(int i, int j) {
  int m;

  if (i < j) {
    m = (i + j) / 2;
    merge_sort(i, m);
    merge_sort(m + 1, j);
    // Merging two arrays
    merge_array(i, m, m + 1, j);
  }
}

void merge_array(int a, int b, int c, int d) {
  int t[50];
  int i = a, j = c, k = 0;

  while (i <= b && j <= d) {
    if (arr_sort[i] < arr_sort[j])
      t[k++] = arr_sort[i++];
    else
      t[k++] = arr_sort[j++];
  }

  //collect remaining elements 
  while (i <= b)
    t[k++] = arr_sort[i++];

  while (j <= d)
    t[k++] = arr_sort[j++];

  for (i = a, j = 0; i <= d; i++, j++)
    arr_sort[i] = t[j];
}
