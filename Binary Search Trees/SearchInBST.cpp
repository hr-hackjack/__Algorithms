//https://leetcode.com/problems/search-in-a-binary-search-tree/

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
    TreeNode* searchBST(TreeNode* root, int val) {
        //if root is null return null
        if(!root) return root;
        //create node to return 
        TreeNode *node=new TreeNode(); 
        // if root->val != val,search in left and right
        //otherwise this would be required node and we would return it
        if(val<root->val){
            //search in left 
            node=searchBST(root->left,val);
        } else if(val>root->val){
            //search in right
            node=searchBST(root->right,val);
        } else {
            //required node
            node=root;
        }
        return node;
    }
};

//Iterative

//TC - O(height)
//SC - O(1)
//Hence itertive is better becoz of constant space

/*

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        while(root != NULL && root->val != val)
        {
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
};

*/