/*
 * matrix.h
 *
 *  Created on: Oct 23, 2017
 *      Author: m_eltobgy
 */

#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_
#include <iostream>
#include <stdio.h>
#include "strings.h"
#include <cstring>
#include "conio.h"
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
class matrix {
	int rows, columns;
public:
	matrix();
	virtual ~matrix();
	int Getrows(string s);
	int Getcolumns(string s);
	float** create_matrix(int rows, int columns);
	void destroy_matrix(float** matrix, int rows);
	float** fill_matrix(string s, float** A, int rows, int columns);
	float** createEmptyMatrix(int rows, int columns);
	float** sum_matrix(float** A, float** B, int rows, int columns);
	float** sub_matrix(float** A, float** B, int rows, int columns);
	float** multiply_matrix(float** A, float** B, int rows, int columns);
	float** Transpose_matrix(float** A, int rows, int columns);
	void print_matrix(float** A, int rows, int columns);
};

#endif /* SRC_MATRIX_H_ */
