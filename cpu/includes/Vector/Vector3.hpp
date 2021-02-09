#ifndef BLAS_VECTOR3_HPP
#define BLAS_VECTOR3_HPP

#include <limits>
#include <type_traits>

#include "Vector.hpp"

namespace BLAS {
    //!
    //! \brief 3D vector class.
    //!
    //! This class defines 3D vector and associated operations.
    //!
    //! \tparam T - Type of the element
    //!
    template<typename T>
    class Vector<T, 3> final {
    public:
        static_assert(std::is_floating_point<T>::value,
                "Vector only can be instantiated with floating point types.");

        //! Constructs 3D vector filled with zeros.
        constexpr Vector() : _x{ 0 }, _y{ 0 }, _z{ 0 }
        {
            // Do nothing
        }

        //! Constructs 3D vector whose elements are initialized with given values.
        constexpr Vector(T x, T y, T z) : _x{ x }, _y{ y }, _z{ z }
        {
            // Do nothing
        }

        //! Constructs 3D vector with initializer list.
        template <typename U>
        Vector(const std::initializer_list<U>& list);

        //! Copy constructor.
        constexpr Vector(const Vector& v) : _x{ v._x }, _y{ v._y }, _z{ v._z }
        {
            // Do nothing
        }

        //! Move constructor.
        constexpr Vector(Vector&& v) noexcept : _x{ v._x }, _y{ v._y }, _z{ v._z }
        {
            // Do nothing
        }

        //! Default destructor.
        ~Vector() = default;

    private:
        T _x;
        T _y;
        T _z;
    };

}

#include "Vector3-Impl.hpp"

#endif //BLAS_VECTOR3_HPP
