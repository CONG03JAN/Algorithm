### 数据结构



#### 1. STL 的应用：

一般用 `stack / queue / priority_queue / map / set / vector` 容器类模版，分别包含在 `<stack>` 、`<queue>` 、`<map>`、`<set>` 和  `<vector>`头文件中。

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

**优先队列可用于实现哈弗曼树**。

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

**Vector:**

```c++
vector<elemtype> c;
vector<elemtype> c1(c2);
vector<elemtype> c(n);
vector<elemtype> c(n, elem);
vector<elemtype> c(beg, end);

c.assign(beg, end);
c.assign(n, elem);
c.at(idx);
c.back();
c.begin();
c.capacity();
c.clear();
c.empty();
c.end();
c.erase(pos);
c.erase(beg, end);
c.front();
c.insert(pos, elem);
c.insert(pos, n, elem);
c.insert(pos, beg, end);
c.max_size();
c.pop_back();
c.rbegin();
c.rend();
c.resize();
c.size();
c1.swap(c2);
swap(c1, c2);
```



#### 2. 二叉树的应用：

##### 2.1. 二叉树的递归遍历：

##### 2.2. 二叉排序树：



#### 3. 图论：

##### 3.1. 并查集：

##### 3.2. 最小生成树（MST）

##### 3.3. 最短路径

##### 3.4. 拓扑排序