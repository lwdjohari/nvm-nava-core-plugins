#ifndef NAVA_CORE_INTERFACE_V2_DB_PRIMARY_KEY_H
#define NAVA_CORE_INTERFACE_V2_DB_PRIMARY_KEY_H

#include <cstddef>
#include <memory>
#include <vector>

#include "nvm/nava/core/interfaces/db_column.h"

namespace nava {
namespace core {
namespace interfaces {

class IDbPrimaryKey {
 public:
  virtual ~IDbPrimaryKey() {}

  virtual std::string name() const = 0;
  virtual std::shared_ptr<std::vector<DbColumn>> columns() const = 0;
  virtual DbPrimaryKeyGeneration generation() const = 0;
};

class DbPrimaryKey : public IDbPrimaryKey {
 private:
  std::string name_;
  std::shared_ptr<std::vector<DbColumn>> columns_;
  DbPrimaryKeyGeneration generation_;

 public:
  DbPrimaryKey()
      : name_(std::string()),
        columns_(std::make_shared<std::vector<DbColumn>>()),
        generation_(DbPrimaryKeyGeneration::None) {}

  DbPrimaryKey(const std::string& name,
               const std::shared_ptr<std::vector<DbColumn>>& columns,
               DbPrimaryKeyGeneration generation)
      : name_(name), columns_(columns), generation_(generation) {}

  virtual ~IDbPrimaryKey() override {}

  std::string name() const override { return name_; }

  std::shared_ptr<std::vector<DbColumn>> columns() const override {
    return columns_;
  }

  DbPrimaryKeyGeneration generation() const override { return generation_; }
};

}  // namespace interfaces
}  // namespace core
}  // namespace nava

#endif  // NAVA_CORE_INTERFACE_V2_DB_PRIMARY_KEY_H
