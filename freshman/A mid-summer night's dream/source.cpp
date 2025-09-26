#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int num;
    while(cin>>num){
        vector<int> v;
        int A; // 中位數
        int sec = 0,thir; // 第2、3輸出
        for(int i=0;i<num;i++){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end()); 
        if(num%2==0){
            A = v[num/2-1];
            int Apuls=v[num/2];
            for(int val:v){
                if(val>=A&&val<=Apuls){
                    sec++;
                }
            }
            thir = v[num/2]-v[num/2-1]+1;
        }else{
            A = v[num/2];
            for(int i : v){ // 計算sec
                if(i == A)sec++;
            }
            thir = 1;
        }
       cout << A << " " << sec << " " << thir << endl;
    }
}