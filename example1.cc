/*
 * Usage of CDK Matrix
 *
 * File:   example1.cc
 * Date:   04/29/20
 * Author: Mansi Pedireddy 
 * Email:  mrp170002@utdallas.edu
 * Course: CS 3377.501 Spring2020 
 * Version:1.0
 * Copyright: 2020, All Rights Reserved
 * Description: Creates and displays matrix
 */

#include "headerfile.h"
//#include "binFileIOExample.cc"

int contents(string matrixDisplay[MATRIX_HEIGHT+1][MATRIX_WIDTH+1])
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"0","a", "b", "c","d","e"};
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"0","a", "b", "c"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) columnTitles, (char **) rowTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL){
      printf("Error creating Matrix\n");
      exit(1);
    }



drawCDKMatrix(myMatrix, true);

int hMAX = MATRIX_HEIGHT+1 ;

for(int i = 1; i < hMAX; i++)
{

int wMAX = MATRIX_WIDTH+1 ;

for (int j = 1; j < wMAX; j++)
{
setCDKMatrixCell(myMatrix, i, j, matrixDisplay[i][j].c_str());
}
}

drawCDKMatrix(myMatrix, true);


  sleep(10);
  endCDK();
  return(0);

}
