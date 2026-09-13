#include <iostream>
#include <vector>
#include <random>

int main() {
    std::vector<std::vector<int>> matrix(15, std::vector<int>(15));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 99);

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            matrix[i][j] = dist(gen);
        }
    }

    std::cout << "Matrix:" << std::endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            std::cout << matrix[i][j] << " ";

            if (matrix[i][j] < 10) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    int max_sum = 0;
    int min_sum = 999999;

    int max_i = 0;
    int max_j = 0;

    int min_i = 0;
    int min_j = 0;

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            int current_sum = 0;

            for (int di = 0; di < 3; di++) {
                for (int dj = 0; dj < 3; dj++) {
                    current_sum += matrix[i + di][j + dj];
                }
            }

            if (current_sum > max_sum) {
                max_sum = current_sum;
                max_i = i;
                max_j = j;
            }

            if (current_sum < min_sum) {
                min_sum = current_sum;
                min_i = i;
                min_j = j;
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Maximum 3x3 sum: " << max_sum << std::endl;

    std::cout << "Maximum square:" << std::endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[max_i + i][max_j + j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Minimum 3x3 sum: " << min_sum << std::endl;

    std::cout << "Minimum square:" << std::endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[min_i + i][min_j + j] << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<float>> matrix5x5(
        5, std::vector<float>(5)
    );

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int sum3x3 = 0;

            int mi = i * 3;
            int mj = j * 3;

            for (int di = 0; di < 3; di++) {
                for (int dj = 0; dj < 3; dj++) {
                    sum3x3 += matrix[mi + di][mj + dj];
                }
            }

            matrix5x5[i][j] =
                static_cast<float>(sum3x3) / max_sum;
        }
    }

    std::cout << std::endl;
    std::cout << "Matrix 5x5:" << std::endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << matrix5x5[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}