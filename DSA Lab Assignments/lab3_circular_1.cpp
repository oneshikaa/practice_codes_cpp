// Cicular Linked List
#include<iostream>
using namespace std;



struct Linkedlist
{
    int data;
    struct Linkedlist * next;
};

typedef struct Linkedlist node;
node * head = NULL, * temp;

void insertEnd()
{
    node * temp = new node;
    cout << "Enter data: " << endl;
    cin >> temp->data;
    temp->next = head->next;
    head->next = temp;
    temp = head;
}

void create()
{

    if (head == NULL)
    {
        head  = new node;
        cout << "Enter data: " << endl;
        cin >> head->data;
        head->next = head;
    }
    else
    {
        insertEnd();
    }
}

void display()
{
    node * disp = head;
    do {
            cout << disp->data << endl;
            disp = disp->next;
    
        } while(disp != head);
}




void insertBeginning()
{
    node * beg = new node;
    cout << "Enter data: " << endl;
    cin >> beg->data;
    beg->next = head;
    node * temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = beg;
    head = beg;
}

void insertMiddle()
{
    int num,ref;
    cout << "Enter data: " << endl;
    cin >> num;
    cout << "Enter the number after which input must be added: " << endl;
    cin >> ref;
    node * loopPointer = head;
    while( loopPointer->data != ref)
    {
        loopPointer = loopPointer->next;
    }
    node * temporaryNode = new node;
    temporaryNode->data = num;
    temporaryNode->next = loopPointer->next;
    loopPointer->next = temporaryNode;
}

void deleteEnd()
{
    node * temp = head;
    if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        
    else{
        node * ptr = head->next;
        while(ptr->next!=head)
        {
            ptr = ptr->next;
        } 
        ptr->next = head->next;
        delete head;
        head = ptr;
    }
}

void deleteBeginning()
{
     node * tempPointer = head->next;
     head->next = head->next->next;
     delete tempPointer;
}

void deleteMiddle()
{
    int num;
    cout << "Enter data to delete: "<< endl;
    cin >> num;
    node * temporaryPointer = head->next;
    node * temporaryPointer2 = NULL;
    while(temporaryPointer->next->data != num)
    {
        temporaryPointer = temporaryPointer->next;
    }
    temporaryPointer2 = temporaryPointer->next;
    temporaryPointer->next = temporaryPointer2->next;
    delete temporaryPointer2;
    
}




void Search()
{
    int num, count = 1;
    cout << "Enter the data to search for: " << endl;
    cin >> num;
    node * temporaryPointer = head->next;
    if (head->data == num)
    {
        cout << "The required element was found at the end of the list" << endl;
    }
    else{
    while(temporaryPointer!= head && temporaryPointer->data != num)
    {
        count++;
        temporaryPointer = temporaryPointer->next;
    }
    if (temporaryPointer!= head)
        cout << "The required data was found at position " << count << endl;
    else
        cout << "Node not found!!" << endl;
    
    }
}

int main()
{
    int menu;
    cout << "1. Create node" << endl;
    cout << "2. Display items" << endl;
    cout << "3. Add node at beginning" << endl;
    cout << "4. Add node in the middle" << endl;
    cout << "5. Delete last node" << endl;
    cout << "6. Delete first node" << endl;
    cout << "7. Delete middle node" << endl;
    cout << "8. Search" << endl;
    cout << "9.Exit" << endl;
    do{
    cout << "Enter menu item: " << endl;
    cin >> menu;
    switch(menu)
    {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insertBeginning();
            break;
        case 4:
            insertMiddle();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            deleteBeginning();
            break;
        case 7:
            deleteMiddle();
            break;
        case 8:
            Search();
            break;
        default:
            break;
    }} while(menu != 9);
    return 0;
}