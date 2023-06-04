//#include <iostream>
//#include <list>
//#include <fstream>
//#include <stdlib.h>
//using namespace std;
//enum ActType{
//    walking, study, food, friends
//};
//enum WeekDay{
//    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
//};
//class Action{
//private:
//    string name;
//    int time;
//    ActType type;
//public:
//    Action() {}
//    Action( string &name, int time) : name(name), time(time) {};
//
//    const string &getName() const {
//        return name;
//    }
//
//    void setName(const string &name) {
//        Action::name = name;
//    }
//
//    int getTime() const {
//        return time;
//    }
//
//    void setTime(int time) {
//        Action::time = time;
//    }
//
//    string getType() const {
//        string tyype;
//        switch (type) {
//            case 0:
//                tyype="walking";
//                break;
//            case 1:
//                tyype = "study";
//                break;
//            case 2:
//                tyype = "food";
//                break;
//            case 3:
//                tyype = "friends";
//                break;
//        }
//        return tyype;
//    }
//
//    void setType(ActType newType) {
//        type = newType;
//    }
//
//};
//class DayAct{
//private:
//    list<Action> dayAction;
//    WeekDay dayType;
//public:
//    DayAct() {
//        list<Action> mylist;
//        dayAction = mylist;
//    }
//    const list<Action>& getDayAction() const {
//        return dayAction;
//    }
//
//    string getDayType() const {
//        string tyype;
//        switch(dayType){
//            case 0:
//                tyype = "Monday";
//                break;
//            case 1:
//                tyype = "Tuesday";
//                break;
//            case 2:
//                tyype = "Wednesday";
//                break;
//            case 3:
//                tyype = "Thursday";
//                break;
//            case 4:
//                tyype = "Friday";
//                break;
//            case 5:
//                tyype = "Saturday";
//                break;
//            case 6:
//                tyype = "Sunday";
//                break;
//        }
//        return tyype;
//    }
//
//    void setDayType(WeekDay day) {
//        dayType = day;
//    }
//
//     list<Action> &getDayAction()  {
//        return dayAction;
//    }
//
//    void AddAction(Action newAct){
//        dayAction.push_back(newAct);
//    }
//};
//class WeekAct{
//private:
//    list<DayAct> weekCal;
//    string PersonName;
//public:
//    WeekAct() {
//        list<DayAct> weekList;
//        weekCal = weekList;
//    }
//
//     list<DayAct> &getWeekCal()  {
//        return weekCal;
//    }
//      string &getPersonName()  {
//        return PersonName;
//    }
//
//    void setPersonName(const string &personName) {
//        PersonName = personName;
//    }
//
//    void AddDay(DayAct day){
//        weekCal.push_back(day);
//    }
//
//    void printBusyDay(){
//        cout<<"Calendar for: ";
//        cout<<PersonName<<endl;
//        cout<<"Your schedule for the busiest day: ";
//        list<Action> temp ;
//        string day;
//        for(DayAct d: weekCal){
//            if(d.getDayAction().size()>temp.size()){
//                day = d.getDayType();
//                temp = d.getDayAction();
//            }
//        }
//        cout<<day<<endl;
//        printf("\x1b[32mType:\t\tName:\tDuration \x1b[0m  \n");
//        for(Action a: temp){
//            cout<<a.getType()<<"\t\t"<<a.getName()<<"\t"<<a.getTime()<<endl;
//        }
//    }
//    int TotalWalkTime() {
//        cout<<"Total time of your walks: \n";
//        int totalTime = 0;
//        for (const DayAct& day : weekCal) {
//            for (const Action& action : day.getDayAction()) {
//                if (action.getType() == "walking") {
//                    totalTime += action.getTime();
//                }
//            }
//        }
//        cout<<totalTime<<endl;
//        return totalTime;
//    }
//
//    list<WeekAct> readCalendars(string filePath){
//        list<WeekAct> list;#include <iostream>
////#include <list>
////#include <fstream>
////#include <stdlib.h>
////using namespace std;
////enum ActType{
////    walking, study, food, friends
////};
////enum WeekDay{
////    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
////};
////class Action{
////private:
////    string name;
////    int time;
////    ActType type;
////public:
////    Action() {}
////    Action( string &name, int time) : name(name), time(time) {};
////
////    const string &getName() const {
////        return name;
////    }
////
////    void setName(const string &name) {
////        Action::name = name;
////    }
////
////    int getTime() const {
////        return time;
////    }
////
////    void setTime(int time) {
////        Action::time = time;
////    }
////
////    string getType() const {
////        string tyype;
////        switch (type) {
////            case 0:
////                tyype="walking";
////                break;
////            case 1:
////                tyype = "study";
////                break;
////            case 2:
////                tyype = "food";
////                break;
////            case 3:
////                tyype = "friends";
////                break;
////        }
////        return tyype;
////    }
////
////    void setType(ActType newType) {
////        type = newType;
////    }
////
////};
////class DayAct{
////private:
////    list<Action> dayAction;
////    WeekDay dayType;
////public:
////    DayAct() {
////        list<Action> mylist;
////        dayAction = mylist;
////    }
////    const list<Action>& getDayAction() const {
////        return dayAction;
////    }
////
////    string getDayType() const {
////        string tyype;
////        switch(dayType){
////            case 0:
////                tyype = "Monday";
////                break;
////            case 1:
////                tyype = "Tuesday";
////                break;
////            case 2:
////                tyype = "Wednesday";
////                break;
////            case 3:
////                tyype = "Thursday";
////                break;
////            case 4:
////                tyype = "Friday";
////                break;
////            case 5:
////                tyype = "Saturday";
////                break;
////            case 6:
////                tyype = "Sunday";
////                break;
////        }
////        return tyype;
////    }
////
////    void setDayType(WeekDay day) {
////        dayType = day;
////    }
////
////     list<Action> &getDayAction()  {
////        return dayAction;
////    }
////
////    void AddAction(Action newAct){
////        dayAction.push_back(newAct);
////    }
////};
////class WeekAct{
////private:
////    list<DayAct> weekCal;
////    string PersonName;
////public:
////    WeekAct() {
////        list<DayAct> weekList;
////        weekCal = weekList;
////    }
////
////     list<DayAct> &getWeekCal()  {
////        return weekCal;
////    }
////      string &getPersonName()  {
////        return PersonName;
////    }
////
////    void setPersonName(const string &personName) {
////        PersonName = personName;
////    }
////
////    void AddDay(DayAct day){
////        weekCal.push_back(day);
////    }
////
////    void printBusyDay(){
////        cout<<"Calendar for: ";
////        cout<<PersonName<<endl;
////        cout<<"Your schedule for the busiest day: ";
////        list<Action> temp ;
////        string day;
////        for(DayAct d: weekCal){
////            if(d.getDayAction().size()>temp.size()){
////                day = d.getDayType();
////                temp = d.getDayAction();
////            }
////        }
////        cout<<day<<endl;
////        printf("\x1b[32mType:\t\tName:\tDuration \x1b[0m  \n");
////        for(Action a: temp){
////            cout<<a.getType()<<"\t\t"<<a.getName()<<"\t"<<a.getTime()<<endl;
////        }
////    }
////    int TotalWalkTime() {
////        cout<<"Total time of your walks: \n";
////        int totalTime = 0;
////        for (const DayAct& day : weekCal) {
////            for (const Action& action : day.getDayAction()) {
////                if (action.getType() == "walking") {
////                    totalTime += action.getTime();
////                }
////            }
////        }
////        cout<<totalTime<<endl;
////        return totalTime;
////    }
////
////    list<WeekAct> readCalendars(string filePath){
////        list<WeekAct> list;
////        stack<string> stack1;
////        ifstream inf2(filePath);
////        int calNum=0;
////        while (inf2) {
////            string strInput;
////            inf2 >> strInput;
////            if(strInput=="]") {
////                calNum++;
////            }
////            stack1.push(strInput);
////        }
////        while(calNum!=0) {
////            WeekAct week;
////            stack<string> weekStack;
////            int daysNum=0;
////            stack1.pop();
////                while(stack1.top()!="[") {
////                    weekStack.push(stack1.top());
////                    if(stack1.top()=="<") {
////                        daysNum++;
////                    }
////                    stack1.pop();
////                }
////                stack1.pop();
////                    while(daysNum!=0) {
////                    DayAct day;
////                    stack<string> daysStack;
////                    int actionNum=0;
////                    while(weekStack.top()!="<"){
////                        daysStack.push(weekStack.top());
////                        if(weekStack.top()=="}");
////                        actionNum++;
////                    }
////                    weekStack.pop();
////                        while(actionNum!=0) {
////                            Action act;
////                            //
////
////                            day.AddAction(act);
////
////                        }
////
////                    daysNum--;
////                    week.AddDay(day);
////                    }
////
////            list.push_back(week);
////            calNum--;
////        }
////            else{
////                Action a;
////                int type;
////                type = stoi(stack.top());
////                switch(type){
////                    case 0:
////                        a.setType(ActType::walking);
////                        break;
////                    case 1:
////                        a.setType(ActType::study);
////                        break;
////                    case 2:
////                        a.setType(ActType::food);
////                        break;
////                    case 3:
////                        a.setType(ActType::friends);
////                        break;
////                }
////                stack.pop();
////                a.setTime(stoi(stack.top()));
////                stack.pop();
////                a.setName(stack.top());
////                stack.pop();
////                stack.pop();
////                DayAct day;
////            }
////        }
////
////
////
////
////
////        return list;
////    }
////
////};
////int main(){
////    Action act2;
////    act2.setName("Math");
////    act2.setType(study);
////    act2.setTime(20);
////    Action act;
////    act.setName("Walk");
////    act.setTime(12);
////    act.setType(walking);
////    DayAct day;
////    day.setDayType(Tuesday);
////    day.AddAction(act2);
////    day.AddAction(act);
////    WeekAct week;
////    week.setPersonName("Marik");
////    week.AddDay(day);
////    week.printBusyDay();
////    week.TotalWalkTime();
////
////
////}
//        stack<string> stack1;
//        ifstream inf2(filePath);
//        int calNum=0;
//        while (inf2) {
//            string strInput;
//            inf2 >> strInput;
//            if(strInput=="]") {
//                calNum++;
//            }
//            stack1.push(strInput);
//        }
//        while(calNum!=0) {
//            WeekAct week;
//            stack<string> weekStack;
//            int daysNum=0;
//            stack1.pop();
//                while(stack1.top()!="[") {
//                    weekStack.push(stack1.top());
//                    if(stack1.top()=="<") {
//                        daysNum++;
//                    }
//                    stack1.pop();
//                }
//                stack1.pop();
//                    while(daysNum!=0) {
//                    DayAct day;
//                    stack<string> daysStack;
//                    int actionNum=0;
//                    while(weekStack.top()!="<"){
//                        daysStack.push(weekStack.top());
//                        if(weekStack.top()=="}");
//                        actionNum++;
//                    }
//                    weekStack.pop();
//                        while(actionNum!=0) {
//                            Action act;
//                            //
//
//                            day.AddAction(act);
//
//                        }
//
//                    daysNum--;
//                    week.AddDay(day);
//                    }
//
//            list.push_back(week);
//            calNum--;
//        }
//            else{
//                Action a;
//                int type;
//                type = stoi(stack.top());
//                switch(type){
//                    case 0:
//                        a.setType(ActType::walking);
//                        break;
//                    case 1:
//                        a.setType(ActType::study);
//                        break;
//                    case 2:
//                        a.setType(ActType::food);
//                        break;
//                    case 3:
//                        a.setType(ActType::friends);
//                        break;
//                }
//                stack.pop();
//                a.setTime(stoi(stack.top()));
//                stack.pop();
//                a.setName(stack.top());
//                stack.pop();
//                stack.pop();
//                DayAct day;
//            }
//        }
//
//
//
//
//
//        return list;
//    }
//
//};
//int main(){
//    Action act2;
//    act2.setName("Math");
//    act2.setType(study);
//    act2.setTime(20);
//    Action act;
//    act.setName("Walk");
//    act.setTime(12);
//    act.setType(walking);
//    DayAct day;
//    day.setDayType(Tuesday);
//    day.AddAction(act2);
//    day.AddAction(act);
//    WeekAct week;
//    week.setPersonName("Marik");
//    week.AddDay(day);
//    week.printBusyDay();
//    week.TotalWalkTime();
//
//
//}