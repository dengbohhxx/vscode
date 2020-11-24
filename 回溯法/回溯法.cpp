/*子集树
所给的问题是从n个元素的集合S中找出满足某种性质的子集时，相应的解空间成为子集树。
如0-1背包问题，从所给重量、价值不同的物品中挑选几个物品放入背包，使得在满足背包不超重的情况下，背包内物品价值最大。它的解空间就是一个典型的子集树。
*/
void backtrack (int t)  
{  
  if (t>n) output(x);  
    else  
      for (int i=0;i<=1;i++) {  
        x[t]=i;  
        if (constraint(t)&&bound(t)) backtrack(t+1);  
      }  
}  
 /*
 排列树
      所给的问题是确定n个元素满足某种性质的排列时，相应的解空间就是排列树。
如旅行售货员问题，一个售货员把几个城市旅行一遍，要求走的路程最小。它的解就是几个城市的排列，解空间就是排列树。
      回溯法搜索排列树的算法范式如下：
 */
void backtrack (int t)  
{  
  if (t>n) output(x);  
    else  
      for (int i=t;i<=n;i++) {  
        swap(x[t], x[i]);  
        if (constraint(t)&&bound(t)) backtrack(t+1);  
        swap(x[t], x[i]);  
      }  
}   