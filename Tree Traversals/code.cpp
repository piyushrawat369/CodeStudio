/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorder(TreeNode* current, vector<int>& ino){
    if(current == nullptr)
        return;
    inorder(current->left, ino);
    ino.emplace_back(current->data);
    inorder(current->right, ino);
}
void preorder(TreeNode* current, vector<int>& preo){
    if(current == nullptr)
        return;
    preo.emplace_back(current->data);
    preorder(current->left, preo);
    preorder(current->right, preo);
}
void postorder(TreeNode* current, vector<int>& posto){
    if(current == nullptr)
        return;
    postorder(current->left, posto);
    postorder(current->right, posto);
    posto.emplace_back(current->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;
    vector<int> preo, ino, posto;

    inorder(root, ino);
    ans.emplace_back(ino);

    preorder(root, preo);
    ans.emplace_back(preo); 

    postorder(root, posto);
    ans.emplace_back(posto);

    return ans;
}
