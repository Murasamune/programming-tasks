#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

template <typename T, typename I>
void merge_sort(I first, I last){
    if (first + 1 < last){
        typename std::vector<T>::iterator leftCurrent = first;
        typename std::vector<T>::iterator rightCurrent = first + round((last - first) / 2);

        merge_sort<T>(first, rightCurrent);
        merge_sort<T>(rightCurrent, last);

        typename std::vector<T> resultVec(last - first);

        for (typename std::vector<T>::iterator resultIter = resultVec.begin(); resultIter < resultVec.end(); resultIter++){
            if (*leftCurrent < *rightCurrent || rightCurrent == last){
                *resultIter = *leftCurrent;
                leftCurrent++;
            }

            else{
                *resultIter = *rightCurrent;
                rightCurrent++;
            }
        }

        typename std::vector<T>::iterator resultIter = resultVec.begin();

        for (typename std::vector<T>::iterator iter = first; iter < last; iter++, resultIter++){
            *iter = *resultIter;
        }
    }
}

int main()
{
    std::vector<int> v1 = {2, 1, 4, 3};
    std::vector<int> v2 = {3, 6, 1, 2, 7, 5, 8, 4};

    merge_sort<int>(v1.begin(), v1.end());
    merge_sort<int>(v2.begin(), v2.end());

    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }

    return 0;
}

