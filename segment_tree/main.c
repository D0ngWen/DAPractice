/**
 * @file main.c
 * @author Wen Dong 
 * @brief Template for a segment tree. Solve LeetCode 307 which calculates the 
 *        sum of subranges in the array 'nums'. Additionally, the elements of 
 *        the array nums can be updated.
 * @ref   [OI WiKi Segment Tree](https://oi-wiki.org/ds/seg/#%E7%BA%BF%E6%AE%B5%E6%A0%91%E7%9A%84%E5%9F%BA%E6%9C%AC%E7%BB%93%E6%9E%84%E4%B8%8E%E5%BB%BA%E6%A0%91)
 * @version 0.1
 * @date 2023-08-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>

// #define NUM_MAX_SIZE       120000  // 30000*4

typedef struct {
    int n;          // Size of array nums.
    int *tree;
} NumArray;

static void build(int *nums, int *tree, int left, int right, int index)
{
    int mid;

    if (left == right) {
        tree[index] = nums[left];
        return;
    }

    mid = left + (right - left) / 2;
    build(nums, tree, left, mid, index * 2);
    build(nums, tree, mid + 1, right, index * 2 + 1);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

/**
 * @brief Get sum of subranges in the array nums without 'lazy' symbol.
 */
static int getsum(int * tree, int left, int right, int cur_left, int cur_right, 
                int index)
{
    int mid, sum;

    if (left <= cur_left && cur_right >= right) {
        return tree[index];
    }

    mid = cur_left + (cur_right - cur_left) / 2;
    sum = 0;
    if (left <= mid) {
        sum += getsum(tree, left, right, cur_left, mid, index * 2);
    }
    if (right > mid) {
        sum += getsum(tree, left, right, mid + 1, right, index * 2 + 1);
    }
    return sum;
}

NumArray* numArrayCreate(int* nums, int numsSize)
{
    NumArray *obj;

    obj = calloc(1, sizeof(*obj) + 4*numsSize*sizeof(int));
    obj->n = 4 * numsSize;
    obj->tree = obj + sizeof(*obj);

    build(nums, obj->tree, 0, numsSize - 1, 0);
}

void numArrayUpdate(NumArray* obj, int index, int val)
{

}

int numArraySumRange(NumArray* obj, int left, int right)
{

}

void numArrayFree(NumArray* obj)
{

}

int main() {

}
