//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <algorithm>
//#include <set>
//using namespace std;
//vector<string> nVec;
//int main() {
//
//
//
//    ifstream inf1("/Users/markiyanandrusevych/Desktop/My PC/Study/Programming/semester 2/Exam3/People.txt");
//    vector<string> vector;
//    string word;
//    while (inf1 >> word) {
//        vector.push_back(word);
//    }
//    cout<<"Ur vector: ";
//    for(int i=0; i<vector.size();i++){
//      cout<<vector[i]<<endl;
//    }
//    for(int i=0; i<vector.size();i++){
//        if(word.front()==word.back()){
//            cout<<"-----";
//            nVec.push_back(vector[i]);
//        }
//    }
//    cout<<"New vector: "<<endl;
//    for(int i=0; i<nVec.size();i++){
//        cout<<nVec[i]<<endl;
//    }
//    set<string> myset;
//    for(int i;i<vector.size();i++){
//        myset.insert(vector[i]);
//    }
//    cout<<"Without double words: ";
//    for (auto it=myset.begin(); it != myset.end(); ++it) {
//        cout <<" "<< *it;
//    }
//
//
//}