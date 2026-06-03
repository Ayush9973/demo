#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter three number:";
    cin>>a>>b>>c;
    if((a>b&&a<c) || (a<b&&a>c))
    {
        cout<<"second grt  number is first number:"<<a;
    }
    else if ((b>a&&b<c) || (b>c&&b<a)){
         cout<<"second grt  number is second  number:"<<b;
    }
    else{
        cout<<"third is the gt number:"<<c;
    }
}