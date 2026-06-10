#include<iostream>
using namespace std;
bool ispalidrome(int num){
  int original =num; 
  int rev=0; 
  while(num>0){
    rev=rev*10+num%10;
    num/=10 ;
  }
  return original==rev;
}
int coundigitis(int num){
  int count =0;
  while(num>0){
    count++;
    num/=10;
  }
  return 0;
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    int longestpaloindrome=-1;
    int maxdigits=0;
    for(int i=0;i<n;i++){
      if(ispalidrome(arr[i])){
        int digits=coundigitis(arr[i]);

        if(digits>maxdigits){
          maxdigits=digits;
          longestpaloindrome=arr[i];
        }
      }
    }
  
    if(longestpaloindrome!=-1)
      cout<<"longest Plaindrome="<<longestpaloindrome;
    
    else
    cout<<"No palindrome found";

  return 0;
}
}