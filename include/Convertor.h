#ifndef CCYY_CONVERTOR_H_
#define CCYY_CONVERTOR_H_

#include "Novel.h"

#include <cstddef>
#include <filesystem>
#include <memory>
#include <string>
#include <vector>

namespace ccyy {

class Convertor {
public:
  Convertor(const std::filesystem::path &destination,
            const std::filesystem::path &current_location,
            const std::string &novel_name);

private:
  std::filesystem::path destination_;      // Should be directory
  std::filesystem::path current_location_; // Should be directory

  std::unique_ptr<Novel> novel_;

  std::size_t current_chapter_; // Current chapter id
  std::size_t chapter_nums_;    // Total number of chapters
};

} // namespace ccyy

#endif // CCYY_CONVERTOR_H_