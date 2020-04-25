# Connect 4. 

To compile, install g++ and run "g++ game.cpp -o connect4".
To run, run the generated executable via terminal.

# Testing
I am using CxxTest as the testing framework.

- First, install CxxTest and add the directory containing cxxtestgen to your path. (In Linux, this may be /usr/share/cxxtest)
- Create your test suite header file.
- Run the following command: cxxtestgen --error-printer -o runner.cpp MyTestSuite1.h (Note this may generate running.cpp rather than runner.cpp)
- Run the following command against the generated file: g++ runner.cpp -o runner (or running.cpp)
- You now have your test executable. Execute this to see the results: ./runner

See http://cxxtest.com/guide.html#gettingStarted for more details.