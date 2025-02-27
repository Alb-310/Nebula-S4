#include <stdio.h>
#include "gd.h"
#include ".h/filters.h"
#include ".h/func_divers.h"
#include<time.h>
#include <string.h>

void OldSchool_Filter(gdImagePtr image, FILE *Output, char *path )
{
    Output = fopen (path, "wb");
    gdImageGrayScale(image);
    gdImagePng(image, Output);
    fclose (Output);
}

void Glow_Filter(gdImagePtr image, FILE *Output, char *path )
{
    Output = fopen (path, "wb");
    gdImageNegate(image);
    gdImagePng(image, Output);
    fclose (Output);
}

void RedFlag_Filter(gdImagePtr image, FILE *Output, char *path )
{
    Output = fopen (path, "wb");
    for (int y = 0; y < gdImageSY(image); y++)
    {
        for (int x = 0; x < gdImageSX(image); x++)
        {
            int truepixel = gdImageGetTrueColorPixel (image,x,y);
            int r = gdImageRed(image,truepixel);
            int b = gdImageBlue(image,truepixel);
            int g = gdImageGreen(image,truepixel);
            if ( r>= 120 && b <= 60 && g <= 60)
            {
                continue;
            }
            else if (b == 0 && g == 0)
            {
                continue;
            }
            else if (r < 256 && b <= 10 && g <= 10)
            {
                continue;
            }
            
            else
            {
                r = g = b = (int) (.299 * r + .587 * g + .114 * b);

			    int new_pxl = gdImageColorAllocateAlpha(image,
                 r, g, b, gdImageAlpha(image,truepixel));
			    if (new_pxl == -1) 
                {
				    new_pxl = gdImageColorClosestAlpha(image,
                     r, g, b, gdImageAlpha(image,truepixel));
			    }
			    gdImageSetPixel (image, x, y, new_pxl);
            }
        }
        
    }

    gdImagePng(image, Output);
    fclose (Output);
    
}


void SummerTime_Filter(gdImagePtr image, FILE *Output, char *path )
{
    Output = fopen (path, "wb");
    gdImageColor(image,20,0,0,0);
    gdImageBrightness(image,20);
    gdImageContrast(image,-20.2);
    gdImagePng(image, Output);
    fclose (Output);
}


void Vogue_Filter(gdImagePtr image, FILE *Output, char *path )
{
    Output = fopen (path, "wb");
    gdImageColor(image,0,10,20,0);
    gdImageContrast(image,-20);
    gdImageBrightness(image,5);

    gdImagePtr cdr = gdImageCreateFromFile ("src/resources/ImageProcessing/cadre.png");
    cdr = gdImageScale(cdr,image->sx,image->sy);
    gdImageCopy(image,cdr,0,0,0,0,image->sx,image->sy);

    int x = image->sx/4 - image->sy*0.1;
    int y = image->sy*0.8;

    int *brect = malloc(8*sizeof(int));
	brect[0]=x;
	brect[1]=y;
	brect[2]=x+image->sx;
	brect[3]=y;
	brect[4]=x+image->sx;
	brect[5]=y+image->sy;
	brect[6]=x;
	brect[7]=y+image->sy;
    char* filename = "src/resources/ImageProcessing/Vogue.ttf";
    char* font = realpath(filename,NULL);
    int color = gdImageColorAllocate(image,255,255,255);

    gdImageStringFT(image,brect,0,font,image->sy*0.1,0,x+1,y,"VOGUE");
    gdImageStringFT(image,brect,color,font,image->sy*0.1 - 1,0,x,y,"VOGUE");

    gdImagePng(image, Output);
    gdFree(cdr);
    fclose (Output);
}

void WinterFrost_Filter(gdImagePtr image, FILE *Output, char *path )
{
    Output = fopen (path, "wb");
    gdImageColor(image,0,15,20,0);
    gdImageContrast(image,-20);
    gdImageBrightness(image,-10);


    gdImagePng(image, Output);
    fclose (Output);
}

void TimeOClock_Filter(gdImagePtr image, FILE *Output, char *path  )
{
    Output = fopen (path, "wb");
    gdImageColor(image,0,20,30,0);
    gdImageContrast(image,10);
    gdImageBrightness(image,10);

    gdImagePtr cdr = gdImageCreateFromFile ("src/resources/ImageProcessing/vignette.png");
    cdr = gdImageScale(cdr,image->sx,image->sy);
    
    gdImageCopy(image,cdr,0,0,0,0,image->sx,image->sy);

    int x = image->sx - image->sy*0.2;
    int y = image->sy*0.1;

    int *brect = malloc(8*sizeof(int));
	brect[0]=x;
	brect[1]=y;
	brect[2]=x+image->sx;
	brect[3]=y;
	brect[4]=x+image->sx;
	brect[5]=y+image->sy;
	brect[6]=x;
	brect[7]=y+image->sy;
    char* filename = "src/resources/ImageProcessing/Digit.TTF";
    char* font = realpath(filename,NULL);
    int color = gdImageColorAllocate(image,255,255,255);

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    char output1[6];
    sprintf(output1, "%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min);
    
    gdImageStringFT(image,brect,0,font,image->sy*0.07,0,x+1,y,output1);
    gdImageStringFT(image,brect,color,font,image->sy*0.07 - 2,0,x-1,y,output1);
    
    gdImagePng(image, Output);
    
    gdFree(cdr);
    fclose (Output);

}

void WeekDay_Filter(gdImagePtr image, FILE *Output, char *path  )
{
    Output = fopen (path, "wb");
    gdImageColor(image,10,-5,10,0);
    gdImageContrast(image,-10);
    gdImageBrightness(image,10);

    gdImagePtr cdr = gdImageCreateFromFile ("src/resources/ImageProcessing/vignette.png");
    cdr = gdImageScale(cdr,image->sx,image->sy);
    
    gdImageCopy(image,cdr,0,0,0,0,image->sx,image->sy);

    int x = image->sx - image->sy*0.63;
    int y = image->sy*0.11;

    int *brect = malloc(8*sizeof(int));
	brect[0]=x;
	brect[1]=y;
	brect[2]=x+image->sx;
	brect[3]=y;
	brect[4]=x+image->sx;
	brect[5]=y+image->sy;
	brect[6]=x;
	brect[7]=y+image->sy;
    char* filename = "src/resources/ImageProcessing/Brook.ttf";
    char* font = realpath(filename,NULL);
    int color = gdImageColorAllocate(image,255,255,255);

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );

    timeinfo = localtime ( &rawtime );
    char output1[30];
    char* token = strtok(asctime(timeinfo), " ");
    sprintf(output1, "%s %s %s", token, strtok(NULL, " "), strtok(NULL, " "));
    
    gdImageStringFT(image,brect,0,font,image->sy*0.03,0.25,x+1,y,output1);
    gdImageStringFT(image,brect,color,font,image->sy*0.03 - 0.5,0.25,x-1,y,output1);
    
    gdImagePng(image, Output);
    
    gdFree(cdr);
    fclose (Output);
}