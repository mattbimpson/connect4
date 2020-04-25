// moves.cpp tests
#include <cxxtest/TestSuite.h>
#include "../moves.cpp"
#include<vector>

class MoveTests : public CxxTest::TestSuite
{
    Moves _moves;
    public: void test_getColumns_Returns_Columns(void)
    {
        vector<vector<char>> columns = _moves.getColumns();
        TS_ASSERT(columns.size() == 7);
        TS_ASSERT(columns[0].size() == 6);
    }
};
