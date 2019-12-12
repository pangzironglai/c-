#include<iostream>
using namespace std;

struct Node
{
	int value;
	Node *next;

};

class LinkList
{
public:
	LinkList();                      //构建一个单链表;
	~LinkList();                  //销毁一个单链表;
	void CreateLinkList(int n);   //创建一个单链表
	void TravalLinkList();        //遍历线性表
	int GetLength();              //获取线性表长度
	bool IsEmpty();               //判断单链表是否为空
	Node * Find(int data); //查找节点
	void InsertElemAtEnd(int data);            //在尾部插入指定的元素
	void InsertElemAtIndex(int data, int n);    //在指定位置插入指定元素
	void InsertElemAtHead(int data);           //在头部插入指定元素
	void DeleteElemAtEnd();       //在尾部删除元素
	void DeleteAll();             //删除所有数据
	void DeleteElemAtPoint(int data);     //删除指定的数据
	void DeleteElemAtHead();      //在头部删除节点
private:
	Node * head;              //头结点
};

LinkList::LinkList()
{
	head = new Node;  //定义头节点
	head->value = 0;  // 定义头节点数值
	head->next = nullptr; 
}
LinkList::~LinkList()
{
	delete head; //删除头节点
}

void LinkList::CreateLinkList(int n)
{
	Node *pnew, *ptemp;  //定义两个节点
	ptemp = head;       //讲头节点的值赋予ptemP
	if (n < 0)
	{
		cout << "输入节点个数有误" << '\n';
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++)
	{
		pnew = new Node; 
		pnew->value = i;
		pnew->next = NULL; //新节点下一个地址为NULL
		ptemp->next = pnew; //当前节点的下一个节点设为新节点
		ptemp = pnew;     // 新节点设置为当前节点

	}
}

void LinkList::TravalLinkList()
{
	if (head == NULL || head->next == NULL)
	{
		cout << "链表为空表" << '\n';

	}
	Node *p = head;  //定义一个头指针
	while (p->next != NULL)  //当指针的下一个地址不为空时
	{
		p = p->next;
		cout << p->next << '\n';
	}
}

int LinkList::GetLength()
{
	Node * p = head;
	int count = 0;
	while (p->next != nullptr)
	{
		count++;
		p = p->next;
	}
	return count;
}

Node *LinkList::Find(int data)
{
	Node*p = head;
	while (p->next != nullptr)
	{
		if (p->value == data)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void LinkList::InsertElemAtEnd(int data)
{
	 Node *newNode = new Node;
	 Node *p = head;
	 newNode->value = data;
	 newNode->next = nullptr;
	 if (head == nullptr) head = newNode;
	 else
	 {
		 while (p->next != nullptr)
		 {
			 p = p->next;
		 }
		 p->next = newNode;
	 }
	 
}

void LinkList::InsertElemAtIndex(int data, int n)
{
	if (n<1 || n >GetLength())
	{
		cout << "输入有误" << '\n';
	}
	Node * newNode = new Node;
	Node * p = head;
	newNode->value = data;
	newNode->next = nullptr;
	for (int i = 1; i < n; i++)
	{
		p = p->next;
	}
	newNode->next = p->next;
	p->next = newNode;
}

void LinkList::InsertElemAtHead(int data)
{
	Node *newNode = new Node;
	newNode->value = data;
	newNode->next = nullptr;
	if (head == NULL)
	{
		head = newNode;
	}
	Node *p = head;
	newNode->next = p->next;
	p->next = newNode;
}

void LinkList::DeleteElemAtEnd()
{
	Node *p = head;
	Node *q = head;
	while (p->next != nullptr)
	{
		q = p;  //尾部节点前的一个节点
		p = p->next;  //尾部节点
	}
	delete p;
	p = NULL;
	q->next = NULL;

	
}

void LinkList::DeleteAll()
{
	Node * p = head->next;
	while (p != nullptr)
	{
		DeleteElemAtEnd();
	}
	p->next = NULL;

}

void LinkList::DeleteElemAtPoint(int data)
{
	Node * ptemp = Find(data);
	if (ptemp == head->next)
	{
		DeleteElemAtHead();
	}
	else
	{
		Node * p = head;
		while (p->next != ptemp)
		{
			p = p->next;
		}
		p->next = ptemp->next;
		delete ptemp;
		ptemp = NULL;
	}
}
void LinkList::DeleteElemAtHead()
{
	Node * p = head;
	if (p == NULL || p->next == NULL)
	{
		cout << "该链表为空表" << '\n';
	}
	else
	{
		Node * ptemp = new Node;
		p = p->next;
		ptemp = p->next;
		delete p;
		head->next = ptemp;
	}
}











int main()
{/*
	Node *Node1 = new Node;
	Node *Node2 = new Node;
	Node *Node3 = new Node;
	Node *Node4 = new Node;
	Node *Node5 = new Node;
	Node1->value = 1;
	Node2->value = 2;
	Node3->value = 3;
	Node4->value = 4;
	Node5->value = 5;
	Node1->next = Node2;
	Node2->next = Node3;
	Node3->next = Node4;
	Node4->next = Node5;
*/
	LinkList ll;
	ll.CreateLinkList(6);
	ll.DeleteElemAtPoint(3);



	
}















