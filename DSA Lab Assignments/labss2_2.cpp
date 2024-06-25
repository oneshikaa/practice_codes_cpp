#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};
Node* insert(Node* head, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
	return head;
}
Node* deletes(Node* head, int x)
{
	if (!head)
		return head;
	while (head && head->data == x)
		head = head->next;
	Node *curr = head, *prev = nullptr;

	while (curr) {
		if (curr->data == x)
			prev->next = curr->next;
		else
			prev = curr;
		curr = curr->next;
	}
	return head;
}
void display(Node* node)
{
	while (node) {
        
		cout << node->data << " ";
        node = node->next;
		
	}
}
int main()
{
	Node* head = NULL;
	int n;
	cout<<"Enter number of elements : "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		head=insert(head,temp);
	}
	int key;
	cout<<"Enter the element to be deleted: ";
	cin>>key;
	cout << "Linked List:\n ";
	display(head);
	head = deletes(head, key);
	if (!head)
		cout << "No element present\n"
			<< endl;
	else {
		cout << "\nAfter Deletion: \n";
		display(head);
	}
	
}