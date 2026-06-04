#include<iostream>
using namespace std;
 int countdivisor(int n){
    int count=0;
    for(int i=0;i*i<=n;i++){
        if(n%i==0){
            if(i==n/i)
            count++;
            else
            count+=2;
        }
    }
    return count;

}
int main(){
    int start,end;
    cout<<"Enter range:";
    cin>>start>>end;
    cout<<"number with exactly 9 divison are:";
    for(int i=start;i<=end;i++){
        if(countdivisor(i)==9)
        cout<<i<<" ";
    }
}