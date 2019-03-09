#include "pch.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int DIMENSION = 3;

bool CheckNumberOfSimbolsAfterComma(double num)
{
	int counter = 0;

	stringstream stringStream;
	stringStream << setprecision(15) << num;

	string str = stringStream.str();

	auto dotIndex = str.find(".");

	if (dotIndex == str.npos)
	{
		return false;
	}
	else
	{
		counter = str.size() - 1 - dotIndex;
	}

	if (counter > 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CheckEmptyFile(ifstream& file, char argv[])
{
	if (file.peek() == EOF)
	{
		cout << "File " << argv << " is empty" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool ChechOpenFile(ifstream& file, char argv[])
{
	if (!file.is_open())
	{
		cout << "Failed to found/open " << argv << " for reading" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void InitializeMatrix(ifstream& file1, ifstream& file2, double (&mat1)[DIMENSION][DIMENSION], double (&mat2)[DIMENSION][DIMENSION])
{
	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			file1 >> mat1[i][j];
			file2 >> mat2[i][j];
		}
	}
}

void CalculateMatrix(double mat1[][DIMENSION], double mat2[][DIMENSION], double (&resMat)[DIMENSION][DIMENSION])
{
	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			for (int k = 0; k < DIMENSION; k++)
			{
				resMat[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

void PrintMatrix(double mat[][DIMENSION])
{
	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			if (j == 1)
			{
				cout << " " << fixed << setprecision(3) << mat[i][j] << " ";
			}
			else
			{
				cout << fixed << setprecision(3) << mat[i][j];	
			}
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl
			 << "Usage:multmatrix.exe <matrixfile1> matrixfile2>" << endl;
		return 1;
	}

	double matrix1[DIMENSION][DIMENSION];
	double matrix2[DIMENSION][DIMENSION];
	double resultMatrix[DIMENSION][DIMENSION] = { 0 };

	ifstream matrixFile1(argv[1]);
	ifstream matrixFile2(argv[2]);

	if (ChechOpenFile(matrixFile1, argv[1]) || CheckEmptyFile(matrixFile1, argv[1]) || ChechOpenFile(matrixFile2, argv[2]) || CheckEmptyFile(matrixFile2, argv[2]))
	{
		return 1;
	}

	InitializeMatrix(matrixFile1, matrixFile2, matrix1, matrix2);
	CalculateMatrix(matrix1, matrix2, resultMatrix);
	PrintMatrix(resultMatrix);

	matrixFile1.close();
	matrixFile2.close();
}