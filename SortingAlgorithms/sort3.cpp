#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <cassert>
using namespace std;

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int array[], int size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;
    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, size, largest);
    }
}

void build_max_heap(int array[], int size) {

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
}

void heap_sort(int array[], int size) {

    build_max_heap(array, size);

    for (int i = size - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}
void test1()
{
    cout << "Test 1 started... " << endl;
    cout << "Unsorted array: " << endl;
    int arr[10] = { 54,35,878,34,23,86,45,34,234,54 };
    printArray(arr, 10);

    heap_sort(arr, 10);

    cout << "Sorted array:" << endl;

    printArray(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
        {
            assert(arr[i - 1] <= arr[i]);
            break;
        }
        assert(arr[i] <= arr[i + 1]);
    }
    cout << "test 1 passed" << endl;
}

void test2()
{
    cout << "Test 2 started" << endl;
    cout << "Unsorted array:" << endl;
    int arr[10] = { 54,35,878,34,23,86,45,34,234,54 };
    printArray(arr, 10);
    cout << "Sorted array:" << endl;
    int sortedArr[10] = { 23,34,34,35,45,54,54,86,234,878 };
    printArray(sortedArr, 10);
    heap_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        assert(arr[i] == sortedArr[i]);
    }
    cout << "Test 2 passed" << endl;
}
int main()
{
    test1();
    test2();
}