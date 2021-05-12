#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val), left(nullptr), right(nullptr){}
};

bool isSameTree(TreeNode* p, TreeNode* q){
    if (p == nullptr && q == nullptr){return true;}
    else if (p != nullptr && q != nullptr){
        bool sameVal = (p->val==q->val);
        bool sameLeft = isSameTree(p->left, q->left);
        bool sameRight = isSameTree(p->right, q->right);
        return (sameVal && sameLeft && sameRight);
    }
    else {return false;}
}

bool isSymmetricHelper(TreeNode* p, TreeNode* q){
    if (p == nullptr && q == nullptr){return true;}
    else if (p!= nullptr && q!= nullptr){
        bool sameVal = (p->val == q->val);
        bool sameLeft = isSymmetricHelper(p->left, q->right);
        return (sameVal && sameLeft);
    }
    else{return false;}
}

bool isSymmetric(TreeNode* root){
    return isSymmetricHelper(root, root);
}

void levelOrder(TreeNode* root){
    queue<TreeNode*> readyToPrint;
    readyToPrint.push(root);
    while (!readyToPrint.empty()){
        TreeNode* current = readyToPrint.front();
        cout<<current->val<<" ";
        readyToPrint.pop();
        if (current->left != nullptr){
            readyToPrint.push(current->left);
        }
        if (current->right != nullptr){
            readyToPrint.push(current->right);
        }
    }
    cout<<endl;
}

void inOrder(TreeNode* root){
    TreeNode* current = root;
    if (current != nullptr){
        inOrder(current->left);
        cout<<current->val<<" ";
        inOrder(current->right);
    }
}
void preOrder(TreeNode* root){
    TreeNode* current = root;
    if (current != nullptr){
        cout<<current->val<<" ";
        preOrder(current->left);
        preOrder(current->right);
    }
}
void postOrder(TreeNode* root){
    TreeNode* current = root;
    if (current != nullptr){
        postOrder(current->left);
        postOrder(current->right);
        cout<<current->val<<" ";
    }
}

int main(int argc, char const *argv[]) {
    // Test level-order printing first.
    {
        TreeNode *root = new TreeNode(20);
        root->left = new TreeNode(5);
        root->right = new TreeNode(30);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(10);
        root->right->left = new TreeNode(25);
        cout<<"pre order: ";
        preOrder(root);
        cout<<endl;
        cout<<"in order: ";
        inOrder(root);
        cout<<endl;
        cout<<"post order: ";
        postOrder(root);
        cout<<endl;
        cout<<"level order: ";
        levelOrder(root);
    }
    cout<<endl;
    // Test symmetry of the trees.
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(3);
        root->right->left = new TreeNode(3);
        root->right->right = new TreeNode(4);
        cout << (isSymmetric(root) ? "Symmetric!" : "Not Symmetric!") << endl;
        root->right->right = new TreeNode(41);
        cout << (isSymmetric(root) ? "Symmetric!" : "Not Symmetric!") << endl;
    }

    // Testing if trees are identical.
    {
        TreeNode *root1 = new TreeNode(1);
        root1->left = new TreeNode(2);
        root1->right = new TreeNode(2);
        root1->left->left = new TreeNode(4);
        root1->left->right = new TreeNode(3);
        root1->right->left = new TreeNode(3);
        root1->right->right = new TreeNode(4);

        TreeNode *root2 = new TreeNode(1);
        root2->left = new TreeNode(2);
        root2->right = new TreeNode(2);
        root2->left->left = new TreeNode(4);
        root2->left->right = new TreeNode(3);
        root2->right->left = new TreeNode(3);
        root2->right->right = new TreeNode(4);

        cout << (isSameTree(root1, root2) ? "Identical!" : "Not Identical!") << endl;

        root2->right->right->right = new TreeNode(4);

        cout << (isSameTree(root1, root2) ? "Identical!" : "Not Identical!") << endl;
    }
    return 0;
}