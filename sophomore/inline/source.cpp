#include<iostream>

using namespace std;

inline double cube(const double s){
    return s*s*s;
}

int main(){
    double side;
    for(int i = 1;i<=3;i++){
        cout << "enter the side length of your cube: ";
        cin >> side ;
        cout << "Volume of cube with side "
        <<side<<" is "<< cube(side)<<endl;
    }
    return 0;
}