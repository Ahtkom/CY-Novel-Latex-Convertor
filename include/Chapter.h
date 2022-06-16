#ifndef CCYY_CHAPTER_H_
#define CCYY_CHAPTER_H_

#include <cstddef>
#include <filesystem>
#include <string>
#include <vector>

#include "Section.h"

namespace ccyy {

class Chapter {
public:
  Chapter(const std::filesystem::path &dir, const std::string &chapter_name,
          std::size_t num_sec_after_last);

  std::size_t numSectionAfter() const;

  void listSections() const;

protected:
  void setSections(const std::filesystem::path &section_dir);

private:
  std::string chapter_name_;

  std::size_t num_sections_; // Number of sections under chapter

  std::size_t num_sections_before_; // Number of sections in previous chapters

  std::size_t num_sections_after_; // Number of sections inclusive

  std::vector<Section> sections_;
};

} // namespace ccyy

#endif // CCYY_CHAPTER_H_