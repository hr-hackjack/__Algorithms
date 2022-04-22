//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/#
//TC - O(n)
//SC - O(height)

#include<iostream>
#include<vector>
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
 

//Function to return a list containing elements of left view of the binary tree.

void solve(Node* root, vector<int> &ans, int level)
{
    if(root ==  NULL)
        return;
        
    //when we reach a level for first time, its value will be equal to size of vector
    if(level == ans.size())
        ans.push_back(root->data);
    
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
    
}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}


//Iterative solution 
//TC - O(n)
//SC - theta(width) or O(n)

/*
vector<int> leftView(Node *root)
{
   vector<int> v;
   
        if(root==NULL)
            return v;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int count=q.size();
            for(int i=0;i<count;i++){
                Node* curr=q.front();
                q.pop();

                //i = 0 shows the left most element
                if(i==0)
                    v.push_back(curr->data);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        return v;
}

*/