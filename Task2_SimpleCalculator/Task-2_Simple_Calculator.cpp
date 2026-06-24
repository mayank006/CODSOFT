#include<iostream>
using namespace std;
int main(){
    float a,b;
    char op;
    cout << "Enter First Number(a) : ";
    cin >> a;
    cout << "Enter Second Number(b) : ";
    cin >> b;
    cout << "Enter an operator from(+,-,*,/) : ";
    cin >> op;

    switch (op){
        case '+' : cout << "a+b = "<<a+b;
                   break;
        case '-' : cout << "a-b = "<<a-b;
                   break;
        case '*' : cout << "a*b = "<<a*b;
                   break;
        case '/' : cout << "a/b = "<<a/b;
                   break;
        default : cout<<"Invalid Operator";
    }
    return 0;
}