#ifndef COUNT_INVERSIONS
#define COUNT_INVERSIONS

#include <vector>

using std::vector;

unsigned long CountInversions(vector<int> &input);

unsigned long CountInversionsRec(vector<int> &input,
                                 unsigned long &inversionTracker);

void SortAndCountInversions(vector<int> &left, vector<int> &right,
                            vector<int> &input,
                            unsigned long &inversionTracker);

#endif
