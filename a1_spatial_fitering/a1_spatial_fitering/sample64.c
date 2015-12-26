/*
�摜�����̂��߂̃T���v���v���O����

2003-10-30   �֓��p�Y
2014-12-26   �֓��p�Y�@�@64bit�n�r�ւ̑Ή��Dlong�^���W�o�C�g�ɂȂ��Ă��܂��̂ŁCint�^�ɕύX�i�S�o�C�g�j

*/

#include "lib64.h"
#include <stdio.h>

int main ()
{
	int i,j, k, l, nx, ny;
	IMAGE im1;
	float **inputimage ;
	float **outimage ;
	char filename[512] ;
	
	float filter[3][3] = {0, 1.0, 0,
		              1.0, -4, 1.0,
			      0, 1.0, 0} ;
	//��ԃt�B���^�̃T���v��

	printf ("Sample Program for Filtering \n");

	printf ("Input Image Filename (PGM) = ");
	scanf("%s", filename) ;
	getchar() ;


	//PGM�摜��ǂݍ���
	im1 = Input_PBM (filename);
	if (im1 == 0)
	{
	  printf ("No such file as '%s'\n", filename);
	  exit(0);
	}

	ny = im1->info->ny; nx = im1->info->nx;   // �摜�̃T�C�Y��ǂݍ��񂾉摜��񂩂�l��

	inputimage = f2d(ny, nx);  // ny�s nx���float�^�̂Q�����z����m��
	outimage = f2d(ny, nx);    // ny�s nx���float�^�̂Q�����z����m��

	//�摜�̉�f�l��float�^��2�����z��ɃR�s�[�i�����̂��߁j
	for (i=0; i<ny; i++)
	  for (j=0; j<nx; j++)
			inputimage[i][j] = (float)im1->data[i][j] ;

	//�t�B���^�����O�̏����v���O����
	for (i=1; i<ny-1; i++)
	  for (j=1; j<nx-1; j++)
	  {
		  outimage[i][j] = 0.0;
    	for (k=-1; k<=1; k++)
	      for (l=-1; l<=1; l++)
			outimage[i][j] += filter[k+1][l+1]*inputimage[i+k][j+l] ;
	  }

	//float�^��2�����z�񂩂�IMAGE�\���̃f�[�^�ɃR�s�[�i�Z�[�u���邽�߁j
	for (i=0; i<ny; i++)
	  for (j=0; j<nx; j++)
			im1->data[i][j] = (unsigned char)(outimage[i][j]);

	//PGM�摜�Ƃ��ăt�@�C���ɃZ�[�u
	printf ("Output Image Filename (PGM) = ");
	scanf("%s", filename) ;
	getchar() ;

	Output_PBM (im1, filename);
}


