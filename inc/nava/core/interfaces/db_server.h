#ifndef NAVA_CORE_INTERFACES_V2_DB_SERVER_H
#define NAVA_CORE_INTERFACES_V2_DB_SERVER_H

#include <cstddef>
#include <string>

#include "nava/core/interfaces/db_declarations.h"

namespace nava {
namespace core {
namespace interfaces {

class IServerVersion {
 public:
  virtual ~IServerVersion() {}

  virtual DbDriverType DbServer() const = 0;
  virtual void DbServer(DbDriverType server) = 0;

  virtual int Major() const = 0;
  virtual void Major(int value) = 0;

  virtual int Minor() const = 0;
  virtual void Minor(int value) = 0;

  virtual int Rev() const = 0;
  virtual void Rev(int value) = 0;

  virtual bool RetrievalSuccess() const = 0;
  virtual void RetrievalSuccess(bool value) = 0;

  virtual std::string ResolveDbDriveType(const DbDriverType &type) = 0;
};



class ServerVersion : public IServerVersion {
 public:
  ServerVersion()
      : db_server_(DbDriverType::Pgsql),
        major_(0),
        minor_(0),
        rev_(0),
        is_retrieval_success_(false) {}

  ServerVersion(DbDriverType server, int major, int minor, int rev,
                bool retrieval_success)
      : db_server_(server),
        major_(major),
        minor_(minor),
        rev_(rev),
        is_retrieval_success_(retrieval_success) {}

  virtual ~ServerVersion() {}

  DbDriverType DbServer() const override { return db_server_; }

  int Major() const override { return major_; }

  int Minor() const override { return minor_; }

  int Rev() const override { return rev_; }

  bool RetrievalSuccess() const override { return is_retrieval_success_; }

  void DbServer(DbDriverType server) override { db_server_ = server; }

  void Major(int value) override { major_ = value; }

  void Minor(int value) override { minor_ = value; }

  void Rev(int value) override { rev_ = value; }

  void RetrievalSuccess(bool value) override { is_retrieval_success_ = value; }

  static std::string ResolveDbDriveType(const DbDriverType &type) override {
    switch (type) {
      case DbDriverType::Pgsql:
        return std::move(std::string("Postgresql"));
      case DbDriverType::Sqlite:
        return std::move(std::string("Sqlite"));
      case DbDriverType::Mysql:
        return std::move(std::string("Mysql"));
      case DbDriverType::Oracle:
        return std::move(std::string("Oracle"));
      case DbDriverType::SqlServer:
        return std::move(std::string("Sqlserver"));

      default:
        return std::move(std::string(""));
    }
  }

 private:
  DbDriverType db_server_;
  int major_;
  int minor_;
  int rev_;
  bool is_retrieval_success_;
};

}  // namespace interfaces
}  // namespace core
}  // namespace nava

#endif  // NAVA_CORE_INTERFACES_V2_DB_SERVER_H