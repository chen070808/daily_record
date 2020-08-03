# week1

## 2020.8.03 周一

### 事件一

写LeetCode每日一题，美好一周从简单开始。[415 字符串相加](https://leetcode-cn.com/problems/add-strings) ，两个字符串表示的数相加，是大数板子中有用到的，不过我一般都用Python写大数的题，Python的int可以无限制的拓展内存，因此只要内存足够，Python的int可以无限长。模拟竖式加法，对于输入的数每一位从后向前加，保留进位信息，主要问题有两个，不过都是小问题，数位不一样长，可以在每一位相加时判断指针位置，超出位数（即小于0）对应数为0，或在一开始就将较短数前面补0。另一个是顺序，由于是从后往前算，故可以算完后翻转，c++在 头文件`<algorithm>`中定义了`void reverse( BidirIt first, BidirIt last )`方法，其输入要翻转元素的范围，将输入元素翻转，如在本题中字符串背景下。

```c++
string ans="Hello";
cout<<ans<<"\n";
reverse(ans.begin(),ans.end());
cout<<ans<<endl;
```

输出为

```
Hello
olleH

```

其要求输入的`BidirIt` 必须满足[*值可交换* *(ValueSwappable)* ](https://zh.cppreference.com/w/cpp/named_req/ValueSwappable)和 [*遗留双向迭代器* *(LegacyBidirectionalIterator)* ](https://zh.cppreference.com/w/cpp/named_req/BidirectionalIterator)的要求。

调试的过程中有一个报错，string类型的内存溢出，错误点在有下标指针出现了小于0的-1。

	Line 1060: Char 9: runtime error: addition of unsigned offset to 0x7ffe3d283500 overflowed to 0x7ffe3d2834fd (basic_string.h)
	SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/8/../../../../include/c++/8/bits/basic_string.h:1070:9

还有个内存占用比较小的就是直接在num1上进行运算，通过拼接0是其为较长数，然后每一位运算结果写入对应位中，最大位的进位，如5+5=10中的1通过在最后判断，当结果有更大的进位则在结果前拼接1，否则直接输出结果。

### 事件二

练习了codeforce的gym，感觉需要加强基础算法的实现，今天连最短路径都忘了，唉，要多复习。