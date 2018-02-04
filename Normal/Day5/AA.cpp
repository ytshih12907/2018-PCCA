#include <iostream>
#include <algorithm>
#define MAXL 1005
#define MAXINT 0x7fffffff //2147483647
using namespace std;
int cost[MAXL][MAXL], cut[52], len, n; //cost[1005][1005]
int min(int x, int y)
{
  if (x > y)
    return y;
  else
    return x;
}
int dp(int left, int right) //0 5
{                                  //每次小區塊的 最左邊邊界與最右邊邊界  0 5
  bool found = false;              //
  if (cost[left][right] != MAXINT) //只要cost[左][右]有塞東西  就回傳  不用再算-->極為最小成本 (因為cost[左][右]是右上角  剛好是答案)
    return cost[left][right];
  for (int i = 0; i < n; i++) //
  { //i=0  cut[0]=1  1在0~5間-found=true;cost[0][5]=Min(cost[0][5], dp(左=0,1)+dp(1,右=5) 加 右=5  減 左=0 )
    if ((cut[i] > left) && (cut[i] < right))
    {               //cut[0~n]放所需要切的位置  例如2 5 7  //cut[0~n]若介於 最左邊與最右邊間(剛好在這個區塊中)
      found = true; //found=true (有找到可以切的位置)
      cost[left][right] = min(cost[left][right], dp(left, cut[i]) + dp(cut[i], right) + right - left);
    }
  }
  
  
  if (found == false)
    cost[left][right] = 0;
  return cost[left][right];
}
int main()
{
  int result;
  while (cin >> len)
  { //len=長度
    if (len == 0)
      break;
    cin >> n; //n=切幾刀
    for (int i = 0; i < n; i++)
    {
      cin >> cut[i]; //cut[]=這三刀切的位置
    }
    for (int i = 0; i <= len; i++)
      for (int j = 0; j <= len; j++)
        cost[i][j] = MAXINT; //    cost[0~長度][0~長度]都=2147483647
    result = dp(0, len);     //最省錢解法=result          result=dp(0,len) -->木頭刻度0~100-->100個距離  1~100 99個距離而已(像尺)(0為沒長度  最左邊刻度 )
    cout << "The minimum cutting is " << result << "." << endl;
  }
  return 0;
}
/*
100
3
25 50 75
10
4
4 5 7 8
0

*/