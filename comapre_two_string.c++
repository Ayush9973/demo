#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char srt[100],str2[100];
    cout<<"Enter first string:";
    cin >>srt;
    cout<<"Enter scenod sting";
    cin>>str2;
    if(strcmp(srt ,str2)==0){
        cout<<"equal";
    }
    else
    cout<<"not equal";
    return 0;
}