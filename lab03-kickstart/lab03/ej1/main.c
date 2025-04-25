/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "weather_table.h"
#include "weather_utils.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create a table variable */
    WeatherTable table;

    /* parse the file to fill the table */
    table_from_file(table, filepath);

    /* Calculate minimum temperature in history */
    int min_temp = min_temp_hist(table);
    printf("Minimum temperature in history: %d\n", min_temp);

    /* Calculate maximum temperature per year */
    int max_temp_per_year[YEARS];
    max_temp_anual(table, max_temp_per_year);
    printf("Maximum temperatures per year:\n");
    for (unsigned int year = 0; year < YEARS; ++year) {
        printf("Year %u: %d\n", FST_YEAR + year, max_temp_per_year[year]);
    }

    /* Calculate maximum rainfall per month */
    int max_rainfall_per_month[YEARS][MONTHS];
    max_rainfall_month(table, max_rainfall_per_month);
    printf("Maximum rainfall per month:\n");
    for (unsigned int year = 0; year < YEARS; ++year) {
        printf("Year %u:\n", FST_YEAR + year);
        for (unsigned int month = 0; month < MONTHS; ++month) {
            printf("  Month %u: %d\n", month + 1, max_rainfall_per_month[year][month]);
        }
    } 

    month_t month_max_rainfall_anual[YEARS];
    month_max_rainfall(table, month_max_rainfall_anual);
    printf("Maximum rainfall in a month:\n");
    for (unsigned int year = 0; year < YEARS; ++year) {
        printf("Year %u: Month %u\n", FST_YEAR + year, month_max_rainfall_anual[year] + 1);
    }
    /* show the table in the screen */
    table_dump(table);

    return EXIT_SUCCESS;
}
