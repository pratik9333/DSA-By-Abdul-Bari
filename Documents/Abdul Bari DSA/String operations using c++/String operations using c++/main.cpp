//
//  main.cpp
//  String operations using c++
//
//  Created by Pratik Aswani on 03/02/22.
//

#include <iostream>

using namespace std;

void findLength(char str[]){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
}


void changeCase(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i]>=97 && str[i]<=122){
            str[i] -= 32;
        }
        else if(str[i]>=65 && str[i]<=90){
            str[i] += 32;
        }
        cout<<str[i];
        i++;
    }
}

void countWords(char arr[]){
    int i = 0, count = 1;
    while (arr[i] != '\0'){
        if(arr[i] == ' '){
            if(arr[i-1] != ' '){
                count++;
            }
        }
        i++;
    }
    cout<<"words in string are = "<<count<<"\n";
}

void validate(char arr[]){
    int i = 0, flag = 0;
    while(arr[i] != '\0'){
        if(!(arr[i]>=65 && arr[i]<=90) && !(arr[i]>=97 && arr[i]<=122) && !(arr[i] >=48 && arr[i] <= 57)){
            cout<<"Invalid String";
            flag  = 1;
            break;
        }
        i++;
    }
    if(flag == 0)
        cout<<"Validate String";
}

void reverse(char arr[],int len){
    int i = 0,j = len-1, temp;
    while (i < j){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    cout<<arr;
}

void compare(char arr[]){
    int i ,j;
    char s[] = "madam";
    for(i = 0, j =0 ; arr[i]!= '\0' && s[j] != '\0'; i++,j++){
            if(arr[i]!=s[j])
                break;
        }
if(arr[i] == s[j]){
    cout<<"Equal";
}
else{
    cout<<"Not Equal";
}
    if(arr[i] > s[j]){
        cout<<"First Greater";
    }
    if(arr[i] < s[j]){
        cout<<"Second Greater";
    }
}

void checkPalindrome(char arr[]){
    int i = 0 , k = 4;
    char s[] = "madag";
    while(i < k){
        if(arr[i] != s[k]){
            cout<<"Not Palindrome";
            break;
        }
        i++;
        k--;
    }
}

void checkDuplicate(char s[]){
    int i;
    
    int h[27];
    
    for(i = 0 ; i<27; i++){
        h[i] = 0;
    }
    
    for(i=0; s[i]!= '\0'; i++){
        h[s[i] - 97]++;
    }
    
    for(i=0; s[i]!='\0'; i++){
        cout<<h[s[i]];
    }
    
    //for(i = 0; )
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char str[] = "finding";
    
    checkDuplicate(str);
    return 0;
}
