#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class City {
private:
    int number;
public:
    static int count;

    City() {
        number = count;
        count++;
    }

    int getNumber() const {
        return number;
    }
};

class Road {
private:
    City one;
    City two;
public:
    Road(const City one, const City two){
        if(one.getNumber()<two.getNumber()){
            this->one = one;
            this->two = two;
        }else{
            this->one = two;
            this->two = one;
        }

    }

    City getOne() const {
        return one;
    }

    City getTwo() const {
        return two;
    }
//    Road& operator=(const Road& other) {
//        one = other.one;
//        two = other.two;
//        return *this;
//    }
//
//    bool operator<(const Road& r) const {
//        return (this->getTwo().getNumber() < r.getTwo().getNumber());
//    }
};

bool DFS(const vector<City>& cities, const vector<Road>& roads, int destination) {
    bool result = false;
    vector<City> visited;
    stack<City> dfs;
    for (City c : cities) {
        if (c.getNumber() == 1) {
            dfs.push(c);
            visited.push_back(c);
            break;
        }
    }
    bool flag = true;

    while (flag && !dfs.empty()) {

        vector<Road> tempR;

        for (Road r : roads) {
            if (dfs.top().getNumber() == r.getOne().getNumber()) {
                bool vis  = true;
                for(City cc : visited){

                    if(cc.getNumber()==r.getTwo().getNumber()){
                        vis = false;
                    }
                }
                if(vis){tempR.push_back(r);}
            }
        }
        if (!tempR.empty()) {
            sort(tempR.begin(), tempR.end(), [](const Road& a, const Road& b) {
                return a.getTwo().getNumber() > b.getTwo().getNumber();
            });
            if (tempR.back().getTwo().getNumber() == destination) {
                result = true;
                flag = false;
            }
            dfs.push(tempR.back().getTwo());
            visited.push_back(tempR.back().getTwo());
        }else{
            dfs.pop();
        }
    }
    if(result){
        cout<<"There is a way from City 1 to City "<<destination<<" :"<< endl;
        while(!dfs.empty()){
            cout<<dfs.top().getNumber()<<"<-";
            dfs.pop();
        }
    }else{
        cout<<"There is no way from City 1 to City "<<destination;
    };
    return result;
};


int City::count = 1;

int main() {

    City Lviv = City();
    City Kyiv = City();
    City Poltava = City();
    City Kharkiv = City();
    City Odesa = City();
    Road m1 = Road(Lviv, Kyiv);
    Road m2 = Road(Kyiv, Poltava);
    Road m3 = Road(Kharkiv, Odesa);
    Road m4 = Road(Kharkiv, Lviv);
    vector<Road> rr;
    rr.push_back(m1);
    rr.push_back(m2);
    rr.push_back(m3);
    rr.push_back(m4);
    vector<City> myCities;
    myCities.push_back(Lviv);
    myCities.push_back(Kyiv);
    myCities.push_back(Kharkiv);
    myCities.push_back(Poltava);

    DFS(myCities, rr, 5);
}

