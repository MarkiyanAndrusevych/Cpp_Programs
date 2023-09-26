//Task Insertion sort [array]
#include <iostream>
#include <algorithm>

using namespace std;

void Insertion_Sort(int array[], const int length)
{
    for (int i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

//Insertion sort testing feature
void run_tests()
{
    int arr1[] = { 55, 24, 32, 11, 44 };
    const int len1 = size_t (arr1);
    Insertion_Sort(arr1, len1);
    for (const int i : arr1) {
        if (i != 11 && i != 24 && i != 32 && i != 44 && i != 55) {
            cout << "Test case 1 failed" << endl;
            return;
        }
    }

    //Check if the array num 2 is sorted correctly
    int arr2[] = { 1, 2, 3, 4, 5 };
    const int len2 = size_t(arr2);
    Insertion_Sort(arr2, len2);
    for (const int i : arr2) {
        if (i != 1 && i != 2 && i != 3 && i != 4 && i != 5) {
            cout << "Test case 2 failed" << endl;
            return;
        }
    }

    cout << "All test cases passed!!" << endl;
}

int main()
{
    int array[] = { 55, 24, 32, 11, 44 };
    const int length = size_t(array);
    Insertion_Sort(array, length);
    for (int j = 0; j < length; j++) {
        cout << "array[" << j << "] = " << array[j] << endl;
    }
    cout << endl;

    run_tests();

    return 0;
}