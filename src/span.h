#pragma once
#if __has_include(<span>)
#include <span>
#else
#define TCB_SPAN_NAMESPACE_NAME std
#include "../third_party/span.hpp"
#endif
