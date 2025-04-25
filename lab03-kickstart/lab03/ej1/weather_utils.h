#ifndef _WEATHER_UTILS
#define _WEATHER_UTILS

#include <stdio.h>
#include "weather.h"
#include "weather_table.h"

int min_temp_hist(WeatherTable table);

void max_temp_anual(WeatherTable table, int output[YEARS]);

void max_rainfall_month(WeatherTable table, int output[YEARS][MONTHS]);

void month_max_rainfall(WeatherTable table, month_t output[YEARS]);
#endif // _WEATHER_UTILS