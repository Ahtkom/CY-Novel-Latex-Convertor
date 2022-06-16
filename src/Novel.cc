#include "Novel.h"
#include "Chapter.h"
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>

namespace ccyy {

/* public static */
std::unique_ptr<Novel> Novel::getNovelUnderDir(const std::filesystem::path &dir,
                                               const std::string &novel_name) {
  return std::unique_ptr<Novel>(new Novel(dir, novel_name));
}

Novel::Novel(const std::filesystem::path &dir, const std::string &novel_name)
    : novel_dir_(dir), novel_name_(novel_name) {
  setChapters(dir / novel_name_);
}

void Novel::listContents() const {
  std::cout << novel_name_ << std::endl;
  for (const auto &chap : chapters_) {
    chap.listSections();
  }
}

void Novel::setChapters(const std::filesystem::path &chapter_dir) {
  auto chapter_dir_it = std::filesystem::directory_iterator(chapter_dir);

  chapters_.reserve(static_cast<std::size_t>(
      std::distance(chapter_dir_it, std::filesystem::directory_iterator())));

  std::size_t num_sec_after_last = 0;
  std::size_t count = 0;
  for (const auto &chap : chapter_dir_it) {
    chapters_.push_back(Chapter(novel_dir_ / novel_name_, chap.path().string(),
                                num_sec_after_last));
    num_sec_after_last = chapters_[count].numSectionAfter();
    count++;
  }
}

} // namespace ccyy
