//#include <iostream>
//#include <set>
//#include <list>
//#include <vector>
//#include <fstream>
//#include <iterator>
//#include <cstring>
//#include <string>
//#include <string.h>
//using namespace std;
//void f(vector<string> l){
//        cout<<"Number of 'x': "<< count(l.begin(),l.end(),"x")<<endl;
//}
//void Delete(vector<string> vector){
//    auto it =  find(vector.begin(),vector.end(),"p");
//    vector.erase(it,vector.end());
//    for(int i=0; i<vector.size();i++){
//        cout<<"Vector after delete: "<<vector[i]<<endl;
//    }
//}
//
////void EachCount(vector<string> vector){
////    cout<<"Number of '+': "<<count(vector.begin(),vector.end(),"+")<<endl;
////    cout<<"Number of '*': "<<count(vector.begin(),vector.end(),"*")<<endl;
////}
////void GenCount(vector<string> vector){
////    cout<<"General number of elements '+' and '*': "<<count(vector.begin(),vector.end(),"+")+count(vector.begin(),
////                                                                                                   vector.end(),"*")<<endl;
////}
//enum ActType{
//    Walk, Study, Eat, Friends
//
//};
//enum DayType{
//    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
//};
//class Action{
//private:
//    string ActName;
//    int duration;
//    ActType TypeOfAction;
//public:
//    Action(){}
//
//    Action( string &actName, int duration, ActType typeOfAction) : ActName(actName), duration(duration),
//                                                                        TypeOfAction(typeOfAction) {}
//
//    void setActName(const string &actName) {
//        ActName = actName;
//    }
//
//    void setDuration(int duration) {
//        Action::duration = duration;
//    }
//
//    void setTypeOfAction(ActType typeOfAction) {
//        TypeOfAction = typeOfAction;
//    }
//
//    string getActName()  {
//        return ActName;
//    }
//    int getDuration()  {
//        return duration;
//    }
//
//    string getTypeOfAction()  {
//        string type;
//        switch(TypeOfAction){
//            case 0:
//                type = "Walk";
//                break;
//            case 1:
//                type = "Study";
//                break;
//            case 2:
//                type = "Eat";
//                break;
//            case 3:
//                type = "Friends";
//                break;
//        }
//        return type;
//    }
//};
//class DayCal{
//private:
//    list<Action> dayAct;
//    DayType TypeOfDay;
//public:
//    DayCal(){
//        list<Action> dayAction;
//        dayAction = dayAct;
//    }
//    list<Action> getDayAct(){
//        return dayAct;
//    }
//    DayType getTypeOfDay(){
//        string type;
//        switch(TypeOfDay){
//            case 0:
//                type = "Monday";
//                break;
//            case 1:
//                type = "Tuesday";
//                break;
//            case 2:
//                type = "Wednesday";
//                break;
//            case 3:
//                type = "Thursday";
//                break;
//            case 4:
//                type = "Friday";
//                break;
//            case 5:
//                type = "Saturday";
//                break;
//            case 6:
//                type = "Sunday";
//                break;
//        }
//        return TypeOfDay;
//    }
//
//
//    void setDayAct( list<Action> &dayAct) {
//        DayCal::dayAct = dayAct;
//    }
//
//    void setTypeOfDay(DayType typeOfDay) {
//        TypeOfDay = typeOfDay;
//    }
//    void AddAct(Action myAct){
//        dayAct.push_back(myAct);
//    }
//};
//class WeekCal{
//private:
//    string PersonName;
//    list<DayCal> WeekAct;
//public:
//    WeekCal() {
//        list<DayCal> WeekAction;
//        WeekAct = WeekAction;
//    }
//
//     string &getPersonName()  {
//        return PersonName;
//    }
//
//    void setPersonName( string personName) {
//        PersonName = personName;
//    }
//
//     list<DayCal> getWeekAct()  {
//        return WeekAct;
//    }
//
//    void setWeekAct( list<DayCal> &weekAct) {
//        WeekAct = weekAct;
//    }
//    void AddDay(DayCal myDay){
//        WeekAct.push_back(myDay);
//    }
//    void MostActiveDay(){
//        cout<<"Owner of the calendar: ";
//        cout<<PersonName<<endl;
//        cout<<"Your most active day: ";
//        list<Action> temp ;
//        string day;
//        for(DayCal d: WeekAct){
//            if(d.getDayAct().size()>temp.size()){
//                day = d.getTypeOfDay();
//                temp = d.getDayAct();
//            }
//        }
//                cout<<day<<endl;
//        printf("Type:\t\tName:\tDuration\n");
//        for(Action a: temp){
//            cout<<a.getTypeOfAction()<<"\t\t"<<a.getActName()<<"\t"<<a.getDuration()<<endl;
//        }
//    }
//
//    int WalkingSum(){
//        int totalTime = 0;
//        for ( DayCal& day : WeekAct) {
//            for ( Action& action : day.getDayAct()) {
//                if  (action.getTypeOfAction() == "Walk") {
//                    totalTime += action.getDuration();
//                }
//            }
//        }
//        ofstream inf1("/Users/markiyanandrusevych/Desktop/My PC/Study/Programming/semester 2/Exam3/People.txt");
//        inf1<<totalTime<<"; ";
//        return totalTime;
//
//    }
//    };
//
//
//int main() {
//Action act;
//Action act2;
//act.setActName("Cafe");
//act.setDuration(6);
//act.setTypeOfAction(Friends);
//act2.setActName("Math");
//act2.setDuration(7);
//act2.setTypeOfAction(Walk);
//DayCal day;
//DayCal day2;
//day.setTypeOfDay(Monday);
//day.AddAct(act);
//day.AddAct(act2);
//day2.setTypeOfDay(Tuesday);
//day2.AddAct(act2);
//WeekCal week;
//WeekCal week2;
//week.setPersonName("Marik");
//week.AddDay(day);
//week2.setPersonName("Anna");
//week2.AddDay(day2);
//week.MostActiveDay();
//week2.MostActiveDay();
//week.WalkingSum();
//week2.WalkingSum();
////    vector<string> v={"+","*","+","x","o","p"};
////    EachCount(v);
////    GenCount(v);
////-----------------------------------------
////vector<string> v={"1","2","+","x","p","p"};
////    for(int i=0; i<v.size();i++){
////        cout<<"Vector before delete: "<<v[i]<<endl;
////    }
////    Delete(v);
////    f(v);
//}
//
//
