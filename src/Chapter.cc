#include "Chapter.h"
#include "Section.h"
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <string>

namespace ccyy {

Chapter::Chapter(const std::filesystem::path &dir,
                 const std::string &chapter_name,
                 std::size_t num_sec_after_last)
    : chapter_name_(chapter_name), num_sections_before_(num_sec_after_last) {
  setSections(dir / chapter_name);
}

std::size_t Chapter::numSectionAfter() const { return num_sections_after_; }

void Chapter::listSections() const {
  for (std::size_t i = 0; i != sections_.size(); ++i) {
    std::cout << "  " << i + 1 + num_sections_before_
              << "章: " << sections_[i].getSectionName() << std::endl;
  }
}

void Chapter::setSections(const std::filesystem::path &section_dir) {
  auto section_dir_it = std::filesystem::directory_iterator(section_dir);

  num_sections_ = static_cast<std::size_t>(
      std::distance(section_dir_it, std::filesystem::directory_iterator()));

  num_sections_after_ = num_sections_before_ + num_sections_;

  for (const auto &sec : section_dir_it) {
    sections_.push_back(Section(sec.path().string()));
  }
}

} // namespace ccyy