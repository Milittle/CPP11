### IO读取
1. C++ 可以从设备以及内存中读取数据或写入数据
2. IO库定义了读写内置类型值的操作, 此外,一些类,如string,也是也定义了类似的IO操作
3. 本章介绍比较简单的IO操作
4. 14章介绍自己重载输入输出运算符
5. 17章介绍如何对文本文件进行随机访问

### 基本操作
1. istream 输入流 提供输入操作
2. ostream 输出流 提供输出操作
3. cin 一个istream对象,从标准输入读取数据
4. cout 一个ostream对象,从标准输出写入数据
5. cerr 一个ostream对象,用来输出程序错误消息,写入到标准错误
6. >> 运算符用来从一个istream对象读取输入数据
7. << 运算符用来从一个ostream对象读取输出数据
8. getline函数用来从一个istream对象中读取一行数据,存到指定string中


### IO对象无拷贝和赋值
1. 由于IO对象无拷贝和赋值,也就是拷贝构造函数和赋值运算符都被禁用了
2. 所以我们一般传递流的话,那就只能通过引用的方式来传递流
3. 读取一个IO对象会改变其状态,所以不能将传递和返回的引用定义为const的


### 流状态与流出错的代码
1. stream::iostate表示流的状态类型
2. 四种类型的状态: stream::badbit stream::failbit stream::eofbit stream::goodbit
3. 相关函数:
	s.eof() eof置位返回true
	s.fail() failbit或者badbit置位 返回true
	s.bad() badbit置位返回true
	s.good() 有效状态返回true
	s.clear() 所有条件状态为复位,将流的状态置为有效 返回void
	s.clear(flags) 根据给定的flags标志位,将流对应的状态为复位,类型为iostate 返回void
	s.setstate(flags) 根据给定flags标志位,将流s中对应的条件状态为置位,类型位iostate 返回void
	s.rdstate() 返回流s的当前状态,返回类型iostate

### 检测流状态的条件会不会失败
1. 我们通常通过条件语句来检测流的状态
2. 只要badbit failbit eofbit中任意一个被置位,那么检测流装填的条件表达式,就会失败
3. 使用good和fail是确定流总体状态的正确方法.
4. 而eof和bad操作只能表示特定的错误

### 管理条件状态
1. 我们可以使用如下方式来实现流状态的管理
` auto old_state = cin.rdstate();`
` cin.clear();`
` process_input(cin);`
` cin.setstate(old_state);`
使用如上的方式维护流的状态
2. 