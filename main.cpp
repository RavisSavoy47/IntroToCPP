#include <iostream>

int Add(int num1, int num2)
{
	return num1 + num2;
}

int test = 10;
int numbers[] = { 1, 2, 3 };
int number2[10] = { 1, 2, 3 };

int main()
{
	//this is output
	std::cout << "Gib" << std::endl;
	std::cout << "He likes" "\nBeans.";
	int age = 12;
	int health = 10;
	int damage = 10;
	int speed = 10;
	bool isAlive = health;

	for (int i : numbers)
	{
		std::cout << numbers[i] << std::endl;
	}

	std::cin >> age;
	std::cout << "Your age is: " << age;
	return 0;
}