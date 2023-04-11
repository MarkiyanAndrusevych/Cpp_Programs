#include <iostream>
using namespace std;
template <typename T>
void Doubling(T arr[],int size) {
    int newSize=0;
  if(size%2==0){
      newSize=size+size/2;
  }else{
      newSize=size+size/2+1;
  }
  T newArr[newSize];
  int counter = 0;
  for(int i=0;i<size;i++){
      if(i%2==0) {
          newArr[counter] = arr[i];
          counter++;
      }else{
          newArr[counter]=arr[i];
          counter++;
          newArr[counter]=arr[i];
          counter++;
      }
  }
  for(int j=0;j<newSize;j++){
      cout<<newArr[j]<<":";
  }
}
int main(){
    int my[] = {1,2,3,4,5,6,77,88};
    Doubling (my,8);
    string my2[] = {"Andriy","Marik","Pruvut"};
    Doubling (my2,3);
}