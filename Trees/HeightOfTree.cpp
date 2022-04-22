//also called max depth of tree
//https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/
//longest path from root to leaf node

//TC - O(n)
//SC - O(height)

#include<bits/stdc++.h>
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
    int maxDepth(TreeNode* root) {
        
        //base case
        if(root == NULL)
            return 0;
        
        int opt1 = maxDepth(root->left);
        int opt2 = maxDepth(root->right);
        
        int depth = max(opt1,opt2) + 1;
        
        return depth;
        
        
    }
};