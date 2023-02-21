#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/*1.Створіть клас для банківського рахунку та  клас Клієнт.
 Клас Банківський рахунок повинен мати поля Клієн, номера рахунку та баланс,
повинен містити методи для додавання грошей
 на рахунок і знімання, показ балансу та загальної інформації.
Клас Клієнт повинен мати поля імʼяі клієнта, адреса та номер телефону.
Ввести дані про 10 банківських рахунків,
надати можливість пошуку рахунку за іменем клієнта та за адресою клієнта,
надати меню для додавання чи зняття грошей з вибраного рахунку*/
class Client
{
private:
    string name;
    string surname;
    string address;
    int telNumber;

public:
    Client() {}
    Client(string n, string s, string a, int t) : name(n), surname(s), address(a), telNumber(t) {}
    string getName()
    {
        return name;
    }
    string getSurname()
    {
        return surname;
    }
    string getAdress()
    {
        return address;
    }
    int getTelNumber()
    {
        return telNumber;
    }
    friend std::ostream &operator<<(ostream &os, Client &t)
    {
        os << ' ' << t.name << ';'
           << ' ' << t.surname << ';'
           << ' ' << t.telNumber << ';'
           << ' ' << t.address << '.';
        return os;
    }
};
class BankAccount
{

private:
    Client client;
    int accNum;
    float balance;

public:
    static BankAccount arr[];
    static int count;
    BankAccount() {}
    BankAccount(Client c, int acc) : client(c), accNum(acc), balance(0.00)
    {
        arr[count].client = this->client;
        arr[count].accNum = this->accNum;
        arr[count].balance = this->balance;

        count++;
    }
    Client getClient()
    {
        return client;
    }
    int getAccNum()
    {
        return accNum;
    }
    float getBalance()
    {
        return balance;
    }
    int getCount()
    {
        return count;
    }
    void addMoney(float x)
    {
        this->balance += x;
        cout << "Success! Your balance is : " << balance << endl;
    }
    void withdrawMoney(float x)
    {
        if (x < this->balance)
        {
            this->balance -= x;
            cout << "Your balance: " << balance << endl;
        }
        else
        {
            cout << "Not enough money on ur account :(" << endl;
        }
    }
    void getInfo()
    {
        cout << "---Full acc info---" << endl;
        cout << "Account holder:" << endl;
        cout << "Name: " << this->getClient().getName() << endl;
        cout << "Last name: " << this->getClient().getSurname() << endl;
        cout << "Account details: " << endl;
        cout << "Acc number: " << this->getAccNum() << endl;
        cout << "Balance : " << this->getBalance() << endl;
    }
    /* friend std::ostream &operator<<(ostream &os, Client &t)
     {
         os << ' ' << t.getName() << ';'
            << ' ' << t.getSurname() << ';'
            << ' ' << t.getTelNumber() << ';'
            << ' ' << t.getAdress() << '.';
         return os;
     }*/
    static void searchAcc(string s)
    {
        int k=0;
        for (int i = 0; i <= count; i++)
        {
            if (arr[i].getClient().getName() == s || arr[i].client.getAdress() == s || arr[i].client.getSurname() == s)
            {
                cout << "I found the following accounts matching "  << "'" << s << "':" << endl;
                arr[i].getInfo();
                k++;
            }
        }
        if(k==0){
            cout << "No account found!" <<endl;
        }
        else{
            cout<<"Found "<< k<<" accounts."<<endl;
        }
    }
};
int BankAccount::count = 0;
BankAccount BankAccount::arr[10];

int main()
{
    Client c1("Fiona", "Williamson", "Lviv", 43001);
    Client c2("Finley", "Adkins", "Rivne", 12341);
    Client c3("Luz", "Lozano", "Kyiv", 00001);
    Client c4("Edgar", "Miles", "Odesa", 00001);
    Client c5("Jarrett", "Barr", "Uzhorod", 00001);
    Client c6("Geovanni", "Bell", "Frankivsk", 00001);
    Client c7("Mariah", "Lane", "Dnipro", 00001);
    Client c8("Angie", "Wagner", "Chop", 00001);
    Client c9("Marik", "Bauer", "Vinnytsa", 00001);
    Client c10("Ryann", "Tapia", "Bahmut", 00001);
    BankAccount test(c, 8484838);
    test.addMoney(100.0);
    test.getInfo();//виведення повної інофрмації про рахунок
    test.withdrawMoney(170);//при нестачі коштів інформує про це
    BankAccount test2(c, 002);
    cout << test2.arr[0].getAccNum() << endl;
    BankAccount::searchAcc("l");
    /*Зробив завдання.Є можливість пошуку по рахункам, додавання/знімання коштів, отримання інформації про рахунок, баланс.
}