#include <iostream>
#include <windows.h>

using namespace std;

class Time
{
private:
    static int count;
public:
    int hours;
    int minutes;
    int seconds;
    Time()
    {
        count++;
    }
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        while (seconds >= 60) { // ���������, ��� ������� �� ������ 59
            seconds -= 60;
            minutes++;
        }
        while (minutes >= 60) { // ���������, ��� ������ �� ������ 59
            minutes -= 60;
            hours++;
        }
        while (hours >= 24) { // ���������, ��� ���� �� ������ 23
            hours -= 24;
        }
        count++;
    }
    ~Time()
    {
        count--;
    }
    Time addSeconds(int s)
    {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds + s;
        int newHours = totalSeconds / 3600 % 24;
        int newMinutes = (totalSeconds / 60) % 60;
        int newSeconds = totalSeconds % 60;

        return Time(newHours, newMinutes, newSeconds);
    }
    static int getCount()
    {
        return count;
    }
    void display()
    {
        cout << "�����: " << hours << " �����, " << minutes << " �����, " << seconds << " ������." << endl;
    }
};
int Time::count = 0;