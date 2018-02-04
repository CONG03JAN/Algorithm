### 数据结构



#### 1. 栈和队列的应用：

一般用 `stack / queue` 容器类模版，分别包含在 `<stack>` 和 `<queue>` 头文件中。

包含的操作有：

**Stack：**

```c++
stack<elemtype> s; // 定义栈元素类型

s.push(x); // 入栈
s.pop(); // 出栈
s.top(); // 访问栈顶
s.empty(); // 判断栈是否为空
s.size(); // 访问栈的元素个数
```

**Queue：**

```c++
queue<elemtype> q; // 定义队列元素类型

q.push(x); // 入队
q.pop(); // 出队
q.front(); // 访问队头
q.back(); // 访问队尾
q.empty(); // 判断队列是否为空
q.size(); // 访问队列的元素个数
```

**Priority_Queue：**

```c++
priority_queue<elemeype> pq;

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



#### 2. 二叉树的应用：


