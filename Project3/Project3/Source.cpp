#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string read = "C:\\Users\\Maxim\\Downloads\\f_4495eb87e64417ef.txt";
	string write = "C:\\Users\\Maxim\\Downloads\\332211.txt";
	fstream fsRead;
	fstream fsWrite;
	string msg = "";
	string str = "";
	fsRead.open(read, fstream::in);
	fsWrite.open(write, fstream::out | fstream::app);
	if (!fsRead.is_open())
	{
		
	}
	else
	{
		while (!fsRead.eof())
		
		//for (int i = 0; i < 100; i++)
		{

			msg = "";
			str = "";
			fsRead >> msg;
			if (msg == "X:") {
				str += "v\t";
				fsRead >> msg;
				str += msg + "\t";
				fsRead >> msg;
				fsRead >> msg;
				str += msg + "\t";
				fsRead >> msg;
				fsRead >> msg;
				str += msg + "\t";
				fsRead >> msg;
				fsRead >> msg;

			}
			fsWrite << str << "\n";
			//cout << msg << endl;

		}
	}
	fsRead.close();
	return 0;
}