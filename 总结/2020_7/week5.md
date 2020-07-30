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

![](http://latex.codecogs.com/gif.latex?

![](http://latex.codecogs.com/gif.latex?\sqrt{2})

使用<img src="http://chart.googleapis.com/chart?cht=tx&chl= " style="border:none;">

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

