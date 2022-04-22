//https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1

//TC - O(n)
//SC - O(height)

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int findMax(Node *root)
    {
        if(root == NULL)
            return INT_MIN;
            
        else
            return max(root->data, max(findMax(root->left), findMax(root->right)));
    }
    int findMin(Node *root)
    {
        if(root == NULL)
            return INT_MAX;
            
        else
            return min(root->data, min(findMin(root->left), findMin(root->right)));
    }
};