#ifndef __TEST_H__
#define __TEST_H__

#include <stdio.h>

void test();

template <class T>
void test_t(T t) {
    printf("aaa");
    printf("test\n");
    (void)t;
}

#endif

