#include<iostream>
#include<string>
using namespace std;

class BankAccount{
private:
    double balance;
public:
    BankAccount(double initial){
        balance = initial;
    }

    void deposit(double amount){
        if(amount>0){
            balance += amount;
        }
    }

    double getBalance(){
        return balance;
    }
};

int main(){
    BankAccount acc(1000);
    acc.deposit(500);
    cout << "餘額: " << acc.getBalance() << endl;
    // acc.balance = 9999;  // 錯誤！無法直接修改
}