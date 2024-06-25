#include <iostream>
using namespace std;

struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
};
typedef struct tree node;
node *root = NULL;
node *temp;
int num,l;

    
    
 
void create()
{
    temp = new node;
    cout << "Enter the data" << endl;
    cin >> num;
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;
}
void search(node *p)
{
    if (temp->data < p->data && p->left == NULL)
    {
        p->left = temp;
    }
    if (temp->data < p->data && p->left != NULL)
    {
        search(p->left);
    }
    if (temp->data > p->data && p->right == NULL)
    {
        p->right = temp;
    }
    if (temp->data > p->data && p->right != NULL)
    {
        search(p->right);
    }
}
void insert()
{
    create();
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        search(root);
    }
}
void tree_minimum(node *p)
{
    while (p != NULL)
    {
        p = p->left;
    }
    cout << p->data;
}

int tree_search(node *p, int key)
{
    if (p == NULL)
    {
        return 0;
    }
    if (key == p->data)
    {
        return 1;
    }
    if (key < p->data)
    {
        tree_search(p->left, key);
    }
    else
    {
        tree_search(p->right, key);
    }
}

void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void leaf_node(node *p)
{
        if (p->right == NULL && p->left == NULL)
        {
            l++;
           cout<<"inside if"<<endl;
        }
        else
        {
            cout<<"else"<<endl;
             leaf_node(p->left);
             leaf_node(p->right);
           
        }
        cout<<"number of leaf nodes"<<l;

    
}

int main(void)
{
    
    insert();
    insert();
    insert();
    insert();
    inorder(root);
    leaf_node(root);
   // cout << "leaf node : " << l;

    // tree_minimum(root);
}