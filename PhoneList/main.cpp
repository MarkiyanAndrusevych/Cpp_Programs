#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <functional>
#include <set>
using namespace std;

class Contact
{
private:
    string name;
    string address;
    int number1;
    int number2;
    int number3;

public:
    Contact() {number1 = 0;number2=0;number3= 0;};

    string getName() const {
        return name;
    }

    void setName(const string& name) {
        this->name = name;
    }

    string getAddress() const {
        return address;
    }

    void setAddress(const string& address) {
        this->address = address;
    }

    int getNumber1() const {
        return number1;
    }

    void setNumber1(int number1) {
        this->number1 = number1;
    }

    int getNumber2() const {
        return number2;
    }

    void setNumber2(int number2) {
        this->number2 = number2;
    }

    int getNumber3() const {
        return number3;
    }

    void setNumber3(int number3) {
        this->number3 = number3;
    }

    bool operator<(const Contact& other) const {
        return name < other.name || (name == other.name && address < other.address);
    }
};

class PhoneBook {
private:
    set<Contact> contacts;
public:
    PhoneBook() {
        contacts = set<Contact>();
    };

    set<Contact>& getContacts() {
        return contacts;
    }
};

int main() {
    PhoneBook marik = PhoneBook();
    ifstream inf2("/Users/markiyanandrusevych/Desktop/My PC/Study/Programming/semester 2/PhoneList/devices.txt");
    if (!inf2) {
        cerr << "Uh oh, devices.txt could not be opened for reading!" << endl;
        exit(1);
    }

    string name, address, numberStr;
    while (inf2 >> name >> address >> numberStr) {

        try {
             int number = stoi(numberStr);
            Contact temp = Contact();
            temp.setName(name);
            temp.setAddress(address);
            temp.setNumber1(number);


            auto it = marik.getContacts().find(temp);
            if (it == marik.getContacts().end()) {
                marik.getContacts().insert(temp);
            } else {
                Contact& present = const_cast<Contact&>(*it);
                present.setNumber2(temp.getNumber1());
            }
        }
        catch (std::exception &e) {
            cout << "Error reading file" << endl;
        }
    }
    vector<Contact> sorted;
    for (Contact c: marik.getContacts()) {
        sorted.push_back(c);
    }
    sort(sorted.begin(), sorted.end(), [](const Contact& c1, const Contact& c2) {
        return c1.getName() < c2.getName() || (c1.getName() == c2.getName() && c1.getAddress() < c2.getAddress());
    });
    for (Contact c: sorted) {
        cout << c.getName() << "\t" << c.getAddress() << "\t" << c.getNumber1()<<endl;
    }
    ofstream inf1("/Users/markiyanandrusevych/Desktop/My PC/Study/Programming/semester 2/PhoneList/devices2.txt");
    if (!inf1) {
        cerr << "Uh oh, devices2.txt could not be opened for reading!" << endl;
        exit(1);
    }
    for (int k = 0; k < sorted.size(); k++) {
        string s;
        s = "{" + sorted.at(k).getName() + "/" + sorted.at(k).getAddress() + "/" + to_string( sorted.at(k).getNumber1()) + "/" +
            to_string(sorted.at(k).getNumber2()) + "}";
        inf1 << s << "; ";
    }


    ofstream inf3("/Users/markiyanandrusevych/Desktop/My PC/Study/Programming/semester 2/PhoneList/devices3.txt");
    if (!inf3) {
        cerr << "Uh oh, devices2.txt could not be opened for reading!" << endl;
        exit(1);
    }
    for(Contact d : marik.getContacts()){
        string m;
        if(d.getAddress()=="Lviv"){
            m = "{" + d.getName() + "/" + d.getAddress() + "/" + to_string( d.getNumber1()) + "/" +
                to_string(d.getNumber2()) + "}";
            inf3 << m << "; ";
        }
    }
    return 0;
}

