
/*----------------------------------------------------------------------

	Grey image include file

  ---------------------------------------------------------------------- */

#include <stdio.h>
#include <math.h>
#include <malloc.h>

/* The image header data structure      */
struct header {
	int ny, nx;             /* Rows and columns in the image */
	int oi, oj;             /* Origin */
};

/*      The IMAGE data structure        */
struct image {
		struct header *info;            /* Pointer to header */
		unsigned char **data;           /* Pixel values */
};


typedef struct image * IMAGE;

IMAGE Input_PBM (char *fn);
IMAGE Output_PBM (IMAGE image, char *filename);
void get_num_pbm (FILE *f, char *b, int *bi, int *res);
void pbm_getln (FILE *f, char *b);
void pbm_param (char *s);
struct image  *newimage (int ny, int nx);
void freeimage (struct image  *z);
void sys_abort (int val, char *mess);
void copy (IMAGE *a, IMAGE b);
void CopyVarImage (IMAGE *a, IMAGE *b);
float ** f2d (int ny, int nx);


/*---------------------------------*/

struct bmpimage {
  short infosize, bits;
  int offset, width, height, xreso, yreso;
  unsigned char **red, **green, **blue;
};

typedef struct bmpimage * BMPIMAGE;

BMPIMAGE Input_BMP(char *fn);
BMPIMAGE Output_BMP (BMPIMAGE image, char *filename);
struct bmpimage  *new_bmpimage (  short infosize, short bits, int offset, int width, int height, int xreso, int yreso);
void free_bmpimage (struct bmpimage  *z);
//void copy_bmpimage (BMP_IMAGE *a, BMP_IMAGE b);
//void CopyVarBmpImage (BMPIMAGE *a, BMPIMAGE *b);


