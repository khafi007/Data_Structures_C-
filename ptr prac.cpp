#include<iostream>
using namespace std;


int main(){
	int arr[5], *pp, i;
	pp = arr;
	cout<< "Enter vals:(index) "<<endl;
	for (int i =0; i<=4; i++)
	{
		cin>>arr[i];
	 } 
	pp =arr;
	cout<<"Enter vals: (pointer)"<<endl;
	for(int i =0; i<=4; i++){
		cin>>*pp;
		pp++;
		
	}
	cout<<"vals from array usinhg pointer: "<<endl;
	pp = arr;
	for (int i = 0; i<= 4; i++){
		cout<<*pp<<"\t";
		pp++;
		
	}
	cout<<endl;
	cout<<"Using while loop: "<<endl;
	int *ptr = arr;
	while(*ptr != NULL){
		cout<< *ptr++<<"\t";
		
		
	}
	
	return 0;

}


