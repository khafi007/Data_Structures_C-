#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


void insert_at_end(struct Node** start, int value)
{

    if (*start == NULL) {
        struct Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }



    Node* last = (*start)->prev;

    struct Node* new_node = new Node;
    new_node->data = value;
    new_node->next = *start;

    (*start)->prev = new_node;
    new_node->prev = last;

    last->next = new_node;
}

void deleteNode(struct Node** start, int key)
{

    if (*start == NULL)   // empty check
        return;


    struct Node *curr = *start, *prev_1 = NULL;
    while (curr->data != key) {

        if (curr->next == *start) {     // If node is not present in the list
            cout<<"\nList doesn't have node with value "<< key;
            return;
        }

        prev_1 = curr;
        curr = curr->next;
    }


    if (curr->next == *start && prev_1 == NULL) {
        (*start) = NULL;
        return;
    }


    if (curr == *start) {

        prev_1 = (*start)->prev;

        *start = (*start)->next;
        prev_1->next = *start;
        (*start)->prev = prev_1;
    }


    else {

        struct Node* temp = curr->next;
        prev_1->next = temp;
        temp->prev = prev_1;
    }
}


void display(struct Node* start)
{
    struct Node* temp = start;

    while (temp->next != start) {
        cout<< temp->data;
        temp = temp->next;
    }
    cout<< temp->data;
}

int main()
{

    struct Node* start = NULL;

    insert_at_end(&start, 1);
    insert_at_end(&start, 2);
    insert_at_end(&start, 3);
    insert_at_end(&start, 4);
    insert_at_end(&start, 5);

    cout<<"Doubly Ring List : " <<endl;
    display(start);

    deleteNode(&start, 1);
    cout<<"\nDeleting first element "<<endl;
    display(start);

    deleteNode(&start, 5);
    cout<<"\nDeleting last element "<<endl;
    display(start);

    deleteNode(&start, 3);
    cout<<"\nDeleting mid element : "<<endl;
    display(start);
    cout<<"\nInserting value :"<<endl;
    insert_at_end(&start,5);
    cout<<"\nInserting value again :"<<endl;
    insert_at_end(&start,4);
    display(start);

    return 0;
}
