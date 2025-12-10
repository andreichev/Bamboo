#pragma once

#include <memory>

#define F_DELETE(allocator, ptr) Bamboo::deleteObject(allocator, ptr)
#define F_NEW(allocator, type) F_PLACEMENT_NEW(allocator->alloc(sizeof(type)), type)
#define F_PLACEMENT_NEW(ptr, type) ::new (Bamboo::PlacementNewTag(), ptr) type

namespace Bamboo {
struct PlacementNewTag {};
} // namespace Bamboo

void *operator new(size_t, Bamboo::PlacementNewTag, void *ptr);
void operator delete(void *, Bamboo::PlacementNewTag, void *) throw();

namespace Bamboo {
template<typename T>
using Shared = std::shared_ptr<T>;

struct AllocatorI {
    virtual ~AllocatorI() = default;

    virtual void *alloc(size_t size) = 0;
    virtual void free(void *ptr) = 0;
};

template<typename ObjectT>
inline void deleteObject(AllocatorI *allocator, ObjectT *object) {
    if (!object) {
        return;
    }
    object->~ObjectT();
    allocator->free(object);
}

AllocatorI *getAllocator();

template<typename T>
constexpr Shared<T> createShared(T *ptr) {
    AllocatorI *alloc = getAllocator();
    auto deleter = [alloc](T *ptr) { F_DELETE(alloc, ptr); };
    return std::shared_ptr<T>(ptr, deleter);
}

template<typename T1, typename T2>
inline Shared<T1> SharedCast(const Shared<T2> &r) {
    return std::dynamic_pointer_cast<T1>(r);
}

template<typename T, typename... Args>
constexpr Shared<T> makeShared(Args &&...args) {
    AllocatorI *alloc = getAllocator();
    T *ptr = F_NEW(alloc, T)(std::forward<Args>(args)...);
    auto deleter = [alloc](T *ptr) { F_DELETE(alloc, ptr); };
    return std::shared_ptr<T>(ptr, deleter);
}

class DefaultAllocator : public AllocatorI {
public:
    DefaultAllocator() = default;
    ~DefaultAllocator() override = default;

    void *alloc(size_t size) override;
    void free(void *ptr) override;
};

} // namespace Bamboo