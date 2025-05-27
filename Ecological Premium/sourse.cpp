#include<iostream>

using namespace std;

int main(){
    int test;cin>>test;
    for(int t = 0;t<test;t++){
        int farmers,sum = 0;cin>>farmers;
        for(int f = 0;f<farmers;f++){
            int x,animals,envir,premium;
            cin>>x>>animals>>envir;
            premium = x * envir;
            sum +=premium;
        }
        cout<<sum<<endl;
    }
}