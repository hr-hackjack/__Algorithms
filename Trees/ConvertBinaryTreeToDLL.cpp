//Do inplace conversion means use the same space which is occupied by tree to convert it in DLL
//order of traversal should be inorder

//https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1/#

//TC - O(n)
//SC - O(height)


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 

// This function should return head to the DLL
class Solution
{
    public:
    
    Node* prev = NULL;
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if(root == NULL)
            return root;
            
        Node* head = bToDLL(root->left);
        if(prev == NULL)
            head = root;
            
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        bToDLL(root->right);
        return head;
    }
};

