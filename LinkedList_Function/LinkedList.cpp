#include <iostream>
#include "LinkedList.h"

// ���� : 
Monster* CreateMonster(LinkedList& list, std::string name, int hp)
{
	Monster* element = new Monster;

	element->name = name;
	element->hp = hp;

	if (list.pTail == nullptr)
	{
		list.pHead = element;
		list.pTail = element;
	}
	else
	{
		list.pTail->pNext = element;
		list.pTail = element;
	}

	return element;
}

// ��� : while ���� �̿��� ���� ���
void PrintMonsters(const LinkedList& list)
{
	Monster* element{ list.pHead };

	while (element != nullptr)
	{
		std::cout << element->name << " : " << element->hp << std::endl;
		element = element->pNext;
	}
}

// ��� : ��� ȣ���� �̿��� ���� ���
void RecursivePrint(Monster* element)
{
	// Base Case
	if (element == nullptr)
	{
		return;
	}
	// Recursive Case
	else
	{
		std::cout << element->name << " : " << element->hp << std::endl;
		RecursivePrint(element->pNext);
	}
}

int GetCountMonster(const LinkedList& list)
{
	Monster* monsters{ list.pHead };
	int count{};

	while (monsters != nullptr)
	{
		++count;
		monsters = monsters->pNext;
	}

	return count;
}

// �˻� : 
Monster* FindMonster(const LinkedList& list, std::string findName)
{
	Monster* element{ list.pHead };

	while (element != nullptr)
	{
		if (element->name == findName)
		{
			return element;
		}
		element = element->pNext;
	}

	return nullptr;
}

void DeleteAll(LinkedList& list)
{
	Monster* element{ list.pHead };

	while (element != nullptr)
	{
		Monster* next{ element->pNext };
		delete element;

		element = next;
	}

	list.pHead = list.pTail = nullptr;
}

bool Delete(LinkedList& list, std::string name)
{
	Monster* element{ list.pHead };
	Monster* previous{ nullptr };

	while (element != nullptr)
	{
		if (element->name == name)
		{
			break;
		}

		previous = element;
		element = element->pNext;
	}

	if (element == nullptr)
	{
		return false;
	}

	// ������ ���Ұ� �ϳ� �ۿ� ���� ��
	if (list.pHead == list.pTail)
	{
		list.pHead = list.pTail = nullptr;
	}
	// 
	else if (list.pHead == element)
	{
		list.pHead = element->pNext;
	}
	else if (list.pTail == element)
	{
		list.pTail = previous->pNext = nullptr;
	}
	else
	{
		previous->pNext = element->pNext->pNext;
	}

	delete element;

	return false;
}

// ���� : ����ڰ� ���ϴ� ��ġ�� ����
Monster* Insert(LinkedList& list, std::string findName, std::string name, int hp)
{
	Monster* search{ list.pHead };			// list Ž���� ���� ���� ����
	Monster* newMonster = new Monster;		// ���ο� list ����

	// ���� �Է�
	newMonster->name = name;
	newMonster->hp = hp;

	// Traveres : ��ġ�� ��ġ ������ŭ Ž��
	while(search->name != findName)
	{
		search = search->pNext;
	}

	// ����� ���Ұ� �ϳ� �ۿ� ���� ��
	if (list.pHead == list.pTail)
	{
		list.pTail = newMonster;
	}
	// ������ ó�� ��ġ�� ������ ��
	else if (list.pHead == search)
	{
		newMonster->pNext = search->pNext;
		list.pHead->pNext = newMonster;
	}
	// ������ ������ ��ġ�� ������ ��
	else if(list.pTail == search)
	{
		newMonster->pNext = list.pHead->pNext;
		list.pHead->pNext = newMonster;
	}
	// ������ �߰��� ������ ��
	else
	{
		newMonster->pNext = search;
	}

	return newMonster;
}