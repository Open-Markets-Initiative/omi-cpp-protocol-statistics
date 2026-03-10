#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Contains The Index Value Using Last Sale Values Of Index Components
struct IndexValueDenominatorCode {

    static constexpr const char* name = "Index Value Denominator Code";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr IndexValueDenominatorCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit IndexValueDenominatorCode(const char value)
     : value{ value } {}

    // get value of IndexValueDenominatorCode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
