#include <iostream>

#define LOG(STATUS, MESSAGE) std::cout << #STATUS << ": " << MESSAGE << std::endl;

#define CREATE_PRINT_FUNCTION(NAME) \
void print##NAME() { \
std::cout << #NAME << std::endl; \
}

CREATE_PRINT_FUNCTION(Hello)
CREATE_PRINT_FUNCTION(World)
CREATE_PRINT_FUNCTION(Bla)
CREATE_PRINT_FUNCTION(HelloWorld)

#define ADD(X, Y) ((X) + (Y))
#define MULTIPLY(X, Y) ((X) * (Y))

#define DO_SECRET_OPERATION(X, Y) \
std::cout << SECRET_OPERATION(X, Y) << std::endl;

#define SECRET_OPERATION MULTIPLY

#define SUMUP(INITIAL, LIMIT) ({ int sum = (INITIAL); \
for (int i = 1; i <= (LIMIT); ++i) { \
sum += i; } \
sum; })

int fibonacci(int n)
{
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    LOG(INFO, "Program starting")

    printBla();
    printHello();
    printWorld();
    printHelloWorld();

    LOG(DEBUG, "Hello World printed")

    DO_SECRET_OPERATION(9, 7)
    #define SECRET_OPERATION ADD
    DO_SECRET_OPERATION(9, 7)

    std::cout << SUMUP(0, 21) << std::endl;

    std::cout << fibonacci(10) << std::endl;

    LOG(INFO, "Program finished")
    return 0;
}