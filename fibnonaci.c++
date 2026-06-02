#include<iostream>
using namespace std;

int main() {
    cout << "Enter number of terms: ";
    int n;
    cin >> n;

    int a = 0, b = 1;

    cout << "Fibonacci Series: ";

    for(int i = 1; i <= n; i++) {
        cout << a << " ";
        int sum = a + b;
        a = b;
        b = sum;
    }

    return 0;
}