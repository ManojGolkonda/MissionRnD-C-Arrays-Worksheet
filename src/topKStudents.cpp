/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <stdlib.h>

struct student {
	char *name;
	int score;
};

void swap1(char *str1, char *str2)
{
	char *temp = str1;
	str1 = str2;
	str2 = temp;
}

void sort1(struct student *students,int len)
{
	for (int i = 0; i < len - 1; i++)
	for (int j = 0; j < len - i - 1; j++)
	if (students[j].score < students[j + 1].score)
	{
		int temp = students[j].score;
		students[j].score = students[j + 1].score;
		students[j + 1].score = temp;
		swap1(students[j].name, students[j + 1].name);
	}
}

struct student ** topKStudents(struct student *students, int len, int K) 
{
	if (K < 1)
		return NULL;
	if (K>len)
		K = len;
	struct student **students1 = (struct student **)malloc(K*sizeof(struct student *));
	sort1(students, len);
	for (int i = 0; i < K; i++)
	{
		students1[i] = &students[i];
	}
	return students1;		
}