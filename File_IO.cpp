// File_IO.cpp : Defines the entry point for the console application.
// Author Duncan Reeves, CP2, C++

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <array>
#include "File_IO.h"

using namespace std;


const int SIZE = 100;
int main()
{
	ofstream writeMe;
	ifstream readMe;
	array <double, SIZE> Voltages;
	double dataStorer;
	string fileName = "C:\\Users\\sreeves\\Documents\\Visual Studio 2015\\Projects\\File_IO\\File_IO\\VoltFile.txt";
	string fileName2 = "C:\\Users\\sreeves\\Documents\\Visual Studio 2015\\Projects\\File_IO\\File_IO\\VoltFile2.txt";
	int NumOfVoltages = 0;
	char *tempString = "foo";

	readMe.open(fileName);
	if (readMe.fail())
	{
		cout << "Could not open the file.... check to see if it exists." << endl;
		return 0;
	}

	do
	{
		readMe.read(tempString, 6);
		//cout << tempString;

		readMe >> dataStorer;
		if (!readMe.fail())
		{
			Voltages[NumOfVoltages] = dataStorer;
			NumOfVoltages++;
		}
		else
		{
			cout << "There was an error in reading the file." << endl;
			return 0;
		}

	} while (!readMe.eof());


	cout << "The voltage values are..." << endl;
	for (int X = 0; X < NumOfVoltages; X++)
	{
		cout << Voltages[X] << endl;
	}



	writeMe.open(fileName2);
	{
		do
		{
			if (writeMe.fail())
			{
				cout << "There was an error in creating the new file." << endl;
				return 0;
			}
			else
			{
				for (int X = 0; X < NumOfVoltages; X++)
				{
					writeMe << Voltages[X] << endl;
				}
			}
		} while (!readMe.eof());
	}
	
    return 0;
}
