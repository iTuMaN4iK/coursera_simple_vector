#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T> class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size)
      : data_(new T[size]), size_(size), capacity_(size){};
  ~SimpleVector() {
    if (data_ != nullptr)
      delete[] data_;
  };

  T &operator[](size_t index) { return data_[index]; }

  T *begin() { return data_; }
  T *end() { return data_ + size_; };

  size_t Size() const { return size_; }
  size_t Capacity() const { return capacity_; }
  void PushBack(const T &value) {
    if (size_ >= capacity_) {
      T *old = data_;
      capacity_ = capacity_ == 0 ? 1 : 2 * capacity_;
      data_ = new T[capacity_];
      for (size_t i = 0; i < size_; i++) {
        data_[i] = old[i];
      }
      delete[] old;
    }
    data_[size_++] = value;
  }

private:
  T *data_ = nullptr;
  size_t size_, capacity_ = 0;
};
