#ifndef MAIN_H
#define MAIN_H

/* This is a header file containing declarations
 * for prototype functions defined in the 0x07-more-functions_nested_loops
 * tasks and directory
 * This is like creating my own library with declared functions
 * The tasks defines  the functions
 *
 *
 * enclosing the files  contentinbetween ifndef,define and endif,
 * stops the compiler from processing the file twice if its included twice,
 * if not so, this will cause an error
 */

int _putchar(char c);
void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));
int (*get_op_func(char *s))(int, int);

#endif
