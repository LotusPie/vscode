#include <iostream>
#include <string>
using namespace std;

class car{
public:
    string brand;
    int speed;

    void accelerate(){
        speed+=10;
        cout << brand << " 加速到 " << speed << " km/h" << endl;
    }
};

int main(){
    car myCar;
    myCar.brand = "Kia";
    myCar.speed = 0;
    myCar.accelerate();
}