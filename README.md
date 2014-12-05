dynArray
========

A vector with backward indexing using negative indices.

The goal is to a) get familiar with the standard library's container interface and b) to exercise writing a template class.

Many scripting languages allow dynamic arrays to be indexed with negative indices where a[-1] denotes the last element in the arraya[size-1] and a[-size] the first element a[0] .

Create a template class dynArray<T> that uses a std::vector<T> as a member (not as a super class) for its implementation. Implement the indexing member functions similar to std::vector for dynArray in a way that negative indices are allowed and every index access is actually bounds checked (use std::vector's facility for that).

    Provide constructors for the following initializations, as it would be with std::vector (ignore allocator argument versions of std::vector) :

    dynArray<char> a1{};
    dynArray<int> a2{1,2,3,4,5}; // initializer_list
    dynArray<double> a3(10,3.14); // count + value
    dynArray<std::string> a4(std::istream_iterator<std::string>{std::cin},std::istream_iterator<std::string>{}); // any iterator type!

    Provide a Factory Function makedynArray() that takes an initializer_list<T> and returns a dynArray<T> filled with the elements from the inialiazer list. 

    Create Unit Tests for all of your template class' behaviors. Best, one or more tests for a feature, before you implement it.
        Use different element types for your template class in the tests to prove that it works with different instantiations
        you must implement your class in a header file (dynArray.h) in the unit test project, a separate library won't work easily, because a template class lacks a .cpp file with content the linker is happy with. 

The following functions of std::vector you should not implement:

    allocator template paramter and functions using it
    getallocator
    reserve(),max_size()
    operator=() -- automatically provided one should be OK
    assign()
    data()
    shrink_to_fit()
    emplace(), emplace_back(), insert()
    swap
    comparison opperators
    all rvalue-reference overloads (unless you want to) 

But you must implement all other members of std::vector by delegating to it. 
