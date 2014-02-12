/* ========================================================================== */
/*                                                                            */
/*   histogram.cpp                                                            */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include "stdafx.h"
#include "histogram.h"
#include <iostream>

void histogram::createHistogram256(FIBITMAP* gray_bitmap){
	int HEIGHT = FreeImage_GetHeight(gray_bitmap);
	int WIDTH = FreeImage_GetWidth(gray_bitmap);
	int totalPixels = 0;
	float normalize;
	RGBQUAD color;
	ofstream histogramFile;
	int histogram_array[256];
	histogramFile.open("histogram256.csv", ios::out);

	for (int i = 0; i < 256; i++){
		histogram_array[i] = 0;
	}

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(gray_bitmap, i, j, &color);
			histogram_array[color.rgbRed] ++;
		}
	}

	for (int i = 0; i < 256; i++)
		totalPixels += histogram_array[i];

	for (int i = 0; i < 256; i++){
		normalize = histogram_array[i] / float(totalPixels);
		histogramFile << i << "," << normalize << endl;
	}
}

void histogram::createHistogram10(FIBITMAP* gray_bitmap){
	int HEIGHT = FreeImage_GetHeight(gray_bitmap);
	int WIDTH = FreeImage_GetWidth(gray_bitmap);
	int totalPixels = 0;
	float normalize;
	RGBQUAD color;
	ofstream histogramFile;
	int histogram_array[10];
	histogramFile.open("histogram10.csv", ios::out);

	for (int i = 0; i < 10; i++){
		histogram_array[i] = 0;
	}

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(gray_bitmap, i, j, &color);
			histogram_array[(int)((color.rgbRed * 10) / 256)] ++;
			//“(int) ((intensiteit * 10) / 256)
		}
	}

	for (int i = 0; i < 10; i++)
		totalPixels += histogram_array[i];

	for (int i = 0; i < 10; i++){
		normalize = histogram_array[i] / float(totalPixels);
		histogramFile << i << "," << normalize << endl;
	}
}
