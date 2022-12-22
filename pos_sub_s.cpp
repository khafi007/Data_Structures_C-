#include<iostream>
using namespace std;


void pos_subs(string a, string b){
	
	if (a.length()==0){
		cout<<b<<endl;
		return;
	}
	char ch = a[0];
	string ros = a.substr(1);
	
	pos_subs(ros,b);
	pos_subs(ros,b+ch);

}


int main(){
	pos_subs("ABC","");
	
	return 0;
}
