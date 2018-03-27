#include<stdio.h>
#include<algorithm>
#include<iostream>
#define MAX 20
using namespace std;

long long dp[MAX][state];
long long num[MAX];

/*
pos表示当前的数位，此处pos=0表示个位，pos=1表示十位，以此类推
state表示状态参数，也可以有多个状态参数
lead表示前导零（一般来说只有当答案和0有关系时才需要这个参数）
limit表示当前pos位是否受限）
*/
long long dfs(int pos, int state, bool lead, bool limit) {
    if(pos==-1) // 表示已经搜索结束
        return 1; // 返回并不确定，结合实际情况改变
    
    if(!lead && !limit && dp[pos][state] != -1) // 在不受限的情况下如果dp已被更新，则直接返回
        return dp[pos][state];
    
    int end = limit? num[pos]: 9; // end用以确定搜索终点，不受限就是9，受限就是当前pos位的数值
    
    long long ans = 0;
    
    // 注意边界
    for(int i = 0; i <= end; i++) {
        ans += dfs(pos-1, newstate, newlead, limit && (i == end) ); // 只有前面所有位数都受限，下一位才受限
    }

    if(!limit && !lead)// 只有当不受限时（即范围为整十，整百...），才更新dp数组，因为受限区间不能代表整区间
        dp[pos][state] = ans;
    
    return ans;
}
