#ifndef NAVA_CORE_INTERFACES_V2_DB_COLUMN_H
#define NAVA_CORE_INTERFACES_V2_DB_COLUMN_H

#include <cstddef>
#include <memory>
#include <string>

#include "nvm/nullable.h"
#include "nava/core/interfaces/db_declarations.h"
#include "nava/core/interfaces/db_type_length.h"


namespace nava {
namespace core {
namespace interfaces {

class IDbColumn {
 public:
  virtual ~IDbColumn() {}

  virtual std::string Name() const = 0;
  virtual void Name(const std::string& name) = 0;

  virtual std::string TableName() const = 0;
  virtual void TableName(const std::string& table_name) = 0;

  virtual std::string TableSchema() const = 0;
  virtual void TableSchema(const std::string& table_schema) = 0;

  virtual DbDriverType DbType() const = 0;
  virtual void DbType(DbDriverType db_type) = 0;

  virtual uint Position() const = 0;
  virtual void Position(uint position) = 0;

  virtual std::shared_ptr<DbTypeLength> Length() const = 0;
  virtual void Length(const std::shared_ptr<DbTypeLength>& length) = 0;

  virtual bool HasDefault() const = 0;
  virtual void HasDefault(bool has_default) = 0;

  virtual bool IsNotNull() const = 0;
  virtual void IsNotNull(bool is_not_null) = 0;

  virtual bool IsUpdatable() const = 0;
  virtual void IsUpdatable(bool is_updatable) = 0;

  virtual bool IsSelfRef() const = 0;
  virtual void IsSelfRef(bool is_self_ref) = 0;

  virtual bool IsIdentity() const = 0;
  virtual void IsIdentity(bool is_identity) = 0;

  virtual int IdentityGenerationType() const = 0;
  virtual void IdentityGenerationType(int identity_generation_type) = 0;

  virtual bool IdentityCycle() const = 0;
  virtual void IdentityCycle(bool identity_cycle) = 0;

  virtual DbDataType Datatype() const = 0;
  virtual void Datatype(DbDataType datatype) = 0;

  virtual std::string DbDataType() const = 0;
  virtual void DbDataType(const std::string& db_data_type) = 0;

  virtual Nullable<std::string> DefaultValue() const = 0;
  virtual void DefaultValue(
      const Nullable<std::string>& default_value) = 0;

  virtual DbObjectNameType ObjectNameType() const = 0;
  virtual void ObjectNameType(DbObjectNameType object_name_type) = 0;

  virtual std::string Comment() const = 0;
  virtual void Comment(const std::string& comment) = 0;
};

class DbColumn : public IDbColumn {
 private:
  std::string name_;
  std::string table_name_;
  std::string table_schema_;
  DbDriverType db_type_;
  uint position_;
  std::shared_ptr<DbTypeLength> length_;
  bool has_default_;
  bool is_not_null_;
  bool is_updatable_;
  bool is_self_ref_;
  bool is_identity_;
  int identity_generation_type_;
  bool identity_cycle_;
  DbDataType datatype_;
  std::string db_data_type_;
  Nullable<std::string> default_value_;
  DbObjectNameType object_name_type_;
  std::string comment_;

 public:
  // Default constructor
  DbColumn() = default;

  // Constructor to initialize all fields
  DbColumn(const std::string& name, const std::string& table_name,
           const std::string& table_schema, DbDriverType db_type, uint position,
           const std::shared_ptr<DbTypeLength>& length, bool has_default,
           bool is_not_null, bool is_updatable, bool is_self_ref,
           bool is_identity, int identity_generation_type, bool identity_cycle,
           DbDataType datatype, const std::string& db_data_type,
           const Nullable<std::string>& default_value,
           DbObjectNameType object_name_type, const std::string& comment)
      : name_(name),
        table_name_(table_name),
        table_schema_(table_schema),
        db_type_(db_type),
        position_(position),
        length_(length),
        has_default_(has_default),
        is_not_null_(is_not_null),
        is_updatable_(is_updatable),
        is_self_ref_(is_self_ref),
        is_identity_(is_identity),
        identity_generation_type_(identity_generation_type),
        identity_cycle_(identity_cycle),
        datatype_(datatype),
        db_data_type_(db_data_type),
        default_value_(default_value),
        object_name_type_(object_name_type),
        comment_(comment) {}

  // Getter and Setter methods
  std::string Name() const override { return name_; }

  void Name(const std::string& name) override { name_ = name; }

  std::string TableName() const override { return table_name_; }

  void TableName(const std::string& table_name) override { table_name_ = table_name; }

  std::string TableSchema() const override { return table_schema_; }

  void TableSchema(const std::string& table_schema) override {
    table_schema_ = table_schema;
  }

  DbDriverType DbType() const override { return db_type_; }

  void DbType(DbDriverType db_type)  override { db_type_ = db_type; }

  uint Position() const override { return position_; }

  void Position(uint position) override { position_ = position; }

  std::shared_ptr<DbTypeLength> Length() const override { return length_; }

  void Length(const std::shared_ptr<DbTypeLength>& length) override { length_ = length; }

  bool HasDefault() const override { return has_default_; }

  void HasDefault(bool has_default) override { has_default_ = has_default; }

  bool IsNotNull() const override{ return is_not_null_; }

  void IsNotNull(bool is_not_null) override { is_not_null_ = is_not_null; }

  bool IsUpdatable() const override { return is_updatable_; }

  void IsUpdatable(bool is_updatable)override { is_updatable_ = is_updatable; }

  bool IsSelfRef() const override { return is_self_ref_; }

  void IsSelfRef(bool is_self_ref)  override { is_self_ref_ = is_self_ref; }

  bool IsIdentity() const override{ return is_identity_; }

  void IsIdentity(bool is_identity) override{ is_identity_ = is_identity; }

  int IdentityGenerationType() const override{ return identity_generation_type_; }

  void IdentityGenerationType(int identity_generation_type) override {
    identity_generation_type_ = identity_generation_type;
  }

  bool IdentityCycle() const override { return identity_cycle_; }

  void IdentityCycle(bool identity_cycle) override { identity_cycle_ = identity_cycle; }

  DbDataType Datatype() const override{ return datatype_; }

  void Datatype(DbDataType datatype)override { datatype_ = datatype; }

  std::string DbDataType() const override{ return db_data_type_; }

  void DbDataType(const std::string& db_data_type) override{
    db_data_type_ = db_data_type;
  }

  Nullable<std::string> DefaultValue() const override { return default_value_; }

  void DefaultValue(const Nullable<std::string>& default_value) override {
    default_value_ = default_value;
  }

  DbObjectNameType ObjectNameType() const override{ return object_name_type_; }

  void ObjectNameType(DbObjectNameType object_name_type) override {
    object_name_type_ = object_name_type;
  }

  std::string Comment() const { return comment_; }

  void Comment(const std::string& comment) { comment_ = comment; }
};

}  // namespace interfaces
}  // namespace core
}  // namespace nava
#endif