#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int Case;cin>>Case;
    while(Case--){
        int num = 0,med;
        long long sum = 0;
        cin>>num;
        vector <int> v(num);
        for(int i = 0;i < num;i++){
            cin >> v[i];
        }
        med = num / 2;
        sort(v.begin(),v.end());
        for(int i = 0;i < num;i++){
            int temp = v[i]-v[med];
            if(temp<0){
                sum += -(temp);
            }else{
                sum += temp;
            }
        }
        cout<<sum<<endl;
    }
}