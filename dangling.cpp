#include<iostream>
#include<string.h>
using namespace std;

int main(){

    int *ptr1 = new int;
    int *ptr2 = new int;
    *ptr2 = 10;
    *ptr1 = *ptr2;

    ptr1 = ptr2;
    delete ptr2;
    cout<<*ptr1<<endl;
    cout<<*ptr2<<endl;
    cout<<&ptr1<<endl;
    cout<<&ptr2<<endl;

    return 0;

}
