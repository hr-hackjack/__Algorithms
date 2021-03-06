//https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464

//TC - O(height)
//SC - O(1)

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

int findCeil(BinaryTreeNode<int> *node, int x){
    
    int ceil = -1;
    
    while(node)
    {
        if(node->data == x)
        {
            ceil = node->data;
            return ceil;
        }
        
        else if(node->data < x)
        {
            node = node->right;
        }
        
        else
        {
            ceil = node->data;
            node = node->left;
        }
    }
    return ceil;
}