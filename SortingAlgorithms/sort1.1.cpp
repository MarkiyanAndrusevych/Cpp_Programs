#include <iostream>
using namespace std;
int main()
{
    // сортування підрахуноком
    cout << "Sort counting \n";
    int mas[] = {1, 2, 2, 2, 3, 3, 1, 2, 1, 3, 3, 3};
    for (int i = 0; i < sizeof(mas) / 4; i++)
    {
        cout << mas[i] << ",";
    }
    cout << "_____" << endl;
    int one = 0;
    int two = 0;
    int three = 0;
    for (int i = 0; i < sizeof(mas) / 4; i++)
    {
        if (mas[i] == 1)
        {
            one++;
        }
        if (mas[i] == 2)
        {
            two++;
        }
        if (mas[i] == 3)
        {
            three++;
        }
    }
//    cout << one << endl
//         << two << endl
//         << three << endl;
    for (int i = 0; i < one; i++)
    {
        mas[i] = 1;
    }
    for (int i = (one - 1); i < two + (one - 1); i++)
    {
        mas[i] = 2;
    }
    for (int i = (one + two - 1); i < three + two + (one - 1); i++)
    {
        mas[i] = 3;
    }
    for (int i = 0; i < sizeof(mas) / 4; i++)
    {
        cout << mas[i] << ",";

    }

}
