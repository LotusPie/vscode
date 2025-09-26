#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int Case;cin>>Case;
    for(int C = 1;C<=Case;C++){
        // 讀取 N * string.find() * & * string.substr() *
        int N; string line_enter,number;
        cin.ignore();
        getline(cin,line_enter);
        size_t equal = line_enter.find("="); // 找等於的位置
        number = line_enter.substr(equal+1); // 子字串
        N = stoi(number);
        // 讀取 矩陣  * resize() *
        vector <vector<long long>> v;
        v.resize(N);
        for(int i = 0;i<N;i++){
            v[i].resize(N);
            for(int j = 0;j<N;j++){
                cin >> v[i][j];
            }
        }
        // 判斷
        bool is_symmetric = true;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                if(v[i][j]!=v[N-1-i][N-1-j]||v[i][j]<0){
                    is_symmetric = false;
                    break;
                }
            }
        }
        // 輸出
        if(is_symmetric){
            cout<<"Test #"<<C<<": Symmetric."<<endl;
        }else{
            cout<<"Test #"<<C<<": Non-symmetric."<<endl;
        }
    }   
}