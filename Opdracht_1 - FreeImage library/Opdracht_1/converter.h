/* ========================================================================== */
/*                                                                            */
/*   converter.h                                                              */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include "stdafx.h"
#include "FreeImage.h"


class converter{
private:

	//! Declares the Height of the image
	int HEIGHT;

	//! Declares the Width of the image
	int WIDTH;

	//! Declares the gray value of the image
	double grayValue;

public:

	//! This method has parameters bitmap and color and will convert to gray scale
	FIBITMAP* convertToGray(FIBITMAP* bitmap, RGBQUAD& color);

};