
for(int i = 0;icn;i++){
int lo = i + 1, hi = n-1;
while(lo<hi){
int current = a[i] + a[lo] + a[hi];
if(current == target){
found = true;
}
if(current target)
lo++;
}
else{
	hi++;


}
if (found){
	cout<<"true";
}
else{
	cout<<"false";
}
}

