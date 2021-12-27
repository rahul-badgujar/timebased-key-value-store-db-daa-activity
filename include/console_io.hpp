#pragma once

#include <iostream>

/// Fascilates Console based Input Output
class ConsoleIO {
   public:
    /// Prints a string to console.
    static void print(std::string message);
    /// Prints a string to console and moves to next line.
    static void println(std::string message);
    /// Takes a value input of type T, and returns it.
    template <typename T>
    static T input();
};

// template based methods implemented in header file only.
template <typename T>
T ConsoleIO::input() {
    T inputValue;
    std::cin >> inputValue;
    return inputValue;
}