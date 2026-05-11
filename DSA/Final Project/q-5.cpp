#include<iostream>
using namespace std;

class Search
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

    void linearSearch()
    {
        int item;
        int flag = 0;
        int count = 0;

        cout << "Enter Search Element : ";
        cin >> item;

        for(int i = 0; i < size; i++)
        {
            count++;

            if(arr[i] == item)
            {
                cout << "Element Found at Index : " << i << endl;
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            cout << "Element Not Found" << endl;
        }

        cout << "Total Comparisons : " << count << endl;
    }
};

int main()
{
    Search s;

    s.getData();

    s.linearSearch();

    return 0;
}