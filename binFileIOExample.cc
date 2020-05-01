/*
*  * Usage of CDK Matrix
*  
* File:   binFileIOExample.cc
* Date:   04/29/20
* Author: Mansi Pedireddy 
* Email:  mrp170002@utdallas.edu
* Course: CS 3377.501 Spring2020 
* Version:1.0
* Copyright: 2020, All Rights Reserved
* Description: Creates and displays matrix  
*/

#include "headerfile.h"
class BinaryFileHeader
{
  public:
        uint32_t magicNumber;               
	uint32_t versionNumber;
	uint64_t numRecords;
	};

const int maxRecordStringLength = 25;

class BinaryFileRecord
{
 public:
   uint8_t strLength;
   char stringBuffer[maxRecordStringLength];
};



int main()
{
  
  string matrixDisplay[MATRIX_HEIGHT+1][MATRIX_WIDTH+1 ];

  ifstream file("/scratch/perkins/cs3377.bin", ios::in | ios::binary);

if(file.is_open())
{

 BinaryFileHeader *header = new BinaryFileHeader(); 

if(file.read((char *) header, sizeof(BinaryFileHeader)))
  {  
 
 stringstream headernames; 

headernames << "Magic: 0x" << hex << uppercase << header->magicNumber;
matrixDisplay[1][1] = headernames.str();
headernames.str("");

headernames << "NumRecords: " << header->numRecords;
matrixDisplay[1][3] = headernames.str();
headernames.str("");

headernames << "Version: " << header->versionNumber;
matrixDisplay[1][2] = headernames.str();
headernames.str("");

}
stringstream recordfile;

BinaryFileRecord *record = new BinaryFileRecord();
uint64_t numRecords = header-> numRecords < 4 ? header->numRecords : 4;


for (uint64_t i=2; i < numRecords +2; i++)
{
if(file.read((char *) record, sizeof(BinaryFileRecord)))
    {
recordfile << "strlen: " << (int) record->strLength;

matrixDisplay[i][1] = recordfile.str();
matrixDisplay[i][2] = record->stringBuffer;

recordfile.str("");
recordfile.clear();
}
}
file.close();
}
contents(matrixDisplay);
}

