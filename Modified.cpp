#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <functional>

using namespace std;

string Modified(double (*func)(double), double arr[], int size)
{
    ostringstream oss;
    oss << setw(5) << left << "|" << setw(8) << left << "i" << setw(5) << left << "|"
        << setw(15) << left << "a[i]" << setw(5) << left << "|" << setw(20) << left << "modified a[i]" << "|" << endl;
    oss << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

    for (int i = 0; i < size; i++)
    {
        double modified = func(arr[i]);
        oss << setw(5) << left << "|" << setw(8) << left << i << setw(5) << left << "|"
            << setw(15) << left << arr[i] << setw(5) << left << "|" << setw(20) << left << modified << "|" << endl;
        arr[i] = modified;
    }

    return oss.str();
}

int main()
{
    const int SIZE = 5;
    double arr[SIZE] = {1.5, 2.6, 3.7, 4.8, 5.9};
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }
//    for (int i = 0; i < SIZE; i++) {
//        cout << "Enter element " << i << ": ";
//        cin >> arr[i];
//    }


    cout << "Original array:" << endl;
    cout << Modified([](double x) { return x; }, arr, SIZE) << endl;

    cout << "Squared array:" << endl;
    cout << Modified([](double x) { return x * x; }, arr, SIZE) << endl;

    cout << "Sin+Cos-Tan array:" << endl;
    cout << Modified([](double x) { return sin(x) + cos(x) - tan(x); }, arr, SIZE) << endl;

    cout << "Rounded array:" << endl;
    cout << Modified([](double x) { return round(x); }, arr, SIZE) << endl;

    return 0;
}
