#include <iostream>
using namespace std;

void findSymmetricPairs(int arr[][2], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i][0] == arr[j][1] &&
                arr[i][1] == arr[j][0]) {
                
                cout << "(" << arr[i][0] << ", "
                     << arr[i][1] << ") and ("
                     << arr[j][0] << ", "
                     << arr[j][1] << ")" << endl;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n][2];

    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    findSymmetricPairs(arr, n);

    return 0;
}