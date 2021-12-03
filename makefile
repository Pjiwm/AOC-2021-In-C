#until day 25
output: main.o file_reader.o linked_list.o hashtable.o array_sort.o array_copy.o string_helper.o solutions.o day1.o day2.o day3.o day4.o day5.o day6.o day7.o day8.o day9.o day10.o day11.o day12.o day13.o day14.o day15.o day16.o day17.o day18.o day19.o day20.o day21.o day22.o day23.o day24.o day25.o
	gcc -g main.o file_reader.o linked_list.o hashtable.o array_sort.o array_copy.o string_helper.o day1.o day2.o day3.o day4.o day5.o day6.o day7.o day8.o day9.o day10.o day11.o day12.o day13.o day14.o day15.o day16.o day17.o day18.o day19.o day20.o day21.o day22.o day23.o day24.o day25.o -o output -lm


main.o: main.c
	gcc -c main.c

# solutions
solutions.o: solutions/solutions.h

day1.o: solutions/day1.c
	gcc -c solutions/day1.c

day2.o: solutions/day2.c
	gcc -c solutions/day2.c

day3.o: solutions/day3.c
	gcc -c solutions/day3.c

day4.o: solutions/day4.c
	gcc -c solutions/day4.c

day5.o: solutions/day5.c
	gcc -c solutions/day5.c

day6.o: solutions/day6.c
	gcc -c solutions/day6.c

day7.o: solutions/day7.c
	gcc -c solutions/day7.c

day8.o: solutions/day8.c
	gcc -c solutions/day8.c

day9.o: solutions/day9.c
	gcc -c solutions/day9.c

day10.o: solutions/day10.c
	gcc -c solutions/day10.c

day11.o: solutions/day11.c
	gcc -c solutions/day11.c

day12.o: solutions/day12.c
	gcc -c solutions/day12.c

day13.o: solutions/day13.c
	gcc -c solutions/day13.c

day14.o: solutions/day14.c
	gcc -c solutions/day14.c

day15.o: solutions/day15.c
	gcc -c solutions/day15.c

day16.o: solutions/day16.c
	gcc -c solutions/day16.c

day17.o: solutions/day17.c
	gcc -c solutions/day17.c

day18.o: solutions/day18.c
	gcc -c solutions/day18.c

day19.o: solutions/day19.c
	gcc -c solutions/day19.c

day20.o: solutions/day20.c
	gcc -c solutions/day20.c

day21.o: solutions/day21.c
	gcc -c solutions/day21.c

day22.o: solutions/day22.c
	gcc -c solutions/day22.c

day23.o: solutions/day23.c
	gcc -c solutions/day23.c

day24.o: solutions/day24.c
	gcc -c solutions/day24.c

day25.o: solutions/day25.c
	gcc -c solutions/day25.c

# helpers
file_reader.o: helpers/file_reader.c helpers/file_reader.h
	gcc -c helpers/file_reader.c

linked_list.o: helpers/linked_list.c helpers/linked_list.h
	gcc -c helpers/linked_list.c

hashtable.o: helpers/hashtable.c helpers/hashtable.h
	gcc -c helpers/hashtable.c

array_sort.o: helpers/array_sort.c helpers/array_helper.h
	gcc -c helpers/array_sort.c

array_copy.o: helpers/array_copy.c helpers/array_helper.h
	gcc -c helpers/array_copy.c
string_helper.o: helpers/string_helper.c helpers/string_helper.h
	gcc -c helpers/string_helper.c


clean:
	rm *.o output debug
