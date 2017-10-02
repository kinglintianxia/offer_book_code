//# pragma once

#ifndef STACK_WITH_MIN_H
#define STACK_WITH_MIN_H

#include <iostream>
#include <stdio.h>
#include <stack>
#include <assert.h>

template <typename T>
class StackWithMin
{
public:
    StackWithMin() {}
    ~ StackWithMin() {}

    T& top();   // Fetch top value
    const T& top() const; // Featch top value
    void push(const T& value);  // push in value
    void pop();     // pop out
    const T& min() const;   // min value
    bool empty() const;     // is empty  ?
    size_t size() const;    // size of stack
    // the const that follows the parentheses '()'
    // states that the function won’t modify the implicitly accessed object(means *this).

private:
    std::stack<T> data_stack_;  // The stack stores the values
    std::stack<T> min_stack_;   // The stack stores the minmum values


};

template <typename T>
T & StackWithMin<T>::top()
{
    return data_stack_.top();

}

template <typename T>
void StackWithMin<T>::push(const T &value)
{
    // Push in data stack
    data_stack_.push(value);
    // value < min data
    if (min_stack_.size() == 0 || min_stack_.top() > value)
        min_stack_.push(value);
     // value >= min data
    else
        min_stack_.push(min_stack_.top());

}

template <typename T>
void StackWithMin<T>::pop()
{
    // Do not forget the assersion
    // If not true, the assert abort()
    assert(data_stack_.size() > 0 && min_stack_.size() > 0);

    data_stack_.pop();
    min_stack_.pop();

}

template <typename T>
const T& StackWithMin<T>::min() const
{
    assert(data_stack_.size() > 0 && min_stack_.size() > 0);
    return min_stack_.top();

}

// Is empty
template <typename T>
bool StackWithMin<T>::empty() const
{
    return data_stack_.empty();

}

template <typename T>
size_t StackWithMin<T>::size() const
{
    return data_stack_.size();

}


#endif // STACK_WITH_MIN_H
