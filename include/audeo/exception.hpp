#ifndef AUDEO_EXCEPTION_HPP_
#define AUDEO_EXCEPTION_HPP_

#ifndef AUDEO_NO_EXCEPTIONS
#    define AUDEO_THROW(except) throw except
#    define AUDEO_CATCH(except) catch (except)
#    define AUDEO_TRY try
#    include <stdexcept>
#include <string_view>

namespace audeo {

class exception : public std::exception {
    using std::exception::exception;
    inline exception(std::string_view message) : exception(message.data()) {}
};

} // namespace audeo

#else
#    define AUDEO_THROW(...)
#    define AUDEO_CATCH(...) if (false)
#    define AUDEO_TRY

#endif

#endif