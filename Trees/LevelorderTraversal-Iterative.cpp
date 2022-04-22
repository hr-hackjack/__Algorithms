//https://leetcode.com/problems/binary-tree-level-order-traversal/
//TC - O(n)
//SC - O(width)

//Recursion is not efficient for this becoz in recursion it will first print left subtree then right subtree
//but we want to print level wise. So everytime we print a left element we want to print all the elements in that level

/*
Approach 2 - We can find height of the tree and then simultaneously keep printing all the element present at that height
This approach is inefficient because we need O(n) time to find height, then O(n*h) elements to print height at that level.
So overall TC becomes O(n+ h*n)

*/

//Hence follow approach 3 which uses queue
//this code print level in different line

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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> answer;

        if(!root) return answer;  //if root is NULL then return

        queue<TreeNode*> q;  //for storing nodes

        q.push(root);  //push root initially to the queue

        while(!q.empty())  //while queue is not empty go and follow few steps
        {
            int size=q.size();  //storing queue size for while loop
            vector<int> v;  //for storing nodes at the same level
            for(int i = 0 ; i<size; i++)  
            {
                TreeNode* temp=q.front();  //store front node of queue  and pop it from queue
                q.pop();
                v.push_back(temp->val);  //push it to v

                if(temp->left) 
                    q.push(temp->left);  //if left subtree exist for temp then store it into the queue

                if(temp->right) 
                    q.push(temp->right);  //if right subtree exist for temp then store it into the queue
            }
            answer.push_back(v);  //push v into answer, as v consist of all the nodes of current level
        }
        return answer;  //return the answer
    }
};