#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
//Ввести послідовність символів.  Видалити з неї всі коми, що йдуть перед першою крапкою і замінити всі цифри 3, що йдуть після першої крапки, на знак +.


int main()
{
    // Введення послідовності
    cout << "Введіть послідовність символів: ";
    string input;
    getline(cin, input);

    // Список введених символів
    list<char> char_list(input.begin(), input.end());

    // Знаходження крапки
    auto dot_pos = find(char_list.begin(), char_list.end(), '.');

    // Знаходження коми
    auto coma_pos = find(char_list.begin(), dot_pos, ',');


    // Заміна всіх 3 після крапки на +
    bool dot_found = false;
    for (auto it = char_list.begin(); it != char_list.end(); ++it) {
        if (*it == '.') {
            dot_found = true;
        } else if (dot_found && isdigit(*it) && *it == '3') {
            *it = '+';
        }
    }
    //Видалення ком до крапки
    while (coma_pos != dot_pos && coma_pos != char_list.end()) {
        char_list.erase(coma_pos);
        dot_pos = find(char_list.begin(), char_list.end(), '.');
        coma_pos = find(char_list.begin(), dot_pos, ',');
    }

    // Виведення нової послідовності
    for (auto c : char_list) {
        cout << c;
    }
    cout << endl;

    return 0;
}

