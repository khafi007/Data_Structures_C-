void reverse (stack<int> &st){
if(st.empty()){
return;
int ele=st. top ();
st.pop();
reverse(st);
insertAtBot tom (st,ele) ;
}}

void insertAtBottom ( stack<int> &st, int ele){
if(st. empty())
st.push(ele) ;
return;|
int topele=st. top ():
st.pop();
insertAtBot tom ( st, ele) ;
st.push(tope le) ;
}
