#include<iostream>
#include<math.h>

using namespace std;

int main(){
    long long a,b;
    while (cin>>a>>b) {
        int ans = 1;
        if(a==0&&b==0) return 0;
        double front = sqrt((double)a);
        int back = sqrt((double)b);
        if(front>(int)front){
            front = (int)front+1;
        }else{
            front = (int)front;
        }
        if(front>back){
                ans = 0;
            }
        for(int i = front;front<back;i++){
            front++;
            ans++;
        }
        cout<<ans<<endl;
    }
}