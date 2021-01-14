#include<iostream>
#define ElemType int
#define ElemLocate int

namespace D_S
{
	class LNode
	{
		private:
			ElemType data;
			LNode * next;
		public:
			LNode(LNode *p=NULL, ElemType e=0)
			{
				this->next=p;
				this->data=e;
			}
			void getData()
			{
				std::cout<<this->data<<std::endl;
			}
			friend class LinkList;

	};

	class LinkList
	{
		private:
			LNode * head;
			LNode * temp;
		public:
			LinkList(int i,int num);//1头插，2尾插
			~LinkList()
			{
				while(this->temp!=NULL)
				{
					this->temp=this->head->next;
					head->next=head->next->next;
					delete this->temp;
				}
			}
			LNode GetElem(int i); 
			int LocateElem(ElemType e);
			bool ListInsert(int pos,ElemLocate num);//type 为1前插 ，为2后插
			bool ListDelete(int pos);
			int ListLength();
			void travel();


	};
}