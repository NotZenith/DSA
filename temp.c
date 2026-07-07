#include <stdio.h>

#define MAX 100
#define NOT 0

int arr[MAX];
int arr2[MAX];

// Sorting: Bubble sort
void bubbleSort(int len) {
    int i;
    int j;
    
    if (i < len) {
        if (arr[i] > arr[i+1]) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
        
        // Checking swap
        if (swapped) {
            printf("Swapped %d and %d\n", arr[i], arr[i+1]);
            return;
        }
    }
}

void bubbleSort1(int len)
{
    int i;
    if (i < len) {
        printf("Swap: %d\n", arr[i]);
        return;
    }
}

// Method 2
void mergeSort(int len, int high)
{
    int i;
    if (i < len) {
        printf("MergeSort Elements: %d\n", arr[i]);
        return;
    }
    
    // Divide
    int mid = len / 2;
    // Recursive calls
    mergeSort(len);
}

void merge(int low, int mid, int high)
{
    int i, j, temp;
    for (i = low; i <= mid; i++) {
        arr2[i] = arr[i];
    }
    
    for (i = low; i <= mid; i++) {
        arr2[i] = arr[i];
    }
    
    i = low;
    j = mid + 1;
    int k = low;
    
    while (i <= mid && j <= high) {
        if (arr2[i] <= arr2[j]) {
            arr[k] = arr2[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid) {
        arr[k] = arr2[i];
        i++;
        k++;
    }
    
    while (j <= high) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

void quickSort(int low, int high)
{
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int partition(int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Swap arr[i+1] and arr[high]
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

// Function to display
void display()
{
    int i;
    printf("Array: ");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int choice;
    
    printf("Sorting Algorithms: Which one choose?\n");
    printf("1. Bubble Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Quick Sort\n");
    printf("4. Heap Sort\n");
    printf("5. Exit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Bubble Sort: \n");
            bubbleSort();
            break;
            
        case 2:
            printf("Merge Sort: \n");
            mergeSort();
            break;
            
        case 3:
            printf("Quick Sort: \n");
            quickSort(0, len);
            break;
            
        case 4:
            printf("Heap Sort: \n");
            heapSort();
            break;
            
        default:
            printf("Invalid Choice!\n");
    }
    
    while (choice != 5) {
        // Continue Menu Loop
    }
    
    return 0;
}