#include "derived.h"
int derived::func() {
    int sub = arr[0];
    for (int i = 1; i < size; i++) {
        sub -= arr[i];
    }
    return sub;
 }