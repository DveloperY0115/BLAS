#ifndef SYMMLESS_VECTOR3_IMPL_HPP
#define SYMMLESS_VECTOR3_IMPL_HPP

#include "Vector3.hpp"

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

    template <typename T>
    SYMMLESS_HOST_DEVICE
        float Vector<T, 3>::Length() {
        return static_cast<float>(std::sqrt(_x * _x + _y * _y + _z * _z));
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
    Vector<T, 3> Vector<T, 3>::Add(T c) const {
        T x = this->_x + c;
        T y = this->_y + c;
        T z = this->_z + c;
        return Vector<T, 3>(x, y, z);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3> Vector<T, 3>::Add(const Vector& v) const {
        T x = this->_x + v._x;
        T y = this->_y + v._y;
        T z = this->_z + v._z;
        return Vector<T, 3>(x, y, z);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3> Vector<T, 3>::Sub(T c) const {
        T x = this->_x - c;
        T y = this->_y - c;
        T z = this->_z - c;
        return Vector<T, 3>(x, y, z);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3> Vector<T, 3>::Sub(const Vector &v) const {
        T x = this->_x - v._x;
        T y = this->_y - v._y;
        T z = this->_z - v._z;
        return Vector<T, 3>(x, y, z);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3> Vector<T, 3>::Mul(T c) const {
        T x = this->_x * c;
        T y = this->_y * c;
        T z = this->_z * c;
        return Vector<T, 3>(x, y, z);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3> Vector<T, 3>::Mul(const Vector &v) const {
        T x = this->_x * v._x;
        T y = this->_y * v._y;
        T z = this->_z * v._z;
        return Vector<T, 3>(x, y, z);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3> Vector<T, 3>::Div(T c) const {
        T c_reversed = 1 / c;
        T x = this->_x * c_reversed;
        T y = this->_y * c_reversed;
        T z = this->_z * c_reversed;
        return Vector<T, 3>(x, y, z);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3> Vector<T, 3>::Div(const Vector &v) const {
        T x = this->_x * (1 / v._x);
        T y = this->_y * (1 / v._y);
        T z = this->_z * (1 / v._z);
        return Vector<T, 3>(x, y, z);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    T Vector<T, 3>::Dot(const Vector &v) const {
        return static_cast<T>(this->_x * v._x + this->_y * v._y + this->_z * v._z);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3> Vector<T, 3>::Cross(const Vector &v) const {
        T x = this->_y * v._z - this->_z * v._y;
        T y = this->_z * v._x - this->_x * v._z;
        T z = this->_x * v._y - this->_y * v._x;
        return Vector<T, 3>(x, y, z);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3> Vector<T, 3>::RSub(T c) const {
        T x = c - this->_x;
        T y = c - this->_y;
        T z = c - this->_z;
        return Vector<T, 3>(x, y, z);
    }

    template <typename T>
    SYMMLESS_HOST_DEVICE
    Vector<T, 3> Vector<T, 3>::RSub(const Vector &v) const {
        T x = v._x - this->_x;
        T y = v._y - this->_y;
        T z = v._z - this->_z;
        return Vector<T, 3>(x, y, z);
    }
}

#endif //SYMMLESS_VECTOR3_IMPL_HPP
