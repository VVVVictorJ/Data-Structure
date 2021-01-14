#include "SqList.h"

namespace D_S
{

	SqList::SqList(size_t n)
	{
		if(n!=0)
		{
			last=-1;
			this->length=n;
			this->data=new ElemType[n];
			if(this->data==NULL)
			{
				std::cerr<<"动态内存分配失败!"<< std::endl;
				exit(1);
			}
			std::cout<<"成功申请动态内存"<<std::endl;
		}
	}

	bool SqList::ListInsert(int i,ElemType e)
	{
		if(i<1||i>this->length+1)
		{
			return false;
		}
		if(this->length>=MaxSize)
		{
			return false;
		}
		for(int j=this->length; j>=i; j--)
		{
			this->data[j]=this->data[j-1];
		}
		this->data[i-1]=e;
		this->length++;
		return true;
	}

	bool SqList::ListDelete(int i,ElemType &e)
	{
		if(i<1||i>this->length)
		{
			return false;
		}
		e=data[i-1];
		for(int j=i; j<this->length; j++)
		{
			this->data[j-1]=this->data[j];
		}
		this->length--;
		return true;
	}

	int SqList::LocateElem(ElemType e)
	{
		int i;
		for(i=0; i<this->length; i++)
		{
			if(this->data[i]==e)
			{
				return i+1;
			}
		}
		return 0;
	}

	void SqList::test_print()
	{
		for(size_t i=0; i<this->length; i++)
		{
			if(!(i%5))
			{
				std::cout<<std::endl;
			}
			std::cout<<this->data[i]<<' ';

		}
	}

	void SqList::test_auto_make(size_t n)
	{
		int i=n;
		for(size_t j=0; j<this->length; j++)
		{
			this->data[j]=i--;
		}
	}
}