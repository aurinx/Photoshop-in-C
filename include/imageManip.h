/*imageManip.h
 *Karun Kannan
 *Aurin Chakravarty
 *10/16/16
 *
 *Contains headers of the manipultion functions
 */

#ifndef _CS120_IMAGEMANIP_H
#define _CS120_IMAGEMANIP_H
#include <stdio.h>
#include <ctype.h>
#include "ppmIO.h"
Image* cropImage(int x1,int y1,int x2,int y2, Image* img);
Image* invertImage(Image* img);
Image* swapImage(Image* img);
#endif
