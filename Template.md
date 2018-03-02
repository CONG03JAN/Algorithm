### ACM 模版简版

#### 

#### 一、简单算法

##### 1. 排序：

```c++
// 排序结果为：
// a 在前，b 在后。
// 先根据 x 排序，若 x 相等再根据 y 排序。
// 按照 return 为 true 的逻辑排序。
int cmp(N a, N b) {
    if(a.x != a.y)
    	return a.x < b.x;
	else
        return a.y < b.y;
}
sort(first, last, cmp);
```

##### 2. 二分查找：

```c++
int l=0,r=100,ans=0;
while (l<=r) {
	mid = (l + r) / 2;
	if (check(mid)) {
        l = mid + 1; ans = mid; 
    } else {
        r=mid-1; //注意+1，-1否则死循环
    }   
}
```

##### 3. 有序表边界查找：

```c++
lower_bound() // 寻找最早可插入位
upper_bound() // 寻找最晚可插入位
```

##### 4. 排版问题：

- 有规律找到规律输出：
- 无规律先完成排版再输出：

```c++
int main(void) {
    int outPutBuf[82][82];
    char a, b;
    int n;
    while (scanf("%d %c %c", &n, &a, &b) == 3) {
        for(int i = 1, j = 1; i <= n; i += 2, j++) {
            int x = n / 2 + 1, y = x;
             x -= j - 1; y -= j - 1;
                 char c = j % 2 == 1? a: b;
             for(int k = 1; k <= i; k++) {
                 outPutBuf[x + k - 1][y] = c;
                 outPutBuf[x][y + k - 1] = c;
                 outPutBuf[x + i - 1][y + k - 1] = c;
                 outPutBuf[x + k - 1][y + i - 1] = c;
             }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%c", outPutBuf[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
```



#### 二、数据结构

##### 1. 栈 \<stack\>

```c++
stack<int> s;
s.push(x);
s.pop();
s.top();
s.empty();
s.size();
```

##### 2. 队列和优先队列 \<queue\>

```c++
// queue
queue<int> q;
q.push(x);
q.pop();
q.front();
q.back();
q.empty();
q.size();

// priority_queue 默认从大优先
priority_queue<int, vector<int>, cmp> pq;
pq.push(x);
pq.pop();
pq.top();
pq.empty();
pq.size();

// 优先级为 return true 时 b 的优先级
struct cmp{
    bool operator()(const int &a, const int &b){
    	return a > b;
	}
}

```

##### 3. \<vector\>：

```c++
vector<int> a；
vector<int> a(10);
vector<int> a(10, 1);
vector<int> b(a);
vector<int> b(a.begin(), a.begin() + 3);
int n[] = {1, 2, 3, 4, 5};
vector<int> a(n, n + 5);

a.push_back(x);

vector<int>::iterator iter;
for(iter = a.begin(); iter != a.end(); t++){
    cout << *iter << endl;
}

a.size();
a.empty();
a.clear():
a = b; a == b; a != b; a > b; a >= b; a < b; a <= b;

a.insert(a.begin(), 1000);
a.insert(a.begin(), 3, 1000);
b.insert(b.begin(), a.begin(), a.end());

a.erase(a.begin());
a.erase(a.begin(), a.begin() + 3);

b.swap(a);
```

##### 4. \<set\>：

```c++
set<int> s;
s.begin();
s.clear();
s.count(x);
s.empty();
s.end();
s.earse();
s.equal_range();
s.find();
s.insert(x);
s.size();
```

##### 5. \<map\>：

```c++
map<string, int> m;
m.begin();
m.clear();
m.count();
m.empty();
m.end();
m.erase();
m.find();
m.insert();
m.size();

```

##### 6. 二叉树：

```c++
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
```

#### 三、图论

##### 1. 并查集：

```c++
int findroot(int x) {
    if(Tree[x] == -1) return x;
    else {
        int tmp = findroot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int findroot2(int x) {
    int ret;
    int tmp = x;
    while(Tree[x] != -1) x = Tree[x];
    ret = x;
    x = tmp;
    while(Tree[x] != -1) {
        int t = Tree[x];
        Tree[x] = ret;
        x = t;
    }
    return ret;
}
```

##### 2. 最小生成树：

```c++
#define N 101
int Tree[N];

int findroot(int x) {
    if(Tree[x] == -1) return x;
    else {
        int tmp = findroot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

struct Edge{
    int a, b;
    int cost;
    bool operator < (const Edge &A) const {
        return cost < A.cost;
    }
} edge[6000];

int main(void) {
    int n;
    while(scanf("%d", &n)) {
        for (int i = 1; i <= n * (n - 1) / 2; i++) {
            scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].cost);
        }
        sort(edge + 1, edge + n * (n - 1) / 2 + 1);
        for (int i = 1; i <= n; i++) {
            Tree[i] = -1;
        }
        int ans = 0;
        for (int i = 1; i <= n * (n - 1) / 2; i++) {
            int a = findroot(edge[i].a);
            int b = findroot(edge[i].b);
            if(a != b){
                Tree[a] = b;
                ans += edge[i].cost;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
```

##### 3. 最短路径：

##### 4. 拓扑排序：



#### 四、数论

##### 1. 进制转换

```c++
// 1. 模拟进制转换规则，利用十进制为中介。
int main(void) {
    int a, b;
    char str[50];
    while (~scanf("%d %s %d", &a, str, &b)) {
        int c = 1;
        int len = strlen(str);
        int tmp = 0;
        char ans[50];
        int size = 0;
        
        // a进制 -> 十进制 
        for (int i = len - 1; i >= 0; i--) {
            int x;
            if (str[i] >= '0' && str[i] <= '9') {
                x = str[i] - '0';
            } else if (str[i] >= 'a' && str[i] <= 'f') {
                x = str[i] - 'a' + 10;
            } else {
                x = str[i] - 'A' + 10;
            }
            tmp += (x * c);
            c *= a;
        }
        // 十进制数存储在 tmp 中
        
        // 十进制 -> b进制
        do {
            int x = tmp % b;
            ans[size++] = (x < 10) ? x + '0': x - 10 + 'A';
            tmp /= b;
        } while(tmp);
        for (int i = size - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}

// 2.
string transform(int x, int y, string s) {
    string res = "";
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-')
            continue;
        if (s[i] >= '0' && s[i] <= '9') {
            sum = sum * x + s[i] - '0';
        } else {
            sum = sum * x + s[i] - 'A' + 10;
        }
    }
    while (sum) {
        char tmp = sum % y;
        sum /= y;
        if (tmp <= 9) {
            tmp += '0';
        } else {
            tmp = tmp - 10 + 'A';
        }
        res = tmp + res;
    }
    if (res.length() == 0)
        res = '-' + res;
    return res;
}
```

##### 2. GCD / LCM：

```c++
int gcd(int a, int b) {
    return b != 0? gcd(b, a % b): a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// 非递归
int GCD(int x, int y) {
    int t;
    while(y > 0){
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}
```

##### 3. 素数判断：

```c++
// Prime素数判断
// 如果一个非0，1，2或者不能被2整除的数不能被3到它的二次方根整除，则为素数。
bool is_prime(int  u) {
    if(u ==  0 || u ==  1) return false;
    if(u ==  2)      return true;
    if(u%2 == 0)      return false;
    for(int i=3; i <=  sqrt(u) ; i+=2) // 只需要判断到sqet(u)
        if(u%i==0)      return false;
    return true;
}
```

##### 4. 素数筛法：

```c++
#define MAX 1000000
int Prime[800000]; // 总共 78499 个素数 
bool IsPrime[MAX]; // 最大的素数为 999983
int Count;
void GetPrime() {
    Count = 1;
    for(int i = 2; i < MAX; i++) {
        if(!IsPrime[i])
            Prime[Count++] = i;
        for(int j = 1; j < Count && Prime[j] * i < MAX; j++) {
            IsPrime[i * Prime[j]] = true;
            if(i % Prime[j] == 0) break;
        }
    }
}
```

##### 5. 欧拉函数：

```c++
// Euler Function欧拉函数
// 求..n-1中与n互质的数的个数
int euler(int n) {
    int ans = 1;
    int i;
    for(i = 2; i * i <= n; i++) {
        if(n % i == 0){
            n /= i;
            ans *= i - 1;
            while(n % i == 0) {
                n /= i;
                ans *= i;
            }
        }
    }
    if(n > 1) {
        ans *= n - 1;
    }
    return ans;
}
```

##### 6. 质因数分解（非素数表算法）：

```c++
void factor(int n, int a[maxn], int b[maxn], int &tot) {
    int temp, i, now;
    temp = (int)((double)sqrt(n) + 1);
    tot = 0;
    now = n;
    for (i = 2; i <= temp; ++i) {
        a[++tot] = i;
        b[tot] = 0;
        while (now & i == 0) {
            ++b[tot];
            now /= i;
        }
    }
    if (now != 1) {
        a[++tot] = now;
        b[tot] = 1;
    }
}
```

##### 7. 快速幂取模：

```c++
long long modexp(long long a, long long b, int mod) {
    long long res = 1;
    while (b > 0) {
        //a=a%mod;
        if (b & 1)
            res = res * a % mod;
        b = b >> 1;
        a = a * a % mod;
    }
    return res;
}
```

##### 8. 求解线性不定方程:

```c++
#define LL long long
//方程组形势 Ax+By=C
//已知A,B,C 求解 x,y
//先求出 Ax+By=gcd(A,B)的解
void Euclid(LL A, LL B, LL &D, LL &X, LL &Y) {
    if (!B) {
        D = A;
        X = 1;
        Y = 0;
    } else {
        Euclid(B, A % B, D, Y, X);
        Y -= X * (A / B);
    }
}
//如果C%D!=0,则方程无解
// C'=C/D,存在方程解为  A(C'x)+B(C'y)=C,X=C'x,Y=C'y
// B'=B/D,A'=A/D,则方程的通解为(X+K*B',Y-K*A'),K为任意整数
```

##### 9. 求解大数乘法(M * N) % MOD:

```c++
#define LL long long
LL Muti(LL A, LL B, LL MOD) {
    LL Ans = 0;
    A = A % MOD;
    B = B % MOD;
    if (B < 0) {
        A = -A;
        B = -B;
    }
    while (B) {
        if (B & 1)
            Ans = (Ans + A) % MOD;
        B >>= 1;
        A = (A + A) % MOD;
    }
    Ans = (Ans + MOD) % MOD;
    return Ans;
}
```



#### 五、搜索

##### 1. BFS

广度优先搜索一般用于搜索最优的问题。

**常用步骤：**

```c++
// 第一步：
// 设置访问标志(用于剪枝)

// 第二部：
// 设置一个 Node，用来标志相关状态
struct N {
    int i,j,k;
    int s; // 步数
}

// 第三步：
// 设计数据读取过程，用于：
// 1. 判断是否到达目标
// 2. 进入下一状态(for 进入多个入口)
// 3. 剪枝(if 判断)

// 第四步：
// 设计队列是否为空的while循环
while(!q.empty()) {
    now = q.front();
    q.pop();
    ...
}
```



##### 2. DFS

一般用于解决又或者没有的问题。

#### 六、动态规划

#### 七、计算几何

```c++
//上交计算几何算法
/****************************************
 * COMPUTATIONAL GEOMETRY ROUTINES
 * WRITTEN BY : LIU Yu (C) 2003
 ****************************************/
//    叉乘
//    两个点的距离
//    点到直线距离
//    返回直线 Ax + By + C =0  的系数
//    线段
//    圆
//    两个圆的公共面积
//    矩形
//    根据下标返回多边形的边
//    两个矩形的公共面积
//    多边形  ,逆时针或顺时针给出x,y
//    多边形顶点
//    多边形的边
//    多边形的周长
//    判断点是否在线段上
//    判断两条线断是否相交，端点重合算相交
//    判断两条线断是否平行
//    判断两条直线断是否相交
//    直线相交的交点
//    判断是否简单多边形
//    求多边形面积
//    判断是否在多边形上
//    判断是否在多边形内部
//    点阵的凸包，返回一个多边形
//   最近点对的距离
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <memory>
using namespace std;
typedef double TYPE;
#define Abs(x) (((x) > 0) ? (x) : (-(x)))
#define Sgn(x) (((x) < 0) ? (-1) : (1))
#define Max(a, b) (((a) > (b)) ? (a) : (b))
#define Min(a, b) (((a) < (b)) ? (a) : (b))
#define Epsilon 1e-10
#define Infinity 1e+10
#define Pi 3.14159265358979323846
TYPE Deg2Rad(TYPE deg) { return (deg * Pi / 180.0); }
TYPE Rad2Deg(TYPE rad) { return (rad * 180.0 / Pi); }
TYPE Sin(TYPE deg) { return sin(Deg2Rad(deg)); }
TYPE Cos(TYPE deg) { return cos(Deg2Rad(deg)); }
TYPE ArcSin(TYPE val) { return Rad2Deg(asin(val)); }
TYPE ArcCos(TYPE val) { return Rad2Deg(acos(val)); }
TYPE Sqrt(TYPE val) { return sqrt(val); }
struct POINT {
    TYPE x;
    TYPE y;
    TYPE z;
    POINT() : x(0), y(0), z(0){};
    POINT(TYPE _x_, TYPE _y_, TYPE _z_ = 0) : x(_x_), y(_y_), z(_z_){};
};
// cross product of (o->a) and (o->b)// 叉乘
TYPE Cross(const POINT &a, const POINT &b, const POINT &o) {
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}
// planar points' distance//  两个点的距离
TYPE Distance(const POINT &a, const POINT &b) {
    return Sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
                (a.z - b.z) * (a.z - b.z));
}
struct LINE {
    POINT a;
    POINT b;
    LINE(){};
    LINE(POINT _a_, POINT _b_) : a(_a_), b(_b_) {}
};
//点到直线距离
double PointToLine(POINT p0, POINT p1, POINT p2, POINT &cp) {
    double d = Distance(p1, p2);
    double s = Cross(p1, p2, p0) / d;
    cp.x = p0.x + s * (p2.y - p1.y) / d;
    cp.y = p0.y - s * (p2.x - p1.x) / d;
    return Abs(s);
}
// 返回直线 Ax + By + C =0  的系数
void Coefficient(const LINE &L, TYPE &A, TYPE &B, TYPE &C) {
    A = L.b.y - L.a.y;
    B = L.a.x - L.b.x;
    C = L.b.x * L.a.y - L.a.x * L.b.y;
}
void Coefficient(const POINT &p, const TYPE a, TYPE &A, TYPE &B, TYPE &C) {
    A = Cos(a); // 线段
    B = Sin(a);
    C = -(p.y * B + p.x * A);
}
struct SEG {
    POINT a;
    POINT b;
    SEG(){};
    SEG(POINT _a_, POINT _b_) : a(_a_), b(_b_){};
};
// 圆
struct CIRCLE {
    TYPE x;
    TYPE y;
    TYPE r;
    CIRCLE() {}
    CIRCLE(TYPE _x_, TYPE _y_, TYPE _r_) : x(_x_), y(_y_), r(_r_) {}
};
POINT Center(const CIRCLE &circle) { return POINT(circle.x, circle.y); }
TYPE Area(const CIRCLE &circle) {
    return Pi * circle.r * circle.r; //两个圆的公共面积
}
TYPE CommonArea(const CIRCLE &A, const CIRCLE &B) {
    TYPE area = 0.0;
    const CIRCLE &M = (A.r > B.r) ? A : B;
    const CIRCLE &N = (A.r > B.r) ? B : A;
    TYPE D = Distance(Center(M), Center(N));
    if ((D < M.r + N.r) && (D > M.r - N.r)) {
        TYPE cosM = (M.r * M.r + D * D - N.r * N.r) / (2.0 * M.r * D);
        TYPE cosN = (N.r * N.r + D * D - M.r * M.r) / (2.0 * N.r * D);
        TYPE alpha = 2.0 * ArcCos(cosM);
        TYPE beta = 2.0 * ArcCos(cosN);
        TYPE TM = 0.5 * M.r * M.r * Sin(alpha);
        TYPE TN = 0.5 * N.r * N.r * Sin(beta);
        TYPE FM = (alpha / 360.0) * Area(M);
        TYPE FN = (beta / 360.0) * Area(N);
        area = FM + FN - TM - TN;
    } else if (D <= M.r - N.r) {
        area = Area(N);
    }
    return area;
}
//    矩形
//    矩形的线段
//        2
//      --------------- b
//      |               |
//    3 |               |  1
//    a ---------------
//         0
struct RECT {
    POINT a; // 左下点  POINT b;  // 右上点
    RECT(){};
    RECT(const POINT &_a_, const POINT &_b_) {
        a = _a_;
        b = _b_;
    }
};
//根据下标返回多边形的边
SEG Edge(const RECT &rect, int idx) {
    SEG edge;
    while (idx < 0)
        idx += 4;
    switch (idx % 4) {
    case 0:
        edge.a = rect.a;
        edge.b = POINT(rect.b.x, rect.a.y);
        break;
    case 1:
        edge.a = POINT(rect.b.x, rect.a.y);
        edge.b = rect.b;
        break;
    case 2:
        edge.a = rect.b;
        edge.b = POINT(rect.a.x, rect.b.y);
        break;
    case 3:
        edge.a = POINT(rect.a.x, rect.b.y);
        edge.b = rect.a;
        break;
    default:
        break;
    }
    return edge;
}
TYPE Area(const RECT &rect) {
    return (rect.b.x - rect.a.x) * (rect.b.y - rect.a.y);
}
//  两个矩形的公共面积
TYPE CommonArea(const RECT &A, const RECT &B) {
    TYPE area = 0.0;
    POINT LL(Max(A.a.x, B.a.x), Max(A.a.y, B.a.y));
    POINT UR(Min(A.b.x, B.b.x), Min(A.b.y, B.b.y));
    if ((LL.x <= UR.x) && (LL.y <= UR.y)) {
        area = Area(RECT(LL, UR));
    }
    return area;
} // 多边形  ,逆时针或顺时针给出x,y
struct POLY {
    int n; // n个点  TYPE * x;  //x,y为点的指针，首尾必须重合  TYPE * y;
    POLY() : n(0), x(NULL), y(NULL){};
    POLY(int _n_, const TYPE *_x_, const TYPE *_y_) {
        n = _n_;
        x = new TYPE[n + 1];
        memcpy(x, _x_, n * sizeof(TYPE));
        x[n] = _x_[0];
        y = new TYPE[n + 1];
        memcpy(y, _y_, n * sizeof(TYPE));
        y[n] = _y_[0];
    }
}; //多边形顶点
POINT Vertex(const POLY &poly, int idx) {
    idx %= poly.n; //多边形的边
    return POINT(poly.x[idx], poly.y[idx]);
}
SEG Edge(const POLY &poly, int idx) {
    idx %= poly.n;
    return SEG(POINT(poly.x[idx], poly.y[idx]),
               POINT(poly.x[idx + 1], poly.y[idx + 1]));
} //多边形的周长
TYPE Perimeter(const POLY &poly) {
    TYPE p = 0.0;
    for (int i = 0; i < poly.n; i++)
        p = p + Distance(Vertex(poly, i), Vertex(poly, i + 1));
    return p;
}
bool IsEqual(TYPE a, TYPE b) { return (Abs(a - b) < Epsilon); }
bool IsEqual(const POINT &a, const POINT &b) {
    return (IsEqual(a.x, b.x) && IsEqual(a.y, b.y));
}
bool IsEqual(const LINE &A, const LINE &B) {
    TYPE A1, B1, C1;
    TYPE A2, B2, C2;
    Coefficient(A, A1, B1, C1);
    Coefficient(B, A2, B2, C2);
    return IsEqual(A1 * B2, A2 * B1) && IsEqual(A1 * C2, A2 * C1) &&
           IsEqual(B1 * C2, B2 * C1);
}
// 判断点是否在线段上
bool IsOnSeg(const SEG &seg, const POINT &p) {
    return (IsEqual(p, seg.a) || IsEqual(p, seg.b)) ||
           (((p.x - seg.a.x) * (p.x - seg.b.x) < 0 ||
             (p.y - seg.a.y) * (p.y - seg.b.y) < 0) &&
            (IsEqual(Cross(seg.b, p, seg.a), 0)));
}
//判断两条线断是否相交，端点重合算相交
bool IsIntersect(const SEG &u, const SEG &v) {
    return (Cross(v.a, u.b, u.a) * Cross(u.b, v.b, u.a) >= 0) &&
           (Cross(u.a, v.b, v.a) * Cross(v.b, u.b, v.a) >= 0) &&
           (Max(u.a.x, u.b.x) >= Min(v.a.x, v.b.x)) &&
           (Max(v.a.x, v.b.x) >= Min(u.a.x, u.b.x)) &&
           (Max(u.a.y, u.b.y) >= Min(v.a.y, v.b.y)) &&
           (Max(v.a.y, v.b.y) >= Min(u.a.y, u.b.y));
}
//判断两条线断是否平行
bool IsParallel(const LINE &A, const LINE &B) {
    TYPE A1, B1, C1;
    TYPE A2, B2, C2;
    Coefficient(A, A1, B1, C1);
    Coefficient(B, A2, B2, C2);
    return (A1 * B2 == A2 * B1) &&
           ((A1 * C2 != A2 * C1) || (B1 * C2 != B2 * C1));
}
//判断两条直线断是否相交
bool IsIntersect(const LINE &A, const LINE &B) {
    return !IsParallel(A, B); //直线相交的交点
}
POINT Intersection(const LINE &A, const LINE &B) {
    TYPE A1, B1, C1;
    TYPE A2, B2, C2;
    Coefficient(A, A1, B1, C1);
    Coefficient(B, A2, B2, C2);
    POINT I(0, 0);
    I.x = -(B2 * C1 - B1 * C2) / (A1 * B2 - A2 * B1);
    I.y = (A2 * C1 - A1 * C2) / (A1 * B2 - A2 * B1);
    return I;
}
bool IsInCircle(const CIRCLE &circle, const RECT &rect) {
    return (circle.x - circle.r >= rect.a.x) &&
           (circle.x + circle.r <= rect.b.x) &&
           (circle.y - circle.r >= rect.a.y) &&
           (circle.y + circle.r <= rect.b.y);
}
//判断是否简单多边形
bool IsSimple(const POLY &poly) {
    if (poly.n < 3)
        return false;
    SEG L1, L2;
    for (int i = 0; i < poly.n - 1; i++) {
        L1 = Edge(poly, i);
        for (int j = i + 1; j < poly.n; j++) {
            L2 = Edge(poly, j);
            if (j == i + 1) {
                if (IsOnSeg(L1, L2.b) || IsOnSeg(L2, L1.a))
                    return false;
            } else if (j == poly.n - i - 1) {
                if (IsOnSeg(L1, L2.a) || IsOnSeg(L2, L1.b))
                    return false;
            } else {
                if (IsIntersect(L1, L2))
                    return false; // for i
            }
        } // for j
    }
    return true;
}
//求多边形面积
TYPE Area(const POLY &poly) {
    if (poly.n < 3)
        return TYPE(0);
    double s = poly.y[0] * (poly.x[poly.n - 1] - poly.x[1]);
    for (int i = 1; i < poly.n; i++) {
        s += poly.y[i] * (poly.x[i - 1] - poly.x[(i + 1) % poly.n]);
    }
    return s / 2;
}
//判断是否在多边形上
bool IsOnPoly(const POLY &poly, const POINT &p) {
    for (int i = 0; i < poly.n; i++) {
        if (IsOnSeg(Edge(poly, i), p))
            return true;
    }
    return false;
}
//判断是否在多边形内部
bool IsInPoly(const POLY &poly, const POINT &p) {
    SEG L(p, POINT(Infinity, p.y));
    int count = 0;
    for (int i = 0; i < poly.n; i++) {
        SEG S = Edge(poly, i);
        if (IsOnSeg(S, p)) {
            return false; //如果想让 在poly上则返回 true,则改为true
        }
        if (!IsEqual(S.a.y, S.b.y)) {
            POINT &q = (S.a.y > S.b.y) ? (S.a) : (S.b);
            if (IsOnSeg(L, q)) {
                ++count;
            } else if (!IsOnSeg(L, S.a) && !IsOnSeg(L, S.b) &&
                       IsIntersect(S, L)) {
                ++count;
            }
        }
    }
    return (count % 2 != 0);
}
// 点阵的凸包，返回一个多边形
POLY ConvexHull(const POINT *set, int n) // 不适用于点少于三个的情况
{
    POINT *points = new POINT[n];
    memcpy(points, set, n * sizeof(POINT));
    TYPE *X = new TYPE[n];
    TYPE *Y = new TYPE[n];
    int i, j, k = 0, top = 2;
    for (i = 1; i < n; i++) {
        if ((points[i].y < points[k].y) ||
            ((points[i].y == points[k].y) && (points[i].x < points[k].x))) {
            k = i;
        }
    }
    std::swap(points[0], points[k]);
    for (i = 1; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if ((Cross(points[j], points[k], points[0]) > 0) ||
                ((Cross(points[j], points[k], points[0]) == 0) &&
                 (Distance(points[0], points[j]) <
                  Distance(points[0], points[k])))) {
                k = j;
            }
        }
        std::swap(points[i], points[k]);
    }
    X[0] = points[0].x;
    Y[0] = points[0].y;
    X[1] = points[1].x;
    Y[1] = points[1].y;
    X[2] = points[2].x;
    Y[2] = points[2].y;
    for (i = 3; i < n; i++) {
        while (Cross(points[i], POINT(X[top], Y[top]),
                     POINT(X[top - 1], Y[top - 1])) >= 0) {
            top--;
        }
        ++top;
        X[top] = points[i].x;
        Y[top] = points[i].y;
    }
    delete[] points;
    POLY poly(++top, X, Y);
    delete[] X;
    delete[] Y;
    return poly;
}
//最近点对的距离, Written By PrincessSnow
#define MAXN 100000
POINT pt[MAXN];
bool cmp(POINT n1, POINT n2) {
    return (n1.x < n2.x || n1.x == n2.x && n1.y < n2.y);
}
double Get(double dis, int mid, int start, int end) {
    int s = mid, e = mid, i, j;
    double t;
    while (s > start && pt[mid].x - pt[s].x <= dis)
        s--;
    while (e < end && pt[e].x - pt[mid].x <= dis)
        e++;
    for (i = s; i <= e; i++)
        for (j = i + 1; j <= e && j <= i + 7; j++) {
            t = Distance(pt[i], pt[j]);
            if (t < dis)
                dis = t;
        }
    return dis;
}
double ClosestPairDistance(int start, int end) {
    int m = end - start + 1, mid, i;
    double t1, t2, dis = -1, t;
    if (m <= 3) {
        for (i = start; i < end; i++) {
            t = Distance(pt[i], pt[i + 1]);
            if (t < dis || dis == -1)
                dis = t;
        }
        t = Distance(pt[start], pt[end]);
        if (t < dis)
            dis = t;
        return dis;
    }
    if (m % 2 == 0)
        mid = start + m / 2 - 1;
    else
        mid = start + m / 2;
    if (m % 2 == 0) {
        t1 = ClosestPairDistance(start, mid);
        t2 = ClosestPairDistance(mid + 1, end);
    } else {
        t1 = ClosestPairDistance(start, mid);
        t2 = ClosestPairDistance(mid + 1, end);
    }
    if (t1 < t2)
        dis = t1;
    else
        dis = t2;
    dis = Get(dis, mid, start, end);
    return dis;
}

// 1.  球面上两点最短距离
// 计算圆心角lat 表示纬度, -90 <= w <= 90, lng 表示经度
// 返回两点所在大圆劣弧对应圆心角,  0 <= angle <=  pi
double angle(double lng1, double lat1, double lng2, double lat2) {
    double dlng = fabs(lng1 - lng2) * pi / 180;
    while (dlng >= pi + pi)
        dlng -= pi + pi;
    if (dlng > pi)
        dlng = pi + pi - dlng;
    lat1 *= pi / 180, lat2 *= pi / 180;
    return acos(cos(lat1) * cos(lat2) * cos(dlng) + sin(lat1) * sin(lat2));
}
// 计算距离, r为球半径
double line_dist(double r, double lng1, double lat1, double lng2, double lat2) {
    double dlng = fabs(lng1 - lng2) * pi / 180;
    while (dlng >= pi + pi)
        dlng -= pi + pi;
    if (dlng > pi)
        dlng = pi + pi - dlng;
    lat1 *= pi / 180, lat2 *= pi / 180;
    return r * sqrt(2 - 2 * (cos(lat1) * cos(lat2) * cos(dlng) +
                             sin(lat1) * sin(lat2)));
}
// 计算球面距离, r为球半径
double sphere_dist(double r, double lng1, double lat1, double lng2,
                   double lat2) {
    return r * angle(lng1, lat1, lng2, lat2);
}

// 2.  三点求圆心坐标
double GetRadiusBy3Points(double x1, double y1, double x2, double y2, double x3,
                          double y3, double &x, double &y) {
    // 由 ( x - x1 )^2 + ( y - y1 )^2 = ( x - x2 )^2 + ( y - y2 )^2 得
    // 2*( x2 - x1 )*x + 2*( y2 - y1 )*y = x2^2 - x1^2 + y2^2 - y1^2
    // 同理得
    // 2*( x3 - x2 )*x + 2*( y3 - y2 )*y = x3^2 - x2^2 + y3^2 - y2^2
    // 由行列式解方程得 x , y
    double a11, a12, a21, a22, b1, b2;
    double d, d1, d2;
    a11 = 2 * (x3 - x2);
    a12 = 2 * (y3 - y2);
    a21 = 2 * (x2 - x1);
    a22 = 2 * (y2 - y1);
    b1 = x3 * x3 - x2 * x2 + y3 * y3 - y2 * y2;
    b2 = x2 * x2 - x1 * x1 + y2 * y2 - y1 * y1;
    d = a11 * a22 - a12 * a21;
    d1 = b1 * a22 - a12 * b2;
    d2 = a11 * b2 - b1 * a21;
    // x , y 是圆心坐标
    x = d1 / d;
    y = d2 / d;
    return (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
}
//
//
// 3.  三角形几个重要的点
//设三角形的三条边为a,  b, c，且不妨假设a <=  b <=  c
//三角形的面积可以根据海伦公式算得，如下：
// s = sqrt(p * (p - a) * (p - b) * (p - c)), p = (a +  b + c) / 2
// 1. 费马点(该点到三角形三个顶点的距离之和最小)
//有个有趣的结论：若三角形的三个内角均小于120度，
//那么该点连接三个顶点形成的三个角均为120度；若三角形存在一个内角
//大于120度，则该顶点就是费马点)
//计算公式如下:
//若有一个内角大于120度（这里假设为角C)，则距离为a  +  b
//若三个内角均小于120度，则距离为
// sqrt((a * a +  b * b + c * c + 4 * sqrt(3.0) * s) / 2),其中
// 2.内心----角平分线的交点
//令x =  (a + b - c) / 2, y =  (a - b +  c) / 2, z =  (-a +  b + c) / 2, h =  s
/// p
// 计算公式为 sqrt(x * x + h * h) + sqrt(y * y +  h * h) +  sqrt(z * z +  h * h)
// 3.重心----中线的交点
// ACM算法模板集
//  - 46 -
//计算公式如下：
// 2.0 / 3 * (sqrt((2 * (a * a +  b * b) - c * c) / 4)
//             +  sqrt((2 * (a * a +  c * c) - b * b) / 4)
//             +  sqrt((2 * (b * b + c * c) - a * a) / 4))
// 4.垂心----垂线的交点
//计算公式如下：
// 3 * (c / 2 / sqrt(1 - cosC * cosC))
```

#### 八、字符串

##### 1. KMP：

```c++
vector<int> find_substring(string pattern, string text) {
    int n = pattern.size();
    vector<int> next(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0) {
            j = next[j];
            if (pattern[j] == pattern[i]) {
                next[i + 1] = j + 1;
                break;
            }
        }
    }
    vector<int> positions;
    int m = text.size();
    for (int i = 0, j = 0; i < m; ++i) {
        if (j < n && text[i] == pattern[j]) {
            j++;
        } else {
            while (j > 0) {
                j = next[j];
                if (text[i] == pattern[j]) {
                    j++;
                    bresk;
                }
            }
        }
        if (j == n) {
            positions.push_back(i - n + 1);
        }
    }
    return positions;
}
```

##### 2. 全排列、全组合：

```c++
//全排列,全组合
/**** **** **** **** **** ****
 *    Function Name :        全排列,全组合
 **** **** **** **** **** ****/
void createper(int n) //全排列
{
    int total, i, j, k, t, *a = new int[n], top;
    total = 1;
    for (i = 1; i <= n; i++) {
        a[i] = i;
        total *= i;
    }
    for (i = 1; i < n; i++)
        printf("%d  ", a[i]);
    printf("%d\n", a[n]);
    for (i = 1; i < total; i++) {
        j = n;
        while (a[j] < a[j - 1])
            j--;
        k = n;
        while (a[j - 1] > a[k])
            k--;
        t = a[j - 1];
        a[j - 1] = a[k];
        a[k] = t;
        top = (j + n - 1) / 2;
        for (k = j; k <= top; k++) {
            t = a[k];
            a[k] = a[n - k + j];
            a[n - k + j] = t;
        }
        for (j = 1; j < n; j++)
            printf("%d ", a[j]);
        printf("%d\n", a[n]);
    }
}
void createfab(int m, int n) //全组合
{
    int i, j, lcount, *a = new int[n + 2];
    for (i = 1; i <= n; i++)
        a[i] = i;
    a[n + 1] = m + 1;
    for (j = 1; j < n; j++)
        printf("%d  ", a[j]);
    printf("%d\n", a[n]);
    lcount = 1;
    while (a[1] < m - n + 1) {
        for (i = n; i > 0; i--) {
            if (a[i] < a[i + 1] - 1) {
                a[i]++;
                for (j = i; j < n; j++)
                    a[j + 1] = a[j] + 1;
                for (j = 1; j < n; j++)
                    printf("%d  ", a[j]);
                printf("%d\n", a[n]);
                lcount++;
                break;
            }
        }
    }
}
```

