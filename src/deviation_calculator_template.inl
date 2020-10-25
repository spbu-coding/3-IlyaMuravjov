#include <stdbool.h>
#include "deviation_calculator_template.h"

REAL SQUARED(REAL)(REAL x) {
    return x * x;
}

REAL GET_DISTANCE_SQUARED(REAL)(SOLUTION(REAL) *solution1, SOLUTION(REAL) *solution2) {
    return SQUARED(REAL)(solution1->x1 - solution2->x1) + SQUARED(REAL)(solution1->x2 - solution2->x2);
}

SOLUTION(REAL) SOLVE_SYSTEM(REAL)(REAL deviated_term) {
    return (SOLUTION(REAL)) {
            20002 - (10000 * deviated_term),
            10000 * (deviated_term - 2)
    };
}

REAL CALCULATE_ACCEPTABLE_TERM_DEVIATION(REAL)() {
    SOLUTION(REAL) reference_solution = SOLVE_SYSTEM(REAL)(REFERENCE_TERM);
    REAL term_deviation = INITIAL_TERM_DEVIATION;
    while (true) {
        SOLUTION(REAL) deviated_solution = SOLVE_SYSTEM(REAL)(REFERENCE_TERM + term_deviation);
        if (GET_DISTANCE_SQUARED(REAL)(&reference_solution, &deviated_solution) <=
            SQUARED(REAL)(MAX_SOLUTION_DEVIATION) || term_deviation == 0) return term_deviation;
        term_deviation /= 2;
    }
}
