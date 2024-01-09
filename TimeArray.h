#include <iostream>
#include <windows.h>
#include <time.h>
#include <C:\Users\Amina\OneDrive\Рабочий стол\Учеба\2 курс\ООП и Теория алгоритмов\Теория алгоритмов\готовое\лаба 5.3\лаба 5.3\Time.h>
using namespace std;

class TimeArray {
private:
	double SrH, SrM, SrS;
	static int count;
	int h, m, s;;
public:
	int SizeArr;
	Time* arr;

	TimeArray() {
		count++;
	}

	TimeArray(int size) {
		count++;
		SizeArr = size;
		arr = new Time[SizeArr];
		for (int i = 0; i < size; i++)
		{
			cout << "Введите часы: ";
			cin >> h;
			cout << "Введите минуты: ";
			cin >> m;
			cout << "Введите секунды: ";
			cin >> s;
			arr[i] = Time(h, m, s);
		}
	}

	TimeArray(int size, bool b) {
		count++;
		SizeArr = size;
		arr = new Time[SizeArr];
		for (int i = 0; i < size; i++)
		{
			h = rand() % 23;
			m = rand() % 59;
			s = rand() % 59;
			arr[i] = Time(h, m, s);
		}
	}

	~TimeArray() {
		count--;
	}

	void NumOut(int i) {
		arr[i-1].display();
	}

	void ArrayOut() {
		for (int i = 0; i < SizeArr; i++)
		{
			arr[i].display();
		}
	}

	static int GetCount() {
		return count;
	}

	void SrArefm(){
		for (int i = 0; i < SizeArr; i++)
		{
			SrH += arr[i].hours;
			SrM += arr[i].minutes;
			SrS += arr[i].seconds;
		}
		SrH = SrH / SizeArr;
		SrM = SrM / SizeArr;
		SrS = SrS / SizeArr;
		cout << "\nСреднее арефметическое для каждого параметра:\n";
		cout << "Время: " << SrH << " часов, " << SrM << " минут, " << SrS << " секунд." << endl;
		return;
	}
};

int TimeArray::count = 0;