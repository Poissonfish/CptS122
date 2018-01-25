#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *my_strcpy (char *destination, const char *source);
char *my_strncat (char *destination, const char *source, int n);
int my_strcmp (const char *sl, const char *s2);

int main (void) {
  const char *src = "Hello, I'm James";
  char *des = NULL;
  // Question 1
  des = my_strcpy(NULL, src);
  printf("src : %s\ndes : %s\n", src, des);
  // Question 2
  des = my_strncat("zzzzz", src, 5);
  printf("src : %s\ndes : %s\n", src, des);
  // Question 3
  char *str1 = "abcdfdd",
       *str2 = "abcd";
  printf("comparison : %d\n", my_strcmp (str1, str2));
  printf("comparison : %d\n", strcmp (str1, str2));
}


// This function copies all characters in the string pointed to
// by source into the array pointed to by destination.
// The null character is also copied.
// The function returns destination.
char *my_strcpy (char *destination, const char *source) {
  // Get size of src string (w/ '\0')
  int size = 1;
  while (source[size - 1] != '\0')
    size ++;
  // Allocate memory for destionation
  destination = malloc(sizeof(char) * size);
  // Assign value to destination
  for (int i = 0; i < size; i ++)
    destination[i] = source[i];
  return destination;
}


// This function appends no more than n characters from the string
// pointed to by source to the end of the string pointed to by destination.
// The null character is appended to the end of the result.
// If the length of the C string in source is less than n,
// then only the content up to the terminating null character is copied.
// The destination pointer is returned.
char *my_strncat (char *destination, const char *source, int n) {
  // Get size of src string (w\o '\0')
  int size = 1;
  while (destination[size] != '\0')
    size ++;
  // Create new string (+1 for space of '\0')
  char *newString = malloc(sizeof(char) * (size + n + 1));
  // Copy destination to newstring
  for (int i = 0; i < size; i ++)
    newString[i] = destination[i];
  // Copy source to newstring
  for (int i = size; i < (size + n); i ++) {
    newString[i] = *source;
    // If encounter a NULL in source, break the loop
    if (*source == '\0')
      break;
    else
      source ++;
  }
  // Add '\0' at the end;
  newString[size + n] = '\0';
  return (newString);
}


// This function compares the string pointed to by s1 to the string
// pointed to by s2. If the string pointed to by s1 comes before the string
// pointed to by s2 in dictionary ordering, then -1 is returned.
// If the string pointed to by s1 is the same as the string pointed to by s2,
// then 0 is returned (the compare function is case sensitive).
// Otherwise, 1 is returned. For this problem,
// you must use pointer arithmetic only, please do NOT use array notation!
int my_strcmp (const char *s1, const char *s2) {
  do {
    if (*s1 < *s2)
      return -1;
    else if (*s1 > *s2)
      return 1;
  } while (*s1 ++ == *s2 ++);
  return 0;
}
