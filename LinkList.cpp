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
	LinkList();                      //����һ��������;
	~LinkList();                  //����һ��������;
	void CreateLinkList(int n);   //����һ��������
	void TravalLinkList();        //�������Ա�
	int GetLength();              //��ȡ���Ա���
	bool IsEmpty();               //�жϵ������Ƿ�Ϊ��
	Node * Find(int data); //���ҽڵ�
	void InsertElemAtEnd(int data);            //��β������ָ����Ԫ��
	void InsertElemAtIndex(int data, int n);    //��ָ��λ�ò���ָ��Ԫ��
	void InsertElemAtHead(int data);           //��ͷ������ָ��Ԫ��
	void DeleteElemAtEnd();       //��β��ɾ��Ԫ��
	void DeleteAll();             //ɾ����������
	void DeleteElemAtPoint(int data);     //ɾ��ָ��������
	void DeleteElemAtHead();      //��ͷ��ɾ���ڵ�
private:
	Node * head;              //ͷ���
};

LinkList::LinkList()
{
	head = new Node;  //����ͷ�ڵ�
	head->value = 0;  // ����ͷ�ڵ���ֵ
	head->next = nullptr; 
}
LinkList::~LinkList()
{
	delete head; //ɾ��ͷ�ڵ�
}

void LinkList::CreateLinkList(int n)
{
	Node *pnew, *ptemp;  //���������ڵ�
	ptemp = head;       //��ͷ�ڵ��ֵ����ptemP
	if (n < 0)
	{
		cout << "����ڵ��������" << '\n';
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++)
	{
		pnew = new Node; 
		pnew->value = i;
		pnew->next = NULL; //�½ڵ���һ����ַΪNULL
		ptemp->next = pnew; //��ǰ�ڵ����һ���ڵ���Ϊ�½ڵ�
		ptemp = pnew;     // �½ڵ�����Ϊ��ǰ�ڵ�

	}
}

void LinkList::TravalLinkList()
{
	if (head == NULL || head->next == NULL)
	{
		cout << "����Ϊ�ձ�" << '\n';

	}
	Node *p = head;  //����һ��ͷָ��
	while (p->next != NULL)  //��ָ�����һ����ַ��Ϊ��ʱ
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
		cout << "��������" << '\n';
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
		q = p;  //β���ڵ�ǰ��һ���ڵ�
		p = p->next;  //β���ڵ�
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
		cout << "������Ϊ�ձ�" << '\n';
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















