# morse code interpreter

A simple piece of software that takes morse code input, parses it, and produces plaintext output. 

## Usage:

Run `make`, and it will produce an executable called `interpreter`.

Running the executable, it will prompt you for input, and the formatting is as follows:

The morse code sequences must be delimited with a space in order to be recognised, e.g. `.... . .-.. .-.. ----`, and spaces can be written using `/` in between these sequences.

## Notes:

This version does not have support for full alphanumeric characters yet - it only uses the alphabet, and a forward slash can be used to denote a space.
