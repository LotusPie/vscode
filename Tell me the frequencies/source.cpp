#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

bool compare(const pair<int,int>& a,const pair<int,int>& b){
    if(a.second<b.second){
        return true;
    }else if(a.second==b.second){
        if(a.first>b.first){
            return true;
        }
    }
    return false;
}

int main(){
    string enter;bool f = false;
    while(getline(cin,enter)){
        vector <int> char_freq(128,0);
        vector <pair<int,int>> freq;
        for(char c:enter){
            if(c>=32&&c<128){
                char_freq[c]++;
            }
        }
        for(int i = 32;i<128;i++){
            if(char_freq[i]>0){
                freq.push_back(make_pair(i,char_freq[i]));
            }
        }
        sort(freq.begin(),freq.end(),compare);
        if(f){
            cout<<endl;
        }f = true;
        for(const pair<int,int>& p:freq){
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
}