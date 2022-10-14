#include <stdio.h>
#include <stdlib.h>


int main() {
    int x;
    int num = 69;
    int result;
    for (x = 31; x >= 0; x--) {
        result = num >> x;
        if((result & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    return 0;
}