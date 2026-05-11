#include<iostream>
using namespace std;

class Sort
{
private:
    int arr[100];
    int size;

public:

    void getData()
    {
        cout << "Enter Array Size : ";
        cin >> size;

        for(int i = 0; i < size; i++)
        {
            cout << "Enter Element " << i + 1 << " : ";
            cin >> arr[i];
        }
    }

    void display()
    {
        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void quickSort(int low, int high)
    {
        if(low < high)
        {
            int pivot = partition(low, high);

            quickSort(low, pivot - 1);
            quickSort(pivot + 1, high);
        }
    }

    int partition(int low, int high)
    {
        int pivot = arr[low];
        int start = low;
        int end = high;

        while(start < end)
        {
            while(arr[start] <= pivot)
            {
                start++;
            }

            while(arr[end] > pivot)
            {
                end--;
            }

            if(start < end)
            {
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
            }
        }

        int temp = arr[low];
        arr[low] = arr[end];
        arr[end] = temp;

        return end;
    }

    void sorting()
    {
        quickSort(0, size - 1);
    }
};

int main()
{
    Sort s;

    s.getData();

    cout << "\nOriginal Array : ";
    s.display();

    s.sorting();

    cout << "Sorted Array : ";
    s.display();

    return 0;
}