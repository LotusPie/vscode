#include<iostream>
using namespace std;

void swap1(int*a,int*b);
void swap2(int&a,int&b);

int main(){
    int a = 1;
    int b = 2;
    cout<<"a="<<a<<"; b="<<b<<endl;
    
    //swap by pointer
    swap1(&a,&b);
    cout<<"a="<<a<<"; b="<<b<<endl;

    //swap by reference
    swap2(a,b);
    cout<<"a="<<a<<"; b="<<b<<endl;
}
void swap1(int*a,int*b){
    int temp =*a;
    *a = *b;
    *b = temp;
}
void swap2(int&a,int&b){
    int temp = a;
    a = b;
    b = temp;
}