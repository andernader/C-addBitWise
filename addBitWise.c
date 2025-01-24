#include <stdio.h>

void addBitWise(int a, int b, int c, int result[2]);

int main(){
    int a = 2, b = 4, c = 0;
    int arr[2];
    unsigned int temp_result = 0;
    int result = 0;

    printf("A = ");
    scanf("%d%*[^\n]", &a);
    printf("B = ");
    scanf("%d%*[^\n]", &b);
    int bit;
    printf("The calculation is between 2 to the power of : ");
    scanf("%d%*[^\n]", &bit);
    printf("\n\n");

    for(int i = 0; i < bit; i++){
        char temp_a = a & 1;
        printf("temp_a = %d     ", temp_a);
        char temp_b = b & 1;
        printf("temp_b = %d     ", temp_b);
        a = a >> 1;
        b = b >> 1;
        addBitWise(temp_a, temp_b, c, arr);
        printf("temp = %d\n", arr[0]);
        temp_result = temp_result << 1;
        temp_result = temp_result | arr[0];
        c = arr[1];
    }
    printf("\ntemp_result = %u\n\n", temp_result);
    for(int i = 0; i < bit; i++){
        char temp = temp_result & 1;
        temp_result = temp_result >> 1;
        printf("temp = %d\n", temp);
        result = result << 1;
        result = result | temp;
    }
    printf("\nresult = %d\n", result);
    printf("\n%s - %s\n%s\n", __TIME__, __DATE__, "Ammar Mullaoglu");


    return 0;
}

void addBitWise(int a, int b, int c, int result[2]){
    result[0] = a ^ b ^ c;
    result[1] = a&b | (a^b)&c;
}
