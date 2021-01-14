#include "LinkList.h"
#define ElemType int

namespace D_S
{
	//单链表
	LinkList::LinkList(int i, int num)
	{
		this->head=new LNode;
		this->temp=new LNode;
		//1 headinsert, 2 tailinsert
		if(i==1)
		{
			while(num)
			{
				this->temp=new LNode(NULL,num);
				this->temp->next=this->head->next;
				this->head->next=this->temp;
				num--;
			}
		}
		else
		{
			this->temp=this->head;
			while(num)
			{
				this->temp->next=new LNode(NULL,num);
				this->temp=this->temp->next;
				num--;
			}
		}
	}

	LNode LinkList::GetElem(int i)
	{
		if(i<0)
		{
			std::cerr<<"index error"<<std::endl;
			exit(1);
		}
		int j=1;
		this->temp=this->head->next;
		while(this->temp!=NULL)
		{
			if(j==i)
			{
				return LNode(NULL,this->temp->data);//返回临时对象
			}
			j++;
			this->temp=this->temp->next;
		}
		//return new LNode(NULL,0);
	}

	void LinkList::travel()
	{
		this->temp=this->head->next;
		int i=0;
		if(this->temp)
		{
			while(this->temp)
			{
				if(i%5==0)
				{
					std::cout<<std::endl;
				}
				std::cout<<this->temp->data<<'\t';
				this->temp=this->temp->next;
				i++;
			}
		}
		std::cout<<std::endl;
	}

	int LinkList::LocateElem(ElemType e)
	{
		int i=0;
		this->temp=this->head->next;
		while(this->temp!=NULL)
		{
			if(this->temp->data==e)
			{
				return i+1;
			}
			this->temp=this->temp->next;
			i++;
		}
		return 0;
	}

	bool LinkList::ListInsert(int i,ElemType num)
	{
		if(i<1||i>this->ListLength())
		{
			std::cerr<<"out of index!"<< std::endl;
		}
		int pos=1;
		this->temp=this->head->next;
		while(i!=pos)
		{
			pos++;
			this->temp=this->temp->next;
		}
		try
		{
			this->temp->next=new LNode(this->temp->next,num);
		}
		catch(...)
		{
			std::cout<<"ERROR!"<<std::endl;
			throw;
		}
		return true;
	}

	int LinkList::ListLength()
	{
		int cnt=0;
		this->temp=this->head->next;
		while(this->temp!=NULL)
		{
			cnt++;
			this->temp=this->temp->next;
		}
		return cnt;
	}

	bool LinkList::ListDelete(int pos)
	{
		int i=1;
		this->temp=this->head->next;
		while(i!=pos-1)
		{
			this->temp=this->temp->next;
		}
		try
		{
			LNode *q=this->temp;
			this->temp->next=this->temp->next->next;
			delete q;
			q=NULL;
		}
		catch(...)
		{
			std::cout<<"ERROR!!!"<<std::endl;
			throw;
		}
		return true;
	}
}