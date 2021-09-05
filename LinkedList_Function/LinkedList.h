#pragma once
#include <string>

struct Monster
{
	std::string name{ "" };
	int hp{ 0 };

	Monster* pNext{ nullptr };
};

struct LinkedList
{
	Monster* pHead{ nullptr };
	Monster* pTail{ nullptr };
};

Monster* CreateMonster(LinkedList& list, std::string name, int hp);
void PrintMonsters(const LinkedList& list);
int GetCountMonster(const LinkedList& list);
Monster* FindMonster(const LinkedList& list, std::string findName);
void DeleteAll(LinkedList& list);
bool Delete(LinkedList& list, std::string name);
void RecursivePrint(Monster* element);
Monster* Insert(LinkedList& list, std::string findName, std::string name, int hp);