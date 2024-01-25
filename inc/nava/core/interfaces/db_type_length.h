#ifndef NAVA_CORE_INTERFACES_V2_DB_TYPE_LENGTH_H
#define NAVA_CORE_INTERFACES_V2_DB_TYPE_LENGTH_H

#include <cstddef>


namespace nava {
namespace core {
namespace interfaces {


class IDbTypeLength {
 public:
  //  IDbTypeLength() = 0;
  //  IDbTypeLength(size_t max_length, bool is_length_base,
  //                                   bool is_use_max_keyword) = 0;

  virtual void MaxLength(size_t max_length) = 0;

  virtual void IsLengthBase(bool is_length_base) = 0;

  virtual void IsUseMaxKeyword(bool is_use_max_keyword) = 0;

  virtual const size_t &MaxLength() const = 0;

  virtual bool IsLengthBase() const = 0;

  virtual bool IsUseMaxKeyword() const = 0;
};

class DbTypeLength : public IDbTypeLength {
 private:
  size_t max_length_;
  bool is_length_base_;
  bool is_use_max_keyword_;

 public:
  explicit DbTypeLength::DbTypeLength()
      : is_length_base_(false),
        max_length_(0),
        is_use_max_keyword_(false){

        };

  explicit DbTypeLength::DbTypeLength(size_t max_length, bool is_length_base,
                                      bool is_use_max_keyword)
      : is_length_base_(is_length_base),
        max_length_(max_length),
        is_use_max_keyword_(is_use_max_keyword){

        };

  virtual DbTypeLength::~DbTypeLength(){};

  virtual void MaxLength(size_t max_length) override {
    max_length_ = max_length;
  };

  virtual void IsLengthBase(bool is_length_base) override {
    is_length_base_ = true;
  };

  virtual void IsUseMaxKeyword(bool is_use_max_keyword) override {
    is_use_max_keyword_ = is_use_max_keyword;
  };

  virtual const size_t &MaxLength() const override { return max_length_; };

  virtual bool IsLengthBase() const override { return is_length_base_; };

  virtual bool IsUseMaxKeyword() const override { return is_use_max_keyword_; };
};

}  // namespace interfaces
}  // namespace core
}  // namespace nava
#endif