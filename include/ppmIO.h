/*ppmIO.h
 *Aurin Chakravarty (achakra16)
 *Karun Kannan (kkannan1)
 *10/17/16
 *Headers for ppmIO.c 
 */

#ifndef _CS120_PPMIO_H
#define _CS120_PPMIO_H
#include <stdio.h>
#include <ctype.h>
typedef struct _pixel {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} Pixel;

typedef struct _image {
  Pixel *data;
  int rows;
  int cols;
  int colors;
} Image;
Image* readPPM( Image* img, char fileName[]);
int readFile(char fileName[],Image* img);


#endif
