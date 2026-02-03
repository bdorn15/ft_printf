# ft_printf
A minimal reimplementation of the libc `printf` function as a **static library**: `libftprintf.a`.

This project focuses on:
- variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`)
- parsing a format string and dispatching conversions
- number conversion (base 10 / base 16)
- correct return value semantics (number of written characters)
- proper error propagation (`write` failures return `-1`)

## Supported conversions

Mandatory conversions implemented:

- `%c` prints a single character
- `%s` prints a string (prints `(null)` for `NULL`)
- `%p` prints a pointer in hexadecimal format
- `%d` / `%i` prints a signed integer (base 10)
- `%u` prints an unsigned integer (base 10)
- `%x` prints a hexadecimal number (lowercase)
- `%X` prints a hexadecimal number (uppercase)
- `%%` prints a literal `%`

> Note: This implementation does **not** implement the original `printf` buffer management.

## Files

- `ft_printf.c` — main loop (format parsing + dispatcher)
- `ft_print_chars.c` — character/string output helpers
- `ft_print_num.c` — signed/unsigned decimal conversion
- `ft_print_hex.c` — hex conversion and pointer printing
- `ft_printf.h` — public header

## Build

Build the static library:

  make

Clean build artifacts:

  make clean     # removes .o files
  make fclean    # removes .o files and libftprintf.a
  make re        # rebuild everything

## Usage

If you want to use my tester:

After make: cc -Wall -Wextra -Werror main.c libftprintf.a -o test

Then execute ./test

## Linux vs Windows note

Pointer formatting (%p) can differ between platforms (MinGW/MSVCRT vs glibc).
If you want Linux-like output and comparisons, test inside Ubuntu (WSL) or a Linux environment.

## License

This repository is for educational purposes (42 project).
