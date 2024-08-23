#include <typeinfo>
#include <cstdio>
#include <iostream>
#include <vector>

//fold expression
// ... - args means subtract all arguments
// how to use this customAdd(1,2,3,4) => should return (1+3) + (2+3) + (3+3) + (4+3)
template<typename... Args>
auto customAdd(Args... args) {
    
    return ([args](){return args+3;}() + ...);  // fold expression for custom add all arguments
}
// by default fold expression support + and *
// how to use : do_add(1,2,3,4,5)
template<typename... Args>
auto do_add(Args... args)
{
    return (...+ args);
}
// if want to implement string concatenate
// concatenate1("hello","!","I","am","a","developer""...")
// only use fold expression
template<typename... Args>
std::string concatenate1(Args&&... args) {
    return (std::string{} + ... + std::forward<Args>(args)); // Fold expression
}


template<typename... Args>
std::string concatenate(Args&&... args) {
    // Lambda function to concatenate strings
    auto concat_lambda = [](auto&&... parts) {
        return (std::string{} + ... + parts); // Fold expression
    };
    return concat_lambda(std::forward<Args>(args)...);
}

int main() {
    std::vector<float> vec{1,2,3,4};
    
    auto l=[]<typename T>(const std::vector<T>& vec){ 
        return vec.size();
        
        
    };
    
    std::cout << "customAdd: " << do_add(1,2,3,4,5) << std::endl;
    std::cout << "customAdd: " << concatenate1("1","2","3","4","5") << std::endl;
    std::string result = concatenate("Hello, ", "this ", "is ", "a ", "test.");
    std::cout << result << std::endl; // Output: Hello, this is a test.
    std::cout << "lambda vector: " << l(vec) << std::endl;
    return 0;
}
