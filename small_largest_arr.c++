#include<iostream>
using namespace std;
int samllest(int arr[],int n){
    int mai=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<mai)
        mai=arr[i];
    }
    return mai;
}
int largest(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Samllest ="<<samllest(arr,n)<<endl;
    cout<<"laregst ="<<largest(arr,n);
    return 0;
}