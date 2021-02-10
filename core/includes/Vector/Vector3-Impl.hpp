#ifndef SYMMLESS_VECTOR3_IMPL_HPP
#define SYMMLESS_VECTOR3_IMPL_HPP

namespace Symmless {

    template<typename T>
    template<typename U>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3>::Vector(const std::initializer_list<U>& list) {
        Set(list);
    }

    template<typename T>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3>& Vector<T, 3>::operator=(const Vector& v) {
        Set(v);
        return (*this);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    void Vector<T, 3>::Set(T s) {
        _x = s;
        _y = s;
        _z = s;
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    void Vector<T, 3>::Set(T x, T y, T z) {
        _x = x;
        _y = y;
        _z = z;
    }

    template <typename T>
    template <typename U>
    SYMMLESS_HOST_DEVICE
    void Vector<T, 3>::Set(const std::initializer_list<U>& list) {
        assert(list.size() >= 3);

        auto first_elem = list.begin();
        _x = static_cast<T>(*first_elem);
        _y = static_cast<T>(*(++first_elem));
        _z = static_cast<T>(*(++first_elem));
    }

    template<typename T>
    SYMMLESS_HOST_DEVICE
    void Vector<T, 3>::Set(const Vector &v) {
        _x = v._x;
        _y = v._y;
        _z = v._z;
    }

    template<typename T>
    SYMMLESS_HOST_DEVICE
    void Vector<T, 3>::SetZero() {
        _x = static_cast<T>(0);
        _y = static_cast<T>(0);
        _z = static_cast<T>(0);
    }

    template<typename T>
    SYMMLESS_HOST_DEVICE
    void Vector<T, 3>::Normalize() {
        float length_reversed = 1 / Length();
        _x *= length_reversed;
        _y *= length_reversed;
        _z *= length_reversed;
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    float Vector<T, 3>::Length() {
        return static_cast<float>(std::sqrt(_x * _x + _y * _y + _z * _z));
    }
}

#endif //SYMMLESS_VECTOR3_IMPL_HPP