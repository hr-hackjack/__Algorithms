//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#
//A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

//Approach 1 
//TC - O(n^2)

#include<iostream>
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
 

class Solution{
    
    private:
    
    int height(Node *root)
    {
        //base case
        if(root == NULL)
            return 0;
            
        int opt1 = height(root->left);
        int opt2 = height(root->right);
        
        int ans = max(opt1, opt2) + 1;
        
        return ans;
    }
    
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //base case
        if(root == NULL)
            return true;
            
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diffOfHeight = abs(height(root->left) - height(root->right)) <= 1;
        
        if(left && right && diffOfHeight)
            return true;
            
        else
            return false;
    }
};

//Approach 2 - use pair to reduce time complexity
//TC - O(n)
//did myself. made error in calculating height


/*

class Solution{
    
    private:
    
    pair<bool,int> isBalancedFast(Node *root)
    {
        //base case
        if(root == NULL)
        {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);
        
        bool leftBalanced = left.first;
        bool rightBalanced = right.first;
        bool diffOfHeight = abs(left.second - right.second) <= 1;
        
        pair<bool,int> ans;
        
        if(leftBalanced && rightBalanced && diffOfHeight)
            ans.first = true;
            
        else
            ans.first = false;
            
        ans.second = max(left.second,right.second) + 1;
        
        return ans;
        
    }
    
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};


*/
