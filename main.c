#include "geek.h"

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} TreeNode;

TreeNode* treeInsert(TreeNode *t, int data) {
    TreeNode *newNode;
    newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode *current = t;
    TreeNode *parent = t;
    if (t == NULL) {
        t = newNode;
    } else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printTree(TreeNode *root) {
    if (root) {
        printf("%d", root->key);
        if(root->left || root->right) {
            printf("(");
            if (root->left)
                printTree(root->left);

            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

TreeNode* getSuccessor(TreeNode *node) {
    TreeNode *current = node->right;
    TreeNode *parent = node;
    TreeNode *s = node;
    while (current != NULL) {
        parent = s;
        s = current;
        current = current->left;
    }
    if (s != node->right) {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}

boolean delete(TreeNode *root, int key) {
    TreeNode *parent = root;
    TreeNode *current = root;
    boolean isLeftChild = true;
    while (current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
        if (current == NULL)
            return false;
    }
    if (current->left == NULL && current->right == NULL) {
        if (current == root)
            root = NULL;
        else if (isLeftChild)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if (current->right == NULL) {
        if (isLeftChild)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if (current->left == NULL) {
        if (isLeftChild)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else {
        TreeNode *successor = getSuccessor(current);
        if (current == root)
            root = successor;
        else if (isLeftChild)
            parent->left = successor;
        else
            parent->right = successor;
        successor->left = current->left;
    }
    return true;
}

//1.
int deepTree(TreeNode *root) { //считает глубину дерева
   if (root == NULL)
       return 0;
   else
       return 1 + max(deepTree(root->left), deepTree(root->right));
}


int max(int a, int b) {  //возвращает максимальное из двух чисел
    return (a >= b) ? a : b;
}

boolean isBalance(TreeNode *root) {
    int leftDeep = deepTree(root->left);
    int rightDeep = deepTree(root->right);
    if(root == NULL)
        return true;
    if(abs(leftDeep - rightDeep) <= 1 && isBalance(root->left) && isBalance(root->right))
        return true;
    else
        return false;
}


void treeCreator(const int n, const int size) {
    int border = 100;
    int isBalanced = 0;
    for (int i = 0; i < n; i++) {
        TreeNode *tree = NULL;
        tree = treeInsert(tree, size / 2);
        for (int j = 0; j < size; j++) {
            treeInsert(tree, rand() % border );
        }
    if (isBalance(tree))
        isBalanced++;
    }
    int procent = (isBalanced / size) * 100;
    printf("%2d",  procent);
}

////////////////////////////////////2
boolean binTreeSearch(TreeNode *root, int value) {
    TreeNode *current = root;
    if (current == NULL)
        return false;
    if (current->key == value)
        return true;
    if (value < current->key)
        binTreeSearch(current->left, value);
    if (value > current->key)
        binTreeSearch(current->right, value);
    if (current == NULL)
        return false;
}

int main(const int argc, const char **argv) {
    TreeNode *tree = NULL;
    tree = treeInsert(tree, 10);
    treeInsert(tree, 8);
    treeInsert(tree, 19);
    treeInsert(tree, 25);
    treeInsert(tree, 22);
    treeInsert(tree, 16);
    treeInsert(tree, 21);
    printTree(tree);
    printf(" \n");
   // if (isBalance(tree)) {
   //     printf("tree is balanced");
    //    } else {
    //    printf("tree is NOT balanced");
    //    }
    //treeCreator(50, 1000);

    if (binTreeSearch(tree, 25)) {
        printf("value is found");
        } else {
        printf("value is NOT found");
        }
    return 0;
}
