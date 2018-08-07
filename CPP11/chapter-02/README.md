### 2_1

int占4个字节、long占4个字节、long long 占8个字节、short占2个字节

无符号类型不会有负数，同样的字节表示的数字更大

有符号类型会有负数

float 单精度浮点型 占4个字节

double 双精度浮点型 占8个字节

### 2_2

利率---double

本金---int

付款---double

### 2_3

```c++
unsigned u = 10, u2 = 42;
std::cout<<u2-u<<std::endl;//32
std::cout<<u-u2<<std::endl;//unsigned最大数减32
int i=10,i2=42;
std::cout<<i2-i<<std::endl;//32
std::cout<<i-i2<<std::endl;//-32
std::cout<<i-u<<std::endl;//0
std::cout<<u-i<<std::endl;//0
```

根据观察，vs2017在运算同一个表达式里面存在有符号数和无符号数的时候，先将无符号数转化为有符号数，然后进行运算，最后在以无符号数的形式显示。这是很重要的一个点。

### 2_4

已经验证

### 2_5

(a) 'a'是一个普通的char字符类型，L'a'是一个wchar_t类型，"a"是一个const char*字符串字面值，L"a"是一个const wchar_t *的字符串字面值

(b)10是一个int类型的字面值，10u是一个unsigned int类型的字面值，10L是一个long类型的字面值，10uL是一个unsigned long类型的字面值，012是一个八进制数（对应十进制10），0xc是一个十六进制（对应十进制12）

(c)3.14是一个double的字面值，3.14f是一个float的字面值，3.14L是一个long double的字面值

(d)10是一个int的字面值，10u是一个unsigned int 的字面值，10.是一个double的字面值，10e-2是一个double的字面值。

### 2_6

