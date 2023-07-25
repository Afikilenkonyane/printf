#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define M_LONG 2
#define M_SHORT 1

/**
 * struct fomt - STruc
 *
 * @fomt: The form.
 * @fn: The function assoc.
 */
struct fomt
{
	char fomt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fomt fomt_t - STruct
 *
 * @fomt: The format
 * @fom_t: The function
 */

typedef struct fomt fomt_t;

int _printf(const char *format, ...);
int handle_prrint(const char *fomt, int *index,
va_list args, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int prrint_charr(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int prrint_strring(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int prrint_perrcent(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int prrint_int(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int prrint_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int prrint_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int prrint_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int prrint_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int prrint_hexa_upperr(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int prrint_hexa(va_list args, char mapp_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function nonprintable characters */
int prrint_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to memory address */
int prrint_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to specifiers */
int gmt_flags(const char *format, int *j);
int gmt_width(const char *format, int *j, va_list args);
int gmt_precision(const char *format, int *j, va_list args);
int gmt_size(const char *format, int *j);

/*Function to print string in reverse*/
int prrint_rreverse(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/*rot 13*/
int prrint_ro13tring(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* wrute  handler */
int hand_wrrite_char(char d, char buffer[],
	int flags, int width, int precision, int size);
int wrrite_number(int is_neg, int index, char buffer[],
	int flags, int width, int precision, int size);
int wrrite_numb(int index, char buffer[], int flags, int width, int precision,
	int length, char pad, char ext_c);
int wrrite_pointerr(char buffer[], int index, int len,
	int width, int flags, char padding, char ext_c, int padding_start);

int wrrite_unsgnd(int is_neg, int index,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_prrintable(char);
int app_hexa_code(char, char[], int);
int is_digi(char);

long int conv_size_number(long int numb, int siz);
long int conv_size_unsgnd(unsigned long int num, int siz);

#endif /* MAIN_H */

