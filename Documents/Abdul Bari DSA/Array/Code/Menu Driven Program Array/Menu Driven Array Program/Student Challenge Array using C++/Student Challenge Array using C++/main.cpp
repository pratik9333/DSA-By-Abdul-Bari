//
//  main.cpp
//  Student Challenge Array using C++
//
//  Created by Pratik Aswani on 29/01/22.
//

#include <iostream>

using namespace std;

class Array{
private:
    int length;
    int size;
    int *A;
public:
    Array(int sz){
        A = new int[sz];
        length = 0;
        size = sz;
    }
    void insertElement();
    void findMissingElement();
    void findDuplicate();
    void findPairSumK(int a);
    void findMaxAndMinSingleScan();
};

void Array::insertElement(){
    int i;
    for(i=0; i<size; i++){
        cin>>A[i];
    }
}

void Array::findMaxAndMinSingleScan(){
    int i, min = A[0], max = A[0];
    for(i = 0; i <size; i++){
        if(A[i] > max){
            max = A[i];
        }
        if(A[i] < min){
            min = A[i];
        }
    }
    cout<<min<<"\t"<<max<<"\n";
}

void Array::findPairSumK(int target){
    int max=A[0],i,x;
    for(i = 0; i <size; i++){
        if(max<A[i]){
            max = A[i];
        }
    }
    int H[max+1];
    
    for(i = 0; i < max+1 ; i++){
        H[i] = 0;
    }
    for(i = 0; i < size;i++){
        if(target >= A[i]){
            x = target - A[i];
            if(H[x] != 0){
                cout<<x<<"\t"<<A[i]<<"\n";
            }
            H[A[i]] = 1;
        }
    }
}



void Array::findMissingElement(){
    int max = A[0], i;
    for(i=1; i<size;i++){
        if(max<A[i]){
            max = A[i];
        }
    }
    int H[max];
    for(i=0; i < max+1; i++){
        H[i] = 0;
    }
    for(i=0;i<size;i++){
        H[A[i]]++;
        //cout<<H[A[i]]<<"\n";
    }
    for(i=0 ; i<max+1;i++){
        if(H[i]==0){
            //cout<<H[i]<<"\n";
            cout<<i<<" is the missing element"<<"\n";
        }
    }
}


void Array::findDuplicate(){
    int max = A[0], i;
    for(i=1; i<size;i++){
        if(max<A[i]){
            max = A[i];
        }
    }
    int H[max];
    for(i=0; i < max+1; i++){
        H[i] = 0;
    }
    for(i=0;i<size;i++){
        H[A[i]]++;
        //cout<<H[A[i]]<<"\n";
    }
    for(i=0 ; i<max+1;i++){
        if(H[i]!=0){
            //cout<<H[i]<<"\n";
            cout<<i<<" repeated "<<H[i]<<"\n";
        }
    }
}

int main(int argc, const char * argv[]) {
    
    Array *arr = new Array(7);
    
    arr->insertElement();
    arr->findMaxAndMinSingleScan();
    return 0;
}
