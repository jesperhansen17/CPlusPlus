template <typename T, typename R> bool operator==(const T& lhs, const R& rhs) { return (rhs.denom==lhs.denom && rhs.nom==lhs.nom  ); }
template <typename T, typename R> bool operator!=(const T& lhs, const R& rhs) { return !(lhs == rhs); }
template <typename T, typename R> bool operator>(const T& lhs, const R& rhs) { return (rhs<lhs); }
template <typename T, typename R> bool operator>=(const T& lhs, const R& rhs) { return !(lhs<rhs); }
template <typename T, typename R> bool operator<=(const T& lhs, const R& rhs) { return !(rhs<lhs); }
