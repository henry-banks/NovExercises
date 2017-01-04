#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int menu()
{
	cin.clear();

	printf("\nDo you want to:\n");
	printf("0. EXIT\n");
	printf("1. DISPLAY file\n");
	printf("2. WRITE to file\n");
	printf("3. CLEAR file\n");

	int choice;
	cin >> choice;
	printf("\n\n");

	return choice;
}

void display()
{
	fstream file;
	file.open("MyLog.txt", ios_base::in);
	if (file.is_open())
	{
		string temp;
		while (getline(file, temp))
			cout << temp << endl;
	}
	file.close();
	printf("\n\n");
}

void write()
{
	fstream file;
	file.open("MyLog.txt", ios_base::app);
	if (file.is_open()) 
	{
		printf("Input new text:\n");
		string temp;
		cin.ignore(1000, '\n');
		getline(std::cin, temp);

		file << temp;
	}
	else
		printf("Could not open file");

	file.close();
	printf("\n\n");
}

void clear()
{
	fstream file;
	file.open("MyLog.txt", ios_base::out);
	if (file.is_open())
		file.clear();
	file.close();
}

void main()
{
	int choice = -1;
	do {
		choice = menu();
		switch (choice)
		{
		case 0: printf("Exiting..."); break;
		case 1: display(); break;
		case 2: write(); break;
		case 3: clear(); break;
		default: printf("Try again\n");
		}
	} while (choice != 0);

	printf("\n\n");
	system("pause");
}