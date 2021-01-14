#include<iostream>
#define ElemType int
#define MaxSize 100

namespace D_S
{
	//顺序表
	class SqList
	{
		private:
			int last;
			int length=MaxSize;
			ElemType * data;
		public:

			SqList(size_t n);
			bool ListInsert(int i,ElemType e);
			bool ListDelete(int i,ElemType &e);
			int LocateElem(ElemType e);
			void test_print();
			void test_auto_make(size_t n);
	};



}
