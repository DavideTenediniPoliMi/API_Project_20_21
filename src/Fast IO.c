#include <stdlib.h>
#include <stdio.h>

#define ui unsigned int

#ifdef  _WIN32
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif

#ifdef  linux
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

int expect_ui() {
    char ch;
    ui num;

    do {
        ch = gc();
    } while (ch != EOF && !isdigit(ch));

    if(ch == EOF) {
        return EOF;
    }

    num = 0;
    do {
        num = num * 10 + (ch - '0');
        ch = gc();
    } while(isdigit(ch));

    return num;
}

int expect_char() {
    char ch;

    do {
        ch = gc();
    } while(ch != EOF && !isalpha(ch));

    return ch;
}

void print_ui(const ui n) {
    ui trail0, reversed, num;
    num = n;

    if(num == 0) {
        pc('0');
        return;
    }

    trail0 = 0;
    while(num % 10 == 0) {
        trail0 ++;
        num /= 10;
    }

    reversed = 0;
    while(num >= 10) {
        reversed = (reversed * 10) + (num % 10);
        num /= 10;
    }

    if(num != 0) {
        pc(num + '0');
    }
        
    while(reversed != 0) {
        pc((reversed % 10) + '0');
        reversed /= 10;
    }

    while(trail0 > 0) {
        pc('0');
        trail0 --;
    }
}
