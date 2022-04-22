//https://practice.geeksforgeeks.org/problems/sum-tree/1#
//TC - O(n)
//SC- O(height)

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

// Should return true if tree is Sum Tree, else false
class Solution
{
    private:
    pair<bool,int> isSumTreeFast(Node* root)
    {
        //base case
        if(root == NULL)
        {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        //in ques it is asked to not check leaf node
        if(root->left == NULL && root->right == NULL)
        {
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> left = isSumTreeFast(root->left);
        pair<bool,int> right = isSumTreeFast(root->right);
        
        bool isLeftSumTree = left.first;
        bool isRightSumTree = right.first;
        
        bool condition = (left.second + right.second) == root->data;
        
        pair<bool,int> ans;
        if(isLeftSumTree && isRightSumTree && condition)
            ans.first = true;
            
        else
            ans.first = false;

        //yaha dhyan de. sum me left , right aur root teeno ka data pass krna hai

        ans.second = left.second + right.second + root->data;
        
        return ans;
        
        
    }
    public:
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
};