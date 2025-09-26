#include<iostream>

using namespace std;

int main(){
    double H,U,D,F;
    while(cin>>H>>U>>D>>F){
        F = U * F / 100;
        if(H==0)return 0;
        double curH = 0;
        int Day = 1;
        curH += U;
        if(curH>H){
            cout<<"success " <<"on "<<"day "<< Day << endl;
            continue;
        }
        curH -= D;
        if(curH<0){
            cout<<"failure " <<"on "<<"day "<< Day << endl;
            continue;
        }
        while(curH>=0&&curH<=H){
            Day++;
            if(U>0){
                U -= F;
            }
            if(U<0)U=0;
            curH += U;
            if(curH<0||curH>H){
                break;}
            curH -= D;
            //cout<<"D "<<Day<<endl;
            //cout<<"now "<<curH<<endl;
        }
        if(curH>H){
            cout<<"success " <<"on "<<"day "<< Day << endl;
        }
        else if(curH<0){
            cout<<"failure " <<"on "<<"day "<< Day << endl;
        }
    }
}