# charbuf

*A dynamically sized string object in C*

CharBuf is a dynamically sized string object for the C programming language. It allows object-like methods such as appending, put, get, compare and more. It has a stream-lined interface that make string operations easy.

## Installation

Use the code in `charbuf.c`, copy and paste it, such as into a header file.

## Usage

To run the main tests, compile the file by typing this into your terminal

```
$ gcc charbuf.c -o charbuf
$ ./charbuf
```

## Guide


### `CharBuf* CharBuf_new(size_t size)`:

Creates a new empty buffer with starting size.


### `static inline int CharBuf_fits(CharBuf* cb, size_t size)`:

Checks if the buffer can fit a size.



### `void CharBuf_expand(CharBuf** cb, size_t factor)`:

Expands the buffer by a factor.


### `void CharBuf_expand_size(CharBuf** cb, size_t size)`:

Expands the buffer by some size

### `void CharBuf_put(CharBuf* cb, char ch)`:

Adds a character to the end of the buffer.


### `char CharBuf_get(CharBuf* cb, size_t index)`:

Gets a character from the buffer. If `index` is more than the length, it modulos down.


### `void CharBuf_append(CharBuf* cb, const char* string)`:

Appends a C-style string to the buffer.



### `int CharBuf_match(CharBuf* cb1, CharBuf* cb2)`:

Checks if one buffer is equal to another.



### `void CharBuf_trim_last(CharBuf* cb)`:

Removes last character in the buffer.

### `char CharBuf_pop(CharBuf* cb)`:

Removes and returns the last character in the bfufer.


 
### `void CharBuf_print(CharBuf* cb)`: 

Prints the buffer to stdout.
