// Copyright (C) 2019 star.engine at outlook dot com
//
// This file is part of StarEngine
//
// StarEngine is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// StarEngine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with StarEngine.  If not, see <https://www.gnu.org/licenses/>.

#pragma once
#include <Star/SOverload.h>

namespace Star {

struct GetVariantName {
    template<class... T>
    const char* operator()(const std::variant<T...>& var) const noexcept {
        return visit(*this, var);
    }
    template<class T>
    const char* operator()(const T& var) const noexcept {
        return getName(var);
    }
    const char* operator()(const std::monostate& var) const noexcept {
        return "monostate";
    }
};

template<class... T>
inline const char* getVariantName(const std::variant<T...>& var) noexcept {
    GetVariantName g;
    return visit(g, var);
}

}