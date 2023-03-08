#include<iostream>
#include<fstream>
#include<cstdlib>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;
class Phone{
protected:
    string name;
    string brand;
    double price;
public:
    Phone(string Name, string Brand, double Price) : name(Name), brand(Brand), price(Price){}
    virtual void print()=0;
};
class Mobile : public Phone{
private:
    string colour;
    int memory;
public:
    Mobile( string Name, string Brand, double Price, string Colour, int Memory) : colour(Colour), memory(Memory), Phone(Name,Brand,Price) {}
    void print(){
        cout<<"Mobile info: \n"<<
        "Name: "<<name<<", Brand: "<<
        brand<<", Price: "<<
        price<<", Colour: "<<
        colour<<", Memory: "<<
        memory<<".\n";
    }
};
class RadioPhone : public Phone{
private:
    int radius;
    bool answeringMachine;
public:
    RadioPhone( string Name, string Brand, double Price, int Radius, bool AnsweringMachine ) : radius(Radius), answeringMachine(AnsweringMachine), Phone(Name,Brand,Price){}
    void print(){
        string x;
        if(answeringMachine){
            x="YES!";
        }
        else{
            x="NO!";
        }
        cout<<"Mobile info: \n"<<
            "Name: "<<name<<", Brand: "<<
            brand<<", Price: "<<
            price<<", Radius: "<<
            radius<<", Answering machine: "<<
            x<<".\n";
    }
};

bool My_func(string *r, string *s)
{
    return stod(s[5])<stod(r[5]);
}
int main(){
    Mobile m1("3441","Motorla", 120.80,"White", 16);
    m1.print();
    RadioPhone r1("3111","Nokia", 120.80, 2, false);
    r1.print();
    ifstream inf("/Users/markiyanandrusevych/Documents/maa_ua/semester 2/InheritancePolimorfism/phones.txt");
    ifstream inf2("/Users/markiyanandrusevych/Documents/maa_ua/semester 2/InheritancePolimorfism/phones2.txt");
    if (!inf|!inf2)
    {
        cerr << "Uh oh, SomeText.txt could not be opened for reading!" << endl;
        exit(1);
    }
    string name,brand,colour;
    int count = 0;
    string masIn[200];

    while (inf)
    {
        string strInput;
        inf >> strInput;
        masIn[count]=strInput;
        count++;
    }
    count--;
    while (inf2)
    {
        string strInput;
        inf2 >> strInput;
        masIn[count]=strInput;
        count++;
    }
    cout<<count<<endl;

    string masMain[10][10];
    string masTemp[10];
    int x = 0;
    for(int i = 0; i<=count-2; i+=10){
        for(int j=0; j<10;j++){
            masMain[x][j] = masIn[i+j];
        }
        x++;
    }
    if(masMain[2][9]=="true"||masMain[2][9] == "false"){
        cout<<"Radio\n";
    }

    string *arr[x];
    string *arrSort[x];
    for (int i = 0; i < x; i++)
    {
        arrSort[i] = masMain[i];
//        arr[i] = &masMain[i][5];
    }

//    for(int w=0;  w<6;  w++){
//    string *less;
//
//    if(stof(arrSort[w][5])>stof(arrSort[w+1][5])){
//        less=arrSort[w];
//        arrSort[w+1]=arrSort[w];
//        arrSort[w]=less;
//        w=0;
//        cout<<arrSort[w][5]<<" ";
//    }
//    }
//    for (int l = 0; l < x; l++)
//    {
//       cout<< arrSort[l][0]<<" ";
//
//    }

    ofstream outf("/Users/markiyanandrusevych/Documents/maa_ua/semester 2/InheritancePolimorfism/phonesByPrice.txt");
 if (!outf)
 {
     cerr << "Uh oh, SomeText.txt could not be opened for writing!" << endl;
     exit(1);
 }
 for(int k=0; k<x; k++){
     string s;
     for(int l=0; l<10; l++){
        s= masMain[k][l];
         outf << s;
         if(l!=9){
             outf<<" ";
         }

     }
     outf<<endl;
 }
 double sum=0.00;
 for(int m=0;m<6;m++){
     sum +=stod(masMain[m][5]);
 }

outf<<"Total sum: "<<sum<<endl;
outf<<"Radio phones with  answering machine: "<<endl;
    int count2=0;
for(int n=0; n<x; n++){

    if(masMain[n][9]=="true"){
        for (x=0; x<10; x++){
            outf<<masMain[n][x]<<" ";
        }
        outf<<endl;
        count2++;
    }
}
    outf<<"Total phones with  answering machine: "<<count2;



}
