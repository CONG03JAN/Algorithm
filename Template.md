### ACM 模版简版

#### 

#### 一、简单算法：

##### 1. 排序：

```c++
#include <cstdlib>

// 排序结果为：
// a 在前，b 在后。
// 按照 return 为 true 的逻辑排序。
int cmp(int a, int b) {
    return a > b;
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



#### 二、数据结构：

##### 1. 栈 \<stack\>

```c++
#include <stack>
using namespace std;

stack<int> s;
s.push(x);
s.pop();
s.top();
s.empty();
s.size();
```

##### 2. 队列和优先队列 \<queue\>

```c++
#include <queue>
using namespace std;

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
#include <vector>
using namespace std;

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
#include <set>
using namespace std;

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
#include <map>
using namespace std;

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



#### 三、数论：

##### 1. 进制转换

```c++
#include "iostream"
#include "cstring"
using namespace std;

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
#include<iostream>
using namespace std;
#define MAX 1000000
int Prime[MAX];
bool IsPrime[MAX];
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
#include <iostream>
using namespace std;
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
#include <iostream>
using namespace std;
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

##### 10. 高精度整数：

```c++

```



#### 四、搜索

##### 1. BFS

广度优先搜索一般用于搜索最优的问题。

**常用步骤：**

```c++
// 第一步：
// 设置访问标志(用于剪枝)

// 第二部：
// 设置一个 Node，用来标志相关状态
struct N{
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
while(!q.empty()){
    now = q.front();
    q.pop();
    ...
}
```



##### 2. DFS

一般用于解决又或者没有的问题。