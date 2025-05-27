#include<iostream>
#include<string>

using namespace std;

int m[8][8]; // map
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; // diration

int main(){
    int a,b,c; // a is king , b is queen 
    while(cin>>a>>b>>c){
        if(a==b){ // condition one
            cout<<"Illegal state"<<endl;
            continue;
        }
        for(int i = 0;i<8;i++){ 
            for(int j = 0;j<8;j++){
                m[i][j]= 0;
            }
        }
        
    }
}