#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int test,Test = 1;
    while(cin>>test){
        bool B2 = true;
        vector<int> v,sum;
        for(int i = 0;i<test;i++){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        if(v[0]<1) B2=false;
        for(int i = 1;i<test;i++){
            if(v[i-1]>=v[i]) B2=false;
        }
        for(int i = 0;i<test;i++){
            for(int j = i;j<test;j++){
                sum.push_back(v[i]+v[j]);
            }
        }
        sort(sum.begin(),sum.end());
        for(int i = 1;i<sum.size();i++){
            if(sum[i-1]==sum[i]) B2=false;
        }
        /*for(int i = 0;i<sum.size();i++){
           cout<<sum[i]<<" ";
        }
        cout<<endl;*/
        if(B2){
            cout << "Case #" << Test << ": It is a B2-Sequence." << endl;
        }
        else{
            cout << "Case #" << Test << ": It is not a B2-Sequence." << endl;
        }
        Test++;
        cout<<endl;
    }
}