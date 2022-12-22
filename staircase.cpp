#include <iostream>
using namespace std;
int stairs_steps(int n)
{
if (n <= 1)
return n;
else
return stairs_steps(n-1)+stairs_steps(n-2);
}
int countWays(int s)
{
return stairs_steps(s + 1);
}
int pairs(int n,string a = ""){
if(n<0)
return 0;
if(n==0){
cout<<a<<endl;
return 0;
}
pairs(n-1,a+"1");
pairs(n-2,a+"2");

}
int main()
{
int n = 4;
cout<<"Enter a number of stairs: ";
cin>>n;
int a = stairs_steps(n);
int m = countWays(n);
cout << "Number of ways = " << m<<endl;
pairs(n);
return 0;
}
