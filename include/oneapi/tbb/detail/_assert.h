#ifndef __TBB_detail__assert_H
#define __TBB_detail__assert_H

#include <cassert>

// VITA-TBB: Both of these just map to assert(). The _EX variant is used in
// wait_context for overflow checks — same behavior, message ignored.
#define __TBB_ASSERT(expr, msg)    assert(expr)
#define __TBB_ASSERT_EX(expr, msg) assert(expr)

#endif // __TBB_detail__assert_H