#include "minmax.hh"

bool check(int mid,
           std::vector<int> const& items,
           int nPartitions,
           std::vector<std::vector<int>>& partitions) {
  int count = 1;
  int sum = 0;
  std::vector<std::vector<int>> tempPartitions;
  std::vector<int> part;

  for (auto const& n : items) {
    if (n > mid)
      return false;

    sum += n;

    if (sum > mid) {
      ++count;
      sum = n;

      tempPartitions.push_back(part);
      part.clear();
    }

    part.push_back(n);
  }

  if (count <= nPartitions) {
    tempPartitions.push_back(part);
    partitions = tempPartitions;
  }

  return count <= nPartitions;
}

int homework::minMaxPartition(std::vector<int> const& items,
                              int nPartitions,
                              std::vector<std::vector<int>>& partitions) {
  int start = 1;
  int end = 0;

  for (auto const& n : items) {
    end += n;
  }

  int answer = 0;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (check(mid, items, nPartitions, partitions)) {
      // mid is a possible solution
      answer = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return answer;
}
