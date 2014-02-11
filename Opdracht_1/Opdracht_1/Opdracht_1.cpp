// Opdracht_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "EasyBMP.h"
#include <string>

typedef unsigned char Byte;
using namespace std;

int main(int argc, char* argv[])
{
	
	cout << "Enter filename with max 30 characters:" << endl;
	char s[30];
	cin.getline(s, 30);

	//char* s = std::cin;

	BMP Image;
	Image.ReadFromFile(s);
	int height = Image.TellHeight();
	int width = Image.TellWidth();

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			double Temp = 0.30*(Image(x, y)->Red) + 0.59*(Image(x, y)->Green) + 0.11*(Image(x, y)->Blue);
			Image(x, y)->Red = (Byte)Temp;
			Image(x, y)->Green = (Byte)Temp;
			Image(x, y)->Blue = (Byte)Temp;
		}
	}
	



	Image.SetBitDepth(8);
	CreateGrayscaleColorTable(Image);
	char output[30] = "grey_";
	strcat(output, s);
	std::cout << output << std::endl;
	Image.WriteToFile(output);

	std::cin.get();
	return 0;
}
