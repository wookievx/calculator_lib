//
// Created by lukaszlampart on 13.11.15.
//

#ifndef MULTIGRAPHSCC_UNIVERSALEDGE_H
#define MULTIGRAPHSCC_UNIVERSALEDGE_H
#include <unordered_map>
#include <functional>
#include <exception>
/*
 * W tej wersji na szablonach nie zrobię potęgowania, (w cpp nie ma operatora potęgowania, a zadany typ powinien go
 * implementować)
 */
template <typename T> class onp_calc {
public:
    //Tej klasy nie da się utworzyć, skopiować itp. służy jako swoisty namespace
    onp_calc() = delete;
    onp_calc& operator=(const onp_calc&) = delete;
    onp_calc(const onp_calc&) = delete;
    onp_calc(onp_calc&&) = delete;

    static std::unordered_map<char,std::function<T(T,T)>>& operations() {
        return operation_map;
    };

private:
    static std::unordered_map<char,std::function<T(T,T)>> operation_map;

    static T op_add (const T& a, const T& b) {
        return a+b;
    }

    static T op_sub (const T& a, const T& b) {
        return a-b;
    }

    static T op_mul (const T& a, const T& b) {
        return a*b;
    }

    static T op_div (const T& a, const T& b) {
        return a/b;
    }
};

template<typename T> std::unordered_map<char,std::function<T(T,T)>> onp_calc<T>::operation_map {
        {'+',onp_calc<T>::op_add},
        {'-',onp_calc<T>::op_sub},
        {'*',onp_calc<T>::op_mul},
        {'/',onp_calc<T>::op_div}
};
// Co tu się stało? ustawiliśmy obiekty "funcyjne" naszymi funkcjami

#endif //MULTIGRAPHSCC_UNIVERSALEDGE_H
