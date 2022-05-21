#include<iostream>
using namespace std;



int fun(int val){
	
	if (val == 5)
	return 5;
	else{
		cout<<"val: "<<val<<" + fun ("<<val+1<<")"<<endl;
		return 	val+fun(val +1);
		
	}
	
}


int main(){
	cout<<fun(0);
	
	return 0;
	
}
