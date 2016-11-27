/* ppmIO.c
 * Aurin Chakravarty (achakr16)
 *
 * 10/17/16
 * Handles the input and output of files/images
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "ppmIO.h"
/*typedef struct _pixel {
=======
typedef struct _pixel {
>>>>>>> 47fe61df147cd9406756da749e887126a7c2cc67
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
<<<<<<< HEAD
*/

Image* readPPM( Image* img, char fileName[]) {
  if (!fileName) {
    fprintf(stderr, "Error:ppmIO - writePPM given a bad filehandle\n");
    return 0;
  }
  FILE *fp = fopen(fileName, "r");

  int rows;
  int columns;
  int colors;
  char ch;

  if((ch=fgetc(fp)) !='P'){
    fprintf(stderr,"Error: Not a proper file format\n");
    return img;
  } else if ((ch=fgetc(fp)) != '6'){
    printf(stderr,"Error: Not a proper file format\n");
    return img;
  }
  ch = fgetc(fp);
  while (ispunct(ch)||isspace(ch)) {
    if(ch == '#') {
      ch = fgetc(fp);
      while(ch != '\n') {
	ch = fgetc(fp);
      }
    }
    ch = fgetc(fp);
  }
  ungetc(ch,fp);
  fscanf(fp," %d", &rows);
  fscanf(fp," %d", &columns);
  fscanf(fp," %d", &colors);
  unsigned char k;
  //while(isspace(ch = fgetc(fp)));
  //ungetc(ch, fp);
  k = fgetc(fp); //removes new line char
  img = malloc(sizeof(Image));
  img->data = malloc(rows*columns*sizeof(Pixel));

  //fread(img->data, sizeof(Pixel), rows*columns, fp);
  for(int i=0;i<(rows*columns);i++){
    for(int j=0;j<3;j++){
      k = fgetc(fp);
      if(j==0){
	img->data[i].r = (k);
      }else if(j ==1){
	img->data[i].g = (k);
      }else{
	img->data[i].b = (k);
      }
    }
  }
  img->rows = rows;
  img->cols = columns;
  img->colors= colors;
  return img;
}
  

int writeImage(char fileName[], Image* img) {
  if (!fileName) {
    fprintf(stderr, "Error can't find file");
  }
  FILE* fp = fopen(fileName, "w");
  fprintf(fp, "P6\n");
  fprintf(fp, "%d %d\n%d\n", img->rows, img->cols, img->colors);
  fwrite(img->data, sizeof(Pixel), img->rows * img->cols, fp);
  return 0;
}
