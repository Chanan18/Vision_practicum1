// Opdracht_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FreeImage.h"

typedef unsigned char Byte;
using namespace std;

int main(int argc, char* argv[])
{
	
	cout << "Enter filename with max 30 characters:" << endl;
	char s[30];
	cin.getline(s, 30);
	FreeImage_Initialise();

	FIBITMAP* bitmap = FreeImage_Load(FIF_BMP, s, BMP_DEFAULT);
	RGBQUAD color;

	if (!bitmap){
		exit(1);
	}

	int HEIGHT = FreeImage_GetHeight(bitmap);
	int WIDTH = FreeImage_GetWidth(bitmap);
	double grayValue;

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(bitmap, i, j, &color);
			grayValue = (color.rgbRed * 0.30) +
				(color.rgbGreen * 0.59) +
				(color.rgbBlue * 0.11);
			color.rgbRed = color.rgbGreen = color.rgbBlue = grayValue;
			FreeImage_SetPixelColor(bitmap, i, j, &color);
		}
	}

		char output[30] = "grey_";
		strcat(output, s);
		std::cout << output << std::endl;
		//Image.WriteToFile(output);
		if (FreeImage_Save(FIF_BMP, bitmap, "lol.bmp", 0)){
			cout << "Succesfully saved!!!!!!" << endl;
		}
	std::cin.get();
	return 0;
}
