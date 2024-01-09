#include <iostream>
#include <time.h>
#include <C:\Users\Amina\OneDrive\Рабочий стол\Учеба\2 курс\ООП и Теория алгоритмов\Теория алгоритмов\готовое\лаба 5.3\лаба 5.3\TimeArray.h>

using namespace std;

TimeArray Arr1(int size);
TimeArray ArrRand(int size);

int main()
{
    srand(time(0));
    setlocale(0, "");
    Time T;
    TimeArray arr;
    int h, m, s, size, index, choice;

    cout << "Введите размер массива: ";
    cin >> size;

    cout << "Выберите тип заполнения массива:\n"
        "1. Вручную\n"
        "2. Рандомными числами от 0 до 59\n"
        "Ваш выбор: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        arr = Arr1(size);
        break;
    case 2:
        arr = ArrRand(size);
        break;
    default:
        return 0;
        break;
    }
    cout << "Ваш массив:\n";
    arr.ArrayOut();

    cout << "\nВведите к какой элемент вы хотите посмотреть: ";
    cin >> index;
    cout << "Ваш элемент:\n";
    arr.NumOut(index);
    arr.SrArefm();
    cout << "\nКоличество объектов времени: " << Time::getCount() << endl;
    return 0;
}

TimeArray Arr1(int size)
{
    TimeArray arr(size);
    return arr;
}

TimeArray ArrRand(int size)
{
    TimeArray arr(size, true);
    return arr;
}