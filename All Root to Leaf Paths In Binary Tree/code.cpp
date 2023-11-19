/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        int data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/


void helper(BinaryTreeNode<int>* root, vector<string> &root_leaf, string str)

{
    if(root->left==NULL && root->right==NULL)
    {
        string s=to_string(root->data);
        root_leaf.push_back(str+s);
        return;
    }

    string s=to_string(root->data);
    if(root->left!=NULL)
        helper(root->left,root_leaf,str+s+" ");

    if(root->right!=NULL)
        helper(root->right,root_leaf,str+s+" ");

    return;
}

vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    vector<string> root_leaf;
    if(root==NULL)
        return root_leaf;

    helper(root,root_leaf,"");
    return root_leaf;
}

