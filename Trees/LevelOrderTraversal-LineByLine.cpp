//Approach 1 

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

//Approach 2

/*

#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public : 

    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node* root)
{
    cout <<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    //if we enter -1 as data, we are considering it as NULL
    if(data == -1)
        return NULL;

    cout <<"Enter data of left of "<< data << endl;
    //recursive call
    root->left = buildTree(root->left);
    cout <<"Enter data of right of " <<data <<endl;
    //recursive call
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);

    //separator
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        //ye if condition k andar ke code ki wjh se har level different line me print ho rha hai

        if(temp == NULL)        //purana level completely traverse ho gya hai
        {
            cout <<endl;
            if(!q.empty())      //means queue still has some child element left
                q.push(NULL);
        }
        else
        {
            cout <<temp->data <<" ";
            if(temp->left)
            q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        
    }
}

*/