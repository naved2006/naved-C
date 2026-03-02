#include <iostream>
using namespace std;

class Timeconverter {

public :
    
        void secondsToTime(int totalseconds){
            int h ,m ,s;

            h = totalseconds / 3600;
            m = (totalseconds % 3600 ) / 60;
            s = totalseconds % 60;
        
        cout << "Time is: " << h << ":" << m << ":" << s << endl;
    }
        void timeToSeconds(int h, int m, int s){
            int total;

            total = h * 3600 + m * 60 + s;

        cout << "Total seconds are: " << total << endl;   
    }
};

int main(){

    Timeconverter t;
    int choice;

    cout << " 1. Seconds to Time" << endl;
    cout << " 2. Time to Seconds" << endl; 
    cout << "Enter Your Choices";
    cin >> choice;

    switch(choice){
        
        case 1:
        {
            int totalseconds;
            cout << "Total Seconds";
            cin >> totalseconds;

            t.secondsToTime(totalseconds);
            break;
        }

        case 2:
        {
            int h, m, s;

            cout << "Total hours";
            cin >> h;

            cout << "Total minutes";
            cin >> m;

            cout << "Total seconds";
            cin >> s;

            t.timeToSeconds(h, m, s);
            break;
        }

        default:
            cout <<"Wrong choice entered" << endl;

    }
        return 0;
}