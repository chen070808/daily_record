# week2

## 2020.8.10 周一

### 事件一

一场gym联系赛[2017 ACM-ICPC, Universidad Nacional de Colombia Programming Contest](https://codeforces.com/gym/101466)

### 事件二

LeetCode每日一题[696 计数二进制子串](https://leetcode-cn.com/problems/count-binary-substrings) ，按照连续的01进行分组，由于要求连续且01数相同，因此答案的贡献来自于相邻两个连续不同的分组间最小值，这个值就是一个连续组的贡献如，题目中“00110011”可分为{2,2,2,2}，前两组的贡献为2，其中有01和0011，第二三组为2，其中有10和1100，第三四组为2，有01和0011,共为6，由于重复出现的子串依旧要计数，因此第三四组仍旧可以贡献2。