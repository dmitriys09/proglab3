#ifndef COMMAND_H
#define COMMAND_H
#include <string.h>
#include <stdint.h>

int encode_file(const char *in_file, const char *out_file);
int decode_file(const char *in_file, const char *out_file);

#endif
