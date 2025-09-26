#include<iostream>
#include<math.h>
#include<cmath>

using namespace std;

int main(){
    int S,ans;
    long long Day,Sn;
    while(cin>>S>>Day){
        /*long long cur_day = 1,ans;
        for(int i = S;cur_day!=Day;i++){
            ans = i;
            for(int j = i;j>0;j--){
                cur_day++;
                if(cur_day==Day) break;
            }
        }
        cout<<ans<<endl;*/
        /*if(S>=Day){
            cout<<S<<endl;
            continue;
        }
        int a1,an,n;
        a1 = S;an = a1 + 1;n = 2;
        Sn = (a1+an)*n/2;
        while(Sn<Day){
            n++;an = an + 1;
            Sn = (a1+an)*n/2;
        }
        cout<<an<<endl;*/
        double D = 4*S*S-4*S+1+8*Day;
        long long m = (long long)ceil(((1-2*S)+sqrt(D))/2);
        ans = S + m - 1;
        cout<<ans<<endl;
    }
}