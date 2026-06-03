#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter two number";
    cin>>a;
    cin>>b;
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    cout<<"GCD="<<a;
}