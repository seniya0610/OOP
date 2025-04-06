#include <iostream>
#include <cmath>
using namespace std;

class Tempreture;
class Humidity;

class Tempreture
{
private:
    float tempreture;

public:
    Tempreture(float t) : tempreture(t) {}
    friend float CalculateHeatIndex(Tempreture, Humidity);
};

class Humidity
{
private:
    float humidity;

public:
    Humidity(float h) : humidity(h) {}
    friend float CalculateHeatIndex(Tempreture, Humidity);
};

float CalculateHeatIndex(Tempreture T, Humidity R)
{

    float tC = T.tempreture; // temp in C
    float r = R.humidity;

    float tF = (tC * 9 / 5) + 32; // temp conversion to F

    float HI_F = -42.379 + 2.04901523 * tF + 10.14333127 * r - 0.22475541 * tF * r - 0.00683783 * tF * tF - 0.05481717 * r * r + 0.00122874 * tF * tF * r + 0.00085282 * tF * r * r - 0.00000199 * tF * tF * r * r;

    float HI_C = (HI_F - 32) * 5 / 9; // temp conversion back to C
    return HI_C;
}

int main()
{
    Tempreture t(32);
    Humidity h(70);
    float Ans = CalculateHeatIndex(t, h);
    cout << "Heat Index: " << Ans << endl;
}
