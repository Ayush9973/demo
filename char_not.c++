#include<iostream>
using namespace std;
int main(){
    cout<<"Enter a Char: ";
    char str;
    cin>>str;
    if('!'==str||'@'==str||'%'==str||'$'==str)
    cout<<"special char";
    else
    cout<<"alahabet";

}