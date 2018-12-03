//
// Created by Jumormt on 2018/3/17.
//
#include <iostream>
#include <cstring>

using namespace std;

struct Node{

    Node(char v='0'):value(v), left(0), right(0){}
    char value;
    Node* left;
    Node* right;
};

char pre[50] = "ABDHLEKCFG";        //前序序列
char mid[50] = "HLDBEKAFCG";        //中序序列
char post[50] = "LHDKEBFGCA";        //后序序列


class BiTree{

public:

    BiTree(Node* n):root(n){}

    // 定位c在中序遍历的位置
    int Position(char c)
    {
        return strchr(mid,c)-mid;
    }

//    // 数组初始化树的方法
//    // 注意要传入指针的引用，因为函数内试图改变指针的大小R=new Node;不加引用就是无效改变！！另外R->value = ch[i];是确实会改变传入指针所指对象的。
//    void  Create(Node *&R, int i)
//    {
//        if (ch[i]==0)
//            R = NULL;
//        else
//        {
//            R=new Node;
//            R->value = ch[i];
//            Create(R->left, 2*i);
//            Create(R->right, 2*i+1);
//        }
//    }

    // 已知前序和中序遍历整个树 注意传入新参为Node*& root，因为函数内试图改变指针的大小root=new Node;不加引用就是无效改变！！另外root->value = pre[i];是确实会改变传入指针所指对象的。
    // root为当前遍历树的根节点，i为当前根节点在__前序__遍历pre的序号，j为在__中序__遍历中树序列mid始序号。
    void PreMidCreate(Node*& root, int i, int j, int length){

        if (length <= 0)
            return;

        root = new Node();

        root->value = pre[i];

        int pos = Position(pre[i]);

        int lenL = pos - j;
        int lenR = length - lenL - 1;

        PreMidCreate(root->left, i+1, j, lenL);
        PreMidCreate(root->right, i+1+lenL, pos+1, lenR);
    }

    // 已知后序和中序遍历整个树
    // root为当前遍历树的根节点，i为当前根节点在__前序__遍历pre的序号，j为在__中序__遍历中树序列mid始序号。
    void PostMidCreate(Node*& root, int i, int j, int length){

        if (length <= 0)
            return;

        root = new Node();

        root->value = post[i];

        int pos = Position(post[i]);

        int lenL = pos - j;
        int lenR = length - lenL - 1;

        PostMidCreate(root->left, i-1-lenR, j, lenL);
        PostMidCreate(root->right, i-1, pos+1, lenR);
    }

    //前序遍历
    void preOrder(Node* root){
        if (root){
            cout<<root->value<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    // 中序遍历
    void midOrder(Node* root){
        if (root){
            midOrder(root->left);
            cout<<root->value<<" ";
            midOrder(root->right);
        }

    }

    // 后序遍历
    void postOrder(Node* root){
        if (root){
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->value<<" ";
        }

    }

    void deleteTree(Node* node){
        if (node){
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    ~BiTree(){
        deleteTree(root);
    }


    Node* getRoot(){
        return root;
    }


private:

    Node* root;
};

//
//int main(){
//
//    Node* node = new Node();
//    BiTree tree(node);
//
//    tree.PreMidCreate(node, 0, 0, strlen(mid));
//
//    tree.preOrder(node);
//}