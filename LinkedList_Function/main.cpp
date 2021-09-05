#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList myList;

	CreateMonster(myList, "Wolf", 10);
	CreateMonster(myList, "Slime", 5);
	CreateMonster(myList, "BOSS", 1000);
	PrintMonsters(myList);

	std::cout << "------------------" << std::endl;
	Insert(myList, "Wolf", "Demon", 7);
	PrintMonsters(myList);

	//RecursivePrint(myList.pHead);
	// std::cout << "Count : " << GetCountMonster(myList) << std::endl;

	/*if (FindMonster(myList, "Slime") != nullptr)
	{
		std::cout << "Found!" << std::endl;
	}
	else
	{
		std::cout << "Not Found!" << std::endl;
	}*/


	Delete(myList, "Slime");
	// PrintMonsters(myList);
	// RecursivePrint(myList.pHead);
	Delete(myList, "Wolf");

	DeleteAll(myList);
}