#include <iostream>
using namespace std;
struct  Rule{
    string s1;
    string s2;
};
string markov(string input, Rule rule){
    int len = rule.s1.length();
    for(int i = 0; i <= input.length() - len; i++){
        int k = i;
        string temp;
        while (k < i + len){
            temp += input[k];
            k++;
        }
        if(temp == rule.s1){
            int j = i;
            for(char c : rule.s2){
                input[j] = c;
                j++;
            }
        }
    }
    return input;
}
void twoRules(string s, Rule rule1, Rule rule2){
    cout<<markov(markov(s,rule1),rule2);
}
int main(){
    cout<<"Введіть свій рядок: "<<endl;
    string s;
    cin>>s;
    cout<<"Введіть алгоритм Маркова P->Q"<<endl;
    cout<<"Введіть P1: "<<endl;
    Rule r1;
    cin>>r1.s1;
    cout<<"Введіть Q1: "<<endl;
    cin>>r1.s2;
    cout<<"Введіть P2: "<<endl;
    Rule r2;
    cin>>r2.s1;
    cout<<"Введіть Q2: "<<endl;
    cin>>r2.s2;
    twoRules(s,r1,r2);


}
