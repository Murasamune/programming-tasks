#include <iostream>
#include <string>

class LineNumberBuffer : public std::streambuf{
private:
    std::streambuf *out;
    bool newLine;
    int lineCounter;
protected:
    int overflow(int c) override {
        if (newLine) {
            std::string str = std::to_string(lineCounter) + "\t";
            lineCounter++;
            out->sputn(str.data(), str.size());
            newLine = false;
        }
        if (c == '\n'){
            newLine = true;
        }
        out->sputc(c);
        return c;
    }
public:
    LineNumberBuffer(std::streambuf *_out){
        out = _out;
        newLine = true;
        lineCounter = 1;
    }
    ~LineNumberBuffer(){}
};

int main()
{
    std::streambuf *backup = std::cout.rdbuf();
    LineNumberBuffer *test = new LineNumberBuffer(backup);
    std::cout.rdbuf(test);
    std::cout << "first line\nsecond line\n";
    std::cout.rdbuf(backup);
    return 0;
}
