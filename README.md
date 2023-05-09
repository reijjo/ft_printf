# ft_printf <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" alt='c' height='40px' width='40px' title='c' />

#### Conversions included:
| Specifier | Description |
|-----------|-------------|
| %c        | Prints a single character |
| %s        | Prints a string |
| %p        | Prints a pointer address |
| %d or %i  | Prints a signed integer |
| %o        | Prints an unsigned octal integer |
| %u        | Prints an unsigned decimal integer |
| %x or %X  | Prints an unsigned hexadecimal integer |
| %f        | Prints a floating-point number |
| %%        | Prints a % character |

#### Flags included:
| Flag | Description |
|------|-------------|
| -    | Left-align the output within the field width |
| 0    | Pad the output with zeros instead of spaces |
| +    | Prefix the output with a plus sign (+) if it's positive |
| ' '  | Prefix the output with a space if it's positive |
| #    | Use an alternate form for the conversion specifier |
| .    | Precision for the conversion specifier |
| h    | Short integer |
| hh   | Signed char |
| l    | Long integer |
| ll   | Long long integer |

## How to use:
* Clone this repository inside your projects folder
* Run the Makefile in this folder (make re)
* Include ft_printf.h in your main file and compile your main file with libftprintf.a
```c
#include "ft_printf/ft_printf.h"

int main(void) {
	ft_printf("moimoi!");
	return (0);
}
```
* gcc main.c ft_printf/libftprintf.a
* ./a.out
* moimoi!

## In a nutshell:
* Just use it like the printf function.


