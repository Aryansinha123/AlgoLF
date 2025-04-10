#include <iostream>
#include <iomanip>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int bruteForce(int w[], int v[], int n, int capacity) {
    int maxAmount = 0;
    int combinations = 1 << n;  // Total possible combinations of items

    for (int i = 0; i < combinations; i++) {
        int currentWeight = 0;
        int currentAmount = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                currentWeight += w[j];
                currentAmount += v[j];
            }
        }

        if (currentWeight <= capacity) {
            maxAmount = max(maxAmount, currentAmount);
        }
    }

    return maxAmount;
}

int main() {
    int n;

    std::cin >> n;

    int w[10];
    int v[10];
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }

    double average = (double)sum / n;

    std::cout << "Sum of values: " << sum << std::endl;
    std::cout << "Average of values: " << std::fixed << std::setprecision(2) << average << std::endl;

    int capacity;
    std::cin >> capacity;

    int maxAmountBrute = bruteForce(w, v, n, capacity);
    std::cout << "Maximum amount: " << maxAmountBrute << std::endl;

    return 0;
}