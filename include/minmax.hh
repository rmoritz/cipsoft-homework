#ifndef MINMAX_HH
#define MINMAX_HH

#include <vector>

//! \brief Contains the solution to the homework assignment
namespace homework {
/*! \brief Divide items into nPartitions such that
    the largest sum of the items in any partition
    has the minimum value.

    \param items the items to be partitioned
    \param nPartitions the number of partitions for items
    \param partitions the resulting partitions
    \return the maximum partition sum
*/
int getMinMaxPartition(std::vector<int> const& items,
                       int nPartitions,
                       std::vector<std::vector<int>>& partitions);
}  // namespace homework

#endif  // #ifndef MINMAX_HH
