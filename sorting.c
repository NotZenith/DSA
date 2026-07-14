#include<stdio.h>
#define MAX 100

int arr[MAX];
int n = 0;

void insertElement(){
    if(n==MAX){
        printf("Array is full\n");
        return;
    }
    
    int value;
    printf("Enter element to insert: ");
    scanf("%d",&value);
    
    arr[n]= value;
    n++;
    
    printf("Element inserted successfully.\n");
    
}

void displayArray(){
    int i;
    if(n==0){
        printf("array is empty");
        return;
    }
    printf("\nElements: \n");
    for( i = 0; i < n; i++){
        printf("%d",arr[i]);
    }
}

void bubbleSort(){
    int i, j, temp;
    for( i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if( arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nSorted completed.\n");
}

void merge(int low, int mid, int high){
    int temp[MAX];
    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high){
        
            if(arr[i] <= arr[i++]){
                temp[k++]=arr[i++];
            }
        else{
            temp[k++]= arr[j++];
        }
    
    }
    while(i<= mid){
        temp[k++] = arr[i++];
    }
    while(i <= mid){
        temp[k++]= arr[i++];
    }

    while(j <= high){
        temp[k++]= arr[j++];
    }
    for(i = low; i <= high; i++){
        arr[i]= temp[i];
    }
}

void mergeSort(int low, int high){
    if(low<high){
        int mid = (low+high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);

        merge(low, mid, high);
    }
}

int partition(int low, int high){
    int pivot = arr[high];
    int i = low-1;
    int j, temp;

    for(j = low; j <high; j++){
        if(arr[j]<pivot){
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j]= temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1]= arr[high];
    arr[high] =  temp;
    return i+1;
}

void quickSort(int low, int high){
    if(low<high){
        int p = partition(low, high);

        quickSort(low, p-1);
        quickSort(p+1, high);
    }
}

int main(){
    int choice;

    do {
        printf("\n");
        printf("1: Insert Element\n");
        printf("2: Display Array\n");
        printf("3: Bubble Sort\n");
        printf("4: Merge Sort\n");
        printf("5: Quick Sort\n");
        printf("6: Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
    

    switch(choice){
        case 1:
            insertElement();
            break;

        case 2:
            displayArray();
            break;

        case 3:
            if(n == 0){
                printf("\nArray is empty~\n");
            }
            else{
                bubbleSort();
            }
            break;
        
        case 4:
            if(n == 0){
                printf("\nArray is empty\n");
            }
            else{
                mergeSort(0, n-1);
                printf("\n Merge sort Completed \n");
            }
            break;

        case 5:
            if(n==0){
                printf("Array is empty");
            }
            else{
                quickSort(0, n-1);
                printf("Quick sort completed\n");
            }
            break;
        case 6:
            printf("Program temriinated.");
            break;
        
        default:
            printf("Invalid choice.\n");
    }
    } while(choice != 6);
    return 0;

}