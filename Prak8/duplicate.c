#include "duplicate.h"
#include <stdio.h>
#include <stdlib.h>
Set arrToSet(int *arr, int arrSize)
{
	Set result;
	CreateEmpty(&result);

	int i = 0;
	while (i < arrSize)
	{
		if (!IsMember(result, arr[i]))
		{
			Insert(&result, arr[i]);
		}
		i++;
	}

	return result;
}

void removeDuplicateDesc(int *arr, int arrSize, int *arrRes, int *arrResSize)
{
	Set resSet;
	resSet = arrToSet(arr, arrSize);

	*arrResSize = resSet.Count;

	int i = 0;
	while (i < resSet.Count)
	{
		arrRes[i] = resSet.Elements[i];
		i++;
	}

	int j = 0;
	while (j < *arrResSize)
	{
		int k = j + 1;
		while (k < *arrResSize)
		{
			if (arrRes[j] < arrRes[k])
			{
				int temp = arrRes[j];
				arrRes[j] = arrRes[k];
				arrRes[k] = temp;
			}
			k++;
		}
		j++;
	}
}