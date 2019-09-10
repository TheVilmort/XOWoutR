#include<iostream>
#include<string>
#include<vector>
using namespace std;

void ShowBG(vector<string> vec_str)
{
	for (size_t i = 0; i < vec_str.size(); i++)
	{
		if (i % 3 == 0)
		{
			cout << "\n";
		}
		cout << vec_str[i];
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	bool win = false;
	vector<string> battleGround(9, "-");
	ShowBG(battleGround);

	for (size_t value = 0; win == false && value < 9; )
	{
		
		string str_number;
		size_t number;
	

		cout << "\n\n" << "Enter number for change:";
		cin >> str_number;

			if (isdigit(str_number[0]))
			{
				number = atoi(str_number.c_str());
			}
			if (str_number.size() != 1)
			{
				system("cls");
				cout<<"Incorrect enter size! Try again!"<<"\n";
				ShowBG(battleGround);
			}
			else if (!(isdigit(str_number[0])))
			{
				system("cls");
				cout<<"You enterd a character, not a number!Try again!"<<"\n";
				ShowBG(battleGround);
			}
			else if (number == 0)
			{
				system("cls");
				cout<<"Number must be greater than 0!Try again!"<<"\n";
				ShowBG(battleGround);
			}
			else if (battleGround[number - 1] != "-")
			{
				system("cls");
				cout<<"This slot is already taken!Try again!"<<"\n";
				ShowBG(battleGround);
			}
			else if (!(value % 2))
			{
				system("cls");
				battleGround[number - 1] = "X";
				ShowBG(battleGround);
				++value;
			}
			else if (value % 2)
			{
				system("cls");
				battleGround[number - 1] = "O";
				ShowBG(battleGround);
				++value;
			}

	}
	cout << "\n\n"<<"Game over!"<<"\n";

	return 0;
}


	

	





