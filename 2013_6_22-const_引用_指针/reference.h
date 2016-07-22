#pragma once
//��ͨ����
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
	int& c = b; // ����һ�����ñ����������ı���
	c = 4;
	cout << "a:" << a << endl;//4
	cout << "b:" << a << endl;//4
	cout << "c:" << a << endl;//4
}
//const����
void TestReference2()
{
	int d1 = 4;
	const int & d2 = d1;
	cout << "d1:" << d1 << endl;//4
	cout << "d2:" << d2 << endl;//4

	d1 = 5; // d1�ı� d2��ֵҲ��ı䡣
	cout << "d1:" << d1 << endl;//5
	cout << "d2:" << d2 << endl;//5

	//d2 = 6; // ���ܸ�������const int�ǲ��ܱ��޸ĵ����� ��ֵ

	const int d3 = 1;
	const int & d4 = d3;
	cout << "d3:" << d3 << endl;//1
	cout << "d4:" << d4 << endl;//1

	//int& d5 = d3;
	
	const int & d6 = 5; // �������г��ԣ� ֻ�г����ÿ������ó���
	double d7 = 1.1;
	cout << "d6:" << d6 << endl;//5
	cout << "d7:" << d7 << endl;//1.1

	//int& d8 = d7; //d7��double���ͣ� d8��int��d7��ֵ�� d8ʱҪ����һ����ʱ����
	// Ҳ����˵d8���õ���������г��Ե���ʱ������ ���Բ��ܸ�ֵ��
	
	const int& d9 = d7;//d9�Ѿ���ʼ��Ϊd7��ǰֵ1����doubleתΪconst int��ֵΪ1������d7��ֵ�����仯ʱ��d9������֮�ı�
	d7 = 2.2;
	cout << "d7:" << d7 << endl;//2.2
	cout << "d9:" << d9 << endl;//1
}

//ֵ���ݡ����ô��ݡ�ָ�봫�ݵ���ͬ��ʹ��

void Swap1(int left, int right) // ������ʵ�ֽ�����--��//��δ��������ֵ������
{
	int temp = left;
	left = right;
	right = temp;
}
//2.�����ô��ݡ�����β�Ϊ�������ͣ����β���ʵ�εı�����
void Swap2(int& left, int& right)
{
	int temp = right;
	right = left;
	left = temp;
} 
//3.��ָ�봫�ݡ�
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
	//Swap3(a, b);//�贫ָ����������Ϊ������������a��b��������
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
}

//����ֵ����/���ô��ݵ�Ч��
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


//3.����ϣ�������ڸı����x��ֵʱ������ʹ�ó����ô��Ρ�
void ReadBigData(const BigData& x)
{
	int a = x.array[100];
}
//��ֵ������ֵ&��������Ϊ����ֵ
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

////ϲ��������̵��ˣ��������Զһ�㣬С��������ϵͳ�ڵ�
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