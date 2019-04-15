/*************************************************************************
	> File Name: binary_tree.cpp
	> Author: sly
	> Mail: shulingyun@hrbeu.edu.cn
	> Created Time: 2019年04月14日 星期日 20时25分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *tree, int val) {
    if (tree == NULL) return getNewNode(val);
    if (tree->key == val) return tree;
    if (tree->key > val) tree->lchild = insert(tree->lchild, val);
    else tree->rchild = insert(tree->rchild, val);
    return tree;
}


void pre_order(Node *tree) {
    if (tree == NULL) return ;
    printf("%d ", tree->key);
    pre_order(tree->lchild);
    pre_order(tree->rchild);
    return ;
}

void in_order(Node *tree) {
    if (tree == NULL) return ;
    in_order(tree->lchild);
    printf("%d ", tree->key);
    in_order(tree->rchild);
    return ;
}

void post_order(Node *tree) {
    if (tree == NULL) return ;
    post_order(tree->lchild);
    post_order(tree->rchild);
    printf("%d ", tree->key);
    return ;
}


void clear(Node *tree) {
    if (tree == NULL) return ;
    clear(tree->lchild);
    clear(tree->rchild);
    free(tree);
    return ;
}

int main() {
    #define MAX_OP 20
    srand(time(0));
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        printf("insert %d to binary serach tree\n", val);
        root = insert(root, val);
        printf("pre order = "), pre_order(root), printf("\n");
        printf("in order = "), in_order(root), printf("\n");
        printf("post order = "), post_order(root), printf("\n");
    }
    return 0;
}



