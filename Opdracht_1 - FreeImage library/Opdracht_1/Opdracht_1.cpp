// Opdracht_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include "FreeImage.h"
#include "converter.h"
#include "histogram.h"

typedef unsigned char Byte;
using namespace std;

int main(int argc, char* argv[])
{
	converter c;
	histogram h;
	cout << "Enter filename with max 30 characters:" << endl;
	char s[30];
	cin.getline(s, 30);
	FreeImage_Initialise();

	FIBITMAP* bitmap = FreeImage_Load(FIF_BMP, s, BMP_DEFAULT);
	RGBQUAD color;

	if (!bitmap){
		exit(1);
	}

	FIBITMAP* gray_bitmap = FreeImage_Clone(bitmap);
	gray_bitmap = c.convertToGray(gray_bitmap, color);

	char output[30] = "grey_";
	strcat(output, s);
	std::cout << output << std::endl;
	//Image.WriteToFile(output);
	if (FreeImage_Save(FIF_BMP, gray_bitmap, output, 0)){
		cout << "Succesfully saved!!!!!!" << endl;
	}

	h.createHistogram256(gray_bitmap);
	h.createHistogram10(gray_bitmap);

	std::cin.get();
	return 0;
}

