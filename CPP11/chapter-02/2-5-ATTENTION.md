### 2-5处理类型

#### 2.5.1类型别名
1. 类型别名有两种方式进行创建
2. typedef 语法: typedef double wages; wages就是double的同义词
3. using别名声明 using SI = Sales_item; SI就是Sales_item的同义词  (新标准用法)
4. 在普通类型中,其实还挺好理解的,但是在const和指针一起命名的时候就会产生难以理解的地方
5. 所以应该从变量的类型角度去理解typedef的类型.
比如: typedef char *pstring; 其实pstring的类型是一个常量指针, 也就是是指向char的常量指针

#### 2.5.2auto
1. 用来推测表达式的类型
2. 因为一行只能表明一种数据类型,所以不能在auto中声明不同类型
3. 符合类型和auto,对于引用来讲,auto推测的就是引用对象的类型,而非引用本身
4. auto而且还会忽略顶层const,一般底层const会保留下来
5. 综合auto推测值类型的时候,需要明确会忽略顶层const和引用属性
6. 如果要auto推测出来具有顶层const的话,必须显示添加const  const auto a = i; i为const int
7. 当然也可以将&推测加在auto推测里面 auto &i = s;

#### 2.5.3 decltype类型指示符(c++11新关键字)
1. 有这么一种需求,那就是通过表达式推测其类型的需求,而不是通过它去初始化对象
2. 那么就可以使用decltype类型来推测
3. 编译器分析表达式并得到它的类型,而不进行表达式计算
4. decltype处理顶层const和引用和auto机制不一致
5. 如果decltype(n) n是一个变量,则decltype就会获取该变量的类型 包括顶层const和引用属性
6. 引用从来都是指的是对象的同义词出现的,但是在decltype这里是一个特例
7. 如果表达式不是一个变量的话,那么decltype就是表达式结果的类型
8. decltype(*p) 得到的是该类型的引用类型
9. decltype((variable)) 这个是引用类型 decltype(variable) 这个取决于variable的类型
10. 所以decltype始终是通过表达式来识别类型的,变量除外
