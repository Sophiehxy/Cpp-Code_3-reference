#pragma once
//普通引用
void TestReference1()
{
	int a = 1;
	int& b = a;
	cout << "a:address->" << &a << endl;
	cout << "b:address->" << &b << endl;
	cout << "a:" << a << endl;//1
	cout << "b:" << a << endl;//1
	a = 2;
	cout << "a:" << a << endl;//2
	cout << "b:" << a << endl;//2
	b = 3;
	cout << "a:" << a << endl;//3
	cout << "b:" << a << endl;//3
	int& c = b; // 引用一个引用变量，别名的别名
	c = 4;
	cout << "a:" << a << endl;//4
	cout << "b:" << a << endl;//4
	cout << "c:" << a << endl;//4
}
//const引用
void TestReference2()
{
	int d1 = 4;
	const int & d2 = d1;
	cout << "d1:" << d1 << endl;//4
	cout << "d2:" << d2 << endl;//4

	d1 = 5; // d1改变 d2的值也会改变。
	cout << "d1:" << d1 << endl;//5
	cout << "d2:" << d2 << endl;//5

	//d2 = 6; // 不能给常量（const int是不能被修改的量） 赋值

	const int d3 = 1;
	const int & d4 = d3;
	cout << "d3:" << d3 << endl;//1
	cout << "d4:" << d4 << endl;//1

	//int& d5 = d3;
	
	const int & d6 = 5; // 常量具有常性， 只有常引用可以引用常量
	double d7 = 1.1;
	cout << "d6:" << d6 << endl;//5
	cout << "d7:" << d7 << endl;//1.1

	//int& d8 = d7; //d7是double类型， d8是int，d7赋值给 d8时要生成一个临时变量
	// 也就是说d8引用的是这个带有常性的临时变量， 所以不能赋值。
	
	const int& d9 = d7;//d9已经初始化为d7当前值1（由double转为const int，值为1），当d7的值发生变化时，d9并不随之改变
	d7 = 2.2;
	cout << "d7:" << d7 << endl;//2.2
	cout << "d9:" << d9 << endl;//1
}

//值传递、引用传递、指针传递的异同及使用

void Swap1(int left, int right) // 这里能实现交换吗？--》//并未发生交换值得作用
{
	int temp = left;
	left = right;
	right = temp;
}
//2.【引用传递】如果形参为引用类型，则形参是实参的别名。
void Swap2(int& left, int& right)
{
	int temp = right;
	right = left;
	left = temp;
} 
//3.【指针传递】
void Swap3(int* pLeft, int* pRight)
{
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
} 
void TestReference3()
{
	int a = 1;
	int b = 2;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	//Swap1(a, b);//1,2->1,2
	Swap2(a, b);//1,2->2,1
	//Swap3(a, b);//需传指针型数据作为参数，此例中a，b并不合适
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
}

//测试值传递/引用传递的效率
#include <Windows.h>
struct BigData
{
	int array[1000];
};
void DealBigData(BigData& x)
{
	x.array[0] = 0;
	x.array[1] = 1;
	x.array[2] = 2;
}

void TestReference4()
{
	BigData bd;
	int begin = GetTickCount();
	for (int i = 0; i < 1000000; ++i)
	{
		DealBigData(bd);
	}
	int end = GetTickCount();
	cout << "cost time:" << end - begin << endl;
}


//3.当不希望函数内改变参数x的值时，尽量使用常引用传参。
void ReadBigData(const BigData& x)
{
	int a = x.array[100];
}
//传值做返回值&传引用作为返回值
//int& Add(int d1, int d2)
int Add(int d1, int d2)
{
	int ret = d1 + d2;
	return ret;
}
void TestReference5()
{
	int a = 3, b = 4;
	int c = Add(a, b);
	cout << "c:" << c << endl;
}

////喜欢这样编程的人，最好离他远一点，小心他把你系统黑掉
//void Swap(int& l, int& r)
//{
//	int temp = l;
//	l = r;
//	r = temp;
//}
//void TestReference6()
//{
//	int* p = 0;
//	int& a = *p;
//	int b = 2;
//	Swap(a, b);
//}