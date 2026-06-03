#include<iostream>
using namespace std;
int main(){
    cout<<"Enter three number";
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    if(a>b&&a>c){
        cout<<"first number is grt number"<<a;
    }
        else if(b>a&&b>c){
            cout<<"second number is grt nubmber"<<b;
        }
        else
        cout<<"third numberis grt number"<<c;
        return 0;

    }
