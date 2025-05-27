#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;

int main(){
    int test;cin>>test;
    while(test--){
        vector<int> ans(10,0);
        string enter;cin>>enter;
        for(int i = 0;i<enter.size();i++){
            if(islower(enter[i])){
                if(enter[i]=='c'){
                    for(int j = 1;j<4;j++)ans[j]++;
                    for(int j = 6;j<10;j++)ans[j]++;
                }
                else if(enter[i]=='d'){
                    for(int j = 1;j<4;j++)ans[j]++;
                    for(int j = 6;j<9;j++)ans[j]++;  
                }
                else if(enter[i]=='e'){
                    for(int j = 1;j<4;j++)ans[j]++;
                    for(int j = 6;j<8;j++)ans[j]++;  
                }
                else if(enter[i]=='f'){
                    for(int j = 1;j<4;j++)ans[j]++;
                    ans[6]++;  
                }
                else if(enter[i]=='g'){
                    for(int j = 1;j<4;j++)ans[j]++; 
                }
                else if(enter[i]=='a'){
                    for(int j = 1;j<3;j++)ans[j]++;
                }
                else if(enter[i]=='b'){
                    ans[1]++;
                }
            }
            else if(isupper(enter[i])){
                if(enter[i]=='C'){
                    ans[2]++;
                }
                else if(enter[i]=='D'){
                    for(int j = 0;j<4;j++)ans[j]++;
                    for(int j = 6;j<9;j++)ans[j]++;  
                }
                else if(enter[i]=='E'){
                    for(int j = 0;j<4;j++)ans[j]++;
                    for(int j = 6;j<8;j++)ans[j]++;  
                }
                else if(enter[i]=='F'){
                    for(int j = 0;j<4;j++)ans[j]++;
                    ans[6]++;  
                }
                else if(enter[i]=='G'){
                    for(int j = 0;j<4;j++)ans[j]++;
                }
                else if(enter[i]=='A'){
                    for(int j = 0;j<3;j++)ans[j]++;
                }
                else if(enter[i]=='B'){
                    for(int j = 0;j<2;j++)ans[j]++;
                }
            }  
        }
        for(int a:ans){
                cout<<a<<" ";
            }
            cout<<endl;
    }
}