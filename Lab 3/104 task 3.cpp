#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time() : hour(0), minute(0), second(0)
    {
    }

    int hours() { return hour; }

    int minutes() { return minute; }

    int seconds() { return second; }

    void reset(int _h, int _m, int _s)
    {
        hour = _h;
        minute = _m;
        second = _s;
    }

    void advance(int _h, int _m, int _s)
    {
        second += _s;
        if (second > 59)
        {
            minute += second / 60;
            second %= 60;
        }

        minute += _m;
        if (minute > 59)
        {
            hour += minute / 60;
            minute %= 60;
        }

        hour += _h;
        if (hour > 23)
        {
            hour %= 24;
        }
    }

    void print()
    {
        cout << "Current time is " << hour << ":" << minute << ":" << second << '\n';
    }
};

int main()
{
    Time bdTime;

    bdTime.print();

    bdTime.advance(4, 23, 53);
    bdTime.print();

    bdTime.advance(56, 50, 13);
    bdTime.print();

    bdTime.reset(10, 10, 10);
    cout << "hour: " << bdTime.hours() << "\nminute: " << bdTime.minutes() << "\nsecond: " << bdTime.seconds() << '\n';

    return 0;
}