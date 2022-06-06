CFLAGS 			= -Wall -Wextra -pedantic
PROFILEFLAGS 	= -g -pg
CC        		= g++
DOC 			= doc

#sudo apt-get install qtbase5-dev
#sudo apt-get install qttools5-dev
#v pripade chyby - sudo strip --remove-section=.note.ABI-tag /usr/lib/x86_64-linux-gnu/libQt5Core.so.5
all:
	cd Calculator && cmake -S . -B build
	cd Calculator && cmake --build build
	cd Calculator && cd build && make

pack: clean
	cd ../../ && zip -r xdolez0c_xvecer30_xpolia05_xloren16.zip *

clean:
	rm -f *.o *.zip
	cd Calculator && rm -rf build
	cd tests && rm -rf build
	cd profiler && rm -f stddev
	cd .. && cd profiling && rm -f gprof-result-huge.txt

test:
	cd tests && cmake -S . -B build
	cd tests && cmake --build build
	cd tests && cd build && make && ./mathlib_test

# sudo apt-get install doxygen
# sudo apt-get install graphviz
doc: clean
	@doxygen ./doxygen/Doxyfile

run: all
	cd Calculator && cd build && ./Calculator

profile:	
	cd profiler && $(CC) $(CFLAGS) $(PROFILEFLAGS) stddev.cpp -o stddev
	cd profiler && sed -i 's/\r$$//' gprof_script.sh && chmod +x gprof_script.sh && ./gprof_script.sh
	cd profiler && mv gprof-result-huge.txt ../../profiling
	