#include <iostream>

template <typename T>
class Ostream_iter{
private:
    std::ostream* str;
    int N;
    int counter;
public:
    Ostream_iter(std::ostream& out, int _N){
        str = &out;
        N = _N;
        counter = 0;
    }

    Ostream_iter &operator=(T elem) {
        counter++;
        if (counter == N) {
            *str << elem;
            counter = 0;
        }
        return *this;
    }

    ~Ostream_iter(){
        str = nullptr;
    }
};
/*
int main() {
    Ostream_iter<int> test(std::cout, 3);
    test = 1;
    test = 2;
    test = 3;
    test = 4;
    return 0;
}*/
