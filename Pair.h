#pragma once

template<typename T1, typename T2>
class Pair {
public:
	T1 first;
	T2 second;
    ~Pair() = default;
    Pair() = delete;

    Pair(const T1& first_val, const T2& second_val) : first(first_val), second(second_val) {
    };
};