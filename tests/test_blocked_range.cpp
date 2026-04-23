#include <cassert>
#include "oneapi/tbb.h"

int main() {
    tbb::blocked_range<int> r(0, 100);
    tbb::proportional_split p(1, 3);

    tbb::blocked_range<int> r2(r, p);

    assert(r.end() == r2.begin());
    assert(r2.size() > 0);
    assert(r.size() > r2.size());

    return 0;
}
