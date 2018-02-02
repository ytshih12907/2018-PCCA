# 2018 PCCA Winter 一般組 DAY 2 練習賽 題解
https://vjudge.net/contest/210601
## A    (ﾟ∀ﾟ)
+ ### Stack
+ 看到數字就塞進stack，看到operand就把stack最上面2個數拿出來做運算再塞回stack

---

## B    ヽ(●´∀`●)ﾉ
+ ### Queue
+ 將process依序塞進queue，每次操作把queue的front拿出來看看是否大於quantum
    + 大於 : 把該process時間減掉quantum後再塞回去queue
    + 其他 : 輸出該process名稱和現在的時間

---

## C    (ﾉ>ω<)ﾉ
+ ### Doubly linked list
+ STL List 操作
    + insert x : push_front
    + delete x : 用iterator找到該value，然後erase他
    + deleteFirst : pop_front
    + deleteLast : pop_back

---

## D    (ﾟ3ﾟ)～♪
+ ### Complete binary tree
+ 底下為1-base的操作
    + 找parent : index / 2
    + 找left child : index * 2
    + 找right child : index * 2 + 1
+ 注意不要找到超出node index的範圍

---

## E    \_(¦3」∠)_
+ ### Max heap
+ 照著pseudo code 做一次
+ 其實 #include <algorithm> 有個東西叫 make_heap


---

## F    ┌|◎o◎|┘
+ ### priority queue
+ insert 插入 priority queue (push)
+ extract 拿出 priority queue 最上面元素並拔掉 (top pop)
+ end 結束

---

## G    ( ºωº )
+ ### graph representation
+ 開個 100x100 的二維陣列
+ graph[i][j] = true iff i 和 j 之間有邊


---

## H    (ﾟдﾟ)
+ ### DFS
+ 從最小的點開始 DFS，遇到 n 條邊先往 ID 最小的走
+ 維護一個值，在 DFS 開始時寫入 d[v] 而且值增加一，結束時寫入 f[v] 而且值增加一
+ 圖可能沒有全部點都連通



---

## I     ⁄(⁄ ⁄•⁄ω⁄•⁄ ⁄)⁄
+ ### BFS
+ BFS queue 紀錄兩個值，一個是下次搜尋的點，另一個是下次搜尋的點離原點的距離

---


## J    ⁽⁽٩(๑˃̶͈̀ ᗨ ˂̶͈́)۶⁾⁾
+ ### map
+ 用 map<string,string> key 存 ip，value 存網站名稱

---


## K    (つ´ω`)つ
+ ### queue
+ ENQUEUE
    + 每一個team都有一個queue，每次有人要排隊就把他丟到他所屬的team的queue裡面。
    + 開一個boolean陣列去記每個team是否在team queue裡面，如果不在team queue裡面，就把那個team丟到team queue裡面。
+ DEQUEUE
    + 從team queue front的team的queue裡面pop front。
    + 如果那個team的queue空了就把team queue pop front。

---


## L    ╮(╯_╰)╭
+ ### stack
+ 如果火車頭的數字跟pattern中的下一個數字長得一樣，就拿掉火車頭，否則把火車頭放到stack裡面。
+ 如果stack top的數字跟pattern中的下一個數字長得一樣，就pop stack。
+ 當火車頭已經全數被處理完之後，檢查stack裡面的東西是否跟剩餘的pattern相符。
+ 如果pattern能夠被match，答案為Yes，否則答案為No。


---


## M    (´;ω;`)
+ ### stack
+ 遇到"("或"["就丟進stack裡面，遇到")"或"]"就去檢查stack top是不是對應的左括號，如果是的話就把左括號pop出來，把整個字串做完之後檢查stack是否為空。
+ 測資可以有空字串，input請用getline。



---

## N    (*´ω\`)人(´ω`*)
+ ### queue
+ 用queue去模擬題目敘述的動作，以上。

---

## O    どこ━━━━(゜∀゜三゜∀゜)━━━━!!??
+ ### priority queue
+ 每次透過priority queue取最小的兩個數字相加，然後把相加後的結果加到答案上，再把相加後的結果放回priority queue
+ priority queue是max heap結構，這裡要用的是min heap，可以這樣宣告：
  ```c++11
  priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
  ```
