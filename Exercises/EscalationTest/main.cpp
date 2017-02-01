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

struct Monster
{
	Monster()
	{
		ID = typeID = XCoord = YCoord = normalX = normalY = 0;
	}
	unsigned short ID, typeID;
	float XCoord, YCoord;
	float normalX, normalY;
};

void main()
{
	fstream file;

	file.open("EscalationProgrammerTest.bin", ios_base::in, ios_base::binary);

	unsigned size;
	unsigned int entityNum;
	Monster *monsters = new Monster[150];


	int i = 0;
	if (file.is_open())
	{
		

		while (!file.eof() && file.peek() != EOF)
		{
			file.read((char*)&entityNum, sizeof(unsigned int));
			cout << entityNum << endl;

			if(i <= entityNum)
			{
				Monster temp;

				file.read((char*)&temp, sizeof(Monster));
				cout << temp.ID;
				cout << " " << temp.typeID;
				cout << " " << temp.XCoord;
				cout << " " << temp.YCoord;
				cout << " " << temp.normalX;
				cout << " " << temp.normalY;
				cout << "\n\n";

				monsters[i] = temp;
				i++;
			}	
		}
		

		printf("\nyes\n\n");
	}
	else printf("no\n\n");

	file.close();

	system("pause");
}