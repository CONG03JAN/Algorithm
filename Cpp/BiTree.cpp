#include "cstdio"
#include "iostream"

using namespace std;

#define STACK_MAX_SIZE 30
#define QUEUE_MAX_SIZE 30
#ifndef elemType
typedef char elemType;
#endif

/************************************************************************/
/* 以下是关于二叉树操作的11个简单算法 */
/************************************************************************/
struct BTreeNode {
    elemType data;
    BTreeNode *left;
    BTreeNode *right;
};

/* 1.初始化二叉树 */
void initBTree(BTreeNode **bt) {
    *bt = NULL;
    return;
}

//建立二叉树(根据a所指向的二叉树广义表字符串建立)
void createBTree(BTreeNode **bt, char *a) {
    BTreeNode *p;
    //定义s数组为存储根结点指针的栈使用
    BTreeNode *s[STACK_MAX_SIZE];
    //定义top作为s栈的栈顶指针，初值为-1,表示空栈
    int top = -1;
    //用k作为处理结点的左子树和右子树，k = 1处理左子树，k = 2处理右子树
    int k;
    //用i扫描数组a中存储的二叉树广义表字符串，初值为0
    int i = 0;
    //把树根指针置为空，即从空树开始建立二叉树
    *bt = NULL;
    //每循环一次处理一个字符，直到扫描到字符串结束符\0为止
    while (a[i] != '\0') {
        switch (a[i]) {
        case ' ':
            break; /* 对空格不作任何处理 */
        case '(':
            if (top == STACK_MAX_SIZE - 1) {
                printf("栈空间太小！\n");
                exit(1);
            }
            top++;
            s[top] = p;
            k = 1;
            break;
        case ')':
            if (top == -1) {
                printf("二叉树广义表字符串错误!\n");
                exit(1);
            }
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = new BTreeNode;
            p->data = a[i];
            p->left = p->right = NULL;
            if (*bt == NULL) {
                *bt = p;
            } else {
                if (k == 1) {
                    s[top]->left = p;
                } else {
                    s[top]->right = p;
                }
            }
        }
        // 为扫描下一个字符修改i值
        i++;
    }
    return;
}

/* 2.检查二叉树是否为空，为空则返回true,否则返回false */
bool empty(BTreeNode *bt) {
    if (bt == NULL) {
        return true;
    } else {
        return false;
    }
}

/* 3.求二叉树深度 */
int BTreeDepth(BTreeNode *bt) {
    if (bt == NULL) {
        // 对于空树，返回0结束递归
        return 0;
    } else {
        // 计算左子树的深度
        int dep1 = BTreeDepth(bt->left);
        // 计算右子树的深度
        int dep2 = BTreeDepth(bt->right);
        if (dep1 > dep2) {
            return dep1 + 1;
        } else {
            return dep2 + 1;
        }
    }
}

/* 4.从二叉树中查找值为x的结点，若存在则返回元素存储位置，否则返回空值 */
elemType *findBTree(BTreeNode *bt, elemType x) {
    if (bt == NULL) {
        return NULL;
    } else {
        if (bt->data == x) {
            return &(bt->data);
        } else {
            // 分别向左右子树递归查找
            elemType *p;
            if (p = findBTree(bt->left, x)) {
                return p;
            }
            if (p = findBTree(bt->right, x)) {
                return p;
            }
            return NULL;
        }
    }
}

/* 5.递归遍历输出二叉树(前序遍历) */
void printBTree(BTreeNode *bt) {
    if (bt != NULL) {
        printf("%c, ", bt->data);
        printBTree(bt->left);
        printBTree(bt->right);
    }
    return;
}

/* 6.清除二叉树，使之变为一棵空树 */
void clearBTree(BTreeNode **bt) {
    if (*bt != NULL) {
        clearBTree(&((*bt)->left));
        clearBTree(&((*bt)->right));
        free(*bt);
        *bt = NULL;
    }
    return;
}

/* 7.前序遍历 */
void preOrder(BTreeNode *bt) {
    if (bt != NULL) {
        printf("%c ", bt->data);
        preOrder(bt->left);
        preOrder(bt->right);
    }
    return;
}

/* 8.中序遍历 */
void inOrder(BTreeNode *bt) {
    if (bt != NULL) {
        inOrder(bt->left);
        printf("%c ", bt->data);
        inOrder(bt->right);
    }
    return;
}

/* 9.后序遍历 */
void postOrder(BTreeNode *bt) {
    if (bt != NULL) {
        postOrder(bt->left);
        postOrder(bt->right);
        printf("%c ", bt->data);
    }
    return;
}

/* 按层遍历 */
void levelOrder(BTreeNode *bt) {
    BTreeNode *p;
    BTreeNode *q[QUEUE_MAX_SIZE];
    int front = 0, rear = 0;
    // 将树根指针进队
    if (bt != NULL) {
        rear = (rear + 1) % QUEUE_MAX_SIZE;
        q[rear] = bt;
    }
    // 队列非空
    while (front != rear) {
        // 使队首指针指向队首元素
        front = (front + 1) % QUEUE_MAX_SIZE;
        p = q[front];
        printf("%c ", p->data);
        // 若结点存在左孩子，则左孩子结点指针进队
        if (p->left != NULL) {
            rear = (rear + 1) % QUEUE_MAX_SIZE;
            q[rear] = p->left;
        }
        // 若结点存在右孩子，则右孩子结点指针进队
        if (p->right != NULL) {
            rear = (rear + 1) % QUEUE_MAX_SIZE;
            q[rear] = p->right;
        }
    }
    return;
}

/************************************************************************/
/* 以下是关于二叉搜索树操作的4个简单算法 */
/************************************************************************/

/* 查找 递归算法 */
elemType *findBSTree1(BTreeNode *bst, elemType x) {
    // 树为空则返回NULL
    if (bst == NULL) {
        return NULL;
    } else {
        if (x == bst->data) {
            return &(bst->data);
        } else {
            if (x < bst->data) {
                // 向左子树查找并直接返回
                return findBSTree1(bst->left, x);
            } else {
                // 向右子树查找并直接返回
                return findBSTree1(bst->right, x);
            }
        }
    }
}

/* 查找 非递归算法 */
elemType *findBSTree2(BTreeNode *bst, elemType x) {
    while (bst != NULL) {
        if (x == bst->data) {
            return &(bst->data);
        } else if (x < bst->data) {
            bst = bst->left;
        } else {
            bst = bst->right;
        }
    }
    return NULL;
}

/* 插入 递归算法 */
void insertBSTree1(BTreeNode **bst, elemType x) {
    // 新建一个根结点
    if (*bst == NULL) {
        BTreeNode *p = new BTreeNode;
        p->data = x;
        p->left = p->right = NULL;
        *bst = p;
        return;
    } else if (x < (*bst)->data) {
        // 向左子树完成插入运算
        insertBSTree1(&((*bst)->left), x);
    } else {
        // 向右子树完成插入运算
        insertBSTree1(&((*bst)->right), x);
    }
}

/* 插入  非递归算法 */
void insertBSTree2(BTreeNode **bst, elemType x) {
    BTreeNode *p;
    BTreeNode *t = *bst, *parent = NULL;
    // 为待插入的元素查找插入位置
    while (t != NULL) {
        parent = t;
        if (x < t->data) {
            t = t->left;
        } else {
            t = t->right;
        }
    }
    // 建立值为x，左右指针域为空的新结点
    p = new BTreeNode;
    p->data = x;
    p->left = p->right = NULL;
    // 将新结点链接到指针为空的位置
    if (parent == NULL) {
        // 作为根结点插入
        *bst = p;
    } else if (x < parent->data) {
        // 链接到左指针域
        parent->left = p;
    } else {
        parent->right = p;
    }
    return;
}

/* 创建二叉树 */
void createBSTree(BTreeNode **bst, elemType a[], int n) {
    int i;
    *bst = NULL;
    for (i = 0; i < n; i++) {
        insertBSTree1(bst, a[i]);
    }
    return;
}

/* 删除值为x的结点，成功返回1,失败返回0 */
int deleteBSTree(BTreeNode **bst, elemType x) {
    BTreeNode *temp = *bst;
    if (*bst == NULL) {
        return 0;
    }
    if (x < (*bst)->data) {
        // 向左子树递归
        return deleteBSTree(&((*bst)->left), x);
    }
    if (x > (*bst)->data) {
        // 向右子树递归
        return deleteBSTree(&((*bst)->right), x);
    }
    // 待删除的元素等于树根结点值且左子树为空，将右子树作为整个树并返回1
    if ((*bst)->left == NULL) {
        *bst = (*bst)->right;
        free(temp);
        return 1;
    }
    // 待删除的元素等于树根结点值且右子树为空，将左子树作为整个树并返回1
    if ((*bst)->right == NULL) {
        *bst = (*bst)->left;
        free(temp);
        return 1;
    } else {
        // 中序前驱结点为空时，把左孩子结点值赋给树根结点，然后从左子树中删除根结点
        if ((*bst)->left->right == NULL) {
            (*bst)->data = (*bst)->left->data;
            return deleteBSTree(&((*bst)->left), (*bst)->data);
        } else { 
        	// 定位到中序前驱结点，把该结点值赋给树根结点，然后从以中序前驱结点为根的树上删除根结点
            BTreeNode *p1 = *bst, *p2 = p1->left;
            while (p2->right != NULL) {
                p1 = p2;
                p2 = p2->right;
            }
            (*bst)->data = p2->data;
            return deleteBSTree(&(p1->right), p2->data);
        }
    }
}

int main(int argc, char *argv[]) {
    elemType x, *px;
    elemType a[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    BTreeNode *bst = NULL;
    createBSTree(&bst, a, 10);
    printf("建立的二叉搜索树的广义表形式为:\r\n");

    std::cout << "\r\n前序遍历:\r\n";
    printBTree(bst);

    printf("\r\n\r\n中序遍历:\r\n");
    inOrder(bst);

    printf("\r\n\r\n输入待查找元素的值：");
    std::cin >> x;
    if (px = findBSTree1(bst, x)) {
        printf("查找成功！得到的x为：%c\r\n", *px);
    } else {
        printf("查找失败\r\n");
    }

    printf("输入待插入的元素值：");
    std::cin >> x;
    insertBSTree1(&bst, x);

    printf("输入待删除元素值：");
    std::cin >> x;
    if (deleteBSTree(&bst, x)) {
        printf("1 ");
    } else {
        printf("0 ");
    }
    printf("\r\n\r\n进行相应操作后的中序遍历为:\r\n");
    inOrder(bst);

    printf("\r\n\r\n操作后的二叉搜索树的广义表的形式为:\r\n");
    printBTree(bst);

    printf("\r\n");

    clearBTree(&bst);
    return 0;
}
