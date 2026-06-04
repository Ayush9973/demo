#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number";
    cin>>n;
    int handshakes=n*(n-1)/2;
    cout<<"Maximunm handshakes="<<handshakes;
    return 0;
}