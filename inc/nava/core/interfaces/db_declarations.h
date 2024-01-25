#ifndef NAVA_CORE_INTERFACES_V2_DB_DECLARATIONS_H
#define NAVA_CORE_INTERFACES_V2_DB_DECLARATIONS_H

#include <cstddef>
#include <cstdint>

#include "nvm/macro.h"

namespace nava {
namespace core {
namespace interfaces {

enum class DbDriverType {
  None = 0,
  Pgsql = 1,
  Sqlite = 2,
  Mysql = 3,
  Oracle = 4,
  SqlServer = 5
};

enum class ConstraintType : uint8_t {
  Unknown = 0,
  PrimaryKey = 1,
  ForeignKey = 2
};

enum class DbDataType : uint8_t {
  None = 0,
  Int8 = 1,
  Int16 = 2,
  Int32 = 3,
  Int64 = 4,
  UInt8 = 5,
  UInt16 = 6,
  UInt32 = 7,
  UInt64 = 8,
  Float = 9,
  Fp16 = 8,
  Double = 16,
  String = 17,
  Boolean = 18,
  Text = 19,
  UUID = 20,
  Datetime = 21,
  DatetimeNoTimezone = 22,
  Date = 23,
  Time = 24,
  TimeNoTimezone = 25,
  Byte = 26,
  NotSupported = 27
};

enum class DbObjectNameType : uint8_t { None = 0, StrongObjectName = 1 };

enum class DbPrimaryKeyGeneration : uint8_t {
  None = 0,
  AutoIncrement = 1,
  Serial = 2,
  Identity = 3
};

enum class DbForeignKeyType : uint8_t {
  None = 0,
  OneToMany = 1,
  OneToOne = 2,
  ManyToMany = 3
};

enum class BooleanOperator : uint16_t {
  None = 0,
  Eq = 1,
  Neq = 2,
  Gt = 4,
  Gte = 8,
  Lt = 16,
  Lte = 32,
  Between = 64,
  In = 128,
  NotIn = 256
};

// cppcheck-suppress unknownMacro
NVM_ENUMCLASS_ENABLE_BITMASK_OPERATORS(BooleanOperator)

inline BooleanOperator NextormGetAllBooleanOperands() {
  return BooleanOperator::Eq | BooleanOperator::Neq | BooleanOperator::Gt |
         BooleanOperator::Gte | BooleanOperator::Lt | BooleanOperator::Lte |
         BooleanOperator::Between | BooleanOperator::In |
         BooleanOperator::NotIn;
}

enum class CodeGeneratorResult {
  Ok = 0,
  Info = 1,
  Warning = 2,
  Error = 3,
  NoDriverSuitable = 4,
  DriverNotImplemented = 5,
  ConfigInvalid = 6,
  DbConnectionFailed = 7
};

}  // namespace interfaces
}  // namespace core
}  // namespace nava

#endif  // NAVA_CORE_INTERFACES_V2_DB_DECLARATIONS_H
