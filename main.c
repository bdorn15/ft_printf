#include "ft_printf.h"
#include <stdio.h>

void test_chars()
{
    int r1;
    int r2;

    r1 = printf("c\n");
    r2 = ft_printf("c\n");

    if (r2 != r1)
        printf("*Fail returns differ*\n");

    r1 = printf("%c\n", 'A');
    r2 = ft_printf("%c\n", 'A');

    if (r2 != r1)
        printf("*Fail returns differ*\n");
    else
        printf("*Character returns match*\n");

}

void test_strings()
{
    int r1;
    int r2;

    r1 = printf("This is a test string\n");
    r2 = ft_printf("This is a test string\n");

    if (r2 != r1)
        printf("*Fail returns differ*\n");

    r1 = printf("%s\n", "Another test string");
    r2 = ft_printf("%s\n", "Another test string");

    if (r2 != r1)
        printf("*Fail returns differ*\n");
    else
        printf("*String returns match*\n");
}

void test_ptr()
{
    int r1;
    int r2;

    int *ptr = &r2;
    r1 = printf("%p\n", ptr);
    r2 = ft_printf("%p\n", ptr);

    if (r2 != r1)
        printf("*Pointer: Fail returns differ*\n");
    else
        printf("*Pointer returns match*\n");
    
    ptr = NULL;
    r1 = printf("%p\n", ptr);
    r2 = ft_printf("%p\n", ptr);

    if (r2 != r1)
        printf("*Pointer: Fail returns differ*\n");
    else
        printf("*Pointer returns match*\n");

}

void test_int()
{
    int r1;
    int r2;

    int x = 1;
    r1 = printf("%d\n", x);
    r2 = ft_printf("%d\n", x);

    if (r2 != r1)
        printf("*Integer: Fail returns differ*\n");
    else
        printf("*Integer returns match*\n");

    x = -10;
    r1 = printf("%d\n", x);
    r2 = ft_printf("%d\n", x);

    if (r2 != r1)
        printf("*Integer: Fail returns differ*\n");
    else
        printf("*Integer returns match*\n");

    x = INT_MIN;

    r1 = printf("%d\n", x);
    r2 = ft_printf("%d\n", x);

    if (r2 != r1)
        printf("*Integer: Fail returns differ*\n");
    else
        printf("*Integer returns match*\n");

}


static void test_uint(void)
{
    int r1, r2;

    r1 = printf("%u\n", 0u);
    r2 = ft_printf("%u\n", 0u);
    if (r2 != r1)
        printf("*Unsigned integer: Fail returns differ*\n");
    else
        printf("*Unsigned integer returns match*\n");

    r1 = printf("%u\n", 42u);
    r2 = ft_printf("%u\n", 42u);
    if (r2 != r1)
        printf("*Unsigned integer: Fail returns differ*\n");
    else
        printf("*Unsigned integer returns match*\n");
    

    r1 = printf("%u\n", (unsigned int)-1);
    r2 = ft_printf("%u\n", (unsigned int)-1);
    if (r2 != r1)
        printf("*Unsigned integer: Fail returns differ*\n");
    else
        printf("*Unsigned integer returns match*\n");
    
}

void test_hex()
{
    int r1;
    int r2;

    int x = 1;
    r1 = printf("%x\n", x);
    r2 = ft_printf("%x\n", x);

    if (r2 != r1)
        printf("*Hex: Fail returns differ*\n");
    else
        printf("*Hexadecimal returns match*\n");

    x = 15;
    r1 = printf("%x\n", x);
    r2 = ft_printf("%x\n", x);

    if (r2 != r1)
        printf("*Hex: Fail returns differ*\n");
    else
        printf("*Hexadecimal: returns match*\n");

    x = 12;
    r1 = printf("%X\n", x);
    r2 = ft_printf("%X\n", x);

    if (r2 != r1)
        printf("*Hex: Fail returns differ*\n");
    else
        printf("*Hexadecimal returns match*\n");

}

void test_per()
{
    int r1;
    int r2;

    r1 = printf("%%\n");
    r2 = ft_printf("%%\n");

    if (r2 != r1)
        printf("*Percentage: Fail returns differ*\n");

    r1 = printf("%%%\n");
    r2 = ft_printf("%%%\n");

    if (r2 != r1)
        printf("*Percentage: Fail returns differ*\n");
    else
        printf("*Percentage returns match*\n");
}

int main (void)
{
    //Test characters
    printf("--------Test Characters-------\n");
    test_chars();

    //Test Strings
    printf("---------Test Strings---------\n");
    test_strings();

    //Test Pointer
    printf("---------Test Pointer---------\n");
    test_ptr();

    //Test integer
    printf("---------Test Integer---------\n");
    test_int();

    //Test uinteger
    printf("---------Test unsgined Integer---------\n");
    test_uint();

    //Test hex
    printf("---------Test Hexadecimal---------\n");
    test_hex();

    //Test per
    printf("---------Test Percentage---------\n");
    test_per();                                         // -w argument needed to silence printf warnings

    return 0;
}