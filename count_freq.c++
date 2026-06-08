#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int fre[256]={0};
    for(int i=0;i<str.length();i++){
        for(int i=0;i<str.length();i++){
            fre[str[i]]++;

        }
        for(int i=0;i<256;i++){
            if(fre[i]>0){
                cout<<char(i)<<" : "<<fre[i]<<endl;
            }
        }
        return 0;

    }
}