#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sample expandable char buffer in C
// Acts as a form of string object

#define CharBuf_EXTRA 10

#define CharBuf_SPACE(chb) (chb->cap - chb->len)
#define CharBuf_FULL(chb) (chb->cap == chb->len)
#define CharBuf_FITS(chb, size) (chb->cap - chb->len) > size

typedef struct
{
  size_t len;
  size_t cap;
  char data[0];
} CharBuf;

CharBuf* CharBuf_new(size_t size)
{
  CharBuf* newbuf = malloc(sizeof(CharBuf) + size);
  newbuf->len = 0;
  newbuf->cap = size;
  return newbuf;
}

static inline int 
CharBuf_fits(CharBuf* cb, size_t size)
{
  return (cb->cap - cb->len) > size
}

// expands by factor
void CharBuf_expand(CharBuf** cb, size_t factor)
{
  (*(cb))->cap *= factor;
  *cb = realloc(*cb, (*(cb))->cap);
}

//expands by size
void CharBuf_expand_size(CharBuf** cb, size_t size)
{
  (*(cb))->cap += size;
  *cb = realloc(*cb, (*(cb))->cap);
}

void CharBuf_put(CharBuf* cb, char ch)
{
  if(CharBuf_FULL(cb)) CharBuf_expand(&cb, 2);
  cb->data[cb->len++] = ch;
}

// Safe modulo get of char in buffer
char CharBuf_get(CharBuf* cb, size_t index)
{
  return cb->data[index % cb->len];
}

void CharBuf_append(CharBuf* cb, const char* string)
{
  size_t append_len = strlen(string);
  if(!CharBuf_fits(cb, append_len)) CharBuf_expand_size(&cb, append_len + CharBuf_EXTRA);
  while(*string)
  {
    cb->data[cb->len++] = *string++;
  }
}

// matches two char buffers from one another
int CharBuf_match(CharBuf* cb1, CharBuf* cb2)
{
  if(cb1->len != cb2->len) return 0;
  for(size_t i = 0; i < cb1->len; i++)
  {
    if(cb1->data[i] != cb2->data[i]) return 0;
  }
  return 1;
}

// trims off the last character
void CharBuf_trim_last(CharBuf* cb)
{
  if(cb->len) cb->len--;
}

char CharBuf_pop(CharBuf* cb)
{
  if(cb->len != 0) return cb->data[--(cb->len)];
  else return '\0';
}

// Prints all the chars in the char buffer 
void CharBuf_print(CharBuf* cb)
{
  for(size_t i = 0; i < cb->len; i++) putc(cb->data[i], stdout);
  putc('\n', stdout);
}

int main(void) {
  CharBuf* foo = CharBuf_new(5);
  CharBuf_put(foo, 'a');
  CharBuf_put(foo, 'a');
  CharBuf_put(foo, 'a');
  CharBuf_put(foo, 'a');
  CharBuf_put(foo, 'a');
  CharBuf_put(foo, 'b');
  CharBuf_put(foo, 'c');
  CharBuf_print(foo);
  return 0;
}
