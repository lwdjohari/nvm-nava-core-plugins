#ifndef NAVA_CORE_INTERFACES_V2_DB_TABLE_TYPE_H
#define NAVA_CORE_INTERFACES_V2_DB_TABLE_TYPE_H

#include <cstddef>


namespace nava {
namespace core {
namespace interfaces {

enum class DbTableType {
  None = 0,                  /**< @brief 0 - Unknown table*/
  Table = 1,                 /**< @brief 1 - Ordinary table*/
  PartitionTable = 2,        /**< @brief 2 - Partition table*/
  View = 3,                  /**< @brief 3 - View*/
  TemporaryTable = 4,        /**< @brief 4 - Temporary table*/
  PartitionedTableChild = 5, /**< @brief 5 - Partitioned child table*/
  HyperTable = 6 /**< @brief 6 - TimescaleDB table or any other equivalent*/
};



}  // namespace interfaces
}  // namespace core
}  // namespace nava
#endif