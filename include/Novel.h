#ifndef CCYY_NOVEL_H_
#define CCYY_NOVEL_H_

#include "Chapter.h"

#include <cstddef>
#include <filesystem>
#include <memory>
#include <string>
#include <vector>

namespace ccyy {

class Novel {
public:
  static std::unique_ptr<Novel>
  getNovelInPath(const std::filesystem::path &abs_path);

  static std::unique_ptr<Novel>
  getNovelUnderDir(const std::filesystem::path &dir,
                   const std::string &novel_name);

public:
  void listContents() const;

protected:
  Novel(const std::filesystem::path &dir, const std::string &novel_name);

  void setChapters(const std::filesystem::path &chapter_dir);

private:
  std::filesystem::path novel_dir_;

  std::string novel_name_;

  std::size_t num_chapters_;

  std::vector<Chapter> chapters_;
};

} // namespace ccyy

#endif // CCYY_NOVEL_H_