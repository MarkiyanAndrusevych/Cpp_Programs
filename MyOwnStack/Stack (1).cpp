#include <iostream>
#include <stack>
using namespace std;
class Stack{
private:
    int *arr;
    int size;
    int count;
public:
    Stack(){
        arr=new int [60];
        size=60;
        count=-1;
    }
    Stack(int StackSize){
        arr= new int [StackSize];
        size=StackSize;
        count=-1;
    }
    int top(){
        int i = arr[count];
        return i;

    }
    void push(int x){
        count++;
        this->arr[count]=x;
    }
    bool empty(){
        if(count>-1){
            return false;
        }
        else{
            return true;
        }
    }
    void pop(){
    arr[count]= NULL;
    count --;
    }
    int sizeStack(){
        return count;
    }



};
int main(){
    //Stack STL
    stack<string> myStack;
    myStack.push("abc");
    myStack.push("def");
    myStack.push("ghi");
    cout <<"Size of myStack: "<< myStack.size()<<endl;
    cout <<"Top element in my stack: "<<myStack.top()<<endl;
    cout<<"Printing and deleting all elements in myStack: \n";
    while(!myStack.empty()){
        cout<<myStack.top();
        myStack.pop();
        if(myStack.empty()){
            cout<<endl;
        }
    }
    cout<<"My custom stack size: "<<myStack.size()<<endl;
    //Custom stack
Stack s1(10);
s1.push(10);
s1.push(4);
s1.push(8);
s1.push(9);
cout<<"Size of my stack: "<<s1.sizeStack()<<endl;
cout<<"Top element: "<<s1.top()<<endl;
cout<<s1.empty()<<endl;
s1.pop();
cout<<"Size after pop: "<<s1.sizeStack()<<endl;
cout<<s1.top()<<endl;
}
