#include <iostream>
#include <stdlib.h>

using namespace std;

struct BinaryTree {
    int data; 
    BinaryTree *parent; 
    BinaryTree *left;
    BinaryTree *right;
};
 
BinaryTree *tree = NULL;

void insert(int number, BinaryTree **tree)
{
    if ((*tree) == NULL) {
        (*tree) = new BinaryTree;
        (*tree)->data = number;
        (*tree)->left = (*tree)->right = NULL;
        return;
    }
    if (number > (*tree)->data) { insert(number, &(*tree)->right); }
    else { insert(number, &(*tree)->left); }
}
 
void show(BinaryTree *tree, int number) {
    if (tree == NULL) { return; }
    else {
        show(tree->left, ++number);
        for (int i = 0; i < number; ++i) cout << "***";
        cout << tree->data << endl;
        number--;
    }
    show(tree->right, ++number);
}

bool find(BinaryTree *tree, int number){
    BinaryTree *current = tree;	
    while(current->data != number){
        if(current != NULL) {			
            if(current->data > number) { current = current->left; }
            else { current = current->right; }
        
            if (current == NULL) { return false; }
        }
    }
    return true;
}

void extract(BinaryTree *&tree) {
    if (tree->right == NULL) { tree = tree->left; return; }
    else { extract(tree->right); }
}
 
int main () {
    int userCommand;
    cin >> userCommand;
    
    while (userCommand != 3) {
        switch (userCommand) {
            case 0:
                int number;
                cin >> number;
                insert(number, &tree);
                break;
            case 1:
                extract(tree);
                break;
            case 2:
                int findNumber;
                cin >> findNumber;
                cout << (find(tree, findNumber) ? "YES" : "NO") << endl;
                break;
            case 5:
                show(tree, 0);
        }
        cin >> userCommand;
    }
    
    // show(tree, 0);
}
