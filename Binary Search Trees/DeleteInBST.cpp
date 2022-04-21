//https://leetcode.com/problems/delete-node-in-a-bst/


//Recursive

//TC - O(height)
//SC - O(height)

//successor wala part acche se krna

#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution {
public:
    
    TreeNode* getSuccessor(TreeNode* curr)
    {
        curr = curr->right;
        while(curr != NULL && curr->left != NULL)
            curr = curr->left;
        
        return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)
            return root;
        
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        
        else
        {
            
            if(root->left == NULL)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            
            else if(root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            //have two child 
            else
            {
                TreeNode* succ = getSuccessor(root);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
            
        }
        return root;
    }
};