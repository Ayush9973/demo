#include<iostream>
using namespace std;
int main(){
    cout<<"Enter a string: ";
    char str[100],str2[100];
    int i;
    cin>>str;
    for(i=0;str[i]!='\0';i++){
        str2[i]=str[i];
    }
    str2[i]='\0';
    cout<<"copied string:"<<str2;
    return 0; 
}
// int main() {
//     char str1[100], str2[100];

//     cout << "Enter a string: ";
//     cin >> str1;

//     strcpy(str2, str1);

//     cout << "Copied string: " << str2;

//     return 0;
// }
