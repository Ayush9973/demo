#include<iostream>
#include<string>
using namespace std;
int main(){
cout<<"Enter your string";
string str;
cin>>str;
for(int i=0;i<=str.length();i++){
    if(str.at(i)>='A'&&str.at(i)<='z')
    str.at(i)+=32;
    else if(str.at(i)>='a'&&str.at(i)<='z')
    str.at(i)-=32;

}
cout<<str;
return 0;
}