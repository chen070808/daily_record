# week5

## 2020.7.27，周一

### 事件一

今天就正是开始进行，不过仍旧在纠结对于每日总结的放置形式，对于了解到的[DailySchedule](https://github.com/nlxxh/DailySchedule)是在一整个README里面写，个人感觉会较为冗长，现在使用week模式，README用于存放本月日历和导航，目前还未成功将日历链接到对应日期标题。

### 事件二

今天写了几道acm签到题，有一个求因子的思路比较重要，[ Divples](https://codeforces.com/gym/102302/problem/B)

给两个数a，b，从小到大输出及时a的因子也是b的倍数的数，队友的处理是依次按照b的倍数向a循环，不过TLE了，我们认为是因为当b为1，a很大时会循环太多次。

```c++
for(i=1;i*b<=a;i++){
		if(a%(i*b)==0){
			pr("%lld ",i*b);
		}
```
我的处理方式是求因子的一般方法，如果一个数i是a的因子的话，那么$a/i$也是a的因子，正如对于6来说，1是因子6也是，2是3也是，这样的话我们就可以只遍历前一半的因子而得出后一半因子，而这个分界点就是$\sqrt{a}$也正因此将复杂度降到了$O(\sqrt{a})$。不过这样得出的 顺序并不是从大到小的顺序，这里使用STL库中的[关联式容器](https://oi-wiki.org/lang/csl/associative-container/)set。`set` 是关联容器，含有键值类型对象的已排序集，搜索、移除和插入拥有对数复杂度。 `set` 内部通常采用红黑树实现。和数学中的集合相似， `set` 中不会出现值相同的元素。

也正因此，set在遍历下为有序的。

```c++
for (ll i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            if (i % b == 0)
                ans.insert(i);
            if ((a / i) % b == 0)
                ans.insert(a / i);
        }
    }
    set<ll>::iterator iter = ans.begin();
    while (iter != ans.end())
    {
        cout << *iter << " ";
        ++iter;
    }
```

### 事件三

GitHub的Markdown不支持LaTeX公式，不过这也不怪GitHub，因为Markdown原生是针对HTML的，本来也不支持， 我尝试了三种不同的方案，不过在GitHub上的显示都不是很好，但在gitee都能正常显示。

以根号2为例，他们的显示效果为

使用$$ 

$\sqrt{2}$

使用

![](http://latex.codecogs.com/gif.latex?写入公式

![](http://latex.codecogs.com/gif.latex?\sqrt{2})

使用<img src="http://chart.googleapis.com/chart?cht=tx&chl= 写入公式" style="border:none;"

<img src="http://chart.googleapis.com/chart?cht=tx&chl= \sqrt{2}" style="border:none;">

## 2020.7.28 ,周二

### 事件一

又是只能写签到题的一天，今天写的时候有一道较为有趣的题[Goat on a Rope](https://codeforces.com/gym/101982/problem/G)一道用到了点线段的最小距离，对于这个距离的计算这篇博客[点到线段的最短距离算法](http://blog.sina.com.cn/s/blog_5d5c80840101bnhw.html)给了较为详细的介绍和代码。不过他使用的是c#代码且最后一句有误，这里我给出基于他而改出来的c++代码,其中(x，y)为给定点，(x1,y1)和(x2,y2)为线段的两个端点。

```c++
double dist(double x,double y,double x1, double y1, double x2, double y2)
{
    double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
    if (cross <= 0)
        return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
 
    double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    if (cross >= d2)
        return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
 
    double r = cross / d2;
    double px = x1 + (x2 - x1) * r;
    double py = y1 + (y2 - y1) * r;
    return sqrt((x - px) * (x - px) + (y - py) * (y - py));
}
```

### 事件二

看了北大陆俊林老师的计算机组成的第一章计算机基本结构。

## 2020.7.29 周三

### 事件一

计组第一章的笔记完成了计划中的80%，本计划还有计算机运行过程和重点题。

### 事件二

简单了解了NLP。

## 2020.7.30 周四

### 事件一

打了场gym练习赛，没什么特别的思路解法，要开始补题了。

### 事件二

看了计组第二章指令系统体系结构的视频，还不是特别清楚，只了解了大概，可能是看的比较快，明天对着书仔细看看。

## 2020.7.31 周五

### 事件一

计组看到了2.6，感觉其中的#写错了写成了非少一横，对比了下第五版，虽然更改了指令集之后内容差别也不是很大，有挺多图片文字都是一样的。吐槽一句，指令字段部分写的好像对不上，也可能是我理解错了意思。要加快速度了，似乎重点在机器指令和地址、寻址方式上（暂无实证）

## 2020.8.01 周六

### 事件一

打了场gym，其中有道[Third-Party Software](https://codeforces.com/gym/101755/problem/C)，有个较为经典的题是，用最少的区间覆盖全部线段，解法很多，用排序之后贪心，也会有挺多的演化。一开始我以为是这样的，后来发现这个题很有趣是用最少的点覆盖全部线段，是找出最少的点，使得每条线段至少包含一个点。解决方法也是排序之后贪心。具体来说就是以右端点为第一优先排序，之后遍历，当新线段的左端点无法覆盖当前右端点时，把新线段的右端点放进来。

### 事件二

今天刚立下flag，八月每天写LeetCode的每日一题，LeetCode就给我来了个困难劝退[632  最小区间](https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists) ，然后说和[「76. 最小覆盖子串」](https://leetcode-cn.com/problems/minimum-window-substring/)思路类似，一看也是一道困难。

思路就是滑动窗口用哈希表来维护序列，这篇题解对滑动窗口的的套路思考写的很清晰。[滑动窗口的套路：找到可行解，再优化可行解](https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/solution/hua-dong-chuang-kou-de-tao-lu-zhao-dao-ke-xing-jie/)

## 2020.8.02 周日

### 事件一

LeetCode每日一题，今天写的是[二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list) 将二叉树转换为先序遍历的，比较简单易写的办法是通过递归的先序遍历获得顺序，之后将节点的右子树指向顺序中下一个节点。[0ms，战胜100%用户，注释很详细，希望对大家有帮助](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/0mszhan-sheng-100yong-hu-zhu-shi-hen-xiang-xi-xi-w/)这篇题解写的很简单，很强，明天要仔细看看，今天要接着写计组实验报告了。

### 事件二

完善计组运算器实验报告，基于Verilog HDL编程语言的行为级仿真，逻辑运算的与或非都没有什么问题，问题会出现在加减运算其中的溢出标志，简单的做法为让加减运算处于九位的状态下，之后将其第九位输出为进位位，不过问题在于由于赋值给九位的数，会将八位的数拓展为九位，拓展位一般为0，而0进行非运算后第九位会变为1，而这就和溢出冲突了，虽然没有溢出但还是有溢出值。解决方法也不难，就是在进行逻辑运算时将其限制在八位环境下，在逻辑运算后拼接0进行加法运算，从而保证第九位仅在加法运算过程中的进位改变。不过后面有要求，参与运算的八位数也要是补码格式，也就是说参与运算的数也会有负数，且九位不参与运算，对此一个简单的解决方案是通过观察最高位，由于是补码运算，最高位第八位表示为符号，在整数的加法运算中结果仍是正数，当最高位为1说明进位了，将其置0并设置溢出信号。负数时，其运算过程中其符号位1一定会被进位，此时符号位为0，当运算有进位是会进到符号位，此时符号位为1，仍旧可以通过对符号位的判断确定是否溢出。（时间匆忙仅是思路，还未加验证）

## other

本周感觉用于学习时间较少，需要对平时浪费的时间进行分析有个app叫timetrack可以自己计时每天各项活动，从而知道时间都去哪了。GitHub的公式显示真的神奇，我当时写的时候三个都不能正常显示，我前两天看的时候第二个恢复了。简单就说到这，写报告去，看机会补点什么。最后碎碎念的吐槽一句，今天中午才说明天就交给老师了，之前老师说是20号。十分令人猝不及防。