#include <stdio.h>
#include <string.h>
#include <ctype.h>

int romanToInt(char * s);

int main(int argc, char** argv) {
    char roman[] = "XIV";
    int num = romanToInt(roman);
    printf("%s = %d\n", roman, num);
    return 0;
}

int romanToInt(char * s) {
    int len = strlen(s);
    int num = 0;
    char roman;
    char nextRoman;

    for (int i = 0; i < len; i++) {
        roman = toupper( s[i] );

        if (i + 1 < len) {
            nextRoman = toupper( s[i+1] );
        } else {
            nextRoman = '\0';
        }

        switch (roman) {
        case 'I':
            if (nextRoman == 'V') {
                num += 4;
                i++;
                continue;
            } else if (nextRoman == 'X') {
                num += 9;
                i++;
                continue;
            }

            num += 1;
            break;
        case 'X':
            if (nextRoman == 'L') {
                num += 40;
                i++;
                continue;
            } else if (nextRoman == 'C') {
                num += 90;
                i++;
                continue;
            }

            num += 10;
            break;
        case 'C':
            if (nextRoman == 'D') {
                num += 400;
                i++;
                continue;
            } else if (nextRoman == 'M') {
                num += 900;
                i++;
                continue;
            }

            num += 100;
            break;
        case 'V':
            num += 5;
            break;
        case 'L':
            num += 50;
            break;
        case 'D':
            num += 500;
            break;
        case 'M':
            num += 1000;
            break;
        }
    }
    return num;
}
