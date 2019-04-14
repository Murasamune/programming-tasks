#include <iostream>
#include <vector>

using namespace std;

template <typename T>
std::vector<std::vector<T>> vecRotate(std::vector<std::vector<T>> &vec, int angle){
if (angle%90 != 0){
    std::cout << "Error! Wrong angle!" << "\n";
}
else{
    for (int i = 0; i < angle/90; i++){
        int rows = vec.size();
        int cols = vec[0].size();
        std::vector<std::vector<T>> temp(cols, std::vector<T>(rows));
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                temp[j][rows - i - 1] = vec[i][j];
            }
        }

        vec.resize(cols);
        for (int i = 0; i < cols; i++){
            vec[i].resize(rows);
        }

        for (int i = 0; i < cols; i++){
            for (int j = 0; j < rows; j++){
                vec[i][j] = temp[i][j];
            }
        }
    }
}
    return vec;
}
/*
int main()
{
    const size_t row = 5;
    const size_t col = 4;
    std::vector<std::vector<int>> test(row, std::vector<int>(col));

    int c = 1;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            test[i][j] = c;
            c++;
            cout << test[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    vecRotate<int>(test, 180);

    for (int i = 0; i < test.size(); i++){
        for (int j = 0; j < test[i].size(); j++){
            cout << test[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
*/
