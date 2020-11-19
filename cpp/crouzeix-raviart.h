// Copyright (c) 2020 Chris Richardson
// FEniCS Project
// SPDX-License-Identifier:    MIT

#pragma once

#include "finite-element.h"

namespace libtab
{

/// Crouzeix-Raviart element
namespace cr
{
/// @note degree must be 1 for Crouzeix-Raviart
/// @param celltype
/// @param degree
FiniteElement create(cell::Type celltype, int degree);

static std::string family_name = "Crouzeix-Raviart";
} // namespace cr
} // namespace libtab
