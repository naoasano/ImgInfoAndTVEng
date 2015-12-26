/*
画像処理のためのサンプルプログラム

2003-10-30   斎藤英雄
2014-12-26   斎藤英雄　　64bitＯＳへの対応．long型が８バイトになってしまうので，int型に変更（４バイト）

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
	//空間フィルタのサンプル

	printf ("Sample Program for Filtering \n");

	printf ("Input Image Filename (PGM) = ");
	scanf("%s", filename) ;
	getchar() ;


	//PGM画像を読み込む
	im1 = Input_PBM (filename);
	if (im1 == 0)
	{
	  printf ("No such file as '%s'\n", filename);
	  exit(0);
	}

	ny = im1->info->ny; nx = im1->info->nx;   // 画像のサイズを読み込んだ画像情報から獲得

	inputimage = f2d(ny, nx);  // ny行 nx列のfloat型の２次元配列を確保
	outimage = f2d(ny, nx);    // ny行 nx列のfloat型の２次元配列を確保

	//画像の画素値をfloat型の2次元配列にコピー（処理のため）
	for (i=0; i<ny; i++)
	  for (j=0; j<nx; j++)
			inputimage[i][j] = (float)im1->data[i][j] ;

	//フィルタリングの処理プログラム
	for (i=1; i<ny-1; i++)
	  for (j=1; j<nx-1; j++)
	  {
		  outimage[i][j] = 0.0;
    	for (k=-1; k<=1; k++)
	      for (l=-1; l<=1; l++)
			outimage[i][j] += filter[k+1][l+1]*inputimage[i+k][j+l] ;
	  }

	//float型の2次元配列からIMAGE構造体データにコピー（セーブするため）
	for (i=0; i<ny; i++)
	  for (j=0; j<nx; j++)
			im1->data[i][j] = (unsigned char)(outimage[i][j]);

	//PGM画像としてファイルにセーブ
	printf ("Output Image Filename (PGM) = ");
	scanf("%s", filename) ;
	getchar() ;

	Output_PBM (im1, filename);
}


