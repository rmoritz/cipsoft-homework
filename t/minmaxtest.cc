#include <catch.hpp>
#include "minmax.hh"

SCENARIO("minMaxPartition") {
  std::vector<int> items;
  auto nPartitions = 0;
  std::vector<std::vector<int>> partitions;

  WHEN("called with no items") {
    // Arrange
    nPartitions = 1;

    // Act
    auto answer = homework::minMaxPartition(items, nPartitions, partitions);

    // Assert
    THEN("returns 0") { REQUIRE(answer == 0); }
    AND_THEN("partitions are empty") { REQUIRE(partitions.empty()); }
  }

  WHEN("called with nPartitions = 0") {
    // Arrange
    items.push_back(1);
    items.push_back(2);

    // Act
    auto answer = homework::minMaxPartition(items, nPartitions, partitions);

    // Assert
    THEN("returns 0") { REQUIRE(answer == 0); }
    AND_THEN("partitions are empty") { REQUIRE(partitions.empty()); }
  }

  WHEN("called with negative nPartitions") {
    // Arrange
    nPartitions = -1;

    // Act
    auto answer = homework::minMaxPartition(items, nPartitions, partitions);

    // Assert
    THEN("returns 0") { REQUIRE(answer == 0); }
    AND_THEN("partitions are empty") { REQUIRE(partitions.empty()); }
  }

  WHEN("called with 6 items and nPartitions = 3") {
    // Arrange
    items.push_back(11);
    items.push_back(16);
    items.push_back(5);
    items.push_back(5);
    items.push_back(12);
    items.push_back(10);

    nPartitions = 3;

    std::vector<std::vector<int>> expected = {{11}, {16, 5, 5}, {12, 10}};

    // Act
    auto answer = homework::minMaxPartition(items, nPartitions, partitions);

    // Assert
    THEN("returns correct answer") { REQUIRE(answer == 26); }
    AND_THEN("partitions are filled correctly") {
      REQUIRE(partitions == expected);
    }
  }
}
