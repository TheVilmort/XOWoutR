#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool check(vector<string> vec_str)
{
	for (int i = 0; i < 3; i++) 
		if (vec_str[i * 3] == vec_str[i * 3 + 1] && vec_str[i * 3 + 1] == vec_str[i * 3 + 2]) //Горизонтальна перевірка
		{
			//cout << vec_str[i * 3] << " is win!";
			return 0; 			
		}
		else if (vec_str[i] == vec_str[i + 3] && vec_str[i + 3] == vec_str[i + 6]) //Вертикальна перевірка
		{
			//cout << vec_str[i] << " is win!";
			return 0; 
		}
		else if ((vec_str[2] == vec_str[4] && vec_str[4] == vec_str[6]) || (vec_str[0] == vec_str[4] && vec_str[4] == vec_str[8])) //Діагональна перевірка
		{
			//cout << vec_str[2] << " is win!";
			return 0; 	
		}
		else
		{
			return '-'; 
		}
}
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
	char choice;
	static size_t value;
	vector<string> battleGround{ "1","2","3","4","5","6","7","8","9"};
	ShowBG(battleGround);

//	cout <<"\n"<< "Who goes first? X or O?" << "\n";
//	cin >> choice;
//	choice == 'X'|| 'x'? value = 0 :  value = 1;

	for (; win == false && value < 9; )
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
			
			else if (battleGround[number - 1] == "X" || battleGround[number - 1] == "Y")
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
			if (!(check(battleGround)))
			{
				break;
			}

			
		}

	cout << "\n\n"<<"Game over!"<<"\n";

	return 0;
}


	
	





