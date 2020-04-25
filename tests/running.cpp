/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MoveTests_init = false;
#include "movetests.h"

static MoveTests suite_MoveTests;

static CxxTest::List Tests_MoveTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MoveTests( "movetests.h", 6, "MoveTests", suite_MoveTests, Tests_MoveTests );

static class TestDescription_suite_MoveTests_test_getColumns_Returns_Columns : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MoveTests_test_getColumns_Returns_Columns() : CxxTest::RealTestDescription( Tests_MoveTests, suiteDescription_MoveTests, 9, "test_getColumns_Returns_Columns" ) {}
 void runTest() { suite_MoveTests.test_getColumns_Returns_Columns(); }
} testDescription_suite_MoveTests_test_getColumns_Returns_Columns;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
