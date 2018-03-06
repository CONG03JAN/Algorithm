### 素数，整数分解，欧拉函数

素数是可能数论里最永恒，最经典的问题了（我们的队名就叫PrimeMusic^-^ ）。素数的判断，筛法求素数，大素数的判断··· 还有很多其他问题都会用到素数。

#### 最水最水的：（心情不爽时用来解闷吧）：

- pku1365 Prime Land 
- pku2034 Anti-prime Sequences// 直接搜索，用DL 优化会快很多。
- pku2739 Sum of Consecutive Prime Numbers 
- pku3518 Prime Gap 
- pku3126 Prime Path 
- pku1595 Prime Cuts 
- pku3641 Pseudoprime numbers 
- pku2191 Mersenne Composite Numbers 
- pku1730 Perfect Pth Powers 
- pku2262 Goldbach's Conjecture 
- pku2909 Goldbach's Conjecture 

#### 筛法：

- pku2689 Prime Distance （很好的一个应用）// 先找出sqrt(2^32) 内的所有素数，然后类似筛选法筛选掉[l,u] 范围内的数 http://162.105.81.212/JudgeOnline/problem?id=2689 
  
#### 反素数：

- zoj2562 More Divisors  //waing... 后记：素数表少打了一个19 ～晕死啊～  http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=2562 

#### 素数判断，整数分解：

这两题都要用到miller_rabin 的素数判断和pollard_rho 的整数分解，算法书上都会有，应该是属于模板题吧，不过最好看懂自己敲一 遍。

- pku1811 Prime Test  // 学习miller 和pollard 的题目。
    http://acm.pku.edu.cn/JudgeOnline/problem?id=1811 
- pku2429 GCD & LCM Inverse  // 分解lcm/gcd 为互质的p,q ，要用到Miller Rabin 和Pollard rho 算法，基本上做出来之后都是模板题了。
    http://acm.pku.edu.cn/JudgeOnline/problem?id=2429 

#### 欧拉函数：

数论里很多地方都能用到欧拉函数，很重要的。

- pku1284 Primitive Roots （很水）// 定理：对于奇素数m, 原根个数为phi(phi(m)), 由于phi(m)=m-1, 所以为phi(m-1) 
    http://acm.pku.edu.cn/JudgeOnline/problem?id=1284 
- pku2407 Relatives （很水）
    http://acm.pku.edu.cn/JudgeOnline/problem?id=2407 
- pku2773 Happy 2006  //n 之后的互质的数都是n 之前的加上n 的倍数的。
    http://162.105.81.212/JudgeOnline/problem?id=2773 
- pku2478 Farey Sequence （快速求欧拉函数）// 求前n 个欧拉函数的和，用学习指导里面的n*(1+lnln(n)) 的算法就可以了，非常快。
    http://162.105.81.212/JudgeOnline/problem?id=2478 
- pku3090 Visible Lattice Points （法雷级数）
    http://acm.pku.edu.cn/JudgeOnline/problem?id=3090 
    * 推荐：（欧拉函数，费马小定理）
- pku3358 Period of an Infinite Binary Expansion// 转化为高次同余方程。
    http://acm.pku.edu.cn/JudgeOnline/problem?id=3358 

#### 整数分解：

这个也很重要的耶，包括大数的表示方法。

- pku2992 Divisors// 注意预处理，有很多组数据. 
    http://acm.pku.edu.cn/JudgeOnline/problem?id=2992 
- fzu1753 Another Easy Problem// 记得n! 有多少个p 的幂是怎么求的。
    http://acm.fzu.edu.cn/problem.php?pid=1753 
- hit2813 Garden visiting 
    http://acm-hit.sunner.cn/judge/show.php?Proid=2813 
- pku3101 Astronomy （分数的最小公倍数）// 高精度gcd ，超时中。
    http://acm.pku.edu.cn/JudgeOnline/problem?id=3101