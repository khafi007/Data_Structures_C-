#include<iostream>
using namespace std;


void table(int t, int l){
	if (l >= 15){
		return;	
		}
	else {
		
		cout<<t<<" x "<<l<<" = "<<t*l<<endl;
		table(t,l+1);
		
	}
	
}


int fun(int val){
	
	if (val == 5)
	return 5;
	else{
		cout<<"val: "<<val<<" + fun ("<<val+1<<")"<<endl;
		return 	val+fun(val +1);
		
	}
	
}


int main(){
	table(10,1);
	
	return 0;
	
}
