#include "double_deviation_calculator.h"
#include "float_deviation_calculator.h"
#include "logging_std_wrappers.h"

int main() {
    if(logging_printf("Acceptable term deviation in double: %e\n", CALCULATE_ACCEPTABLE_TERM_DEVIATION(double)()) < 0)
        return 1;
    if(logging_printf("Acceptable term deviation in float: %e\n", CALCULATE_ACCEPTABLE_TERM_DEVIATION(float)()) < 0)
        return 1;
    return 0;
}
