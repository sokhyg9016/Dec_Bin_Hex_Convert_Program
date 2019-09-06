#include "DecConvert.h"

void Print_Data(const char* message, int* data, size_t size, const char* _mode)
{
	printf(message);

	if (!(strcmp(_mode, "bin")))
	{
		for (int i = (int)size; i > 0; i--)
		{
			if (i != size && i % 4 == 0)
			{
				printf(" %d", data[i - 1]);
			}
			else
				printf("%d", data[i - 1]);
		}
	}
	else
	{
		for (int i = (int)size - 1; i >= 0; i--)
		{
			if (data[i] != 0)
				printf("%c", data[i]);
			else
				continue;
		}
	}
	puts("");
}

void DecimalToHex(int* hex, int dec, size_t size)
{
	int i, tmp;

	i = 0;
	while (dec != 0 && i < (int)size)
	{
		tmp = dec % 16;

		if (tmp < 10)
			tmp += 48;
		else
			tmp += 55;

		hex[i++] = tmp;

		dec /= 16;
	}
}

void DecimalToBin(int* bin, int dec, size_t size)
{
	int i;

	i = 0;

	while (dec != 0)
	{
		bin[i++] = dec % 2;
		dec /= 2;
	}
}

void DecimalToBin2(int* bin, int dec, size_t size)
{
	int i, tmp;

	i = 0;
	for(i = size - 1; i >= 0; i--)
	{
		tmp = dec >> i;

		if (tmp & 1)
			bin[i] = 1;
		else
			bin[i] = 0;
	}
}

void ConvertToDec(int* dec, int* data, size_t size, const char* _mode)
{
	if (!(strcmp(_mode, "hex")))
	{
		int tmp;
		*dec = 0;

		for (int i = (int)size - 1; i >= 0; i--)
		{
			tmp = 0; 

			if (data[i] >= 'A' && data[i] <= 'Z')
				tmp = data[i] - 55;
			else if (data[i] == 0)
				continue;
			else
				tmp = data[i] - '0';
				

			*dec += tmp * (int)pow(16, i);
		}
	}
	else if (!(strcmp(_mode, "bin")))
	{
		*dec = 0;

		for (int i = (int)size - 1; i >= 0; i--)
		{
			*dec += data[i] * (int)pow(2, i);
		}

	}
}

void Convert_Test()
{
	int* hex = NULL;
	int* bin = NULL;
	int decimal;

	size_t size = 0;

	fputs("Enter the size: ", stdout);
	
	if (scanf_s("%ld", &size))
	{
		hex = (int*)malloc(sizeof(int) * size);
		bin = (int*)malloc(sizeof(int) * size);
	}
	else
	{
		fprintf(stderr, "input error\n");
		exit(1);
	}

	for (int i = 0; i < (int)size; i++)
	{
		hex[i] = bin[i] = 0;
	}

	//input
	printf("input decimal: ");
	scanf_s("%d", &decimal);

	//dec -> hex
	DecimalToHex(hex, decimal, size);
	Print_Data("[dec -> hex]: 0X", hex, size, "hex");

	//dec -> bin
	DecimalToBin(bin, decimal, size);
	Print_Data("[dec -> bin]: ", bin, size, "bin");

	//hex -> dec
	ConvertToDec(&decimal, hex, size, "hex");
	printf("[hex -> dec]: %d\n", decimal);

	//bin -> dec
	ConvertToDec(&decimal, bin, size, "bin");
	printf("[bin -> dec]: %d\n", decimal);


	free(hex);
	free(bin);
}