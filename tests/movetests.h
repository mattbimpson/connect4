// moves.cpp tests
#include <cxxtest/TestSuite.h>
#include "../moves.cpp"
#include<vector>

class MoveTests : public CxxTest::TestSuite
{
    
    public: void test_getColumns_Returns_Columns(void)
    {
        Moves _moves;
        vector<vector<char>> columns = _moves.getColumns();
        TS_ASSERT(columns.size() == 7);
        TS_ASSERT(columns[0].size() == 6);
    }

    public: void test_placeToken_Returns_False(void)
    {
        Moves _moves;
        vector<vector<char>> columns = _moves.getColumns();
        bool result = false;
        result = _moves.placeToken(0, true);
        TS_ASSERT(result == false);
    }
};
