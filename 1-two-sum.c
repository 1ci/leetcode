#include <stdio.h>
#include <stdlib.h>

int* findIndices(int target, const int* arrNumbers, size_t length);
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(int argc, char** argv)
{
    int numbers[] = {3, 2, 3 ,15};
    int* indices = findIndices(6, numbers, sizeof(numbers));
    printf("Indices: [%d, %d]\n", indices[0], indices[1]);
    free(indices);

    int returnSize;
    indices = (int*) malloc(2 * sizeof(int));
    indices = twoSum(numbers, sizeof(numbers), 6, &returnSize);
    printf("Indices: [%d, %d]\n", indices[0], indices[1]);
    free(indices);

    return 0;
}

// Given an array of integers, return indices of the two numbers 
// such that they add up to a specific target.
int* findIndices(int target, const int* arrNumbers, size_t length)
{
    int temp_sum = 0;
    int* indices = (int*) malloc(2 * sizeof(int));
    if (indices == NULL)
    {
        fprintf(stderr, "Could not allocate memory");
        return NULL;
    }

    for (int i = 0; i < length-1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            temp_sum = arrNumbers[i] + arrNumbers[j];
            if (temp_sum == target)
            {
                indices[0] = i;
                indices[1] = j;
                return indices; // found
            }
        }
    }
    // could not find two numbers that match the target sum
    return NULL;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int temp_sum = 0;
    int* indices = (int*) malloc(2 * sizeof(int));
    if (indices == NULL)
    {
        // failed to allocate memory
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize-1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            temp_sum = nums[i] + nums[j];
            if (temp_sum == target)
            {
                indices[0] = i;
                indices[1] = j;
                *returnSize = 2;
                return indices; // found
            }
        }
    }
    // could not find two numbers that match the target sum
    *returnSize = 0;
    return NULL;
}