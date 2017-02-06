#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "vec2.h"

using namespace std;

//Read from file
struct EntityRead
{
	EntityRead()
	{
		ID = typeID = XCoord = YCoord = normalX = normalY = 0;
	}
	unsigned short ID, typeID;
	float XCoord, YCoord;
	float normalX, normalY;
};

struct Entity
{
	Entity()
	{
		//zero out everything
		ID = typeID = 0;
		pos = normal = { 0,0 };
		colRad = fov = -1;
	}
	Entity(EntityRead in)
	{
		ID = in.ID;
		typeID = in.typeID;
		pos = { in.XCoord, in.YCoord };
		normal = { in.normalX, in.normalY };
		//Set Collision Radius, Name, and Field of View based on typeID
		switch (typeID)
		{
		case 0:
			name = "Health Pickup";
			colRad = 10;
			fov = -1;
			break;
		case 1:
			name = "Chest";
			colRad = 20;
			fov = -1;
			break;
		case 2:
			name = "Trap";
			colRad = 64;
			fov = -1;
			break;
		case 3:
			name = "Troll";
			colRad = 12;
			fov = 45;
			break;
		case 4:
			name = "Imp";
			colRad = 10;
			fov = 65;
			break;
		case 5:
			name = "Ogre";
			colRad = 25;
			fov = 90;
			break;
		default:
			name = "ERROR";
			colRad = -1;
			fov = -1;
			break;
		}
	}

	string name;
	unsigned short ID, typeID;
	vec2 pos, normal;
	int colRad, fov;
};
struct EntityCol : Entity
{
	EntityCol(Entity in)
	{
		ID = in.ID;
		typeID = in.ID;
		pos = in.pos;
		normal = in.normal;
		colRad = in.colRad;
		fov = in.fov;
	}

	//List of things that this entity is colliding with
	vector<Entity> colList;
};

int populate(vector<Entity> &entities)
{
	ifstream file;
	file.open("EscalationProgrammerTest.bin", ios_base::in | ios_base::binary);

	unsigned int entityNum;
	int count = 0;

	if (file.is_open())
	{
		file.read((char*)&entityNum, sizeof(unsigned int));
		cout << entityNum << endl;

		cout << sizeof(unsigned short) << " " << sizeof(float) << endl;
		while (!file.eof() && file.peek() != EOF)
		{
			int pos1 = file.tellg();
			cout << "pos1: " << pos1 << endl;
			//Position 1 shoudl ALWAYS be a factor of 32 (+ 4 because of initial int)
			if (pos1 != (32 * count) + 4)
			{
				int tempOffset = ((32 * count) + 4) - pos1;
				file.seekg(tempOffset, ios::cur);
				pos1 = file.tellg();
				cout << "new pos1: " << pos1 << endl;
			}

			EntityRead temp;
			file.read((char*)&temp, sizeof(EntityRead));
			cout << temp.ID;
			cout << " " << temp.typeID;
			cout << " " << temp.XCoord;
			cout << " " << temp.YCoord;
			cout << " " << temp.normalX;
			cout << " " << temp.normalY;
			int pos2 = file.tellg();
			cout << endl << "pos2: " << pos2 << endl;

			//further correction
			int offset = (pos2 - pos1) - 20;
			cout << "offset: " << offset;
			file.seekg((12 - offset), ios::cur);

			entities.push_back(temp);
			cout << "\n\n";
			count++;
		}
		printf("Populate Succeeded.\n\n");
	}
	else
		printf("Populate Failed.\n\n");

	file.close();
	return count;
}
void printEntity(Entity e)
{
	cout << e.ID << ": ";
	switch (e.typeID)
	{
	case 0:
		printf("Health Pickup - Collision Radius: 10\n"); break;
	case 1:
		printf("Chest - Collision Radius: 20\n"); break;
	case 2:
		printf("Trap - Collision Radius: 64\n"); break;
	case 3:
		printf("Troll - Collision Radius: 12, FOV: 45 deg\n"); break;
	case 4:
		printf("Imp - Collision Radius: 65, FOV: 10 deg\n"); break;
	case 5:
		printf("Ogre - Collision Radius: 25, FOV: 90 deg\n"); break;
	default:
		printf("N\\A\n"); break;
	}
	cout << "X-Coord: " << e.pos.x << ", Y-Coord: " << e.pos.y
		 << "\nX-Normal: " << e.normal.x << ", Y-Normal: " << e.normal.y << endl;
}
void logEntity(Entity e, ofstream& file)
{
	file << e.ID << ": ";
	switch (e.typeID)
	{
	case 0:
		file << "Health Pickup - Collision Radius: 10\n"; break;
	case 1:
		file << "Chest - Collision Radius: 20\n"; break;
	case 2:
		file << "Trap - Collision Radius: 64\n"; break;
	case 3:
		file << "Troll - Collision Radius: 12, FOV: 45 deg\n"; break;
	case 4:
		file << "Imp - Collision Radius: 65, FOV: 10 deg\n"; break;
	case 5:
		file << "Ogre - Collision Radius: 25, FOV: 90 deg\n"; break;
	default:
		file << "N\\A\n"; break;
	}
	file << "X-Coord: " << e.pos.x << ", Y-Coord: " << e.pos.y
		<< "\nX-Normal: " << e.normal.x << ", Y-Normal: " << e.normal.y << endl;
}
vector <EntityCol> checkCollision(vector<Entity> entities)
{
	//THe console gets filled up oututting all of this so I'm going ot write it all to a log
	ofstream file;
	file.open("overlap.txt", ios::out);
	printf("Outputting to overlap.txt...\n\n");

	vector <EntityCol> out;
	int count = 0;
	for (int i = 0; i < entities.size(); i++)
	{
		bool isColliding = false;
		EntityCol e(entities[i]);
		Entity temp = entities[i];
		vec2 pos1 = e.pos;
		for (int j = 0; j < entities.size(); j++)
		{
			Entity f = entities[j];
			vec2 pos2 = f.pos;
			vec2 pos = abs(pos1 - pos2);
			if (pos.x <= e.colRad || pos.y <= e.colRad)
			{
				isColliding = true;
				e.colList.push_back(f);
			}
		}
		if (isColliding)
		{
			//printf("\n\n\n");
			file << "\n\n\n";
			//printEntity(temp);
			logEntity(temp, file);
			file << "Colliding Entities:\n\n";
			for (int i = 0; i < e.colList.size(); i++)
				//printEntity(e.colList[i]);
				logEntity(e.colList[i], file);

			out.push_back(e);
		}
	}
	file.close();
	printf("Output complete.\n");
	return out;
}
void fovTest()
{
	//SHIT
}


int menu()
{
	int choice = 0;
	printf("MAIN MENU\n");
	printf("---------\n");
	printf("0. Exit\n");
	printf("1. Populate array\n");
	printf("2. Print entity array\n");
	printf("3. Print overlap list (WARNING: Takes a long time)\n");
	printf("4. FOV test\n");
	
	printf("\nChoice: ");
	cin >> choice;

	return choice;
}

void main()
{
	vector<Entity> entities;
	vector <EntityCol> overlapping;

	int choice = -1;
	while (choice != 0)
	{
		choice = menu();
		switch (choice)
		{
		case 0:
			break;
		case 1:
			populate(entities); break;
		case 2:
			for (int i = 0; i < entities.size(); i++)
			{
				printEntity(entities[i]);
				printf("\n");
			}
			break;
		case 3:
			overlapping = checkCollision(entities); break;
		case 4:
			//FOV test
			break;
		default:
			break;
		}
		printf("\n\n");
	}
	system("pause");
}