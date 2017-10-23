//============================================================================
// Name        : SeProject.cpp
// Author      : Mahmoud Eltobgy
// Version     : 1.0
// Copyright   : Your copyright notice
//============================================================================


#include "matrix.h"

int main()
{

	string s1, s2, op,vName1,vName2;
	float** A, ** B, ** C;
	matrix M;
	
	cout <<"--------------------------Program Hints-------------------------------\n";
	cout <<"----------------------------------------------------------------------\n";
		cout <<"At Any time if you want to terminate the program type 'Exit' or 'Terminate' as an input \n";
	cout <<"-----------------------------------------------------------------------\n";
	cout <<"-----------------------------------------------------------------------\n";
while(1)
{

	cout << "Please Enter The first Matrix In The Right Format: \t" << "like A=[1 2; 3 4]" << endl;    //insert A
	
	getline(cin, s1);
	if(s1=="Exit" ||s1=="exit"||s1=="Terminate"||s1=="terminate")
	{
		return 0;;
	}
	vName1 = s1.substr(0,s1.find("="));
	s1 = s1.substr(s1.find('['));
	int m1 = M.Getrows(s1);
	int n1 = M.Getcolumns(s1);
	A = M.create_matrix(m1, n1);
	A = M.fill_matrix(s1, A, m1, n1);

	cout << "Please Enter The second Matrix In The Right Format: \t" << "like B=[1 2; 3 4]" << endl;   //insert B
	getline(cin, s2);
	if(s2=="Exit" ||s2=="exit"||s2=="Terminate"||s2=="terminate")
	{
		return 0;;
	}
	vName2 = s2.substr(0,s2.find("="));
	s2 = s2.substr(s2.find('['));
	int m2 = M.Getrows(s2);
	int n2 = M.Getcolumns(s2);
	B = M.create_matrix(m2, n2);
	B = M.fill_matrix(s2, B, m2, n2);

	cout << "please enter the required operation:\nlike:C=A+B  or\nlike:C=A-B  or\nlike:C=A*B or\nlike:C=A' or\nlike:C=B'" << endl;
	getline(cin, op);
	if(op=="Exit" ||op=="exit"||op=="Terminate"||op=="terminate")
		return 0;
	op=op.substr(op.find("=")+1);
	if(op == (vName1+"'"))
    {
        C=M.Transpose_matrix(A,m1,n1);
        M.print_matrix(C,n1,m1);
        cout << "\r\n";
    }
    else if(op==(vName2+"'"))
    {
        C=M.Transpose_matrix(B,m2,n2);
        M.print_matrix(C,n2,m2);
        cout << "\r\n";
    }


	else if (op.find("+")!=-1 && m1 == m2 && m1 !=0 && n1 == n2)                    // both matrices dimensions must be equal
	{
		cout << "The summation result=" << endl;
		C = M.sum_matrix(A, B, m1, n1);
		M.print_matrix(C, m1, n1);
		cout << "\r\n";
	}

	else if (m1 == m2 && m1 !=0 && n1 == n2 && op==(vName1+"-"+vName2))               // both matrices dimensions must be equal
	{
		cout << "The subtraction result=" << endl;
		C = M.sub_matrix(A, B, m1, n1);
		M.print_matrix(C, m1, n1);
		cout << "\r\n";
	}
	else if (m1 == m2 && m1 !=0 && n1 == n2 && op==(vName2+"-"+vName1))               // both matrices dimensions must be equal
		{
			cout << "The subtraction result=" << endl;
			C = M.sub_matrix(B, A, m1, n1);
			M.print_matrix(C, m1, n1);
			cout << "\r\n";
		}

	else if ( op.find("*") != -1)                      // column of matrix A must be equal to row of matrix B
	{
		cout << "The multiplication result=" << endl;
		C = M.multiply_matrix(A, B, m1, n2);
		M.print_matrix(C, m1, n2);
		cout << "\r\n";
	}



	else
		cout << "Oh!! Error Good Bye" << endl;


	}

	return 0;
}
