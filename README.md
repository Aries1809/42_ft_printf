*This project has been created as part of the 42 curriculum by kseltenr*

# ft_printf

## Description

`ft_printf` is a re-implementation of the libc `printf()`, shipped as the static
library `libftprintf.a`.

- **Mandatory part:** the conversions `%c %s %p %d %i %u %x %X %%`.
- **Bonus part:** the flags `-`, `0`, `.` (precision), `#`, `+` and ` ` (space)
  together with a minimum field width, in any combination, for every conversion.

`ft_printf` returns the number of characters printed, or `-1` if a `write()`
fails. Its output is byte-for-byte identical to glibc's `printf()` on Linux,
including glibc's own choices for cases the C standard leaves open: `(null)` for
a null string, `(nil)` for a null pointer, `%5%` printing a single `%`, and a
trailing lone `%` returning `-1`.

## Instructions

Put your libft in `./libft` (its Makefile must build `libft.a`), then:

```sh
make          # builds libftprintf.a
make bonus    # rebuilds libftprintf.a with flag support
make clean    # removes the object files
make fclean   # removes the object files and the library
make re       # fclean + make
```

Using the library:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("[%-6s] [%+05d] [%#x] [%p]\n", "hi", 42, 255, (void *)0);
	return (0);
}
```

```sh
cc main.c -I inc -L . -lftprintf
```

## Algorithm and data structure

**One pass, no allocation.** `ft_printf` walks the format string once. Each step
prints either one conversion or the whole run of plain text up to the next `%`
with a single `write()`. Numbers are converted into a small buffer on the stack
and also written with a single `write()`. Nothing is ever allocated, so there is
nothing to free, nothing to leak and no allocation failure to handle.

**Error handling.** Every printing function returns how many characters it
wrote, or `-1`. The first `-1` stops the loop and `ft_printf` returns `-1`.

**Mandatory part.** `pf_dispatch` reads the argument with `va_arg` and hands it
to a tiny writer (`pf_putchar`, `pf_putstr`, `pf_putptr`, `pf_putnbr`).
`pf_putnbr` covers `d i u x X p`: it is called with the base to use (`DECIMAL`,
`HEX_LOWER`, `HEX_UPPER`) and a prefix (`""`, `"-"` or `"0x"`).

**Bonus part — the `t_spec` structure.** Each conversion is parsed into a
`t_spec`: the five flags (`minus`, `zero`, `hash`, `space`, `plus`), the `width`,
the precision `prec` (`-1` means "none") and the conversion character.
Right after parsing, `pf_normalize` settles every flag interaction in one place,
so the printing code never has to look at flag combinations:

- `-` cancels `0`; a precision cancels `0`; `0` is ignored for `c`, `s` and `%`
- `+` and ` ` only apply to `d`, `i` and `p`, like glibc; `+` wins over ` `
- `#` only applies to `x` and `X`; `p` always behaves as if `#` was set

The bonus then works as a short pipeline:

1. **parse** (`ft_parse_bonus.c`) — fills the `t_spec` from
   `%[flags][width][.precision]conversion`.
2. **dispatch** (`ft_printf_bonus.c`) — reads the argument with `va_arg`.
3. **convert** (`ft_convert_bonus.c`) — turns the value into its pieces:
   a prefix (`-`, `+`, ` `, `0x`, `0X`) and the digits, or the text cut to the
   precision.
4. **emit** (`ft_emit_bonus.c`) — lays the pieces out in the field:

   ```
   [spaces][prefix][zeros][digits][spaces]
   ```

   The zeros come either from the precision or from the `0` flag filling the
   width; the spaces fill the rest of the width, on the left or on the right
   (`-`). Text (`c`, `s`, `(nil)`) uses the same layout without prefix and
   zeros.

Because every conversion ends up in the same two layout functions
(`pf_emit_nbr` and `pf_emit_str`), any flag combination works for any
conversion without special cases.

## Resources

- `man 3 printf` and `man 3 stdarg`
- ISO/IEC 9899:2011 (C11), §7.21.6.1 — the `fprintf` function
- glibc source, `stdio-common/vfprintf-process-arg.c` — reference for the
  implementation-specific behaviour (`(nil)`, `(null)`, flags on `%p`)
- The 42 Norm
