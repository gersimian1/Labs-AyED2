#include <stdio.h>
#include "weather_utils.h"

int min_temp_hist(WeatherTable table) {
    int result;
 
    result = table[0][0][0]._min_temp;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (table[year][month][day]._min_temp < result) {
                    result = table[year][month][day]._min_temp;
                }
            }
        }
    }
 
    return result;
}

void max_temp_anual(WeatherTable table, int output[YEARS]) {

    for(unsigned int year = 0u; year < YEARS; ++year) {

        int max_temp_year = table[year][0][0]._max_temp;

        for (month_t month = january; month <= december; ++month){
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (table[year][month][day]._max_temp > max_temp_year) {
                    max_temp_year = table[year][month][day]._max_temp;
                }
            }
        }

        output[year] = max_temp_year;
    }
}

void max_rainfall_month(WeatherTable table, int output[YEARS][MONTHS]) {

    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {

            unsigned int max_rainfall_month = table[year][month][0]._rainfall;
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (table[year][month][day]._rainfall > max_rainfall_month) {
                    max_rainfall_month = table[year][month][day]._rainfall;
                }
            }
            output[year][month] = max_rainfall_month;
        }
    }
}

void month_max_rainfall(WeatherTable table, month_t output[YEARS]) {
    for (unsigned int year = 0; year < YEARS; year++) {
        month_t month_max = january;
        unsigned int max_rainfall = 0;
        for (month_t month = january; month <= december; ++month) {
            // calcular suma de lluvias para el mes `month`
            unsigned int month_rainfall = 0;
            for (unsigned int day = 0u; day < DAYS; ++day) {
                month_rainfall += table[year][month][day]._rainfall;
            }
 
 
            // ver si es el máximo para este año
            if (month_rainfall > max_rainfall) {
                // guardar nuevo máximo y su mes
                max_rainfall = month_rainfall;
                month_max = month;
            }
        }
 
 
        output[year] = month_max;
    }
 }
 