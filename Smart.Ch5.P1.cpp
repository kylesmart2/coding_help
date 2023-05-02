//This program will read from a text file to input 3 student names and 
// their test scores
//Kyle Smart 4/24/2017
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string student1, student2, student3;
	int test1, test2, test3, average1, average2, average3;
	ifstream infile;
	ofstream outfile;

	infile.open("student.txt");

	if (!infile)
		cout << "File open failure!\n";


	infile >> student1 >> test1 >> test2 >> test3;
	average1 = (test1 + test2 + test3)/3;

	infile >> student2 >> test1 >> test2 >> test3;
	average2 = (test1 + test2 + test3)/3;

	infile >> student3 >> test1 >> test2 >> test3;
	average3 = (test1 + test2 + test3)/3;

	outfile.open("gradedTests.txt");

	outfile << "The average test score of " << student1 << " is: " << average1 << "\n";
	outfile << "The average test score of " << student2 << " is: " << average2 << "\n";
	outfile << "The average test score of " << student3 << " is: " << average3 << "\n";

	
	infile.close();
	outfile.close();

	return 0;
}