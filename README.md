# morse code interpreter

A simple piece of software that takes a morse code sequence as input, parses it, and produces plaintext output. 

## Usage:

Run `make`, and it will produce an executable called `interpreter`.

Running the executable, it will prompt you for input, and the formatting is as follows:

The morse code sequences must be delimited with a space in order to be recognised, e.g. `--... --...`.

## Features:

- Full alphanumeric support.

- Spaces can be written using the `/` character to separate words.

- Any erroneous output will be caught and padded with a `?` character.

- The program will now continue to prompt for input until the user explicitly sends `quit` to terminate the program, allowing to send many morse code sequences to translate after another without inconvenience.

- Constants for controlling the input / output size have been embedded into the program and can be changed by the user to allow translation of extremely large excerpts / sequences if needed. Refer to `src/main.c` for more information.
