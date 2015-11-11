
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	if (Arr == NULL || len<1)			//handling for invalid cases
		return NULL;
	int i = 0, j = len - 1, m;
	/*	while (i < j)						//finding the index of the given score, so that we can find numbers greater and lesser than the given score
	{									//this is same as binary search :)
	m = (i + j) / 2;
	if (Arr[m]>score)
	j = m;
	else if (Arr[m] < score)
	i = m;
	else
	{
	i = m;
	j = m;
	break;
	}
	}
	while (i > 0 && Arr[i - 1] == score)			//handling duplicates before the number we found
	i--;
	while (j < len - 2 && Arr[j + 1] == score)		//handling duplicates after the number we found
	j++;
	*/
	while (Arr[i] < score && i < len)
		i++;
	j = i;
	while (Arr[j] == score && j < len)
		j++;
	/**lessCount = i;									//updating result
	*moreCount = len - j - 1;*/
	*lessCount = i;
	*moreCount = len - j;
}
