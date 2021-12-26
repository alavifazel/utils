#include "conversions.h"

const char hexChars[] = {'0', '1', '2', '3',
			'4', '5', '6', '7',
			'8', '9', 'A', 'B',
			'C', 'D', 'E', 'F'};

void
binary_to_hex(const char* input, size_t inputBufferSize,
	      char* res, size_t resultBufferSize)
{
  int inputDecimal = 0;
  for(size_t i = inputBufferSize; i --> 0;) {
    inputDecimal += (input[i] - '0') * pow(2, inputBufferSize - i);
  }

  size_t resultIndex = 0;
  while(inputDecimal > 0) {
    res[resultIndex++] = hexChars[inputDecimal % 16];
    inputDecimal /= 16;
  }
  res[resultIndex] = '\0';

  // Reversing the digits to turn them into right order
  for(size_t i = 0; i < resultIndex / 2; ++i) {
    char tmp = res[i];
    res[i] = res[resultIndex - 1 - i];
    res[resultIndex - 1 - i] = tmp;
  }
}


// 101010010
void
hex_to_binary (const char* input, size_t inputBufferSize,
	       char* res, size_t resultBufferSize) {
  int inputDecimal = 0;
  for(size_t i = inputBufferSize; i --> 0;) {
    if(input[i] - '0' >= 0 && input[i] - '0' <= 10) {
      inputDecimal += (input[i] - '0') * pow(16, inputBufferSize - 1 - i);
    } else {
      inputDecimal += (input[i] - 'A' + 10) * pow(16, inputBufferSize - 1 - i);
    }
  }


  size_t resultIndex = 0;
  while(inputDecimal > 0) {
    res[resultIndex++] = (inputDecimal % 2) + '0';
    inputDecimal /= 2;
  }
  res[resultIndex] = '\0';

  // Reversing the digits to turn them into right order
  for(size_t i = 0; i < resultIndex / 2; ++i) {
    char tmp = res[i];
    res[i] = res[resultIndex - 1 - i];
    res[resultIndex - 1 - i] = tmp;
  }
}

void binary_to_hex_test() {
  char input[] = "01010010110101001"; // HEX: 0xA5A8
  size_t input_size = (strlen(input) - 1);
  size_t res_size =  input_size / 4;
  char output[res_size];
  binary_to_hex(input, input_size, output, res_size);
  printf("%s\n", output);
}

void hex_to_binary_test() {
  char input[] = "685"; // BIN: 11010000101
  size_t input_size = strlen(input);
  size_t res_size =  input_size * 4;
  char output[res_size];
  hex_to_binary(input, input_size, output, res_size);
  printf("%s\n", output);
}
