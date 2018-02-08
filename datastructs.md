### 数据结构



#### 1. 栈和队列的应用：

一般用 `stack / queue` 容器类模版，分别包含在 `<stack>` 和 `<queue>` 头文件中。

包含的操作有：

**Stack：**

```c++
stack<elemtype> s; // 栈构造

s.push(x); // 入栈
s.pop(); // 出栈
s.top(); // 访问栈顶
s.empty(); // 判断栈是否为空
s.size(); // 访问栈的元素个数
```

**Queue：**

```c++
queue<elemtype> q; // 队列构造

q.push(x); // 入队
q.pop(); // 出队
q.front(); // 访问队头
q.back(); // 访问队尾
q.empty(); // 判断队列是否为空
q.size(); // 访问队列的元素个数
```

**Priority_Queue：**

```c++
priority_queue<elemeype> pq; // 优先队列构造

q.push(x); // 入队
q.pop(); // 出队
q.top(); // 访问对头
q.empty(); // 判断队列是否为空
q.size; // 访问队列的元素个数
```

**优先队列优先级：**

1. 重载 `<` 操作符来定义优先级：

```c++
bool operator < (const int &a) const{
  return a.score < score;
}
```

2. 重载 `()` 操作符来定义优先级：

```c++
bool operatior () (const int &a, const int &b){
  return a > b;
}
```

**Map：**

```c++
map<elemtype1, elemtype2> m; //关联容器构造

m.insert(pair<int, string>(1, "one")); // 用insert函数插入pair数据
m.insert(map<int, string>::value_type (1, "one")); // 用insert函数插入value_type数据
m[1] = "one"; // 利用数组元素插入

m.size(); // Map的大小

m<int, string>::iterator iter; // Map正向遍历
m<int, string>::reverse_iterator iter2; // Map反向遍历
for(iter = m.begin(); iter != m.end(); iter++)
  	cout << iter->first << ' ' << iter->second << endl;
m[1]; // Map数组形式遍历

m.count() // 判断是否有此关键字
m.find() // 查找数据并返回迭代器
```

**Set：**



#### 2. 二叉树的应用：


