//improved version of Q2 function
#include <iostream>
using namespace std;

int modulo(int num, int divisor) {
    if(num < 0)
        return -1;
    
    while (num >= 0)
        num = num - divisor;
    
    return num + divisor;
}

int main() {
    printf("%d\n", modulo(10, 4));
}


// int main() { 

//     int num;
//     int divisor;
//     int remainder;

//     do {
//         printf("------------------\n");
//         cout << "Enter num ";  
//         cin >> num;
//         cout << "Num is " << num << endl;  
        
//         cout << "Enter s ";  
//         cin >> divisor;
//         cout << "divisor is " << divisor << endl;  
        
//         remainder = modulo(num, divisor); 
//         printf("Remainder: %d\n" , remainder);

//     } while (! (num == -1 && divisor == -1));
    
// }
