#include <iostream>

using namespace std;
typedef struct BINARY_NODE{
    char ch;
    struct BINARY_NODE *lchild;
    struct BINARY_NODE *rchild;
}binary_node;

void recusion(binary_node *root);
void createTree(){
    binary_node nodea = {'a',0,0};
    binary_node nodeb = {'b',0,0};
    binary_node nodec  ={'c',0,0};
    binary_node noded  ={'d',0,0};
    binary_node nodee  ={'e',0,0};
    binary_node nodef  ={'f',0,0};
    binary_node nodeg  ={'g',0,0};
     binary_node nodeh  ={'h',0,0};

     nodea.lchild = &(nodeb);
     nodea.rchild = &(nodef);
     nodeb.rchild = &(nodec);
     nodec.lchild = &(noded);
     nodec.rchild = &(nodee);
     nodef.rchild = &(nodeg);
     nodeg.lchild = &(nodeh);

     recusion(&nodea);

}

void recusion(binary_node* root)
{
    if(root == 0)
        return;
    cout << root->ch;
    recusion(root->lchild);
    recusion(root->rchild);

}
int main()
{
    createTree();
    cout << endl;
    cout << "Hello world!" << endl;
    return 0;
}
