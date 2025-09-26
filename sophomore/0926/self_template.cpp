#include<iostream>
using namespace std;

template<class T>
T maximum(T value1,T value2,T value3){
    T maximumValue = value1; 
    if ( value2 > maximumValue )
    maximumValue = value2;

    if ( value3 > maximumValue )
    maximumValue = value3;

    return maximumValue;
}

int main(){
    int int1,int2,int3;
    cout << "Input three integer values: ";
    cin >> int1 >> int2 >> int3;
    cout << "The maximum integer value is: " << maximum( int1, int2, int3 );

    double double1, double2, double3;
    cout << "\n\nInput three double values: ";
    cin >> double1 >> double2 >> double3;
    cout << "The maximum double value is: " << maximum( double1, double2, double3 );
}