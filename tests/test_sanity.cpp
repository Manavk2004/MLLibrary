// Tells doctest to generate main() in this file. Exactly ONE .cpp in the test
// suite may do this; later test files just #include <doctest/doctest.h>.
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <kensor/core.hpp>
#include <kensor/matrix.hpp>
#include <string>

using kensor::Matrix;


TEST_CASE("skeleton: version reports correctly") {
    CHECK(std::string(kensor::version()) == "0.1.0");
}

TEST_CASE("skeleton: index_t is signed") {
    // This is the wrap-around bug index_t exists to prevent:
    // with unsigned types, 3 - 5 = 18446744073709551614, not -2.
    kensor::index_t a = 3;
    kensor::index_t b = 5;
    CHECK(a - b == -2);
}

TEST_CASE("matrix: constructs zeroed with given shape") {
    Matrix m(2,3);
    CHECK(m.rows() == 2);
    CHECK(m.cols() == 3);
    CHECK(m(0,0) == 0.0);
    CHECK(m(1,2) == 0.0);
}

TEST_CASE("matrix: writes then reads back ") {
    Matrix m(2,2);
    m(0,0) = 1.0;
    m(0,1) = 2.0;
    m(1,0) = 3.0;
    m(1,1) = 4.0;
    CHECK(m(1,0) == 3.0);
    CHECK(m(0,1 ) == 2.0);
}