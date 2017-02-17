#include <stdio.h>
#include <stdlib.h>

void Gray_Code_SetUp(int);
void Gray_Code_Generator(int*, int, int);
int Interval_Check_Zero(int*, int);

int main(void) {
    int bit_length;
    printf("Number of Bits：");
    scanf("%d", &bit_length);
    
    Gray_Code_SetUp(bit_length);
    
    return 0;
}

void Gray_Code_SetUp(int bit_length){
    int* array_of_GrayCode = malloc(bit_length * sizeof(int));
    // Initialization
    for(int i=0; i<bit_length; i++){array_of_GrayCode[i] = 0;}
    // because the first one Gray code must be 0...0
    for(int i=bit_length-1; i>=0; i--) { printf("%d", array_of_GrayCode[i]); }
    printf("\n");
    // Declare the Odd_number
    int Odd_number = 1;
    // Generate Gray Code
    Gray_Code_Generator(array_of_GrayCode, bit_length, Odd_number);
}

int Interval_Check_Zero(int* array_of_GrayCode, int bit_length){
    // if the index which is between 0 ~ (bit_length-2) with no bit "1", return 0, or 1
    int Index ;
    for(Index=0; Index<(bit_length-1); Index++) if(array_of_GrayCode[Index]){return 0;}
    return array_of_GrayCode[Index];
}

void Gray_Code_Generator(int* array_of_GrayCode, int bit_length, int Odd_number){
    int Index, Total_Zero;
    while(!Interval_Check_Zero(array_of_GrayCode, bit_length)) {
        // Zero_Collection
        for(Total_Zero = 0; array_of_GrayCode[Total_Zero] == 0; Total_Zero++);
        // Judge_1's_position
        Index = Odd_number ? 0 : Total_Zero + 1;
        array_of_GrayCode[Index] = !array_of_GrayCode[Index];
        // 0->1, 1->0
        Odd_number = 1 - Odd_number;
        // print
        for(int i = bit_length - 1; i >= 0; i--) { printf("%d", array_of_GrayCode[i]); }
        printf("\n");
    }
}



