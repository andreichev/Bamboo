#include "Bamboo/Allocator.hpp"
#include "Bamboo/Logger.hpp"

void *operator new(size_t, Bamboo::PlacementNewTag, void *_ptr) {
    return _ptr;
}

void operator delete(void *, Bamboo::PlacementNewTag, void *) throw() {}

namespace Bamboo {

void *DefaultAllocator::alloc(size_t size) {
    return std::malloc(size);
}

void DefaultAllocator::free(void *ptr) {
    std::free(ptr);
}

AllocatorI *getAllocator() {
    static DefaultAllocator allocator;
    return &allocator;
}

} // namespace Bamboo