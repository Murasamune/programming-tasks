#include "mask.h"
#pragma once
#include <iostream>

template <typename T> class MyMaskedArray2D;

template <typename T>
class Mass2D{
private:
    int rows;
    int colomns;
    T **mass2d;
public:
    Mass2D()
    {
        rows = 0;
        colomns = 0;
        mass2d = nullptr;
    }

    Mass2D(int _rows, int _colomns)
    {
        rows = _rows;
        colomns = _colomns;
        mass2d = new T*[_rows];
        for (int i = 0; i < _rows; i++)
        {
            mass2d[i] = new T[_colomns];
        }
    }

    Mass2D(int _rows, int _colomns, T* arr)
    {
        rows = _rows;
        colomns = _colomns;
        mass2d = new T*[_rows];
        for (int i = 0; i < _rows; i++)
        {
            mass2d[i] = new T[_colomns];
        }
        int count = 0;
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _colomns; j++)
            {
                mass2d[i][j] = arr[count];
                count++;
            }
        }
    }

    int getRows()
    {
        return this->rows;
    }
    int getColomns()
    {
        return this->colomns;
    }

    Mass2D(const Mass2D<T> &obj)
    {
        rows = obj.rows;
        colomns = obj.colomns;
        mass2d = new T*[rows];
        for (int i = 0; i < rows; i++)
        {
            mass2d[i] = new T[colomns];
        }
        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < colomns; j++)
            {
                mass2d[i][j] = obj.mass2d[i][j];
                count++;
            }
        }
    }

    ~Mass2D()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] mass2d[i];
        }
        delete[] mass2d;
    }


    void swap(Mass2D<T> &obj)
    {
        int tempRows = rows;
        int tempColomns = colomns;
        T** tempMass = mass2d;

        rows = obj.rows;
        colomns = obj.colomns;
        mass2d = obj.mass2d;

        obj.rows = tempRows;
        obj.colomns = tempColomns;
        obj.mass2d = tempMass;
    }

    Mass2D &operator=(const Mass2D &obj)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] mass2d[i];
        }
        delete[] mass2d;
        Mass2D<T> temp(obj);
        this->swap(temp);
        return *this;
    }

    Mass2D operator=(const Mass2D obj)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] mass2d[i];
        }
        delete[] mass2d;
        this->swap(obj);
        return *this;
    }

    Mass2D<T> operator+(const Mass2D &obj) const
    {
        if (rows == obj.rows && colomns == obj.colomns)
        {
            Mass2D<T> res(rows, colomns);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < colomns; j++)
                {
                    res.mass2d[i][j] = mass2d[i][j] + obj.mass2d[i][j];
                }
            }
            return res;
        }
        else
        {
            std::cout << "wrong dimension" << std::endl;
        }
    }

    Mass2D<T> operator-(const Mass2D &obj) const
    {
        if (rows == obj.rows && colomns == obj.colomns)
        {
            Mass2D<T> res(rows, colomns);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < colomns; j++)
                {
                    res.mass2d[i][j] = mass2d[i][j] - obj.mass2d[i][j];
                }
            }
            return res;
        }
        else
        {
            std::cout << "wrong dimension" << std::endl;
        }
    }

    Mass2D<T> operator*(const Mass2D &obj) const
    {
        if (rows == obj.rows && colomns == obj.colomns)
        {
            Mass2D<T> res(rows, colomns);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < colomns; j++)
                {
                    res.mass2d[i][j] = mass2d[i][j] * obj.mass2d[i][j];
                }
            }
            return res;
        }
        else
        {
            std::cout << "wrong dimension" << std::endl;
        }
    }

    Mass2D<T> operator/(const Mass2D &obj) const
    {
        if (rows == obj.rows && colomns == obj.colomns)
        {
            Mass2D<T> res(rows, colomns);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < colomns; j++)
                {
                    res.mass2d[i][j] = mass2d[i][j] / obj.mass2d[i][j];
                }
            }
            return res;
        }
        else
        {
            std::cout << "wrong dimension" << std::endl;
        }
    }

    Mass2D<bool> operator&&(const Mass2D<bool> &obj) const
    {
        if (rows == obj.rows && colomns == obj.colomns)
        {
            Mass2D<bool> res(rows, colomns);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < colomns; j++)
                {
                    res.mass2d[i][j] = mass2d[i][j] && obj.mass2d[i][j];
                }
            }
            return res;
        }
        else
        {
            std::cout << "wrong dimension" << std::endl;
        }
    }

    Mass2D<bool> operator||(const Mass2D<bool> &obj) const
    {
        if (rows == obj.rows && colomns == obj.colomns)
        {
            Mass2D<bool> res(rows, colomns);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < colomns; j++)
                {
                    res.mass2d[i][j] = mass2d[i][j] || obj.mass2d[i][j];
                }
            }
            return res;
        }
        else
        {
            std::cout << "wrong dimension" << std::endl;
        }
    }

    Mass2D<bool> operator!() const
    {
        Mass2D<bool> res(this->rows, this->colomns);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->colomns; j++)
            {
                res.mass2d[i][j] = !this->mass2d[i][j];
            }
        }
        return res;
    }

    T &operator()(int &_rows, int &_colomns)
    {
        if (rows > _rows && colomns > _colomns)
        {
            return mass2d[_rows][_colomns];
        }
        else
        {
            std::cout << "wrong dimension" << std::endl;
        }
    }

    MyMaskedArray2D<T> operator()(Mass2D<bool> &obj){
        if(rows == obj.getRows() && colomns == obj.getColomns())
        {
            MyMaskedArray2D<T> mask (this, &obj);
            return mask;
        }
        else
        {
            std::cout << "wrong dimension" << std::endl;
        }
    }
/*
    void printall(){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colomns; j++)
        {
            std::cout << mass2d[i][j] << " ";
        }
        std::cout << "\n";
    }
*/
};
/*
int main()
{
    int arr[4] = {1, 2, 3, 4};
    Mass2D<int> test3(2, 2, arr);
    test3.printall();

    return 0;
}};*/
