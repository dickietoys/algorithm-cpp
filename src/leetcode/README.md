#### 二叉树

~~~
LC 104. Maximum Depth of Binary Tree
LC 110. Balanced Binary Tree
LC 124. Binary Tree Maximum Path Sum  [**]
LC 236. Lowest Common Ancestor of a Binary Tree  [**]
LC 102. Binary Tree Level Order Traversal
LC 98. Validate Binary Search Tree    [**]
LC 701. Insert into a Binary Search Tree


LC 94. Binary Tree Inorder Traversal       [****]
LC 144. Binary Tree Preorder Traversal     [****]
LC 145. Binary Tree Postorder Traversal    [****]

LC 95. Unique Binary Search Trees II [**]
LC 96. Unique Binary Search Trees    [**]

LC 105. Construct Binary Tree from Preorder and Inorder Traversal [**]
LC 106. Construct Binary Tree from Inorder and Postorder Traversal [**]
LC 889. Construct Binary Tree from Preorder and Postorder Traversal [**]
LC 1008. Construct Binary Search Tree from Preorder Traversal [**]
LC 297. Serialize and Deserialize Binary Tree [**]

LC 112. PathSum     [**]
LC 113. PathSum II  [**]

LC 450. Delete Node in a BST [**]
~~~

#### 链表

~~~
LC 23. Merge k Sorted Lists [**]
LC 82. Remove Duplicates from Sorted List II [****]
LC 83. Remove Duplicates from Sorted List    [****]
LC 206. Reverse Linked List
LC 92. Reverse Linked List II [****]
LC 21. Merge Two Sorted Lists
LC 86. Partition List  [****]
LC 148. Sort List
LC 143. Reorder List  [****]
LC 141. Linked List Cycle
LC 142. Linked List Cycle II
LC 234. Palindrome Linked List
LC 138. Copy List with Random Pointer
LC 146. LRU Cache [****]
LC 24. Swap Nodes in Pairs
~~~

#### 栈和队列

~~~
LC 155. Min Stack
LC 150. Evaluate Reverse Polish Notation
LC 394. Decode String     [****]
LC 133. Clone Graph       [**]
LC 200. Number of Islands [**]
LC 84. Largest Rectangle in Histogram [****]
LC 85. Maximal Rectangle [****]
LC 42. Trapping Rain Water [****]

LC 232. Implement Queue using Stacks
LC 542. 01 Matrix [**]
LC 31. Next Permutation [**]
LC 151. Reverse Words in a String [****]
LC 224. Basic Calculator    [****]
LC 227.	Basic Calculator II [****]
~~~


#### 二分搜索

~~~
给一个有序数组和目标值，找第一次/最后一次/任何一次出现的索引，如果没有出现返回-1
模板四点要素
1、初始化：start=0、end=len-1
2、循环退出条件：start + 1 < end
3、比较中点和目标值：A[mid] ==、 <、> target
4、判断最后两个元素是否符合：A[start]、A[end] ? target
时间复杂度 O(logn)，使用场景一般是有序数组的查找

三种模板：https://leetcode-cn.com/explore/learn/card/binary-search/212/template-analysis/847/
~~~

~~~
LC 704. Binary Search
LintCode 61. Search For Range
LC 35. Search Insert Position
LC 74. Search a 2D Matrix
LC 240. Search a 2D Matrix II [**]
LC 278. First Bad Version
LC 153. Find Minimum in Rotated Sorted Array
LC 154. Find Minimum in Rotated Sorted Array II
LC 33. Search in Rotated Sorted Array
LC 81. Search in Rotated Sorted Array II
LC 287. Find the Duplicate Number  [**]

LC 4. Median of two sorted arrays of same size [****]
LC 189. Rotate Array [**]
LC 215. Kth Largest Element in an Array

LC 349. Intersection of Two Arrays
LC 350. Intersection of Two Arrays II

LC 378. Kth Smallest Element in a Sorted Matrix     [****]
LC 668. Kth Smallest Number in Multiplication Table [**]
LC 719. Find K-th Smallest Pair Distance [**]
LC 410. Split Array Largest Sum [**]
~~~

#### 排序算法

~~~
常用排序算法
LintCode 463
~~~


#### 回溯法

回溯法（backtrack）常用于遍历列表所有子集，是 DFS 深度搜索一种，一般用于全排列，穷尽所有可能，遍历的过程实际上是一个决策树的遍历过程。  
时间复杂度一般 O(N!)，它不像动态规划存在重叠子问题可以优化，回溯算法就是纯暴力穷举，复杂度一般都很高

模板：
~~~
result = []
func backtrack(选择列表,路径):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(选择列表,路径)
        撤销选择
~~~

~~~
LC 78. Subsets [****]
LC 90. Subsets II [****]
LC 46. Permutations
LC 47. Permutations II
LC 39. Combination Sum
LC 40. Combination Sum II
LC 216. Combination Sum III
LC 131. Palindrome Partitioning

LC 36. Valid Sudoku [****]
LC 37. Sodoku Solver [****]

LC 51. N-Queens [****]
Lc 52. N-Queens II

LC 17. Letter Combinations of a Phone Number
LC 93. Restore IP Addresses

LC 79. Word Search
LC 212. Word Search II [**** trie tree]
LC 301. Remove Invalid Parentheses [**** BD BFS]
~~~


#### 图算法

~~~
判断有环
拓扑排序
DFS
BFS

LC 207. Course Schedule [**** detect cycle]
LC 210. Course Schedule II [**** topological sort]
LC 547. Friend Circles [图的深度和广度遍历]
~~~


#### 滑动窗口思想

模板：

~~~
/* 滑动窗口算法框架 */
void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...

        // debug 输出的位置
        printf("window: [%d, %d)\n", left, right);

        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}

需要变化的地方
1、右指针右移之后窗口数据更新
2、判断窗口是否要收缩
3、左指针右移之后窗口数据更新
4、根据题意计算结果
~~~


~~~
LC 3. Longest Substring Without Repeating Characters
LC 15. 3Sum   [****]
LC 16. 3Sum Closest [****]
LC 18. 4Sum [**]
LC 76. Minimum Window Substring
LC 239. Sliding Window Maximum [**]
LC 567. Permutation in String
LC 438. Find All Anagrams in a String

~~~


#### palindrome:
~~~
LC 9.   Palindrome Number
LC 125. Valid Palindrome
LC 214. Shortest Palindrome
~~~

#### 二进制

常用公式

~~~
a = 0 ^ a = a ^ 0
0 = a ^ a
由上可推导出：
a = a ^ b ^ b

交换两个数
a = a ^ b
b = a ^ b
a = a ^ b

移除最后一个1:
a=n & (n - 1)

获取最后一个1:
diff=(n & (n - 1)) ^ n

约瑟夫环
人数为n，报m的退出，
f(n, m) = (f(n−1, m) + m) % n

int last = 0;
for (int i = 2; i <= n; ++i)
{
  last = (last + m) % i;
}

return last;
~~~

~~~
LC 136. Single Number
LC 137. Single Number II   [****]
LC 260. Single Number III
LC 191. Number of 1 Bits
LC 338. Counting Bits [****]
LC 190. Reverse Bits
LC 201. Bitwise AND of Numbers Range [****]
LC 233. Number of Digit One [**]
LC 400. Nth Digit [**]
LC 263. Ugly Number [**]
LC 264. Ugly Number II [**]
LC 8. String to Integer (atoi)
~~~


#### stock 问题:
~~~
LC 121. Best Time to Buy and Sell Stock
LC 122. Best Time to Buy and Sell Stock II
LC 123. Best Time to Buy and Sell Stock III [****]
LC 188. Best Time to Buy and Sell Stock IV  [****]
LC 309. Best Time to Buy and Sell Stock with Cooldown [****]
~~~


#### 动态规划

使用场景

~~~
1. 满足两个条件
   满足以下条件之一
   求最大/最小值（Maximum/Minimum ）
   求是否可行（Yes/No ）
   求可行个数（Count(*) ）
2. 满足不能排序或者交换（Can not sort / swap ）

LC 128. Longest Consecutive Sequence 位置可以交互，所以不用动态规划
~~~

四点要素

~~~
1. 状态 State
   灵感，创造力，存储小规模问题的结果
2. 方程 Function
   状态之间的联系，怎么通过小的状态，来算大的状态
3. 初始化 Intialization
   最极限的小状态是什么, 起点
4. 答案 Answer
   最大的那个状态是什么，终点
~~~

常见四种类型

~~~
Matrix DP (10%)
Sequence (40%)
Two Sequences DP (40%)
Backpack (10%)
~~~

Matrix (10%)

~~~
LC 120. Triangle
LC 62. Unique Paths
LC 63. Unique Paths II
LC 64. Minimum Path Sum
~~~

Sequence (40%)

~~~
LC 115. Distinct Subsequences  [**]
LC 10. Regular Expression Matching  [**]
LC 44. Wildcard Matching
LC 5. Longest Palindromic Substring
LC 70. Climbing Stairs
LC 55. Jump Game [**** greedy]
LC 45. Jump Game II [**** greedy]
LC 132. Palindrome Partitioning II [**]
LC 300. Longest Increasing Subsequence
LC 139. Word Break
LC 140. Word Break II
LC 53. Maximum Subarray
LC 279. Perfect Squares
LC 152. Maximum Product Subarray
~~~

Two Sequences DP（40%）

~~~
LC 1143. Longest Common Subsequence
LC 72. Edit Distance
~~~

Backpack (10%)

~~~
LC 322. Coin Change
LintCode 92. Backpack
LintCode 125. Backpack II
~~~


#### 递归思想

~~~
LC 344. Reverse String
LC 509. Fibonacci Number
~~~

#### Array

~~~
LC 485. Max Consecutive Ones
LC 1295. Find Numbers with Even Number of Digits
LC 977. Squares of a Sorted Array
LC 1089. Duplicate Zeros  [**]
~~~

#### LCOF(剑指offer)
~~~
剑指 Offer 20. 表示数值的字符串 [****]
剑指 Offer 43. 1～n整数中1出现的次数 [****]            (LC 233)
剑指 Offer 44. 数字序列中某一位的数字 [****]            (LC 400)
剑指 Offer 49. 丑数 [****]                           (LC 264)
剑指 Offer 53 - II. 0～n-1中缺失的数字 [****]
剑指 Offer 56 - II. 数组中数字出现的次数 II [****]     (LC 137)
剑指 Offer 57 - II. 和为s的连续正数序列 [****]
剑指 Offer 58 - I. 翻转单词顺序 [****]
剑指 Offer 59 - I. 滑动窗口的最大值 [****]             (LC 239)
剑指 Offer 60. n个骰子的点数 [****]
剑指 Offer 62. 圆圈中最后剩下的数字 [****]
剑指 Offer 65. 不用加减乘除做加法 [****]
剑指 Offer 66. 构建乘积数组 [****]
~~~
