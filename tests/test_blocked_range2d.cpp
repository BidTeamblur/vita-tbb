#include <cassert>
#include "oneapi/tbb.h"

int main() {
    tbb::blocked_range2d<int> r(0, 10, 2, 0, 20, 4);

    assert(!r.empty());
    assert(r.is_divisible());

    tbb::blocked_range2d<int> r2(r, tbb::split{});

    assert(r.rows().end() == r2.rows().begin() ||
           r.cols().end() == r2.cols().begin());

    return 0;
}
