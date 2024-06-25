#include <iostream>
using namespace std;
struct cll{
    int data;
    struct cll * next;
};
typedef struct cll node;
node * last = NULL;

void create()
{
    if (last == NULL)
    {
        last = new node;
        last->next = last;
        cin >> last->data;
    }
    else
    {
        node * temp = new node;
        temp->next = last->next;
        last->next = temp;
        last = temp;
        cin >> last->data;
    }
}

void tempDisplay()
{
    node * temp = last->next;
    cout<<"The output is: \n";
    do
    {
        cout << temp->data << endl;
        if (temp == last)
            cout << last->next->data;
        temp = temp->next;
    } while(temp != last->next);
}

int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        create();
    }
    tempDisplay();
    return 0;
}
