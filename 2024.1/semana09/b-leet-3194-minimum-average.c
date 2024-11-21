int getPivotIdx(const int *arr, int start, int end) {
    int mid = start + (end - start) / 2;
    int a = arr[start], b = arr[mid], c = arr[end];
    if ((a > b) ^ (a > c))
        return start;
    else if ((b > a) ^ (b > c))
        return mid;
    else
        return end;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

const int partition(int *arr, int start, int end) {
    int idx = getPivotIdx(arr, start, end), pivot = arr[idx];
    swap(&arr[end], &arr[idx]);
    int i = start - 1;
    for (; start < end; ++start)
        if (arr[start] < pivot)
            swap(&arr[start], &arr[++i]);

    swap(&arr[end], &arr[++i]);
    return i;
}

void quicksort(int *arr, int start, int end) {
    if (start >= end)
        return;
    int idx = partition(arr, start, end);
    if ((idx - 1) > start)
        quicksort(arr, start, idx - 1);
    if ((idx + 1) < end)
        quicksort(arr, idx + 1, end);
}

double minimumAverage(int *nums, int numsSize) {
    double min = 60.0;
    quicksort(nums, 0, numsSize - 1);
    int half = numsSize / 2;
    for (int i = 0; i < half; ++i) {
        double calc = (nums[i] + nums[numsSize - i - 1]) / 2.0;
        min = calc < min ? calc : min;
    }
    return min;
}
