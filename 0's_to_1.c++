#include<iostream>
using namespace std;
int main(){
    int num,res=0,place=0;
    cout<<"Enter s number:";
    cin>>num;
    if(num==0){
        cout<<"Resut=1";
        return 0;
    }
    while(num>0){
        int digit=num%10;
        if(digit==0)
        digit=1;

        res=res+digit*place;
        place*=10;
        num/=10;
    }
    cout<<"Result="<<res;
    return 0;
}