#include<iostream>
using namespace std;



void fun(int val){
	
	if (val == 10)
	return;
	else{
		cout<<"val: "<<val<<"= fun ("<<(val+1)<<")"<<endl;
		fun(val +1);
		
	}
	
}


int main(){
	fun(0);
	
	return 0;
	
}
