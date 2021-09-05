#include <iostream>
#include "LinkedList.h"

// 생성 : 
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

// 출력 : while 문을 이용한 몬스터 출력
void PrintMonsters(const LinkedList& list)
{
	Monster* element{ list.pHead };

	while (element != nullptr)
	{
		std::cout << element->name << " : " << element->hp << std::endl;
		element = element->pNext;
	}
}

// 출력 : 재귀 호출을 이용한 몬스터 출력
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

// 검색 : 
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

	// 생성된 원소가 하나 밖에 없을 때
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

// 삽입 : 사용자가 원하는 위치에 삽입
Monster* Insert(LinkedList& list, std::string findName, std::string name, int hp)
{
	Monster* search{ list.pHead };			// list 탐색을 위한 변수 생성
	Monster* newMonster = new Monster;		// 새로운 list 생성

	// 정보 입력
	newMonster->name = name;
	newMonster->hp = hp;

	// Traveres : 배치할 위치 이전만큼 탐색
	while(search->name != findName)
	{
		search = search->pNext;
	}

	// 저장된 원소가 하나 밖에 없을 때
	if (list.pHead == list.pTail)
	{
		list.pTail = newMonster;
	}
	// 원소의 처음 위치에 저장할 때
	else if (list.pHead == search)
	{
		newMonster->pNext = search->pNext;
		list.pHead->pNext = newMonster;
	}
	// 원소의 마지막 위치에 저장할 때
	else if(list.pTail == search)
	{
		newMonster->pNext = list.pHead->pNext;
		list.pHead->pNext = newMonster;
	}
	// 원소의 중간에 저장할 때
	else
	{
		newMonster->pNext = search;
	}

	return newMonster;
}