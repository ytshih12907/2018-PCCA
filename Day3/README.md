# Day3題解OuO

https://vjudge.net/contest/210927
https://hackmd.io/s/r1QBrXbLf
https://hackmd.io/s/S1z0sc-8G


<style type="text/css">
    ol { list-style-type: upper-alpha; }
</style>

1. Local Extrema (59/99)
    - 迴圈
    - 找極值(大於前後兩項或小於前後兩項的值)有幾個
    - 邊界不是極值

    ```c++
    #include<cstdio>
    #include<iostream>

    using namespace std;

    int main()
    {
        int n;
        cin >> n;
        int v[n];	
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int local_extrema = 0;
        for(int i = 1; i < n - 1; i++)
            if((v[i - 1] < v[i] && v[i] > v[i + 1]) || (v[i - 1] > v[i] && v[i] < v[i + 1]))
                local_extrema += 1;
        cout << local_extrema << endl;

    }
    ```

2. Transformation: from A to B (33/163)
    - 狀態dfs
    - long long

    ```g++
    #include<iostream>
    #include<vector>
    using namespace std;

    int finish = 0;
    vector<long long> ans;
    void dfs(long long s, long long t)
    {
        if(s > t || s < 0)
            return;
        if(s == t)
        {
            finish = 1;
            puts("YES");
            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            puts("");
        }
        if(finish)
            return;
        ans.push_back(s * 10 + 1);
        dfs(s * 10 + 1, t);
        ans.pop_back();
        ans.push_back(2 * s);
        dfs(2 * s, t);
        ans.pop_back();
    }

    int main()
    {
        int s, t;
        cin >> s >> t;
        ans.push_back(s);
        dfs(s, t);
        if(!finish)
            puts("NO");
        ans.pop_back();
    }

    ```
    

3. Beautiful Divisors (40/119)
    - 迴圈
    - A是B的divisor $\rightarrow B \mod A = 0$

    ```g++  
    #include<iostream>
    #include<cmath>
    using namespace std;

    int main()
    {
        int n;
        cin >> n;
        int Max = 1;
        for(int k = 1; ; k++)
        {
            int b = (pow(2, k) - 1) * pow(2, k - 1);
            if(b > n)
                break;
            if(n % b == 0)
                Max = b;
        }
        cout << Max << endl;
    }

    ```

4. Oil Deposits (32/35)
    - 格子圖的dfs
    - 方向有8個

    ```g++
    #include<iostream>
    #include<vector>
    using namespace std;

    char g[100][100];
    void dfs(int x, int y, int limit_x, int limit_y)
    {
        if(g[x][y] == '*')
            return;
        g[x][y] = '*';
        int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
        int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
        for(int i = 0; i < 8; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x < limit_x && new_x >= 0 && new_y < limit_y && new_y >= 0)
                dfs(new_x, new_y, limit_x, limit_y);
        }
    }

    int main()
    {
        while(1)
        {
            int ans = 0;
            int m, n;
            cin >> m >> n;
            if(m == 0 || n == 0)
                return 0;
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                    cin >> g[i][j];
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                {
                    if(g[i][j] == '*')
                        continue;
                    ans += 1;
                    dfs(i, j, m, n);
                }
            cout << ans << endl;
        }
    }

    ```

5. Generating Fast (39/69)
    - 全排列
    ```g++
    #include<iostream>
    #include<algorithm>
    using namespace std;

    int main()
    {
        int N;
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            string s;
            cin >> s;
            sort(s.begin(), s.end());
            do
            {
                cout << s << endl;
            } while(next_permutation(s.begin(), s.end()));
            cout << endl;
        }
    }
    ```

6. 8 Queens Problem (6/7)
    - 八皇后
    - 可以用dfs實作
    - 請不要C(64,8)

    ```g++
    #include<cstdio>
    #include<iostream>
    using namespace std;

    char g[8][8];

    void dfs(int x)
    {
        if(x >= 8)
        {
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                    cout << g[i][j];
                cout << endl;
            }
            return;
        }
        for(int i = 0; i < 8; i++)
            if(g[x][i] == 'Q')
            {
                dfs(x + 1);
                return;
            }
        for(int y = 0; y < 8; y++)
        {
            int flag = 0;
            int dx[] = {1, 1, 1, -1, -1, -1};
            int dy[] = {1, 0, -1, 1,  0, -1};
            for(int k = 0; k < 6; k++)
            {
                for(int i = 0; ; i++)
                {
                    int new_x = x + dx[k] * i;
                    int new_y = y + dy[k] * i;
                    if(new_x < 0 || new_x >= 8)
                        break;
                    if(new_y < 0 || new_y >= 8)
                        break;
                    if(g[new_x][new_y] == 'Q')
                        flag = 1;
                }
            }
            if(flag == 1)
                continue;
            g[x][y] = 'Q';
            dfs(x + 1);
            g[x][y] = '.';
        }
    }

    int main()
    {
        int n;
        cin >> n;
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                g[i][j] = '.';
        for(int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x][y] = 'Q';
        }
        dfs(0);
    }

    ```
    或者是也可以用next_permutation解歐XD
    ```c++
    #include<bits/stdc++.h>
    
    using namespace std;

    vector<pair<int,int> > iboard;
    vector<int> row,col,diag,vdiag;

    void init(){
        row = vector<int>(8,0);
        col = vector<int>(8,0);
        diag = vector<int>(15,0);
        vdiag = vector<int>(15,0);
    }

    bool test(int i, int j){
        if(row[i] || col[i] || diag[i-j+7] || vdiag[i+j]) return false;
        else return true;
    }

    bool put(int i, int j){
        if(!test(i,j)) return false;
        row[i]=1;
        col[i]=1;
        diag[i-j+7]=1;
        vdiag[i+j]=1;
        return true;
    }

    int main(){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            int r,c;
            cin>>r>>c;
            iboard.push_back({r,c});
        }
        vector<int> perm(8,0);
        vector<string> mat(8);
        for(int i=0;i<8;++i) perm[i]=i;
        do{
            init();
            bool flag = false;
            for(int i=0;i<iboard.size();++i)
                if(perm[iboard[i].first]!=iboard[i].second){
                    flag = true;
                    break;
                }
            if(flag) continue;
            for(int i=0;i<8;++i)
                if(!put(i,perm[i])){
                    flag = true;
                    break;
                }
            if(flag) continue;
            for(int i=0;i<8;++i) mat[i]="........";
            for(int i=0;i<8;++i){
                mat[i][perm[i]] = 'Q';
                puts(mat[i].c_str());
            }
        } while(next_permutation(perm.begin(),perm.end()));
        return 0;
    }
    
    ```

7. Chtholly's request (9/56)
    - 迴圈
    - long long

    ```g++
    #include<cstdio>
    #include<iostream>

    using namespace std;

    long long f(long long k)
    {
        long long g = k;
        while(g > 0)
        {
            k = k * 10 + g % 10;
            g /= 10;
        }
        return k;
    }

    int main()
    {
        int k, p;
        cin >> k >> p;
        long long ans = 0;
        for(int i = 1; i <= k; i++)
            ans = (ans + f(i)) % p;
        cout << ans << endl;
    }
    ```

8. Knight Moves (9/14)
    - bfs最短距離
    - 騎士的移動只有(+-1, +-2), (+-2, +-1)，8個

    ```c++
    #include<iostream>
    #include<queue>

    using namespace std;

    typedef struct _tri{
        int x, y, n;
    } tri;

    int main()
    {
        while(1)
        {
            string s, t;
            cin >> s >> t;
            if(!cin)
                break;
            int visited[8][8];
            for(int i = 0; i < 8; i++)
                for(int j = 0; j < 8; j++)
                    visited[i][j] = 0;
            int sx, sy, tx, ty;
            sx = s[0] - 'a';
            sy = s[1] - '1';
            tx = t[0] - 'a';
            ty = t[1] - '1';
            queue<tri> q;
            q.push({sx, sy, 0});
            int ans;
            while(q.size() != 0)
            {
                tri tmp = q.front();
                q.pop();
                int x = tmp.x;
                int y = tmp.y;
                int n = tmp.n;
                if(x == tx && y == ty)
                {
                    ans = n;
                    break;
                }
                if(visited[x][y])
                    continue;
                visited[x][y] = 1;
                int dx[] = {1,  1,  2,  2, -1, -1, -2, -2};
                int dy[] = {2, -2,  1, -1,  2, -2,  1, -1};
                for(int i = 0; i < 8; i++)
                {
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];
                    if(new_x >= 8 || new_x < 0)
                        continue;
                    if(new_y >= 8 || new_y < 0)
                        continue;
                    q.push({new_x, new_y, n + 1});
                }
            }
            cout << "To get from " << s << " to " << t <<" takes " <<ans <<" knight moves." << endl;
        }
    }

    ```

9. Friends (5/9)
    - 圖論dfs

    ```g++
    #include<iostream>
    #include<vector>

    using namespace std;

    vector<vector<int> > g;
    vector<int> visited;
    int ans;
    int A;

    void dfs(int x)
    {
        if(visited[x])
            return;
        visited[x] = 1;
        A += 1;
        for(int i = 0; i < g[x].size(); i++)
            dfs(g[x][i]);
    }

    void solve()
    {
        int n, m;
        cin >> n >> m;
        g.clear();
        g.resize(n + 1);
        visited.clear();
        visited.resize(n + 1, 0);
        for(int i = 0; i < m; i++)
        {
            int s, t;
            cin >> s >> t;
            g[s].push_back(t);
            g[t].push_back(s);
        }
        ans = 0;
        for(int i = 1; i <= n; i++)
            if(!visited[i])
            {
                A = 0;
                dfs(i);
                ans = max(ans, A);
            }
        cout << ans << endl;
    }


    int main()
    {
        int t;
        cin >> t;
        while(t--)
            solve();
    }


    ```

10. Rank the Languages (13/19)
    - dfs

    ```c++
    #include<iostream>
    #include<algorithm>
    #include<cstdio>
    #include<vector>
    using namespace std;

    vector<vector<char> > g;
    vector<vector<int> > visited;
    int n, m;

    void dfs(int x, int y, char c)
    {
        if(x >= n || x < 0 || y >= m || y < 0)
            return;
        if(g[x][y] != c)
            return;
        if(visited[x][y])
            return;
        visited[x][y] = 1;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++)
            dfs(x + dx[i], y + dy[i], c);
    }

    struct Pair{
        int n;
        char c;
        bool operator<(Pair& p)
        {
            return n == p.n ? c > p.c : n < p.n;
        }
    };


    void solve(int cnt)
    {
        int ans[26];
        for(int i = 0; i < 26; i++) ans[i] = 0;
        cin >> n >> m;
        g.clear();
        g.resize(n);
        for(int i = 0; i < n; i++)
            g[i].resize(m);
        visited.clear();
        visited.resize(n);
        for(int i = 0; i < n; i++)
            visited[i].resize(m, 0);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> g[i][j];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!visited[i][j])
                {
                    ans[g[i][j] - 'a'] += 1;
                    dfs(i, j, g[i][j]);
                }
        Pair p[26];
        for(int i = 0; i < 26; i++)
            p[i] = (Pair){ans[i], (char)i};
        sort(p, p + 26);
        printf("World #%d\n", cnt);
        for(int i = 25; i >= 0 && p[i].n > 0; i--)
            printf("%c: %d\n", p[i].c + 'a', p[i].n);

    }

    int main()
    {
        int t;
        cin >> t;
        for(int i = 1; i <= t; i++)
            solve(i);
    }
    ```
    
11. Jugs (1/2)
    - 狀態dfs
    ```c++
    #include<cstdio>
    #include<iostream>
    #include<vector>
    #include<string>
    using namespace std;


    int Ca, Cb, N;
    int visited[1000][1000];
    vector<string> path;
    int finish;
    void dfs(int a, int b)
    {
        if(visited[a][b])
            return;
        visited[a][b] = 1;
        if(a == N || b == N)
        {
            for(int i = 0; i < path.size(); i++)
                cout << path[i] << endl;
            finish = 1;
        }
        if(finish == 1)
            return;
        if(a != Ca)
        {
            path.push_back("fill A");
            dfs(Ca, b);
            path.pop_back();
        }
        if(b != Cb)
        {
            path.push_back("fill B");
            dfs(a, Cb);
            path.pop_back();
        }
        if(a != 0)
        {
            path.push_back("empty A");
            dfs(0, b);
            path.pop_back();
        }
        if(b != 0)
        {
            path.push_back("empty B");
            dfs(a, 0);
            path.pop_back();
        }
        if(a != 0 && b != Cb)
        {
            path.push_back("pour A B");
            int b_diff = Cb - b;
            if(a >= b_diff)
                dfs(a - b_diff , Cb);
            else
                dfs(0, b + a);
            path.pop_back();
        }
        if(b != 0 && a != Cb)
        {
            path.push_back("pour B A");
            int a_diff = Ca - a;
            if(b >= a_diff)
                dfs(Ca, b - a_diff);
            else
                dfs(a + b, 0);
            path.pop_back();
        }
    }


    int main()
    {
        while(cin >> Ca >> Cb >> N)
        {
            for(int i = 0; i < 1000; i++)
                for(int j = 0; j < 1000; j++)
                    visited[i][j] = 0;
            finish = 0;
            dfs(0, 0);
            cout << "success" << endl;
        }
    }

    ```
    
    
12. Fire! (2/6)
    - bfs最短距離
    - 一開始queue有多個起點

    ```g++
    #include<iostream>
    #include<queue>
    using namespace std;

    char g[1000][1000];
    struct pos{
        int x, y, n;
        char c;
    };

    void solve()
    {
        int R, C;
        cin >> R >> C;
        queue<pos> q;
        pos s;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
            {
                cin >> g[i][j];
                if(g[i][j] == 'F')
                    q.push((pos){i, j, 0, 'F'});
                if(g[i][j] == 'J')
                    s = (pos){i, j, 0, 'J'};
            }
        q.push(s);
        while(q.size())
        {
            pos front = q.front();
            q.pop();
            int x = front.x, y = front.y, n = front.n;
            char c = front.c;
            if(x < 0 || x >= R || y < 0 || y >= C)
            {
                if(c == 'J')
                {
                    cout << n << endl;
                    return;
                }
                continue;
            }
            if(g[x][y] == '#')
                continue;
            g[x][y] = '#';
            int dx[] = {1, 0, -1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++)
            {
                int new_x = x + dx[k];
                int new_y = y + dy[k];
                q.push({new_x, new_y, n + 1, c});
            }
        }
        cout << "IMPOSSIBLE" << endl;
    }



    int main()
    {
        int t;
        cin >> t;
        while(t--)
            solve();
    }

    ```

13. I Hate It (3-1/28-1)
    - 題敘：給一個長度n的序列，有m次查詢每次查詢可以更新單點或查區間最大值
    - 分塊暴搜，建立summary array
    ```c++
    #include<bits/stdc++.h>

    using namespace std;

    vector<int> arr, mA;
    int n,sqtn;
    void init(){
        sqtn = ceil(sqrt(n));
        mA = vector<int>(sqtn,0);
        for(int i=0;i<sqtn;++i)
        for(int j=0;j<sqtn;++j){
            int idx = i*sqtn+j;
            if(idx<n) mA[i] = max(arr[idx],mA[i]);
        }
    }

    int getMax(int from, int to){
        int out = 0;
        for(int base=0,i=0;base<to;++i,base+=sqtn){
            if(base+sqtn<=from || to<=base) continue;
            if(from<=base && base+sqtn<=to) out = max(out,mA[i]);
            else for(int j=0;j<sqtn;++j){
                int idx = base + j;
                if(from<=idx && idx<to)
                    out = max(out,arr[idx]);
            }
        }
        return out;
    }

    void modify(int idx, int val){
        int i = idx/sqtn;
        arr[idx] = val;
        int base = i*sqtn;
        mA[i] = 0;
        for(int j=0;j<sqtn;++j)
            if(base+j<n) mA[i] = max(mA[i],arr[base+j]);
    }

    int main(){
        int m;
        while(~scanf("%d%d",&n,&m)){
            arr.resize(n);
            for(int i=0;i<n;++i)
                scanf("%d",&arr[i]);
            init();
            while(m--){
                int a,b;
                char cmd[2];
                scanf("%s%d%d",cmd,&a,&b);
                if(cmd[0]=='Q'){
                    cout<<getMax(a-1,b)<<"\n";
                } else if(cmd[0]=='U'){
                    modify(a-1,b);
                }
            }
        }
        return 0;
    }
    ```

14. Jurassic Remains(1-1/1-1)
    - 題敘：給24個以內由大寫英文字母構成的字串，問最多可以拿哪幾個字串使得每個字母都出現偶數次
    - 中間相遇
    - 全組合
    - 如果不想中間相遇的話
        - xor是個好東西(´・ω・`)
        - 直接爆搜搭配位元壓縮有可能喇過

    ```c++
    #include<iostream>
    #include<cstdio>
    #include<vector>
    #include<map>

    using namespace std;

    vector<int> arr;
    inline int decode(int sel){
        int out = 0;
        for(int i=0;sel;++i,sel>>=1)
            if(sel&1) out^=arr[i];
        return out;
    }

    inline int bitCount(int val){
        int out = 0;
        for(;val;val>>=1) (val&1)&&++out;
        return out;
    }

    int main(){
        int n;
        cin>>n;
        arr.resize(n);
        for(int i=0;i<n;++i){
            string tmp;
            cin>>tmp;
            arr[i] = 0;
            for(int j=0;j<tmp.size();++j)
                arr[i] ^= 1<<(tmp[j]-'A');
        }
        int m = n/2, ansNum = 0, ans=0;
        map<int,int> record;
        for(int i=0;i<(1<<m);++i){
            int tmp = decode(i);
            if(record.count(tmp)){
                int& rval = record[tmp];
                if(bitCount(rval)<bitCount(i)) rval = i;
            } else record[tmp] = i;
        }
        for(int i=0;i < 1<<(n-m);++i){
            int tmp = decode(i<<m);
            if(record.count(tmp)){
                int& rsel = record[tmp];
                int bCnt = bitCount(i)+bitCount(rsel);
                if(bCnt>ansNum) ansNum=bCnt, ans=rsel|(i<<m);
            }
        }
        printf("%d\n",ansNum);
        for(int i=0,j=0;ans;++i,ans>>=1)
            if(ans&1){
                if(j) printf(" "); else j=1;
                printf("%d",i+1);
            }
        puts("");
        return 0;

    }
    ```
