//#include <iostream>
//#include <set>
//#include <list>
//#include <vector>
//#include <fstream>
//#include <iterator>
//
//using namespace std;
//
//vector<string> finalVec;
//int main() {
//    //Вивід з файлу
//    ifstream inf1("/Users/markiyanandrusevych/Desktop/My PC/Study/Programming/semester 2/Exam3/People.txt");
//    vector<string>newVec;
//    vector<string> vector;
//    set<string> myset;
//    string word;
//    while (inf1 >> word) {
//        vector.push_back(word);
//    }
//    //Вивід вектора на консоль
//    for(int i=0;i<vector.size();i++){
//        cout<<"|"<< vector[i];
//    }
//    //Вектор з новими словами
//    for(string& word :vector){
//        if(word.front()==word.back()){
//            newVec.push_back(word);
//        }
//    }
//    //Вивід нового вектора
//    for(int i=0;i<newVec.size();i++){
//        cout<<"/"<< newVec[i]<<" ";
//    }
//    auto it = unique(vector.begin(),vector.end());
//    vector.erase(it,vector.end());
//    for(int i=0;i<vector.size();i++){
//        cout<<"-"<< vector[i]<<" \n";
//    }
//
//    for(int i = 0; i<vector.size();i++){
//        finalVec.push_back(vector[i]);
//    }
//
//    for(int i = 0; i<finalVec.size();i++){
//        cout<<"|"<< finalVec[i]<<" ";
//    }
//    for(int i=0; i<vector.size();i++){
//        myset.emplace(vector[i]);
//    }
//    for(string s : myset){
//        cout<<"*"<< s;
//    }
//
//
//
//
//}
//
