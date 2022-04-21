//https://leetcode.com/problems/insert-into-a-binary-search-tree/

//Recursive
//TC - O(height)
//SC - O(height)


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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        
        if(root->val > val)
            //made mistake here by simply calling function like below
            //insertIntoBST(root->left, val);
            //instead of what is written below
            
            //simply writing insertIntoBST(root->left, val) this line return to base case when you find leaf node
            //then base case creates a node node with value val
            //but it does not create link between leaf node and new node
            //to create that link, with assign it to root->left
            root->left = insertIntoBST(root->left,val);
        
        else
            root->right = insertIntoBST(root->right,val);
        
        return root;
    }
};


//Iterative

//TC - O(height)
//SC - O(1)
//Hence itertive is better becoz of constant space

/*

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* temp = new TreeNode(val);
        
        //this is required to make connection between leaf node and new node
        TreeNode* parent = NULL;
        TreeNode* curr = root;
       
        while(curr)
        {
            //before changing the curr, save its value in parent which will be utilised to link new node
            parent = curr;
            
            if(curr->val > val)
                curr = curr->left;
            
            else if(curr->val < val)
                curr = curr->right;
            
            else
                return root;
          
        }
        
        //empty list
        if(parent == NULL)
            return temp;
        
        //making connection between parent and new node
        if(parent->val >val)
            parent->left = temp;
        
        else
            parent->right = temp;
        
        
        return root;
    }
};

*/