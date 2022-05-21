#include <iostream>
using namespace std;

class list
{
	private:
		int *lst;//pointer always at first index
		int *curr;//pointer used for current location
		int size; //size is filled index
		int length;	// length is total index
	public:
		list(int len);
		~list();
		void update(int val);
		void addInTheEnd(int val);
		void addAtPosition(int ind, int val);
		void addInTheStart(int val);
		void search(int val);
		void delete_element(int val);
		void deleteByIndex(int ind);
		int *getCurrent();
		int lengthOf();
		void next(); 
		void back();
		void start();
		void end();
		void print();
		bool IsFull();
		int  sizeOf();	
		bool IsEmpty();
		void reverseList();
		void copyList();
		void sortList();
		

};

list::list(int len)
{
	lst = new int[len];
	length = len;
	curr == NULL;
	size = 0;
}

list::~list()
{
	delete lst;
	delete curr;
}

bool list::IsFull(){
	if (size == length)
	return 1;
	else
	return 0;
	
}

bool list::IsEmpty(){
	if (size == 0)
	return 1;
	else
	return 0;
	
}

void list::sortList(){
	curr= lst;
	int tempvar;
	for(int i=0;i<size;i++)
	{		
		for(int j=i+1;j<size;j++)
		{
			if(*(curr + j) < *(curr + i))
			{
				tempvar = *(curr + i);
                *(curr + i) = *(curr + j);
                *(curr + j) = tempvar;
			}
		}
	}
	cout<<"sorted list is: [";
	for (int i = 0; i < size; i++){
	
        cout<<*(curr + i)<<",";
    }
	cout<<"]"<<endl;
}
	


void list::copyList(){
	int *ptrr = new int[length];
	cout<<"Copy of original is: [";
	curr = lst;
	for (int i = 0;i <= size-1; i++){
	*ptrr = *curr;
	cout<<*ptrr<<",";
	ptrr++;
	curr++;
	}
	cout<<"]"<<endl;
}



void list::reverseList(){
	int *ptrrr;
	curr = lst + size -1;
	ptrrr = lst;
	cout<<"Reverse list is: [";
	while (curr != ptrrr){
	cout<<*curr<<",";
	curr--;
	}
	cout<<*ptrrr<<"]"<<endl;
}


void list::addInTheEnd(int val)
{
	curr = lst;
	if (size == 0)
	{
		*curr = val;
		size += 1;
		curr++;
	}
	else if (size < length)
	{
		*(curr + size) = val;
		curr++;
		size += 1;
	}
	else
	{
		cout<<"Index out of bound(Array is full)"<<endl;
	}
}

void list::addAtPosition(int ind, int val)
{
	if (size < length)
	{
		if (ind == 0)
		{
			addInTheStart(val);
			return;
		}
		else if (ind == size)
		{
			addInTheEnd(val);
		}
		else
		{
			curr = lst+size;
			ind = size - ind;
			while(ind != 0)
			{
				curr--;
				*(curr+1) = *curr;
				ind -= 1;
			}
			*curr = val;
			size += 1; 
		}
	}
	else
	{
		cout<<"Index out of bound(Array is full)"<<endl;
	}
}


void list::addInTheStart(int val)
{
	curr = lst + size;
	if (curr == lst)
	{
		*curr = val;
		size += 1;
	}
	else if (size < length)
	{
		while(curr != lst)
		{
			curr--;
			*(curr+1) = *curr;
		}
		*curr = val;
		size += 1;
	}
	else
	{
		cout<<"Index out of bound(Array is full)"<<endl;
	}
}


void list::search(int val)
{
	
	curr = lst;
	while(curr != lst + size)
	{
		if (*curr == val)
		{
			cout<<val<<" is in list "<<endl;
			return;
		}
		curr++;
	}
	cout<<val<<" is not in list"<<endl;
}



void list::delete_element(int val)
{
	curr = lst;
	while(curr != lst + size)
	{
		if (*curr == val)
		{
			while(curr != lst + size)
			{
				*curr = *(curr+1);
				curr++;
			}
			size -= 1;
			return;
		}
		curr++;
	}
	cout<<val<<" is not in list"<<endl;
}

void list::deleteByIndex(int ind)
{
	curr = lst + ind;
	while(curr != lst + size)
	{
		*(curr) = *(curr + 1); 
		curr++;
	}
	size -= 1;
	return;
}



int* list::getCurrent()
{
	return curr;
}





int list::lengthOf()
{
	cout<<"Total Length of list is: "<<length<<endl;
}




int list::sizeOf()
{
	cout<<"Filled elements(size) of list: "<<size<<endl;
}




void list::update(int val)
{
	*curr = val;
}




void list::next()
{
	curr++;
	if (curr == lst + length)
	{
		cout<<"Index out of bound"<<endl;
		curr--;
		return;
	}
	else{
		return;
	}
	
}




void list::back()
{
	curr--;
	if (curr == lst)
	{
		cout<<"Index out of bound"<<endl;
		curr++;
		return;
	}
	else{
		return;
	}
	
}




void list::start()
{
	curr = lst;
}

void list::end()
{
	curr = lst + size;
}

void list::print()
{
	cout<<"'[";
	curr = lst;
	while(curr != lst + size)
	{
		cout<<*curr;
		if (curr != lst+(size-1))
		{
			cout<<",";
		}
		curr++;
	}
	curr = NULL;
	cout<<"]"<<endl;
	cout<<length-size<<" places empty'"<<endl;
}





int main()
{
	list l(5);
	l.addInTheEnd(78);
	l.addInTheEnd(89);
	
	l.addInTheEnd(3);
	l.getCurrent();
	l.addInTheEnd(43);
	l.addInTheEnd(1);
	l.print();
	l.sortList();
	l.copyList();
	l.reverseList();
	l.lengthOf();
	l.delete_element(3);
	l.addInTheStart(5);
	l.print();
	l.delete_element(3);
	l.addInTheEnd(88);
	l.addAtPosition(4,9);
	l.print();
	

	return 0;
}
