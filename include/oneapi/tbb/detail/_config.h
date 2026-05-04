/*
    Copyright (c) 2005-2023 Intel Corporation
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

// ALL comments here are VITA-TBB specific so no prefixes here.
// Upstream _config.h does a lot that we don't really need platform 
// detection, export macros, feature flags and ABI versioning.
// This file defines jsut the stuff other headers actually need.

#ifndef __TBB_detail__config_H
#define __TBB_detail__config_H

#include "_assert.h"

// Export annotations are empty: everything is header-only.
// Upstream uses them for compiled r1:: runtime functions;
// ours are inline stubs or Vita implementations.
#define TBB_EXPORT
#define __TBB_EXPORTED_FUNC


// Upstream uses this to mean `inline` (C++17) on constexpr globals
// in headers. In C++14, constexpr at namespace scope is implicitly
// const, which is fine for compile-time constants like no_slot.
#define __TBB_GLOBAL_VAR


// Used in wait_context to silence a warning about m_version_and_traits.
template <typename T>
void suppress_unused_warning(const T&) {}


// Feature flags of stuff we're not supporting.
// We intentionally leave these undefined.
//
//   TBB_USE_PROFILING_TOOLS  — all no-ops in profiling.h
//   __TBB_RESUMABLE_TASKS    — coroutine suspend/resume, skip
//   __TBB_USE_OPTIONAL_RTTI  — we don't use RTTI anywhere


// Vita thread pool settings.
// These are used by vita_thread_pool.h, not by TBB's own headers.
//
// 3 user cores: SCE_KERNEL_CPU_MASK_USER_0/1/2.
// Main thread takes one, workers get the other two.
#define VITA_TBB_WORKER_COUNT    2
#define VITA_TBB_STACK_SIZE      (256 * 1024)
#define VITA_TBB_WORKER_PRIORITY 144   // slightly above default (160), lower = higher prio
#define VITA_TBB_AFFINITY_MASK   0     // let the OS pick cores, don't pin

#endif /* __TBB_detail__config_H */