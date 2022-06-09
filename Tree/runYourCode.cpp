#include <iostream>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int val;
    Node(int n)
    {
        val = n;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *head){
    if(head == NULL)return ;
    cout<<head->val<<" ";
    preorder(head->left);
    preorder(head->right);
}

int main()
{
    int nn;
    cin >> nn;

    Node *n = new Node(5);
    n->left = new Node(3);
    n->left->left = new Node(2);
    n->left->right = new Node(4);
    n->right = new Node(7);
    n->right->left = new Node(6);
    n->right->right = new Node(8);
    preorder(n);
}