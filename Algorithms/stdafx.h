// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <Sorting.h>
#include <vector>
#include <string>

template <typename T, typename A> inline std::string VectorToString(const std::vector<T, A>& v)
{
	std::string strVector;
	std::vector<T>::const_iterator it;

	for (it = v.begin(); it != v.end(); ++it)
	{
		strVector.append(std::to_string(*it));
		strVector.append(" ");
	}

	return strVector;
}