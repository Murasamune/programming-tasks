#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

template <typename T>
class Mvector{
private:
    T* data;
    unsigned int _size;
public:
    Mvector(){
        data = new T[0];
        _size = 0;
    }
    Mvector(T* d, int s){
        data = d;
        _size = s;
    }
    Mvector(const Mvector<T> &obj){
        _size = obj._size;
        data = new T[_size];
        for (unsigned int i = 0; i < _size; i++){
            data[i] = obj.data[i];
        }
    }
    Mvector(Mvector<T> &&obj){
        data = obj.data;
        _size = obj._size;
        obj.data = nullptr;
        obj._size = 0;
    }
    ~Mvector(){
        delete[] data;
    }

    T* begin() const{
        return data;
    }
    T* end() const{
        return data + _size;
    }

    int size(){
        return this->_size;
    }

    T& operator[](int index){
        return data[index];
    }

    void push_back(const T &obj){
        _size = _size + 1;
        T* newData = new T[_size];
        for (unsigned int i = 0; i < _size - 1; i++){
            newData[i] = move(data[i]);
        }
        newData[_size - 1] = move(obj);
        delete[] data;
        data = newData;
    }
    void push_back(T &&obj){
        _size = _size + 1;
        T* newData = new T[_size];
        for (unsigned int i = 0; i < _size - 1; i++){
            newData[i] = move(this->data[i]);
        }
        newData[_size - 1] = move(obj);
        delete[] data;
        data = newData;
    }

    void pop_back(){
        _size = _size - 1;
        T* newData = new T[_size];
        for (unsigned int i = 0; i < _size; i++){
            newData[i] = move(data[i]);
        }
        delete[] data;
        data = newData;
    }

    void erase(unsigned int first){
        for (int i = first; i < _size - 1; i++){
            data[i] = data[i + 1];
        }
        this->pop_back();
    }

    void erase(unsigned int first, unsigned int last){
        if (last - first + 1 <= _size - last - 1){
            for (int i = 0; i < _size - last - 1; i++){
                data[first + i] = data[first + i + (last - first + 1)];
            }
            for (int i = 0; i < last - first + 1; i++){
                this->pop_back();
            }
        }
        else {
            for (int i = first; i < _size - (last - first + 1); i++){
                data[i] = data[i + (last - first + 1)];
            }
            int temp = _size;
            for (int i = temp - (last - first + 1); i < temp; i++){
                this->pop_back();
            }
        }
    }

    Mvector &operator=(const Mvector<T> &obj){
        Mvector<T> temp(obj);
        this->swap(temp);
        return *this;
    }
    Mvector &operator=(Mvector<T> &&obj){
        this->swap(obj);
        return *this;
    }

    T &operator[](const unsigned int iter){
        return data[iter];
    }

    void swap(Mvector<T> &obj){
        T* temp_data = this->data;
        int temp_size = this->_size;
        data = obj.data;
        _size = obj._size;
        obj.data = temp_data;
        obj._size = temp_size;
    }
/*
    void printall(){
        for (int i = 0; i < _size; i++){
            cout << "data[" << i << "] = " << data[i]
            << "\n*data[" << i << "] = " << &data[i] << endl;
        }
        cout << "size:   " << _size
        << "\n&size: " << &_size << "\n" << endl;
    }
*/
};

template <typename T>
void swap(Mvector<T> &vec1, Mvector<T> &vec2){
    vec1.swap(vec2);
}

int main()
{
	ofstream a("a.txt", ofstream::out);
	ofstream b("b.txt", ofstream::out);
	ofstream c("c.txt", ofstream::out);
	ofstream d("d.txt", ofstream::out);

	Mvector<ofstream> streamVector;

	streamVector.push_back(move(a));
	streamVector.push_back(move(b));
	streamVector.push_back(move(c));
	streamVector.push_back(move(d));

    random_device rd;
	mt19937 g(rd());
	shuffle(streamVector.begin(), streamVector.end(), g);

	streamVector[0] << 1;
	streamVector[1] << 2;
	streamVector[2] << 3;
	streamVector[3] << 4;


    return 0;
}
