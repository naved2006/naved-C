#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 20, 5, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int largest = arr[0];
    int secondLargest = -1; 

    for(int i = 1; i < n; i++) {

       
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    cout << "Largest element: " << largest << endl;

    if(secondLargest == -1)
        cout << "Second largest not found";
    else
        cout << "Second largest element: " << secondLargest;

    return 0;
}