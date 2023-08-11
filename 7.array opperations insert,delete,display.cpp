#include <stdio.h>
void display(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insert(int arr[], int *size, int index, int element) {
    if (index < 0 || index > *size) {
        printf("Invalid index\n");
        return;
    }
    
    for (int i = *size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    
    arr[index] = element;
    (*size)++;
}
   voiddelete(int arr[], int *size, int index) 
{
    if (index < 0 || index >= *size) 
{
        printf("Invalid index\n");
        return 0;
    }
    
    for (int i = index; i < *size - 1; i++) 
{
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
}

int main() 
{
    int arr[100];
    int size = 0; 
    
    insert(arr, &size, 0, 5);
    insert(arr, &size, 1, 10);
    insert(arr, &size, 1, 7);
    
    display(arr, size);

    voiddelete(arr, &size, 1);
    
    display(arr, size);
    
    return 0;
}