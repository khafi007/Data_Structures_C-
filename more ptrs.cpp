#include<iostream>
using namespace std;

struct node {
    char info[15];

};

class trial {
    private:
        node obj1, *temp1,*temp2,*temp3;
        int l,length;
        char *p,*q;
    public:
        trial();
        ~trial();
        void startin();

};

int main(){

    trial lnk;
    lnk.startin();
}
trial::trial(){
    temp1 = temp2 = temp3 = NULL;
    p = q =NULL;
}
trial::~trial(){
    delete temp1;
    delete temp2,temp3;
    delete[] p;
}

void trial::startin(){
    int i,j;
    temp1 = new node;
    temp2 = new node;
    cout<<"Enter info about temp1: "<<endl;
    cin>>temp1->info;
    cout<<"Enter info about temp2: "<<endl;
    cin>>temp2->info;
    temp3 = &obj1;
    cout<<"Enter info about temp3: "<<endl;
    cin>>temp3->info;
    //cin>>temp3.obj1;
    cout<<"showing info: "<<endl;
    cout<<temp1->info<<endl;
    cout<<temp2->info<<endl;
    cout<<temp3->info<<endl;
    cout<<"Enter length of character array: "<<endl;
    cin>>length;
    p = new char [length];
    q = p;
    cout<<"Now enter "<<length<<"characters to fill an array"<<endl;
    for(i=0;i<length;i++){
        cin>>*p;
        p = p+1;
    }
    p = q;
    cout<<"Elements of array are: "<<endl;
    for(j=0;j<length;j++){
        cout<<*p<<" , ";
        p = p +1;
    }
    p = q;
}
