#include <iostream>
#include <time.h>
#include <string>
#include <ostream>
#include <istream>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

template<class T>
class Frame;

template<class T>
class Player
{
public:
	friend Frame<T>;
	Player();
	~Player();
	void push_back(T x, T y);
	int Size();
	void move(int key);
	void move();
	void Render();
	void Step();
	void Orientation(int key);
	bool is_collision();

private:
	

	template<class T>
	class Node
	{
	public:
		T x;
		T y;
		Node* pNext;
		Node(T x = T(), T y = T(), Node* pNext = nullptr)
		{
			this->x = x;
			this->y = y;
			this->pNext = pNext;
		}
		~Node()
		{
			delete x, y;
		}
	};

	Node<T>* head;
	int size;
	int orientation;
	int speed;

};

template<class T>
Player<T>::Player()
{
	head = nullptr;
	size = 0;
	orientation = 0;
	speed = 400;
}

template<class T>
Player<T>::~Player()
{
}

template<class T>
int Player<T>::Size()
{
	return size;
}

template<class T>
void Player<T>::push_back(T x, T y)
{
	if (this->head == nullptr)
	{
		this->head = new Node<T>(x,y);
	}
	else
	{
		Node<T>* current = head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(x,y);
	}
	size++;
}

template<class T>
void Player<T>::move()
{
	switch (orientation)
	{
	case 0:
		
			move(72);
		
		break;
	case 1:
		
			move(80);
		
		
		break;
	case 2:
		
			move(75);
		
		break;
	case 3:
		
		
			move(77);
		
		break;
	default:
		break;
	}
}

template<class T>
void Player<T>::Orientation(int key)
{
	switch (key)
	{

	case 72: 
		if (orientation != 1)
		{
			orientation = 0;
		}
		break;
	case 80: 
		if (orientation != 0)
		{
			orientation = 1;
		}
		break;
	case 75: 
		if (orientation != 3)
		{
			orientation = 2;
		}
		break;
	case 77: 
		if (orientation != 2)
		{
			orientation = 3;
		}
		break;
	default:
		break;
	}
}

template<class T>
void Player<T>::move(int key)
{
	Node<T>* current = this->head->pNext;


	int* x = new int[size];
	int* y = new int[size];
	int i = 0;
	x[i] = this->head->x;
	y[i] = this->head->y;
	i++;

	while (current->pNext != nullptr)
	{
		x[i] = current->x;
		y[i] = current->y;
		i++;
		current = current->pNext;

	}
	i++;
	x[i] = current->x;
	y[i] = current->y;
	i = 0;



	current = this->head->pNext;
	

	switch (key)
	{

	case 72: head->y--;
		orientation = 0;
		while (current->pNext != nullptr)
		{
			current->x = x[i];
			current->y = y[i];
			i++;
			current = current->pNext;
		}
		current->x = x[i];
		current->y = y[i];

		delete[] x;
		delete[] y;
		break;
	case 80: head->y++;
		orientation = 1;
		while (current->pNext != nullptr)
			while (current->pNext != nullptr)
			{
				current->x = x[i];
				current->y = y[i];
				i++;
				current = current->pNext;
			}
			current->x = x[i];
			current->y = y[i];
			delete[] x;
			delete[] y;
		break;
	case 75: head->x--;
		orientation = 2;
		while (current->pNext != nullptr)
		{
			
			current->x = x[i];
			current->y = y[i];
			i++;
			current = current->pNext;
			
		}
		current->x = x[i];
		current->y = y[i];

		delete[] x;
		delete[] y;
		break;
	case 77: head->x++;
		orientation = 3;
		while (current->pNext != nullptr)
		{
			current->x = x[i];
			current->y = y[i];
			i++;
			current = current->pNext;
			
		}
		current->x = x[i];
		current->y = y[i];

		delete[] x;
		delete[] y;
		break;
	default:
		delete[] x;
		delete[] y;
		break;
	}

	

}

template<class T>
void Player<T>::Render()
{
	const int WIDTH = 30;
	const int HIGHT = 20; 

	Node<T>* current = this->head;
	system("cls");
	string str = "";
	string strLine = "";
	bool is_player = false;

	strLine += char(201);
	for (int i = 0; i < WIDTH; i++)
	{
		strLine += char(205);
	}
	strLine += char(187);
	cout << strLine << endl;

	for (int i = 0; i < HIGHT; i++)
	{
		str = char(186);
		for (int j = 0; j < WIDTH; j++)
		{

			is_player = false;
			bool porka = true;
			while (porka)
			{
				if (current->pNext == nullptr)
				{
					porka = false;
				}
				if (i == current->y && j == current->x)
				{
					str += '#';
					is_player = true;
					break;
				}

				current = current->pNext;
			}
			current = this->head;
			if (!is_player)
			{
				str += ' ';
			}
		}
		str += char(186);
		cout << str << endl;
	}
	strLine = "";
	strLine += char(200);
	for (int i = 0; i < WIDTH; i++)
	{
		strLine += char(205);
	}
	strLine += char(188);
	cout << strLine << endl;

	cout << " SCORE: " << this->Size() << endl;
}

template<class T>
bool Player<T>::is_collision()
{
	Node<T>* current = this->head->pNext;
	


	while (current->pNext != nullptr)
	{
		if (this->head->x == current->x && this->head->y == current->y)
		{
			return true;
		}
		current = current->pNext;

	}
	if (this->head->x == current->x && this->head->y == current->y)
	{
		return true;
	}

	return false;
}

template<class T>
void Player<T>::Step()
{
	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(speed));
		move();
		Render();
		if (is_collision()) { break; }
	}
}

int main()
{
	while (true)
	{
		Player<int> pl;
		thread th([&]()
			{
				pl.Step();
			});

		for (int i = 5; i < 20; i++)
		{
			pl.push_back(i, 15);
		}

		pl.Render();

		while (true)
		{

			if (_getch() != 0)
			{
				pl.Orientation(_getch());

			}
			if (pl.is_collision())
			{
				break;
			}

		}


		th.join();
	}
	
	return 0;
}