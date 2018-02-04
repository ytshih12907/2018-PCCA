DP 題單 solution
===
> https://vjudge.net/contest/211396

> https://hackmd.io/s/rJ4QJQ4UG
### UVA-10003
裸裸的

### UVA-10405
LCS 裸裸的

### UVA-11151
最長回文就是自己跟自己的顛倒的LCS

### UVA-674

將硬幣排成一列
`dp[可以用的前綴集合][湊出來的價錢]`
可以得到 `dp[i][j] = sum of (dp[i-1][j-硬幣單位*數量])`
```
const int coin[6] = {0,1,5,10,25,50};

long long dp[6][10000];

int main (){
    dp[0][0]=1;
    for(int c = 1 ; c < 6 ; c ++){
        for(int i = 0 ; i < 10000 ; i ++){
            for(int j = 0 ; i-coin[c]*j >=0 ; j ++){
                dp[c][i]+=dp[c-1][i-coin[c]*j];
            }
        }
    }
}

```

### UVA-624
裸裸的背包

### CF-274E
`dp[第幾回合][停在哪一層]=sum of (dp[前一回合][某個區間])`
所以可以用前綴和優化區間查詢速度
http://codeforces.com/contest/480/submission/34915946


### CF-393D
因為時間範圍蠻大的,所以要用到離散化的技巧
紀錄每次一段旅程結束後最少花費,
`dp[旅程編號i] = min (dp[i-1]+20,dp[j]+50,dp[k]+120)`
j是最大的j使得j+1..i是在一個90分鐘的區間
k是最大的k使得k+1..i是在一個1440分鐘的區間
其中找j,k可以利用set處理
http://codeforces.com/contest/760/submission/29928252

### CF-407A
特殊前綴和
題目要求的是所有區間的最大值
有做好前綴和(1 based)的話 `[i,j]` 得和就是 `psum[j+1]-psum[i]`
那麼固定j後, 想找max就是找最小的`psum[i]`
所以這題只要維護好當前最小的`psum[i]`
處理麻煩的奇偶問題就可以了
http://codeforces.com/contest/788/submission/30835125

### CF-396C
第二第三個問題直接爬過去做就可以了
只有第一個子問題要DP,`dp[前綴位置i]`然後限制一定要在i時是一個字卡的結束
所以`dp[i]=sumof(dp[j])` 此時的j是上一個字卡可以結束的地方
也就代表 [j+1,i] 要是一個合法的字卡
然後dp下去
http://codeforces.com/contest/766/submission/29828728