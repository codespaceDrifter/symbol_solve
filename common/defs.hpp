#ifndef DEFS_HPP
#define DEFS_HPP

#include <memory>
#include <cstdio>
#include <string>
#include <vector>

template<typename T>
using ptr = std::shared_ptr<T>;

template<typename T>
using wptr = std::weak_ptr<T>;

template<typename T>
using uptr = std::unique_ptr<T>;

template<typename T, typename... Args>
ptr<T> make_ptr(Args&&... args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

template<typename T, typename... Args>
ptr<T> make_uptr(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}






#endif

