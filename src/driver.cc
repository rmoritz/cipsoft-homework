#include <cstdlib>
#include <iostream>
#include <vector>
#include "minmax.hh"

int main() {
  int nItems;
  int nPartitions;

  if (!(std::cin >> nItems)) {
    std::cerr << "Expected number of items. Aborting..." << std::endl;
    exit(EXIT_FAILURE);
  }

  if (!(std::cin >> nPartitions)) {
    std::cerr << "Expected number of partitions. Aborting..." << std::endl;
    exit(EXIT_FAILURE);
  }

  std::vector<int> items;
  int n;

  for (auto i = 0; i != nItems; ++i) {
    if (!(std::cin >> n))
      break;

    items.push_back(n);
  }

  if (items.size() != nItems) {
    std::cerr << "File doesn't contain specified number of items. Aborting..."
              << std::endl;
    exit(EXIT_FAILURE);
  }

  std::vector<std::vector<int>> partitions;

  auto answer = homework::minMaxPartition(items, nPartitions, partitions);

  for (auto i = 0; i != partitions.size(); ++i) {
    auto const& part = partitions[i];
    int sum = 0;

    for (auto const& n : part) {
      sum += n;
    }

    std::cout << (i + 1) << ". Tag: " << sum << " km" << std::endl;
  }

  std::cout << std::endl << "Maximum: " << answer << " km" << std::endl;
}
