#ifndef CICADA_UTIL_TYPES_ADD_RVALUE_REFERENCE_HEADER_GUARD
# define CICADA_UTIL_TYPES_ADD_RVALUE_REFERENCE_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "type_identity.hpp"

namespace ccd {
	namespace detail {
		template<typename T>
		auto try_add_rvalue_reference(int)->type_identity<T&&>;

		template<typename T>
		auto try_add_rvalue_reference(...)->type_identity<T>;
	}

	template<typename T>
	using add_rvalue_reference = decltype(detail::try_add_rvalue_reference<T>(0));

	template<typename T>
	using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;
}

#endif