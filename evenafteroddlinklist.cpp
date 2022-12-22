void evenAfte rOdd (nodex &head) {
node* odd=head;
nodex even=head->next;
nodex evenSta rt=even;
while (odd->next!=NULL && even->next !=NULL){
odd->next=even->next;
odd=odd->next;
even->next=odd->next;
even=even->next;
odd->next=evenSta rt;
if (odd->next !=NULL){
even->next=NULL;
}
}
}
