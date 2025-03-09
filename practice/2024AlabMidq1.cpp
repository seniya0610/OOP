#include <iostream>
#include <cmath>
using namespace std;

class StatisticalAnalyzer
{
public:
    static double computeAverage(double *data, int size)
    {
        double sum = 0.0;
        for (int i = 0; i < size; ++i)
        {
            sum += data[i];
        }
        return sum / size;
    }

    static double calculateStandardDeviation(double *data, int size)
    {
        double mean = computeAverage(data, size);
        double sumSquaredDifferences = 0.0;

        for (int i = 0; i < size; ++i)
        {
            sumSquaredDifferences += pow(data[i] - mean, 2);
        }

        return sqrt(sumSquaredDifferences / (size - 1));
    }
};

int main()
{
    double data[] = {10.5, 20.3, 30.7, 40.2, 50.1};
    int size = sizeof(data) / sizeof(data[0]);

    double average = StatisticalAnalyzer::computeAverage(data, size);
    double stdDev = StatisticalAnalyzer::calculateStandardDeviation(data, size);

    cout << "Average: " << average << endl;
    cout << "Standard Deviation: " << stdDev << endl;

    return 0;
}
