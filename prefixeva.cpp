int prefixEvaluation (string s){
stackeint> st;
for(int isSs. length ()-1; i>=0; i--)
if(s [i]>='0' && s[i]<='9'){
st.push (s [il-'0');
else{
int opl=st. top() ;
st.pop();
int op2=st. top();
st. pop();
switch (s[i]){
	case '+':
st.push (op1+op2);
break;
case'-':
st.push(op1-op2);
break;
case "*':
st.push(op1*op2);
break
case '/':
st.push (op1/op2) ;
break;
case ':
st.push pow(op1, op2)) ;
break-
}
}
}
return st.top();
}

