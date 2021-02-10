//
// Created by 유승우 on 2021/02/09.
//

#ifndef BLAS_VECTOR3_IMPL_HPP
#define BLAS_VECTOR3_IMPL_HPP

#include "Vector3.hpp"

namespace BLAS {

    template<typename T>
    template<typename U>
    Vector<T, 3>::Vector(const std::initializer_list<U>& list) {
        Set(list);
    }

    template<typename T>
    Vector<T, 3>& Vector<T, 3>::operator=(const Vector& v) {
        Set(v);
        return (*this);
    }

    template <typename T>
    void Vector<T, 3>::Set(T s) {
        this->_x = s;
        this->_y = s;
        this->_z = s;
    }

    template <typename T>
    void Vector<T, 3>::Set(T x, T y, T z) {
        this->_x = x;
        this->_y = y;
        this->_z = z;
    }

    template <typename T>
    template <typename U>
    void Vector<T, 3>::Set(const std::initializer_list<U>& list) {
        assert(list.size() >= 3);

        auto first_elem = list.begin();
        this->_x = static_cast<T>(*first_elem);
        this->_y = static_cast<T>(*(++first_elem));
        this->_z = static_cast<T>(*(++first_elem));
    }

    template<typename T>
    void Vector<T, 3>::Set(const Vector &v) {
        this->_x = v._x;
        this->_y = v._y;
        this->_z = v._z;
    }

    template<typename T>
    void Vector<T, 3>::SetZero() {
        this->_x = static_cast<T>(0);
        this->_y = static_cast<T>(0);
        this->_z = static_cast<T>(0);
    template<typename T>
    void Vector<T, 3>::Normalize() {
        float length_reversed = 1 / Length();
        _x *= length_reversed;
        _y *= length_reversed;
        _z *= length_reversed;
    }

    template <typename T>
    float Vector<T, 3>::Length() {
        return static_cast<float>(std::sqrt(_x * _x + _y * _y + _z * _z));
    }
}

#endif //BLAS_VECTOR3_IMPL_HPP
