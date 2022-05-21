#include<iostream>
using namespace std;
int main(){
int *val, *rows, *cols;int maxr, maxc, i, j;cout<<"enter dimensions of
array (row col): ";cin>>maxr>>maxc;val = new int[maxr * maxc];rows = new int
[maxr];cols = new int [maxc];for (i = 0; i< maxr;i++){
cout<< "\nEnter elements for row: "<<i+1<<" : ";rows[i] = 0;for
(j =0;j < maxc;j++){cin>> val[i* maxc + j];rows[i] = rows[i] + val [i * maxc +
j];
} 
}
for (j=0; j< maxc; j++){
cols[j] = 0;
for (i=0;i<maxr;i++){
cols[j] = cols[j] + val [i * maxc + j]; 
}
}
cout<<"Given array is: ";
for (i=0;i< maxc; i++){
for (j =0; j<maxc;j++){
cout<< val[i * maxc + j]<<"\n"; 
}
cout<<rows[i]<<"\n";
}
for (j= 0; j< maxc; j++){
cout<<cols[j]<<"\n";
}
cout<<"\n";delete []val;delete []rows;delete []cols;return 0;