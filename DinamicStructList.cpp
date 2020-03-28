#include"Stdafx.h"
#pragma warning(disable : 4996)

using namespace std;
struct List
{
	int x;
	List* Next;
};
int main(int argc, char** argv)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(0, "");

	List* Begin = nullptr;
	char Key{};
	bool flag = false;
	while (TRUE)
	{
		do {
			printf("\nEnter the number - the mode of "
				"operations with Lists: "
				"\n		1 - FORMATION OF THE LIST"
				"\n		2 - VIEWING OF CONTENTS OF THE LIST"
				"\n		3 - Remove the element from the begin of List"
				"\n		4 - Remove the element from the midle of list"
				"\n		5 - Remove the element from the end of List"
				"\n		6 - ADD THE ELEMENT IN THE BEGIN OF LIST"
				"\n		7 - ADD THE ELEMENT IN THE END OF LIST"
				"\n		8 - ADD THE ELEMENT AFTER ELEMENT-KEY OF LIST"
				"\n		9 - END OF WORK\n"
			);
			fflush(stdin);
			scanf("%c", &Key);
			system("cls");
			(Key == '1') ? flag == true : flag;
			if (Key != '1')
			{
				cout << "\nСписок еще не создан, перед тем как выполнять какие либо операци "
					"над списком выберите команду '1'\n";
			}

		} while (!flag);
		switch (Key)
		{
		case '1':
			system("cls");
			Begin = CreateList();
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '2':
			system("cls");
			DisplayList(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '3':
			system("cls");
			RemoveTermBegin(&Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '4':
			system("cls");
			RemoveTermTag(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '5':
			system("cls");
			RemoveTermEnd(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '6':
			system("cls");
			AddTermBegin(&Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '7':
			system("cls");
			AddTermEnd(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '8':
			system("cls");
			AddTermTag(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '9':
			system("cls");
			FreeList(&Begin);
			DisplayList(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			return 0;
		default:
			system("cls");
			cout << "\nIncorrect input!!! Try again!!!\n";
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			if (Begin!=nullptr)
				FreeList(&Begin);
			break;
		}
	}
}

List* CreateList(void)
{
	List* Begin = nullptr, * Previos/*предыдущий*/ = nullptr,
		* Current = nullptr;
	char ok = 'y';

	while (ok == 'y')
	{
		cout << "\nEnter the numbers of List: ";
		Current = (List*)malloc(sizeof(List));

		if (Begin == nullptr)
			Begin = Current;
		else
			Previos->Next = Current;

		Previos = Current;
		scanf("%d", &Current->x);
		fflush(stdin);
		printf("\nContinue? (Y / N): ");
		scanf("%c", &ok);
	}
	Previos->Next = nullptr;
	return Begin;
}


void DisplayList(List* Begin)
{
	List* Current = Begin;

	if (Begin == nullptr)
	{
		cout << "List is empty\n";
		return;
	}
	cout << "\nThe List of numbers: \n";
	while (Current)
	{
		printf("%d", Current->x);
		Current = Current->Next;
	}
	cout << endl;
}

void RemoveTermBegin(List** Begin)
{
	List** Current = Begin;
	*Begin = (*Current)->Next;
	free(Current);
}

void RemoveTermTag(List* Begin)
{
	List* Current = Begin, * Previos = Current;
	int NumberTag;
	cout << "\nEnter number-key: ";
	scanf("%d", &NumberTag);

	while (Current)
	{
		if (Current->x == NumberTag)
		{
			Previos->Next = Current->Next;
			free(Current);
			Current = Previos->Next;
		}
		else
		{
			Previos = Current;
			Current = Current->Next;
		}
	}
}

void RemoveTermEnd(List* Begin)
{
	List* Current = Begin, * Previos = nullptr;

	while (Current->Next)
	{
		Previos = Current;
		Current = Current->Next;
	}

	Previos->Next = NULL;
	free(Current);
}

void AddTermBegin(List** Begin)
{
	List* Current = (List*)malloc(sizeof(List));
	cout << "\nEnter number: ";
	scanf("%d", &Current->x);

	Current->Next = *Begin;
	*Begin = Current;
}


void AddTermEnd(List* Begin)
{
	List* Current = Begin, * Previos = nullptr;

	while (Current)
	{
		Previos = Current;
		Current = Current->Next;
	}

	Current = (List*)malloc(sizeof(List));
	Previos->Next = Current;

	cout << "\nEnter the number: \n";
	scanf("%d", &Current->x);
	Current->Next = nullptr;
}

void AddTermTag(List* Begin)
{
	List* Current = Begin, * Previos = Current;
	int NumberTag;

	cout << "\nEnter number-tag: ";
	cin >> NumberTag;

	while (Current)
	{

		if (Current->x == NumberTag)
		{
			Previos = Current;
			Current = (List*)malloc(sizeof(List));
			Current->Next = Previos->Next;
			Previos->Next = Current;
			cout << "\nEnter the number: \n";
			cin >> Current->x;
			break;
		}
		else
		{
			Previos = Current;
			Current = Current->Next;
		}
	}
}

void FreeList(List** Begin)
{
	List* Current = *Begin;

	while (Current)
	{
		*Begin = (*Begin)->Next;
		free(Current);
		Current = *Begin;
	}
}


