#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "solutions/solutions.h"
#include "helpers/file_reader.h"
void run_all() {
    day1();
    day2();
    day3();
    day4();
    day5();
    day6();
    day7();
    day8();
    day9();
    day10();
    day11();
    day12();
    day13();
    day14();
    day15();
    day16();
    day17();
    day18();
    day19();
    day20();
    day21();
    day22();
    day23();
    day24();
    day25();
}


int main(int argc, char** argv) {
    int8_t day = 0;
    if (argc > 1) {
        day = atoi(argv[1]);
    }
    switch (day) {
    case 1:
        day1();
        break;
    case 2:
        day2();
        break;
    case 3:
        day3();
        break;
    case 4:
        day4();
        break;
    case 5:
        day5();
        break;
    case 6:
        day6();
        break;
    case 7:
        day7();
        break;
    case 8:
        day8();
        break;
    case 9:
        day9();
        break;
    case 10:
        day10();
        break;
    case 11:
        day11();
        break;
    case 12:
        day12();
        break;
    case 13:
        day13();
        break;
    case 14:
        day14();
        break;
    case 15:
        day15();
        break;
    case 16:
        day16();
        break;
    case 17:
        day17();
        break;
    case 18:
        day18();
        break;
    case 19:
        day19();
        break;
    case 20:
        day20();
        break;
    case 21:
        day21();
        break;
    case 22:
        day22();
        break;
    case 23:
        day23();
        break;
    case 24:
        day24();
        break;
    case 25:
        day25();
        break;
    default:
        printf("No specific or invalid argument.\n displaying all days.\n");
        run_all();
        break;
    }

    return 0;
}

