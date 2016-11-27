/*menuUtil.c
 *Aurin Chakravarty
 *10/16/16
 * 
 *Implements menu for the main function
 */
#include "menuUtil.h"
#include "ppmIO.h"
#include "imageManip.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printMenu(Image* img){
  int i =0;
  while(i == 0){
    printf("Main menu:\n r <filename> - read image from <filename>\n w <filename> - write image to <filename>\n c <x1> <y1> <x2> <y2> - crop image to the box with the given corners\n i - invert intensities\n s - swap color chanels\n g - convert to grayscale\n bl <sigma> - Gaussian blur with the given radius (sigma)\nsh <sigma> <amt> - sharpen by given amount (intensity), with radius (sigma)\n br <amt> - change brightness (up or down) by the given amount\n cn <amt> - change contrast (up or down) by the given amount\n q - quit\n");
    char input=getchar();
    //char c;
    char trash;
    char filename[20];
    int x1,y1,x2,y2 = 0;
    switch(input){
    case 'r':
      scanf("%s",filename);
      img=readPPM(img, filename);
      scanf("%c",&trash);
      break;
    case 'w':
      scanf("%s",filename);
      writeImage(filename,img);
      scanf("%c",&trash);
      break;
    case 'c':
      scanf("%d",&x1);
      scanf("%d", &y1);
      scanf("%d", &x2);
      scanf("%d", &y2);
      img = cropImage(x1,y1,x2,y2,img);
      scanf("%c",&trash);
      break;
    case 'i':
      img = invertImage(img);
      scanf("%c",&trash);
      break;
    case 's':
      img =swapImage(img);
      scanf("%c",&trash);
      break;
    case 'q':
      i = 1;
      free(img->data);
      free(img);
      break;
    default:
      printf("This functionality has not been implemented\n");
      scanf("%c",&trash);
    }
  }
  
}
