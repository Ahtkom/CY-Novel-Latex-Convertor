#ifndef CCYY_SECTION_H_
#define CCYY_SECTION_H_

#include <string>

namespace ccyy {

class Section {
public:
  Section(std::string &&section_name)
      : section_name_(std::move(section_name)) {}

  const std::string &getSectionName() const { return section_name_; }

private:
  std::string section_name_;
};

} // namespace ccyy

#endif // CCYY_SECTION_H_