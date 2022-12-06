#include <bits/stdc++.h>

using namespace std;

int main()
{
    double kg, h; cin >> kg >> h;
    double bmi = 1.0 * kg / (h * h);

    string _class, _risk;

    if (bmi < 18.5) _class = "Thin", _risk = "Low";
    if (bmi >= 18.5 && bmi <= 25) _class = "Normal", _risk = "Medium";
    if (bmi > 25 && bmi <= 30) _class = "Overweight", _risk = "High";
    if (bmi > 30 && bmi <= 35) _class = "Class 1 Obese", _risk = "High";
    if (bmi > 35 && bmi <= 40) _class = "Class 2 Obese", _risk = "Very High";
    if (bmi > 40) _class = "Class 3 Obese", _risk = "Extremely High";

    cout << "You are " << _class << " and the risk of disease is " << _risk;
}
