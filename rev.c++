#include<iostream>
using namespace std;
int revs(int num){
    int rev;
    while(num>0){
        rev=rev*10+num%10;
        num=num/10;
    }
    return rev;
}
int main(){
    int num;
    cin>>num;
    cout<<"reverse ="<<revs;
    return 0;
}
