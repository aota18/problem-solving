#include<iostream>
#include<vector>

using namespace std;


class BinaryTree {
    public:
        int value;
        BinaryTree* left;
        BinaryTree* right;
    BinaryTree(int value){
        this->value=value;
    }
};

int getHeight(BinaryTree* tree){
    if(!tree){
        return 0;
    }

    int leftHeight=getHeight(tree->left);
    int rightHeight = getHeight(tree->right);

    return max(leftHeight, rightHeight)+1;
}

int main(void){
    
    
   BinaryTree* bt = new BinaryTree(1);

    cout<<getHeight(bt)<<endl;
}



