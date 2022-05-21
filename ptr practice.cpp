#include<iostream>
using namespace std;

int main(){
    int x,z;
    int *ptrr;


    x= 5;
    z= 9;
    ptrr = &z;
    *ptrr = 21;
    cout<<*ptrr<<endl;
    cout<<x<<endl;
    cout<<z<<endl;
    ptrr = &x;
    *ptrr = 31;
    cout<<*ptrr<<endl;
    cout<<x<<endl;
    cout<<z;

    return 0;


}
