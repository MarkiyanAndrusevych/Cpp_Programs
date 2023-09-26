#include <iostream>
using namespace std;

void QuickSort (int arr[], int first,int last)
{
    int middle = arr[(first + last) / 2];
    int i = first;
    int j = last;
    do{
        while(arr[i] < middle){
            i++;
        }
        while(arr[j] > middle){
            j--;
        }
        if(i <= j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }

    }while(i <= j);

    if(j > first)
    {
        QuickSort(arr,first,j);
    }
    if(i < last)
    {
        QuickSort(arr,i,last);
    }
}

void SelectionSort(int arr[],int size)
{
    int min;

    for(int i = 0;i < size - 1; i ++){
        min = i;
        for(int j = i+1; j < size; j ++){
            if(arr[j] < arr[min]){
                min = j;
            }
            if (min != i)
            {
                swap( arr[min], arr[i]);
            }
        }
    }

}
void Test(int arr[], int answer[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
        if (answer[i] != arr[i]) {
            cout << "\nfailed\n";
            return;
        };
    }
    cout << "\nsuccess\n";
}


int main() {
    int arr1[] = {1 ,2 ,5,6,3,6,1,11,4};
    int ans1[] = {1,1,2,3,4,5,6,6,11};
    int size1 = sizeof (arr1) / sizeof (arr1[0]);

    int arr2[] = {1 ,3 ,-1,-5,-5,1,11,0};
    int ans2[] = {-5,-5,-1,0,1,1,3,11};
    int size2 = sizeof (arr2) / sizeof (arr2[0]);

    QuickSort (arr1, 0, size1-1) ;
    QuickSort (arr2, 0, size2-1) ;

    SelectionSort(arr1,size1);
    SelectionSort(arr2,size2);
    Test(arr1,ans1,size1);
    Test(arr2,ans2,size2);

    return 0;
}


