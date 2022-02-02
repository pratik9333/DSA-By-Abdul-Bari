//
//  main.c
//  Menu Driven Array Program
//
//  Created by Pratik Aswani on 25/01/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *A;
    int *B;
    int *C;
    int length;
    int size;
};

// display array
void displayArray(struct Array arr){
    int i;
    //printf("%d", arr.length);
    for(i = 0; i < arr.size ; i++){
        printf("%d ", arr.C[i]);
    }
}

//insert element at given position
void insertElement(struct Array *arr, int index, int element){
    int i;
    if(index <arr->length && index != -1){
    for(i=arr->length - 1; i>=index; i--){
        arr->A[i+1] = arr->A[i];
    }
    arr->length++;
    arr->A[index] = element;
}
    else{
        printf("Enter correct index");
    }
}

//delete element at given position
void deleteElement(struct Array *arr, int index){
    int i;
    if(index < arr->length && index != -1){
        for(i=index; i < arr->length - 1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
    else{
        printf("Enter correct index");
    }
}

void swap (int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//search element at given position - linear search approach
int linearSearch(struct Array *arr, int key){
    for(int i = 0; i < arr->length; i++){
        if(arr->A[i] == key){
            
            // transposition method
            swap(&arr->A[i], &arr->A[i - 1]);
            
            //back to head method
            //swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

//search element at given position - binary search approach
int binarySearch(struct Array arr, int key){
    int mid,low,high;
    
    low = 0;
    high = arr.length - 1;
    mid = (low+high)/2;
    
    while (low < high){
        if(arr.A[mid] == key){
            return mid;
        }
        else if(key < arr.A[mid]){
            high = mid - 1;
            mid = (low + high)/2;
        }
        else{
            low = mid + 1;
            mid = (low + high)/2;
        }
    }
    return -1;
}

//search element at given position - binary search using recursive approach
int resursiveBinarySearch(struct Array arr, int key){
    return 0;
}

//reverse an array
void reverseArray(struct Array *arr){
    int low=0, c = 0 ,high = arr->length-1;
    while(low < high && low != high){
        swap(&arr->A[low],&arr->A[high]);
        low++;
        high--;
        c++;
    }
    printf("c = %d", c);
    printf("\n");
}

//rotate array
void rotate(struct Array *arr, int rotate, int iterations){
    int i, temp, j;
    if(rotate == 1){
        // left shift
        for(j=0; j<iterations; j++){
            temp = arr->A[arr->length-1];
            for(i = arr->length -1; i>0; i--){
                arr->A[i] = arr->A[i-1];
            }
            arr->A[i] = temp;
        }
    }
    else{
        // right shift
        for(j=0; j<iterations; j++){
            temp = arr->A[0];
            for(i = 0; i<arr->length-1; i++){
                arr->A[i] = arr->A[i+1];
            }
            arr->A[i] = temp;
        }
    }
}

//operations on the sorted array

//check if array is sorted
int checkArrayIsSort(struct Array arr){
    int i;
    for(i=0;i<arr.length-2;i++){
        if(arr.A[i] > arr.A[i+1]){
            return -1;
        }
    }
    return 0;
}

//insert element in sorted array
void insertSortedArray(struct Array *arr, int element){
    int lastItem = arr->length-1;
    if(arr->length == arr->size)
        return;
    while(element < arr->A[lastItem] && lastItem!=0){
        arr->A[lastItem + 1] = arr->A[lastItem];
        lastItem--;
    }
    arr->A[lastItem + 1] = element;
    arr->length++;
}

//rearrange -neg on left side and +pos on right side
void reArrange(struct Array *arr){
    int i=0,j=arr->length-1;
    while (i < j){
        while(arr->A[i]<0)
            i++;
        while(arr->A[j]>=0)
            j--;
        if(i<j) swap (&arr->A[i], &arr->A[j]);
    }
}

void mergeArray(struct Array *arr){
    int m = 0, n = 0, k = 0;
    while (m < arr->length && n < arr->length){
        if(arr->A[m] < arr->B[n]){
            arr->C[k] = arr->A[m];
            m++;
            k++;
        }
        else{
            arr->C[k] = arr->B[n];
            n++;
            k++;
        }
    }
    if(m < arr->length){
        while (m < arr->length){
            arr->C[k++] = arr->A[m++];
        }
    }
    if(n < arr->length){
        while (n < arr->length){
            arr->C[k++] = arr->B[m++];
        }
    }
}

int main(int argc, const char * argv[]) {
    int i;
    struct Array arr;
    printf("Enter size of array");
    scanf("%d", &arr.size);
    arr.size = 10;
    arr.length = 5;
    arr.A = (int *)malloc(sizeof(int) * arr.size);
    arr.B = (int *)malloc(sizeof(int) * arr.size);
    arr.C = (int *)malloc(sizeof(int) * arr.size);
    printf("Enter 5 elements for array A\n");
    for(i = 0 ; i<5 ; i++){
        scanf("%d", &arr.A[i]);
    }
    printf("Enter 5 elements for array B\n");
    for(i = 0 ; i<5 ; i++){
        scanf("%d", &arr.B[i]);
    }
    mergeArray(&arr);
    displayArray(arr);
}
