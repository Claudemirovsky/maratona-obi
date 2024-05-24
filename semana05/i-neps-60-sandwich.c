#include <stdio.h>

// In this one, I needed the help of two giants, namely:
// 1. Caio Cidade, that gave me test cases and even code to steal;
// 2. João Breno, that pretty much gave a summary of both parts
// of the following code, including the GIGABRAIN move of using BinarySearch.

int binary_search(long *arr, long target, int init, int end) {
    if (target < 1)
        return -1;
    while (init <= end) {
        int mid = init + ((end - init) / 2);

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            init = mid + 1;
        else if (arr[mid] > target)
            end = mid - 1;
    }

    return -1;
}

int main() {
    int count, target;
    scanf("%d %d", &count, &target);

    int parts[count], possibilities = 0;

    for (int i = 0; i < count; scanf("%d", &parts[i++]))
        ;

    for (int psum = 0, start = 0, end = 0; end < count; end++) {
        // Thx J.Breno + C.Cidade (i stole almost everything from him lol).
        psum += parts[end];
        if (parts[end] >= target) {
            if (parts[end] == target)
                possibilities++;
            psum = 0;
            start = end + 1;
            continue;
        }

        if (psum == target) {
            possibilities++;
            psum -= parts[start++];
        } else if (psum > target) { // the end pointer stays the same but the
                                    // start pointer advances
            psum -= parts[start++];
            psum -= parts[end--]; // i'll re-add it in the next loop
        }
    }

    int limit = count - 1;
    if (parts[0] < target && parts[limit] < target) {
        long psum[count];
        psum[0] = parts[0];
        for (int i = 1; i < limit; psum[i] = psum[i - 1] + parts[i], i++)
            ;

        long sum = 0;
        while (sum < target && limit > 0) {
            // LA IGUARIA, thx breno²
            sum += parts[limit];
            if (binary_search(psum, target - sum, 0, --limit) != -1)
                possibilities++;
        }
    }
    printf("%d\n", possibilities);
    return 0;
}
