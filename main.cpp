#include <iostream>

int Add(int num1, int num2)
{
	return num1 + num2;
}

int test = 10;
//How arrays and 2D arrays are used
int numbers[] = { 1, 2, 3 };
int number2[10] = { 1, 2, 3 };
int numbers2D[3][3] = { {1, 2, 3},{4, 5, 6}, {7, 8, 9} };

int main()
{
	//this is output
	std::cout << "Gib" << std::endl;
	std::cout << "He likes" "\nBeans.";
	int age = 12;

	//How for loops are used
	for (int i : numbers)
	{
		std::cout << numbers[i] << std::endl;
	}

	//How string character are used
	char firstName[35] = "Bill";
	char lastName[35] = "";
	char fullName[64] = "";

	std::cout << firstName << std::endl;
	std::cin >> lastName;

	std::cout << firstName << " " << lastName;
	strcat_s(fullName, firstName);
	strcat_s(fullName, lastName);
	strcpy_s(firstName, lastName);

	std::cout << fullName;

	std::cin >> age;
	std::cout << "Your age is: " << age;
	//Pauses and waits for input
	system("pause");
	//Clears the screan
	system("cls");
	return 0;
}