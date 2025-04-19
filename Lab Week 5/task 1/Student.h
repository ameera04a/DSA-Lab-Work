#pragma once
#include<string>
#include<iostream>
using namespace std;
class Student
{
	string name;
	double score;
	int time;
public:
	Student(string n);
	void generateScoreTime();
	void displayStudent();
	
};

