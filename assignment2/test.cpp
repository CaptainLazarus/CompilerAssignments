#include<iostream>

using namespace std;

int func(int a){
    cout << a << "\n";
}

using namespace std;

int main(){
    int (*f)(int);
    f = &func;
    f(10);
}