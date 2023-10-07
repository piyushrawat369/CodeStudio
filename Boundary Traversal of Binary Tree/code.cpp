/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()

        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> *root){
    return !(root->left) && !(root->right);
}

void addLeftBoundary(TreeNode<int> *root, vector<int> &res){
    TreeNode<int>* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addLeaf(TreeNode<int> *root, vector<int> &res){
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaf(root->left, res);
    if(root->right) addLeaf(root->right, res);
}

void addRightBoundary(TreeNode<int> *root, vector<int> &res){
    TreeNode<int>* curr = root->right;
    vector<int> tmp;
    while(curr){
        if(!isLeaf(curr)) tmp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    
    for(int i=tmp.size()-1; i>=0; i--){
        res.push_back(tmp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> res;
    if(!root) return res;

    if(!isLeaf(root)) res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeaf(root, res);
    addRightBoundary(root, res);

    return res;
}
