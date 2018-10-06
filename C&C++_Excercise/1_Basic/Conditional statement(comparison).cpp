// 选择编程风格良好的条件比较语句

/* A. 假设布尔变量名字为flag， 它与零值比较的标准if语句如下
1.
if (flag == TRUE)
if (flag == FALSE) 

2.
if (flag)
if (!flag)
*/

/* B. 假设整型变量的名字为value， 它与零值比较的标准if语句如下
1. 
if (value == 0)
if (value != 0)

2.
if (value)
if (!value)
*/

/* C. 假设浮点变量的名字为x， 它与0.0的比较如下
1.
if (x == 0.0)
if (x != 0.0)

2.
if ((x >= -EPSINON)) && (x <= EPSINON))
if ((x >= -EPSINON)) || (x <= EPSINON))
*/

/* D. 指针变量P与0的比较如下 
1.
if (p == NULL)
if (p != NULL)
 
2.
if (p == 0)
if (p != 0)
*/
 
 
/*
注A. VC将TRUE定义为1，VB将TRUE定义为-1，故不能将布尔变量直接与TRUE、FALSE进行比较 
注B. 第二种风格会让人误认为value是布尔变量 
注C. 无论是float还是double都会有精度限制 
注D. 指针变量的零值是“空”（记为NULL），尽管NULL的值与0相同，但是两者意义不同，NULL强调p是指针变量，用0比较容易误解p为整型变量 
*/
