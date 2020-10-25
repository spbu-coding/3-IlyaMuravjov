#define CONCAT_TOKENS(A, B) A ## B

#define MAX_SOLUTION_DEVIATION 1e-6
#define REFERENCE_TERM 2.0001
#define INITIAL_TERM_DEVIATION 0.0001

#define SOLUTION(T) struct CONCAT_TOKENS(T, _solution_t)

SOLUTION(REAL) {
    REAL x1, x2;
};

#define SQUARED(T) CONCAT_TOKENS(T, _squared)

REAL SQUARED(REAL)(REAL x);

#define GET_DISTANCE_SQUARED(T) CONCAT_TOKENS(get_distance_squared_in_, T)

REAL GET_DISTANCE_SQUARED(REAL)(SOLUTION(REAL) *solution1, SOLUTION(REAL) *solution2);

#define SOLVE_SYSTEM(T) CONCAT_TOKENS(solve_systems_in_, T)

// solves { x1+x2=2; x1+1.0001*x2=deviated_term } for x1, x2
SOLUTION(REAL) SOLVE_SYSTEM(REAL)(REAL deviated_term);

#define CALCULATE_ACCEPTABLE_TERM_DEVIATION(T) CONCAT_TOKENS(calculate_acceptable_term_deviation_in_, T)

REAL CALCULATE_ACCEPTABLE_TERM_DEVIATION(REAL)();
