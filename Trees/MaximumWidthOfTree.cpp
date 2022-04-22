//https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1#

//TC - O(n)
//SC - O(width)

#include<iostream>
#include<queue>
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
 

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        if(root == NULL)
        return 0;
        
        int width = 0;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            width = max(width,n);
            for(int i = 0; i<n; i++)
            {
                Node* temp = q.front();
                q.pop();
                
                if(temp->left)
                    q.push(temp->left);
                    
                if(temp->right)
                    q.push(temp->right);
                    
                
            }
        }
        return width;
    }
};