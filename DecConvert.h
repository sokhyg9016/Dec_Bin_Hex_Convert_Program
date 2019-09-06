#pragma once
#pragma warning(disable :4996)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define BINSIZ 8

//Print the hex/bin
void Print_Data(const char* message, int* data, size_t size, const char* _mode);

//Convert functions
void ConvertToDec(int* dec, int* data, size_t size, const char* _mode);
void DecimalToHex(int* hex, int dec, size_t size);
void DecimalToBin2(int* bin, int dec, size_t size);
void DecimalToBin(int* bin, int dec, size_t size);

void Convert_Test();