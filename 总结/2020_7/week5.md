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
我的处理方式是求因子的一般方法，如果一个数i是a的因子的话，那么<img src="http://chart.googleapis.com/chart?cht=tx&chl= a/i" style="border:none;">也是a的因子，正如对于6来说，1是因子6也是，2是3也是，这样的话我们就可以只遍历前一半的因子而得出后一半因子，而这个分界点就是<img src="http://chart.googleapis.com/chart?cht=tx&chl= \sqrt{a}" style="border:none;">也正因此将复杂度降到了<img src="http://chart.googleapis.com/chart?cht=tx&chl= O(\sqrt{a})" style="border:none;">)。不过这样得出的 顺序并不是从大到小的顺序，这里使用STL库中的[关联式容器](https://oi-wiki.org/lang/csl/associative-container/)set。`set` 是关联容器，含有键值类型对象的已排序集，搜索、移除和插入拥有对数复杂度。 `set` 内部通常采用红黑树实现。和数学中的集合相似， `set` 中不会出现值相同的元素。

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

