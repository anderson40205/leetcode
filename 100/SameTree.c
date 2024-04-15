/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSame = true;
void inorder(struct TreeNode* node1, struct TreeNode* node2)
{   
    if( (node1==NULL&&node2!=NULL) || (node1!=NULL&&node2==NULL) )
    {
        isSame = false;
        return;
    }
    if(node1 == NULL && node2 == NULL)
    {
        return;
    }
    if(node1->val != node2->val)
    {
        isSame = false;
        return;
    }
    inorder(node1->left,node2->left);
    if(!isSame) return;
    inorder(node1->right,node2->right);
    if(!isSame) return;
} 

bool isSameTree(struct TreeNode* p, struct TreeNode* q) { 
    isSame = true;
    if(p==NULL && q==NULL)
    {
        return true;
    } 
    else
    {
        inorder(p,q);
        return isSame;
    }
}