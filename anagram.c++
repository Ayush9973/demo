#include<iostream>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()!=s2.length()){
        cout<<"not angram";
        return 0;
    }
    int frq[256]={0};
    for(int i=0;i<s1.length();i++){
        frq[s1[i]]++;
        frq[s2[i]]--;
    }
    bool anagram=true;
    for(int i=0;i<256;i++){
        if(frq[i]!=0){
            anagram=false;
            break;
        }
    }
    if(anagram)
    cout<<"Anagram";
    else
    cout<<"Not anagram";
    return 0;
}