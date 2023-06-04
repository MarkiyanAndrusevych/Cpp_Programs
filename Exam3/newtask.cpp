//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//#include <fstream>
//
//using namespace std;
//
//int main(){
//    //Зчитування з файлу
//    vector<char> l;
//    vector<char>wdot;
//    ifstream inf1("/Users/markiyanandrusevych/Desktop/My PC/Study/Programming/semester 2/Exam3/People.txt");
//    char word;
//    while(inf1>>word){
//        l.push_back(word);
//    }
//    cout<<"Vec:";
//    for(int i=0; i<l.size();i++){
//        cout<<l[i]<<endl;
//    }
//
//    auto it=find(l.begin(), l.end(),'.');
//    replace(l.begin(), it,',','\0');
//    cout<<"New vec: ";
//    for(int i = 0; i<l.size();i++){
//       cout<<l[i];
//    }
//    replace(it,l.end(),'3','+');
//    cout<<"Final vec: ";
//    for(int i=0; i<l.size();i++){
//        cout<<l[i];
//    }
//
//
//}