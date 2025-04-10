#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    std::ifstream file("weather_data.csv");
    std::string line;

    std::vector<std::string> dates;
    std::vector<double> temperature;
    std::vector<double> humidity;
    std::vector<double> windSpeed;

    bool firstLine = true;

    while (std::getline(file, line)) {
        if (firstLine) { // skip header
            firstLine = false;
            continue;
        }

        std::stringstream ss(line);
        std::string date, temp, hum, wind;

        std::getline(ss, date, ',');
        std::getline(ss, temp, ',');
        std::getline(ss, hum, ',');
        std::getline(ss, wind, ',');

        dates.push_back(date);
        temperature.push_back(std::stod(temp));
        humidity.push_back(std::stod(hum));
        windSpeed.push_back(std::stod(wind));
    }

    // Index for x-axis since matplotlib-cpp does not support string x-axis labels directly
    std::vector<int> x(dates.size());
    for (size_t i = 0; i < x.size(); ++i) x[i] = i;

    plt::figure_size(1000, 500);
    plt::plot(x, temperature, {{"label", "Temperature (°C)"}, {"color", "red"}});
    plt::plot(x, humidity, {{"label", "Humidity (%)"}, {"color", "blue"}});
    plt::plot(x, windSpeed, {{"label", "Wind Speed (km/h)"}, {"color", "green"}});
    plt::legend();
    plt::title("Weather Data Visualization");
    plt::xlabel("Days");
    plt::ylabel("Values");
    plt::grid(true);

    // Show x-axis labels (dates) as ticks
    plt::xticks(x, dates);

    plt::show();
    return 0;
}



/*
1. Install matplotlib-cpp:
    Clone: https://github.com/lava/matplotlib-cpp
    Place matplotlibcpp.h in your include path.

2. Install Python deps:
    bash
    Copy
    Edit
    pip install matplotlib numpy
    Compile with g++:
*/