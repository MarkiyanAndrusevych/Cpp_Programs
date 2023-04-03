#include <iostream>
#include <fstream>
using namespace std;
     string GreetUkr(string name){
        string ukr = "Вітаю з днем народження! "
                     "Найголовніше – будь щасливим! "
                     "Адже щастя – це і є здоров’я, любов близьких, можливість розпочинати та закінчувати день із усмішкою на обличчі!"
                     "Тож нехай все це і навіть більше в тебе буде! Нехай здійснюються мрії, збуваються бажання.";
        string result = name+"! "+ukr;
        return result;
    }
    string GreetEng(string name){
        string eng = "Happy birthday!"
                     "The most important thing is to be happy!"
                     "After all, happiness is health, the love of loved ones, the opportunity to start and end the day with a smile on your face!"
                     "So may you have all this and even more! May dreams be remembered, wishes come true.";
        string result = name+"! "+eng;
    return result;
}
    string GreetEsp(string name){
        string esp = "¡Feliz cumpleaños!"
                     "¡Lo más importante es ser feliz!"
                     "Después de todo, la felicidad es la salud, el amor de los seres queridos, la oportunidad de comenzar y terminar el día con una sonrisa en la cara"
                     "¡Que tengas todo esto y aún más! Que los sueños se recuerden, los deseos se hagan realidad";
        string result = name+"! "+esp;
    return result;
}
    void PrintGreeting(string name, string(*language)(string)){
         string g = language(name);
        ofstream g1("/Users/markiyanandrusevych/Documents/maa_ua/semester 2/Greeting/greetings.txt");//Вивід в файл
        g1 << g<<"; ";
     }
int main() {
         bool tak = true;
    while (tak) {
        string name;
        string lang;
        cout << "Оберіть мову: " << endl;
        cout << "1 - Українська" << endl;
        cout << "2 - English" << endl;
        cout << "3 - Español" << endl;
        cin >> lang;
        int l = stoi(lang);
        cout << "Введіть імʼя: " << endl;
        cin >> name;
        switch (l) {
            case 1:
                PrintGreeting(name, GreetUkr);
                break;
            case 2:
                PrintGreeting(name, GreetEng);
                break;
            case 3:
                PrintGreeting(name, GreetEsp);
                break;
            default:
                break;

        }
        break;


    }
}
