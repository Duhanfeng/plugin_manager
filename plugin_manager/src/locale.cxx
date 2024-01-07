#include "locale.hpp"
#include <boost/locale.hpp>

namespace ss
{
std::string toLocalString(const std::string& str)
{

#ifdef _WIN32
    return boost::locale::conv::between(str, "GBK", "UTF-8");
#else
    return str;
#endif
}

std::string toUtf8String(const std::string& str)
{
#ifdef _WIN32
    return boost::locale::conv::between(str, "UTF-8", "GBK");
#else
    return str;
#endif
}

} //namespace ss
