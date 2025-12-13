#pragma once

#include <cstdint>
#include <type_traits>
#include <cstddef>

namespace Bamboo {

#define BAMBOO_INVALID_HANDLE 0

#define BAMBOO_HANDLE(name)                                                                        \
    struct name {                                                                                  \
        name(uint32_t id)                                                                          \
            : id(id) {}                                                                            \
        name()                                                                                     \
            : id(BAMBOO_INVALID_HANDLE) {}                                                         \
        uint32_t id;                                                                               \
        bool isValid() {                                                                           \
            return id != BAMBOO_INVALID_HANDLE;                                                    \
        }                                                                                          \
    };

BAMBOO_HANDLE(EntityHandle);
BAMBOO_HANDLE(TextureHandle);
BAMBOO_HANDLE(MaterialHandle);
BAMBOO_HANDLE(MeshHandle);

struct Vec2 {
    union {
        float x, width;
    };
    union {
        float y, height;
    };

    Vec2()
        : x(0)
        , y(0) {}

    Vec2(float x, float y)
        : x(x)
        , y(y) {}

    bool operator==(const Vec2 &l) {
        return l.x == x && l.y == y;
    }

    bool operator!=(const Vec2 &l) {
        return !(*this == l);
    }

    static Vec2 zero() {
        return Vec2();
    }
};

struct Vec3 {
    union {
        float x, r, width;
    };
    union {
        float y, g, height;
    };
    union {
        float z, b;
    };

    Vec3()
        : x(0)
        , y(0)
        , z(0) {}

    Vec3(float x, float y, float z)
        : x(x)
        , y(y)
        , z(z) {}
};

struct Vec4 {
    union {
        float x, r, width;
    };
    union {
        float y, g, height;
    };
    union {
        float z, b;
    };
    union {
        float w, a;
    };

    Vec4()
        : x(0)
        , y(0)
        , z(0)
        , w(0) {}

    Vec4(float x, float y, float z, float w)
        : x(x)
        , y(y)
        , z(z)
        , w(w) {}
};

using Size = Vec2;
using Color = Vec4;
using Quat = Vec4;

// --------------------------------
// -------- TYPE UTILS ------------
// --------------------------------

template<typename T>
struct RemoveAllPointersHelper {
    using Type = T;
};

template<typename T>
struct RemoveAllPointersHelper<T *> {
    using Type = typename RemoveAllPointersHelper<T>::Type;
};

template<typename T>
using RemoveAllPointers = typename RemoveAllPointersHelper<T>::Type;

template<typename T>
struct StripTypeHelper {
    using Type = std::remove_cvref_t<
        RemoveAllPointers<std::remove_reference_t<std::remove_all_extents_t<T>>>>;
};

template<typename T>
using StripType = typename StripTypeHelper<T>::Type;

template<typename T>
concept hasFields = requires(T) { StripType<T>::getFields(); };

template<typename T, typename U>
constexpr std::size_t offsetOf(U T::*member) {
    return reinterpret_cast<std::size_t>(&(reinterpret_cast<T const volatile *>(0)->*member));
}

inline void *addOffset(void *data, size_t offset) {
    return static_cast<uint8_t *>(data) + offset;
}

// --------------------------------
// -------- OTHER UTILS -----------
// --------------------------------

template<typename Ty>
inline void swap(Ty &_a, Ty &_b) {
    Ty tmp = _a;
    _a = _b;
    _b = tmp;
}

template<typename Ty>
inline constexpr Ty min(const Ty &_a, const Ty &_b) {
    return _a < _b ? _a : _b;
}

template<typename Ty>
inline constexpr Ty max(const Ty &_a, const Ty &_b) {
    return _a > _b ? _a : _b;
}

inline int32_t strCmp(const char *lhs, const char *rhs, int32_t max = 100) {
    for (; max > 0 && *lhs == *rhs; ++lhs, ++rhs, --max) {
        if (*lhs == '\0' || *rhs == '\0') {
            break;
        }
    }

    if (0 == max) {
        return 0;
    }

    return *lhs - *rhs;
}

} // namespace Bamboo