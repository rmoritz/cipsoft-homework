#include "minmax.hh"
#include <catch.hpp>

TEST_CASE("minMaxPartition") {
  SECTION("returns 0 when called with no items") {
    std::vector<int> items;
    std::vector<std::vector<int>> partitions;

    auto answer = homework::minMaxPartition(items, 0, partitions);

    REQUIRE(answer == 0);
  }
}

