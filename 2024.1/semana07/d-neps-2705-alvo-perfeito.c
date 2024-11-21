#include <stdio.h>

int main() {
    int count, target;
    scanf("%d %d", &count, &target);

    int parts[count];

    for (int i = 0; i < count; scanf("%d", &parts[i++]))
        ;

    for (int psum = 0, start = 0, end = 0; start <= end && end < count; end++) {
        psum += parts[end];
        if (parts[end] == target) {
            printf("S\n");
            return 0;
        }

        if (parts[end] > target) {
            psum = 0;
            start = end + 1;
            continue;
        }

        if (psum == target) {
            printf("S\n");
            return 0;
        } else if (psum > target) {
            psum -= parts[start++];
            psum -= parts[end--];
        }
    }

    printf("N\n");

    return 0;
}
