# Connect 4. 

To compile, install g++ and run "g++ game.cpp -o connect4".
To run, run the generated executable via terminal.

# Testing
I am using CxxTest as the testing framework.

- First, install CxxTest and add the directory containing cxxtestgen to your path. (In Linux, this may be /usr/share/cxxtest)
- Create your test suite header file.
- Run the following command: cxxtestgen --error-printer -o runner.cpp MyTestSuite1.h
- Run the following command against the generated file: g++ runner.cpp -o runner
- You now have your test executable. Execute this to see the results: ./runner

See http://cxxtest.com/guide.html#gettingStarted for more details.

# Npm scripts
Added a few scripts for ease of use.
- npm run compile   -   Compiles the application
- npm run start     -   Runs the application
- npm run test      -   Runs unit tests
