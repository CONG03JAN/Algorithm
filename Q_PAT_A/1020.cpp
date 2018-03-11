#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct Node {
    Node *lchild;
    Node *rchild;
    char c;
}Tree[66];

int loc;

Node *creat() {
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

char str1[33], str2[33];

void preOrder(Node *T) {
    printf("%c", T->c);
    if (T->lchild != NULL) {
        preOrder(T->lchild);
    }
    if (T->rchild != NULL) {
        preOrder(T->rchild);
    }
}

Node *build(int s1, int e1, int s2, int e2) {
    Node* ret = creat();
    ret->c = str1[s1];
    int rootIdx;
    for (int i = s2; i <= e2; i++) {
        if (str2[i] == str1[s1]) {
            rootIdx = i;
            break;
        }
    }
    if (rootIdx != s2) {
        ret->lchild = build(s1 - 1, s1 - (rootIdx - s2), s2, rootIdx - 1);
    }
    if (rootIdx != e2) {
        ret->rchild = build(s1 - (rootIdx - s2) - 1, e1, rootIdx + 1, e2);
    }
    return ret;
}

int main(void) {
    while (scanf("%s", str1) != EOF) {
        scanf("%s", str2);
        loc = 0;
        int L1 = strlen(str1);
        int L2 = strlen(str2);
        Node *T = build(L1 - 1, 0, 0, L2 - 1);
        preOrder(T);
        printf("\n");
    }
    return 0;
}
