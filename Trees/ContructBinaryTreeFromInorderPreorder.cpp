//https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
//TC - O(n^2). This can be optimised using map
//SC - O(n)

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;

  Node(int x)
  {
      data = x;
      left = NULL;
      right = NULL;
  }
};

class Solution{
    public:
    
    int findPosition(int inorder[], int element, int size)
    {
        for(int i = 0 ; i<size; i++)
        {
            if(inorder[i] == element)
                return i;
        }
        return -1;
    }
    
    Node* solve(int preorder[], int inorder[], int &preorderIndex, int inorderStart, int inorderEnd, int size)
    {
        //base case
        if(preorderIndex >= size || inorderStart > inorderEnd)
            return NULL;
        
        //first element at any step of preorder vector will be root
        int element = preorder[preorderIndex];
        Node* root = new Node(element);
        
        //find position of root in inorder vector
        int position = findPosition(inorder,element,size);
        
        //move to next index in preorder vector
        preorderIndex++;
        
        //left subtree call - kyuki jo root k baad wala index hoga wo left part me lie krra isliye left ko phle call kiya
        root->left = solve(preorder, inorder, preorderIndex, inorderStart, position-1, size);
        
        //right subtree call
        root->right = solve(preorder, inorder, preorderIndex, position+1, inorderEnd, size);
        
        return root;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        //we know root is at index 0 in preorder
        int preorderIndex = 0;
        
        //0 is start index of inorder and n-1 is end index of inorder vector
        Node* ans = solve(pre,in,preorderIndex, 0, n-1, n);
        return ans;
    }
};

//Optimised solution using map
//TC - O(n)

/*

class Solution{
    public:
    
    void createMapping(int inorder[], map<int,int> &nodeToIndex, int size)
    {
        for(int i = 0 ; i<size; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    Node* solve(int preorder[], int inorder[], int &preorderIndex, int inorderStart, int inorderEnd, int size, map<int,int> &nodeToIndex)
    {
        //base case
        if(preorderIndex >= size || inorderStart > inorderEnd)
            return NULL;
        
        //first element at any step of preorder vector will be root
        int element = preorder[preorderIndex];
        Node* root = new Node(element);
        
        //find position of root in inorder vector
        int position = nodeToIndex[element];
        
        //move to next index in preorder vector
        preorderIndex++;
        
        //left subtree call
        root->left = solve(preorder, inorder, preorderIndex, inorderStart, position-1, size,nodeToIndex);
        
        //right subtree call
        root->right = solve(preorder, inorder, preorderIndex, position+1, inorderEnd, size,nodeToIndex);
        
        return root;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        //we know root is at index 0 in preorder
        int preorderIndex = 0;
        
        
        //to make time complexity O(n) 
        map<int,int> nodeToIndex;
        createMapping(in,nodeToIndex, n);
        //0 is start index of inorder and n-1 is end index of inorder vector
        Node* ans = solve(pre,in,preorderIndex, 0, n-1, n,nodeToIndex);
        return ans;
    }
};

*/