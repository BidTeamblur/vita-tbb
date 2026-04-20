/*
    Copyright (c) 2005-2025 Intel Corporation
    Copyright (c) 2026 UXL Foundation Contributors

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
#ifndef __TBB_detail__utils_H
#define __TBB_detail__utils_H

#include <cstddef>
#include <type_traits>
#include <utility>

#include "_assert.h"

namespace tbb {
namespace detail {
inline namespace d0 {


//! Base class for types that should not be assigned.
class no_assign {
public:
    void operator=(const no_assign&) = delete;
    no_assign(const no_assign&) = default;
    no_assign() = default;
};

} // namespace d0


} // namespace detail
} // namespace tbb



#endif // __TBB_detail__utils_H