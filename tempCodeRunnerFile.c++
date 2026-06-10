#include<iostream>
using namespace std; 
void remvoe(int arr[],int n){
    for(int i=0;i<n;i++){
        bool duplaicate=false;

        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                duplaicate=true;
                break;
                
            }
        }
        if(!duplaicate){
            cout<<arr[i]<<" ";
        }
    }
}
int main(){
   int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    remvoe(arr, n);

    return 0;
}
