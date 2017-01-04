#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person
{
	char *name;
	unsigned ID;
	unsigned age;
};

void main()
{
	fstream file;

	file.open("EscalationProgrammerTest.bin", ios_base::in, ios_base::binary);

	unsigned size;
	Person *people;

	if (file.is_open())
	{
		int i = 0;
		while (!file.eof() && file.peek() != EOF)
		{
			file.read((char*)&size, sizeof(int));
			people = new Person[size];
			file.read((char*)people, sizeof(Person) * size);

			cout << char(&people[i].name) << " " << unsigned(people[i].ID) << " " << people[i].age << endl;
			i++;

			for (int i = 0; i < sizeof(people); i++)
			{
				cout << &people[i].name << " " << unsigned(people[i].ID) << " " << people[i].age << endl;
			}
		}
		

		printf("\nyes\n\n");
	}
	else printf("no\n\n");

	file.close();

	system("pause");
}