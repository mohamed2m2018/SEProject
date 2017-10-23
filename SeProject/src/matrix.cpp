/*
 * matrix.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: m_eltobgy
 */

#include "matrix.h"

matrix::matrix() {
	rows = 0;
    columns = 0;

}

matrix::~matrix() {
	// TODO Auto-generated destructor stub
}


int matrix:: Getrows(string s)
{
   		int rows;
		int postion = s.find("[");        // if martrix is empty ... so return rows =0 
		s = s.substr(postion + 1);
		s = s.erase(s.length() - 1);
		if (s.length() == 0)
			return rows = 0;

		rows = count(s.begin(), s.end(), ';') + 1;
		return rows;
}

int matrix:: Getcolumns(string s)
{
		int columns;
		string s1;
		int postion = s.find("[");                // if martrix is empty ... so return columns =0 
		s1 = s.substr(postion + 1);
		s1 = s1.erase(s1.length() - 1);
		if (s1.length() == 0)
			return columns = 0;
		int	rows = count(s.begin(), s.end(), ';') + 1;
		columns = (count(s.begin(), s.end(), ' ') / rows) + 1;
		return columns;
}

float** matrix::create_matrix(int rows, int columns)     //MUST initialize all values to zero
{

	float** matrix = new float*[rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new float[columns];
	}

	return matrix;
}
void matrix::destroy_matrix(float** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i]; //deletes an inner array of integer;
	}

	delete[] matrix; //delete pointer holding array of pointers;
}

float** matrix::fill_matrix(string s, float** A, int rows, int columns)
{
    s.erase(remove(s.begin(), s.end(), ';'), s.end());
    s.erase(s.find('['),1);
    s.erase(s.find(']'),1);

    stringstream stream ;
    stream << s;

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            stream>>A[i][j];
        }
    }
	return A;
}

float**matrix::createEmptyMatrix(int rows, int columns)
{
	float** result = new float*[rows];

	for (int i = 0; i < rows; i++)
	{
		result[i] = new float[columns];
		memset(result[i], 0, columns * sizeof(float));       //to make every element NULL
	}

	return result;
}

float**matrix::sum_matrix(float** A, float** B, int rows, int columns)
{
	float** result = createEmptyMatrix(rows, columns);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			result[i][j] = A[i][j] + B[i][j];
		}
	}

	return result;
}

float** matrix::sub_matrix(float** A, float** B, int rows, int columns)
	{
		float** result = createEmptyMatrix(rows, columns);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				result[i][j] = A[i][j] - B[i][j];
			}
		}

		return result;
	}

float**matrix:: multiply_matrix(float** A, float** B, int rows, int columns)
	{
		float** result = createEmptyMatrix(rows, columns);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				for (int k = 0; k < columns; k++)
					result[i][j] += A[k][j] * B[i][k];
			}
		}

		return result;
	}


float**matrix:: Transpose_matrix(float** A, int rows, int columns)
	{
		float** result = createEmptyMatrix(columns, rows);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				result[j][i] = A[i][j];
			}
			cout << endl;
		}
		return result;
	}

void matrix::print_matrix(float** A, int rows, int columns)
	{

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << A[i][j] << "\t";
			}
			cout << endl;
		}

	}

