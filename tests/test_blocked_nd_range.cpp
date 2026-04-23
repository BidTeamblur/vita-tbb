#include <cassert>
#include "oneapi/tbb/blocked_nd_range.h"

int main() {
    // 4-dimensions
    int sizes[4] = { 10, 20, 30, 40 };

    tbb::blocked_nd_range<int, 4> r(sizes, 5);

    assert(!r.empty());
    assert(r.is_divisible());
    assert(r.dim_count() == 4);

    assert(r.dim(0).begin() == 0 && r.dim(0).end() == 10);
    assert(r.dim(1).begin() == 0 && r.dim(1).end() == 20);
    assert(r.dim(2).begin() == 0 && r.dim(2).end() == 30);
    assert(r.dim(3).begin() == 0 && r.dim(3).end() == 40);

    // Split test
    tbb::blocked_nd_range<int, 4> r2(r, tbb::split{});

    // At least one dimension must have been split
    bool split0 = r.dim(0).end() == r2.dim(0).begin();
    bool split1 = r.dim(1).end() == r2.dim(1).begin();
    bool split2 = r.dim(2).end() == r2.dim(2).begin();
    bool split3 = r.dim(3).end() == r2.dim(3).begin();

    assert(split0 || split1 || split2 || split3);

    return 0;
}
