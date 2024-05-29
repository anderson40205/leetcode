int max(int a,int b)
{
    return (a>b)? a: b;
}
bool inorder(struct TreeNode* root)
{
    if(root == NULL) return true;
    bool answer = true;
    answer = inorder(root->left);
    if(!answer)return false;
    //
    //printf("%d\n",root->val);
	// We need to calculate the depth of every node, not only the root
    if(abs(Depth(root->left) - Depth(root->right))>=2) return false;
    //
    answer = inorder(root->right);
    if(!answer)return false;
    return answer;
}
bool isBalanced(struct TreeNode* root) {
    if(root == NULL)return true;
    //printf("%d\n",root->val);
    //printf("abs=%d\n",abs(Depth(root->left) - Depth(root->right)));
    if(inorder(root)) return true;
    else return false;
}
int Depth(struct TreeNode* root)
{
    if(root == NULL)return 0;
    return max(Depth(root->left),Depth(root->right))+1;
}
