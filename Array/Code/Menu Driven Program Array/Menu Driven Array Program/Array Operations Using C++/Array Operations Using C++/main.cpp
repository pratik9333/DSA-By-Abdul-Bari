//
//  main.cpp
//  Array Operations Using C++
//
//  Created by Pratik Aswani on 28/01/22.
//

#include <iostream>

using namespace std;

class Array{
private:
    int *A;
    int length;
    int size;
    void swap (int *x, int *y);
public:
    Array(){
        length = 0;
        size = 10;
        A = new int[size];
    }
    ~Array(){
        delete []A;
    }
    void displayArray();
    void insertElement(int index, int element);
    void deleteElement(int index);
    int linearSearch(int key);
    int binarySearch(int key);
    void reverseArray();
    void rotate(int iterations, int rotate);
    int checkArrayIsSort();
    void insertSortedArray(int element);
    void reArrange();
};


// display array
void Array::displayArray(){
    int i;
    cout<<"length = "<<length<<"\n";
    for(i = 0; i<length ; i++){
        cout<<i<<"\n";
        cout<<A[i]<<"\n";
    }
}

//insert element at given position
void Array::insertElement(int index, int element){
    int i;
    if(index <=length && index != -1){
    cout<<length<<"\n";
    for(i=length - 1; i>=index; i--){
        A[i+1] = A[i];
    }
    length++;
    A[index] = element;
    }
    else{
        cout<<"Enter correct index";
    }
}

//delete element at given position
void Array::deleteElement(int index){
    int i;
    if(index < length && index != -1){
        for(i=index; i < length - 1; i++){
            A[i] = A[i+1];
        }
        length--;
    }
    else{
        cout<<"Enter correct index";
    }
}

void Array::swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

//search element at given position - linear search approach
int Array::linearSearch(int key){
    for(int i = 0; i < length; i++){
        if(A[i] == key){
            
            // transposition method
            swap(&A[i], &A[i - 1]);
        
            //back to head method
            //swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

//search element at given position - binary search approach
int Array::binarySearch(int key){
    int mid,low,high;
    
    low = 0;
    high = length - 1;
    mid = (low+high)/2;
    
    while (low < high){
        if(A[mid] == key){
            return mid;
        }
        else if(key < A[mid]){
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

/*//search element at given position - binary search using recursive approach
int resursiveBinarySearch(struct Array arr, int key){
    return 0;
}*/

//reverse an array
void Array::reverseArray(){
    int low=0, c = 0 ,high = length-1;
    while(low < high && low != high){
        swap(&A[low],&A[high]);
        low++;
        high--;
        c++;
    }
    cout<<"\n";
}

//rotate array
void Array::rotate(int rotate, int iterations){
    int i, temp, j;
    if(rotate == 1){
        // left shift
        for(j=0; j<iterations; j++){
            temp = A[length-1];
            for(i = length -1; i>0; i--){
                A[i] = A[i-1];
            }
            A[i] = temp;
        }
    }
    else{
        // right shift
        for(j=0; j<iterations; j++){
            temp = A[0];
            for(i = 0; i<length-1; i++){
                A[i] = A[i+1];
            }
            A[i] = temp;
        }
    }
}

//operations on the sorted array

//check if array is sorted
int Array::checkArrayIsSort(){
    int i;
    for(i=0;i<length-2;i++){
        if(A[i] > A[i+1]){
            return -1;
        }
    }
    return 0;
}

//insert element in sorted array
void Array::insertSortedArray(int element){
    int lastItem = length-1;
    if(length == size)
        return;
    while(element < A[lastItem] && lastItem!=0){
        A[lastItem + 1] = A[lastItem];
        lastItem--;
    }
    A[lastItem + 1] = element;
    length++;
}

//rearrange -neg on left side and +pos on right side
void Array::reArrange(){
    int i=0,j=length-1;
    while (i < j){
        while(A[i]<0)
            i++;
        while(A[j]>=0)
            j--;
        if(i<j) swap (&A[i], &A[j]);
    }
}

int main(int argc, const char * argv[]) {
    int s,x,index,ch;
    Array *arr1; // doubts
    arr1 = new Array();
    
    do
    {
        cout<<"\n\nMenu\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Search\n";
        cout<<"4. Display\n";
        cout<<"5. Reverse\n";
        cout<<"6. Rotate\n";
        cout<<"7. Check if array is sort\n";
        cout<<"8. Insert element in sorted array\n";
        cout<<"9. Rearrange neg and pos values\n";
        cout<<"enter you choice ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter an element and index ";
                cin>>x>>index;
                arr1->insertElement(index,x);
                break;
                
            case 2:
                cout<<"Enter index ";
                cin>>index;
                arr1->deleteElement(index);
                break;
                
            case 3:
                cout<<"Enter element to search";
                cin>>x;
                arr1->binarySearch(x);
                break;
                
            case 4:
                arr1->displayArray();
            
            case 5:
                arr1->reverseArray();
                break;
                
            case 6:
                arr1->rotate(1, 1);
                break;
            
            case 7:
                arr1->checkArrayIsSort();
                break;
            
            case 8:
                cout<<"Enter element to insert";
                cin>>x;
                arr1->insertSortedArray(x);
                break;
            
            case 9:
                arr1->reArrange();
                break;
        }
    }while(ch<6);
}



