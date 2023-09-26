#include <iostream>
#include <string>
using namespace  std;
struct Word {
    string English;
    string Ukrainian;
    Word(){}
    Word(string english, string ukrainian) : English(english), Ukrainian(ukrainian){}
    Word(string english) : English(english){}
};
struct Dictionary{
    Word* word;
    int Size;
    int Count;
    Dictionary(int size) : Size(size){
        this->word = new Word[size];
    }
};
void addWord(Dictionary dictionary, Word word) {
    for (int i = 0; i < dictionary.Size; i++) {
        if (dictionary.word[i].English == "") {
            dictionary.word[i] = word;
            break;
        }
    }
}
string findUkrWord(Dictionary dictionary, string engWord){
    string result= "not found";

    for (int i = 0; i < dictionary.Size; i++) {
        if (dictionary.word[i].English == engWord) {
            result = dictionary.word[i].Ukrainian;
            break;
        }

    }
    return result;
}
void updateDictionary(Dictionary dictionary, string English, string newUkrainian){
    bool result = false;
    for (int i = 0; i < dictionary.Size; i++) {
        if (dictionary.word[i].English == English) {
            dictionary.word[i].Ukrainian=newUkrainian;
            result = true;
            cout << "Word updated!\n";
            break;
        }
    }
    if(!result){
        cout <<"English entry not found\n";
    }
}
void deleteWord(Dictionary dictionary, string engWord){
    bool result = false;
    for (int i = 0; i < dictionary.Size; i++) {
        if (dictionary.word[i].English == engWord) {
              dictionary.word[i] = Word();
              result = true;

            break;
        }
    }
    if(!result){
        cout <<"Word not found\n";
    }
}
void printDictionary(Dictionary dictionary){
    for (int i = 0; i < dictionary.Size; i++) {
        if (dictionary.word[i].English != "") {
            cout<<dictionary.word[i].English<<"\t"<<dictionary.word[i].Ukrainian<<endl;
        }
    }
}
int main(){
    Word w1("Work", "Робота");
    Word w2("Table", "Стіл");
    Word w3("Mouse", "Мишка");
    Dictionary EngUkr(10);
    addWord(EngUkr, w1);
    addWord(EngUkr, w2);
    addWord(EngUkr, w3);
    addWord(EngUkr, Word("Keyboard", "Клавіатура"));
    cout<< findUkrWord(EngUkr, "Mouse")<<endl;
    printDictionary(EngUkr);
    deleteWord(EngUkr, "mouse");//error

}