*This project has been created as part of the 42 curriculum by kseltenr*

# Description

libft is the first project of the 42 core curriculum, in which I had to recreate standard C library functions from scratch without relying on external libraries.

The primary goal of the project is to build an understanding of C programming, pointers, and manual memory management.
By coding these functions, I compiled my own custom static library (libft.a). This library becomes an essential, personalized toolkit that I will use and expand throughout the rest of the 42 curriculum.

## Functions from `<ctype.h>`

- [ft_isascii](/ft_isascii.c): test for ASCII character
- [ft_isalnum](/ft_isalnum.c): alphanumeric character test
- [ft_isalpha](/ft_isalpha.c): alphabetic character test
- [ft_isdigit](/ft_isdigit.c): decimal-digit character test
- [ft_isprint](/ft_isprint.c): printing character test
- [ft_tolower](/ft_tolower.c): uppercase to lowercase letter conversion
- [ft_toupper](/ft_toupper.c): lowercase to uppercase letter conversion

## Functions from `<stdlib.h>`

- [ft_atoi](/ft_atoi.c): convert ASCII string to integer
- [ft_calloc](/ft_calloc.c): memory allocation

## Functions from `<strings.h>`

- [ft_bzero](/ft_bzero.c): write zeroes to a byte string
- [ft_memset](/ft_memset.c): write a byte to a byte string
- [ft_memchr](/ft_memchr.c): locate byte in byte string
- [ft_memcmp](/ft_memcmp.c): compare byte string
- [ft_memmove](/ft_memmove.c): copy byte string
- [ft_memcpy](/ft_memcpy.c): copy memory area

## Functions from `<string.h>`

- [ft_strlen](/ft_strlen.c): find length of string
- [ft_strchr](/ft_strchr.c): locate character in string (first occurrence)
- [ft_strrchr](/ft_strrchr.c): locate character in string (last occurrence)
- [ft_strnstr](/ft_strnstr.c): locate a substring in a string (size bounded)
- [ft_strncmp](/ft_strncmp.c): compare strings (size bounded)
- [ft_strlcpy](/ft_strlcpy.c): copy strings (size bounded)
- [ft_strdup](/ft_strdup.c): save a copy of a string (with malloc)
- [ft_strlcpy](/ft_strlcpy.c): size bounded string copying
- [ft_strlcat](/ft_strlcat.c): size bounded string concatenation

## Non-standard functions

- [ft_putchar_fd](/ft_putchar_fd.c): output character to given file
- [ft_putstr_fd](/ft_putstr_fd.c): output string to given file
- [ft_putendl_fd](/ft_putendl_fd.c): output string to given file with newline
- [ft_putnbr_fd](/ft_putnbr_fd.c): output integer to given file
- [ft_itoa](/ft_itoa.c): convert integer to ASCII string
- [ft_substr](/ft_substr.c): extract substring from string
- [ft_strtrim](/ft_strtrim.c): trim beginning and end of string with specified character
- [ft_strjoin](/ft_strjoin.c): concatenate two strings into a new string (with malloc)
- [ft_split](/ft_split.c): split string with specified character as delimiter into an array of strings
- [ft_strmapi](/ft_strmapi.c): create a new string from modifying string with specified function
- [ft_striteri](/ft_striteri.c): apply a function to each character of a string, passing its index as an argument so it can be modified in place

## Linked list functions
- [ft_lstnew](/ft_lstnew.c): create new list
- [ft_lstsize](/ft_lstsize.c): count elements of a list
- [ft_lstlast](/ft_lstlast.c): find last element of list
- [ft_lstadd_back](/ft_lstadd_back.c): add new element at end of list
- [ft_lstadd_front](/ft_lstadd_front.c): add new element at beginning of list
- [ft_lstdelone](/ft_lstdelone.c): delete element from list
- [ft_lstclear](/ft_lstclear.c): delete sequence of elements of list from a starting point
- [ft_lstiter](/ft_lstiter.c): apply function to content of all list's elements
- [ft_lstmap](/ft_lstmap.c): apply function to content of all list's elements into a new list

# Instructions

## 1. Compilation
run in the terminal:
```bash
cd path/to/libft && make
```

## 2. Usage
- include this header in the code:
```c
#include "libft.h"
```
- add these flags when compiling the code:
```bash
-lft -L path/to/libft -I path/to/libft
```

## 3. Tester
I used this tester: [libftTester](https://github.com/Tripouille/libftTester)

# Resources

Manual pages of the functions, geeksforgeeks.org for understanding concepts better (eg. malloc, linked lists)

AI was used to reformat some code, like replacing spaces with tabs and similar minor norm issues.
It also was used to add test mains before the peer evualtions.
