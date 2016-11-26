/*imageManip.c
 *Karun Kannan (kkannan1)
 *Aurin Chakravarty (achakr16)
 *10/17/16
 *Holds functions that manipulate the image
 */
#include "imageManip.h"
#include "ppmIO.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
Image* cropImage(int x1, int y1, int x2, int y2, Image* img){
  Image* cropImg;
  //check if in bounds
  //if(x1<img->rows && x1i
  if(!(x1<img->rows && x1>0 && x2<img->rows && x2>0)){
    fprintf(stderr,"Error: Input is out of bounds");
    return img;
  }
  if(!(y1<img->rows && y1>0 && y2<img->rows && y2>0)){
    fprintf(stderr,"Error: Input is out of bounds");
    return img;
  }
  int newRow = abs(y2-y1);
  int newCol = abs(x2-x1);
  int count = 0;
  cropImg = malloc(sizeof(Image));
  cropImg->data = malloc((newCol)*(newRow)*sizeof(Pixel));
  for(int i = 0; i< img->rows;i++){
    for(int j = 0; j < img->cols; j++){
      if(j >= x1 && j < x2 && i >= y1 && i < y2) {
      cropImg->data[count] = img->data[i * img->cols + j];
      count++;
      
      }
    }
    //i = i + (img->cols - x2) + x1;
    /*FILE* fp = fopen("out.ppm","w");
    fprintf(fp,"P6\n %d %d\n%d",newRow, newCol, img->colors);
    fwrite(cropImg->data, sizeof(Pixel), newRow * newCol, fp);*/
  }
  /*
  for(int i = y1; i < y2; i++){
    for(int j = x1; j < x2; j++){
      cropImg->data[count] = img->data[i * img->cols + j];
      count++;
    }
    // i = i + (img->cols - x2) + x1;
    }*/
  cropImg->rows = newRow;
  cropImg->cols = newCol;
  cropImg->colors = img->colors;
  free(img->data);
  free(img);
  return cropImg; 
}

Image* invertImage(Image* img){
  for(int i=0;i<img->rows*img->cols;i++){
      //red value:
      img->data[i].r = (unsigned char)(img->colors -(int)(img->data[i].r));
      //green value:
      img->data[i].g = (unsigned char)(img->colors - (int)(img->data[i].g));
      //blue value:
      img->data[i].b = (unsigned char)(img->colors - (int)(img->data[i].b));
    
  }
  return img; 
}

Image* swapImage(Image* img){
  for(int i =0;i<img->rows*img->cols;i++){
    
      unsigned char temp = 0;
      temp = img->data[i].r;
      img->data[i].r = img->data[i].g;
      img->data[i].g = img->data[i].b;
      img->data[i].b = temp;
    
  }
  return img; 
}
