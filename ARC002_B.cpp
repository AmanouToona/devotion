#include <bits/stdc++.h>
using namespace std;
using ll = long long;


bool leap_year (int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) );
}

int main() {
    int year, month, day;
    char srash;

    cin >> year >> srash >> month >> srash >> day;

    vector<int> days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    while (true) {
        while(month < 13) {
            while(day <= days[month - 1]) {
                if (year % (month * day) == 0) {
                    cout << year << '/' << setw(2) << setfill('0') << to_string(month) << '/' << setw(2) << setfill('0') << to_string(day) << endl;
                    return 0;
                }
                if (month == 2 && day == 28 && !leap_year(year)) break;
                day++;
            }
            day = 1;
            month++;
        }
        month = 1;
        year++;
    }
}