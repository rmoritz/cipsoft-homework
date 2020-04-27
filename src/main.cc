#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>

const std::string DELIMITER = "|";
using strvec = std::vector<std::string>;

bool check(int mid, std::vector<int> const& items, int k, strvec& tokens);
int solve(std::vector<int> const& items, int k, strvec& tokens);

int main() {
  int nitems;
  int npartitions;

  if (!(std::cin >> nitems)) {
    std::cerr << "Expected number of items. Aborting..." << std::endl;
    exit(EXIT_FAILURE);
  }

  if (!(std::cin >> npartitions)) {
    std::cerr << "Expected number of partitions. Aborting..." << std::endl;
    exit(EXIT_FAILURE);
  }

  std::vector<int> items;
  int tmp;

  for (auto i = 0; i != nitems; ++i) {
    if (!(std::cin >> tmp)) break;

    items.push_back(tmp);
  }

  if (items.size() != nitems) {
    std::cerr << "File doesn't contain specified number of items. Aborting..."
              << std::endl;
    exit(EXIT_FAILURE);
  }

  strvec tokens;
  auto answer = solve(items, npartitions, tokens); 

  std::cout << "Partitions:\t";
  for (auto const& t : tokens) {
    std::cout << t << " ";
  }

  std::cout << std::endl
	    << "Answer:\t\t" << answer
	    << std::endl;
}

// Check if mid can be maximum sum of partitions
bool check(int mid, std::vector<int> const& items, int k, strvec& tokens) {
  int count = 1;
  int sum = 0;
  strvec temp;

  for (auto const& it : items) {
    if (it > mid) return false;

    sum += it;

    if (sum > mid) {
      ++count;
      sum = it;

      temp.push_back(DELIMITER);
    }

    temp.push_back(std::to_string(it));
  }

  if (count <= k) {
    tokens = temp;
  }

  return count <= k;
}

// Find smallest maximum sum of partition elements for k paritions
int solve(std::vector<int> const& items, int k, strvec& tokens) {
  int start = 1;
  int end = 0;

  for (auto const& it : items) {
    end += it;
  }

  int answer = 0;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (check(mid, items, k, tokens)) {
      // mid is a possible solution
      answer = mid;
      end = mid - 1;
    }
    else {
      start = mid + 1;
    }
  }

  return answer;
}
