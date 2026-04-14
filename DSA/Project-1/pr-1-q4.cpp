#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, -2, 3, -4, 5, 0, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int positive = 0, negative = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            positive++;
        }
        else if(arr[i] < 0) {
            negative++;
        }
    }

    cout << "Positive numbers: " << positive << endl;
    cout << "Negative numbers: " << negative << endl;

    return 0;
}