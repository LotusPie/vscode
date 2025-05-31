#include<iostream>

using namespace std;

string week[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

int main(){
    int Case;cin>>Case;
    while(Case--){
        int M,D,cur_day = 1,i;
        cin>>M>>D;
        if(M==1){
            i = 5;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }else if(M==2){
            i = 1;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }else if(M==3){
            i = 1;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }else if(M==4){
            i = 4;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }else if(M==5){
            i = 6;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }else if(M==6){
            i = 2;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }else if(M==7){
            i = 4;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }else if(M==8){
            i = 0;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }else if(M==9){
            i = 3;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }else if(M==10){
            i = 5;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }else if(M==11){
            i = 1;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }else if(M==12){
            i = 3;
            while(cur_day!=D){
                cur_day++;
                i++;
                if(i==7) i = 0;
            }
            cout<<week[i]<<endl;
        }
    }
}