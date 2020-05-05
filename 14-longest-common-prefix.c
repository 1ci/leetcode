#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 * If there is no common prefix, return an empty string "".
 */
char* longestCommonPrefix(char** strs, int strsSize);

int main(int argc, char** argv) {
    char* strings[] = {
        ""
    };
    char* prefix = longestCommonPrefix(strings, sizeof(strings) / sizeof(char*));
    printf("prefix: %s", prefix);
    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    // find the longest possible prefix length
    size_t prefix_len = UINT_MAX;
    for (int i = 0; i < strsSize; i++) {
        size_t len = strlen( strs[i] );
        if (prefix_len > len) {
            prefix_len = len;
        }
    }
    if (prefix_len == UINT_MAX || prefix_len == 0) {
        prefix_len = 1;
    }

    size_t prefix_size = (prefix_len + 1) * sizeof(char); // null terminator
    char* prefix = (char*) malloc(prefix_size);
    memset(prefix, 0, prefix_size);

    size_t matches;
    char letter;
    for (int i = 0; i < prefix_len; i++) {
        // use the first string
        letter = strs[0][i];
        matches = 1;

        for (int j = 1; j < strsSize; j++, matches++) {
            if (letter != strs[j][i]) {
                prefix[i] = '\0';
                break;
            }
        }

        if (matches == strsSize) {
            prefix[i] = strs[0][i];
        }
    }
    return prefix;
}

// Straight-forward
// char * longestCommonPrefix(char ** strs, int strsSize){
//     int i,str_ptr;
//     char * ret_string;
//     if (strsSize == 0) return "";
//     int max_string = strlen(strs[0]);
//     for (i=1; i<strsSize; i++) {
//         str_ptr = 0;
//         while ((str_ptr < strlen(strs[i])) && (str_ptr < max_string))
//             if (strs[i][str_ptr]==strs[0][str_ptr])
//                 str_ptr++;
//             else break;
//         if (str_ptr < max_string) max_string = str_ptr;
//     }
//     ret_string = malloc((max_string+1) * sizeof(char));
//     for (i=0; i<max_string; i++) ret_string[i]=strs[0][i];
//     ret_string[max_string]='\0';
//     return ret_string;
// }
