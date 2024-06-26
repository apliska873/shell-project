#include "shared.h"

#include <stdio.h>
#include <string.h>

// What goes here?
// * anything shared between multiple other files
// * general use functions

// return 0 if string length < 2, return 1 otherwise
int str_is_empty(char *str) {
  if (strlen(str) < 2)
    return 0;
  return 1;
}

// replaces all instances of the newline character with the NULL character
void remove_newline(char *text) {
  int length = strlen(text);
  for (int i = 0; i < length; i++) {
    if (text[i] == '\n') {
      text[i] = '\0';
    }
  }
  // int idx = 0;
  // while (text[idx] != '\0') {
  //   if (text[idx] == '\n') {
  //     text[idx] = '\0';
  //   }
  //   idx++;
  // }
}

// split the given arguments into separate pieces by character
int split_arguments(char *input, char **args, const char *c) {
  char *token = strtok(input, c);
  int argument_count = 0;

  for (int i = 0; token != NULL; i++) {
    args[i] = token;
    token = strtok(NULL, c);
    argument_count++;
  }
  args[argument_count] = NULL;
  return argument_count;
}

// reverses inputted string
void reverse_string(char *str) {
  int len = strlen(str);
  for (int i = 0, j = len - 1; i <= j; i++, j--) {
    // swapping characters
    char c = str[i];
    str[i] = str[j];
    str[j] = c;
  }
}
// fills char ** with stuff from char[][]
void copy_char_array(char *dest[MAX_CHARS], char *source[MAX_CHARS],
                     int num_args) {
  for (int i = 0; i < num_args; i++) {
    dest[i] = source[i];
  }
}
//
// FUNCTIONS FOR TESTING PURPOSES ONLY GO HERE
// These should all probably get removed once the program is finished
//
void print_array_pointer(char *args[MAX_CHARS], int num_args) { // REMOVE
  printf("array: ");
  for (int i = 0; i < num_args; i++) {
    printf("%s ", args[i]);
  }
  puts("");
}

void print_array_array(char args[MAX_ARGS][MAX_CHARS], int num_args) { // REMOVE
  printf("array: ");
  for (int i = 0; i < num_args; i++) {
    printf("%s ", args[i]);
  }
  puts("");
}
