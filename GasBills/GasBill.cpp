#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <functional>
using namespace std;

class Customer
{
public:
    string customerType;
    string name;
    double payment;

public:
    Customer(string CustomerType, string Name, double Payment) : customerType(CustomerType), name(Name), payment(Payment) {}
    virtual void print() = 0;
};

class CustomerWater : public Customer
{
private:
    double waterMeter;

public:
    CustomerWater(string CustomerType, string Name, double Payment, double WaterMeter) :Customer(CustomerType, Name, Payment), waterMeter(WaterMeter)  {}
    void print()
    {
        cout << "Customer water info:\n"
             << "Name: " << name << ", Payment: " << payment << ", WaterMeter: " << waterMeter << ".\n";
    };

    double getWaterMeter() const {
        return waterMeter;
    }
};

class CustomerGas : public Customer
{
private:
    int familySize;

public:
    CustomerGas (string CustomerType, string Name, double Payment, int FamilySize) :Customer(CustomerType, Name, Payment), familySize(FamilySize)  {}
    void print()
    {
        cout << "Customer gas  info:\n"
             << "Name: " << name << ", Payment: " << payment  << ", Number of people in family: " << familySize << ".\n";
    }

    int getFamilySize() const {
        return familySize;
    }

};

int main() {
    ifstream inf2("/Users/markiyanandrusevych/Desktop/My PC/Study/Programming/test/devices.txt");
    if (!inf2) {
        cerr << "Uh oh, devices.txt could not be opened for reading!" << endl;
        exit(1);
    }

    vector<string> masIn;
    while (inf2) {
        string strInput;
        inf2 >> strInput;
        masIn.push_back(strInput);
    }

    vector<CustomerWater *> waterusers;
    vector<CustomerGas *> gasusers;
    for (int j = 0; j < masIn.size() - 1; j = j + 4) {
        try {
            if (masIn.at(j) == "gas") {
                gasusers.push_back(
                        new CustomerGas(masIn.at(j), masIn.at(j + 1),
                                        stod(masIn.at(j + 2)), stoi(masIn.at(j + 3))));
            } else {
                waterusers.push_back(
                        new CustomerWater(masIn.at(j), masIn.at(j + 1),
                                          stod(masIn.at(j + 2)), stod(masIn.at(j + 3))));
            }
        }
        catch (std::exception &e) {
            cout << "Error reading file" << endl;
        }
    }
    for (CustomerGas *e: gasusers) {
        e->print();
    }
    cout << "*********************" << endl;
    for (CustomerWater *w: waterusers) {
        w->print();
    }
    cout << "*********Sorted by payment************" << endl;
    for (int i = 0; i < waterusers.size() - 1; i++) {
        if (waterusers.at(i)->payment < waterusers.at(i + 1)->payment) { swap(waterusers.at(i), waterusers.at(i + 1)); }
    }
    for (CustomerWater *w: waterusers) {
        w->print();
    }
    cout << "********Sorted by name*************" << endl;
    for (int i = 0; i < gasusers.size() - 1; i++) {
        if (gasusers.at(i)->name > gasusers.at(i + 1)->name) { swap(gasusers.at(i), gasusers.at(i + 1)); }
    }
    for (CustomerGas *e: gasusers) {
        e->print();
    }


//виводимо у файли посортовані обʼєкти
    ofstream inf1("/Users/markiyanandrusevych/Desktop/My PC/Study/Programming/test/devices2.txt");
    if (!inf1) {
        cerr << "Uh oh, devices2.txt could not be opened for reading!" << endl;
        exit(1);
    }
    for (int k = 0; k < gasusers.size(); k++) {
        string s;
        s = "{" + gasusers.at(k)->customerType + "/" + gasusers.at(k)->name + "/" + to_string( gasusers.at(k)->payment) + "/" +
                to_string(gasusers.at(k)->getFamilySize()) + "}";
        inf1 << s << "; ";
    }
    ofstream inf3("/Users/markiyanandrusevych/Desktop/My PC/Study/Programming/test/devices3.txt");
    if (!inf3) {
        cerr << "Uh oh, devices3.txt could not be opened for reading!" << endl;
        exit(1);
    }
    for (int k = 0; k < waterusers.size(); k++) {
        string s;
        s = "{" + waterusers.at(k)->customerType + "/" + waterusers.at(k)->name + "/" + to_string( waterusers.at(k)->payment) + "/" +
            to_string(waterusers.at(k)->getWaterMeter()) + "}";
        inf3 << s << "; ";
    }
    int count = 0;
    for(CustomerWater* c : waterusers){
        if(c->payment<=0){
            for(CustomerGas* g : gasusers){
                if(g->name==c->name&&g->payment>0){
                    count++;
                }
            }
        }
    }
    cout<<"Усього абонентів, які заплатили за газ, але не заплатили за воду: "<<count<<endl;
}