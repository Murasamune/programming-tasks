#pragma once

template <typename T> class Mass2D;

template <typename T>
class MyMaskedArray2D{
public:
    Mass2D<T> *mass2dObj;
    Mass2D<bool> *mass2dmaskObj;

    MyMaskedArray2D(Mass2D<T> *_mass2dObj, Mass2D<bool> *_mass2dmaskObj){
        mass2dObj = _mass2dObj;
        mass2dmaskObj = _mass2dmaskObj;
    }

    ~MyMaskedArray2D(){
        mass2dObj = nullptr;
        delete mass2dObj;
        mass2dmaskObj = nullptr;
        delete mass2dmaskObj;
    }

    MyMaskedArray2D &operator=(const T val){
        for (int i = 0; i < mass2dObj->getRows(); i++){
            for (int j = 0; j < mass2dObj->getColomns(); j++){
                if (this->mass2dmaskObj->mass2d[i][j]){ 
                    this->mass2dObj->mass2d[i][j] = val;
                }
            }
        }
        return *this;
    }
};

