#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);

        if (start > end) return 0;

        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convertToDayOfYear = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int dayOfYear = 0;
            for (int i = 0; i < month - 1; ++i) {
                dayOfYear += days[i];
            }
            dayOfYear += day;
            return dayOfYear;
        };

        return convertToDayOfYear(end) - convertToDayOfYear(start) + 1;

    }
};
