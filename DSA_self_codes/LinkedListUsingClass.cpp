#include<iostream>
using namespace std;

class Node{
    public :

    int data;
    Node *next;
    Node *first;
    
    
//counting number of nodes
int count(Node *q){
    int l =0;
    while(q){
        l++;
        q = q->next;
    }
    return l;
}

//sum of all the elements
int Add(Node *q){
    int sum = 0;
    while(q){
        sum = sum +q->data;
        q = q->next;
    }
    return sum;

}

//finding the maximum value element
int Max(Node *q){
    int m =INT_MIN;
    while(q){
        if(q->data > m){
            m = q->data;
            q = q->next;
        }
      
    }
  return m;
}

int search(Node *q,int key){
    while(q){
        if(q!=NULL){
            if(key == q->data)
            return q->data;
            q = q->next;

        }
       
    }
 return -1;

}

void insert_beg(){
    int x;
    Node *p = new Node;
    cout<<"enter the data to be inserted :   "<<endl;
    cin>>x;
    p->data = x;
    p->next = first;
    first = p;
}

};

int main(){
    Node n;
    int key;

int A[] = {1,2,34,45};


Node *head = new Node;

Node *temp;
Node *last;



head->data = A[0];
head->next = nullptr;
last = head;

//create a linked list
for(int i = 1;i<sizeof(A)/sizeof(A[0]);i++){

    //create temporary node
    temp = new Node;

    //Populate the temporary node
    temp->data = A[i];
    temp->next = nullptr;

    //last's next is pointing to temp
    last->next = temp;
    last = temp;

}

//display linked list
Node *p = head;

while(p!=nullptr){
    cout<<p->data<<"->";
    p = p->next;
}

cout<<"\n";
cout<<"The count is " <<n.count(head)<<endl;
cout<<"The sum is "<<n.Add(head)<<endl;
cout<<"the maximum element is "<<n.Max(head)<<endl;

cout<<"enter the element to be searched "<<endl;
cin>>key;
cout<<n.search(head,key)<<endl;
n.insert_beg();


while(p!=nullptr){
    cout<<p->data<<"->";
    p = p->next;
}

}

/*
displaying using recursion


void display(Node *p){
    if(p!=0){
        cout<<p->data;
        display(p->next)
    }
}

calling the function
display(head)

*/

/*
this will print the linked list in reverse order
void display(Node *p){
    if(p!=0){
           display(p->next);
        cout<<p->data;
     
    }
}

calling the function
display(head)
*/

/* recursive function for maximum element

int max(Node *p){

    int x =0;

    if(p==0)
    return MIN_INT;

    else{
        x = max(p->next);

        if(x>p->data)
        return x;

        else 
        return p->data;
    }

}
*/

/* MY APPROACH

#include<iostream>
using namespace std;

class Linkedlist{

    public :
    //data types
    typedef struct node{
        int data;
        node *next;

    }node;
    
    node *head = NULL;
    node *last;
    
    //functions
    void create(){
        int x;
        if(head == NULL){
  
        head = new node;
        cout<<"enter the data :"<<endl;
        cin>>x;
        head->data = x;
        head->next = NULL;
        last = head;
        }
        else{
            insert_end();
        }
          }

    void display(){
        node *p = head;
        while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
        }
    }

    void insert_beg(){
  
        node *p = new node;
        cout<<"enter the data "<<endl;
        cin>> p->data;
        p->next = head;
        head = p;
    }

    void insert_end(){
        last->next = new node;
        cout<<"enter the data "<<endl;
        cin>>last->data;
        last = last->next;
        last->next = NULL;
    }

    void insert_mid(){
        int num;
        cout<<"After which number you want to insert:"<<endl;
        cin>>num;
        node *q  = head; 
        while(q!=NULL && q->data!=num){
            q = q->next;
            if(q == NULL){
                cout<<"the specified node doesnt exist"<<endl;
                return;
            }
        }
        node *p = new node;
        cout<<"enter the data :"<<endl;
        cin>>p->data;
       
        p->next  = q->next;
         q->next = p;
        
    }

    void del_beg(){
        node *p = head;
        head = head->next;
        delete p;
    }

    void del_end(){
     node *p= head;
     while(p->next->next !=NULL){
        p = p->next;
     }
     delete p->next;
     p->next = NULL;

    }

    void del_mid(){
        node *p = head;
        node *q;
        int num;
        cout<<"enter the number to be deleted :"<<endl;
        cin>>num;
        while(p->next->data!=num)
	{
		p=p->next;
		
	}
    q=p->next;
    p->next=p->next->next;
	delete q;
      
    }

    void search(){
        int num;
        int i = 1; 
        cout<<"enter the number you want to search"<<endl;
        cin>>num;
        node *p = head;
        while(p!=NULL && p->data != num){
            p = p->next;
            i++;
        }
        if(p==NULL){
            cout<<"element not found"<<endl;
        }
        else{
            cout<<"element was found at index "<<i<<endl;
        }
    }

};

int main(){

    Linkedlist list;
    list.create();
    list.insert_beg();
    list.insert_end();
    list.insert_mid();

    list.search();
    list.display();

  


}
*/
