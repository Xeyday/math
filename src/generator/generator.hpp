#pragma once

#include "inja/inja.hpp"

namespace xgm
{
struct generator_options
{
    /// Where to get templates to process from
    std::string input_path      { "templates/" };

    /// The folder to output results to
    std::string output_path     { "generated/" };

    /// Customize the namespace. Use empty name to disable namespacing
    std::string namespace_name  { "xgm" };

    /// Only xyzw members, no rgba/stpq
    bool        xyzw_only       { false };

    /// Generate swizzle members
    bool        swizzle_support { true };

    /// Put everything into single header
    bool        single_header   { false };

    /// Put the implementation in the headers too
    bool        header_only     { true };
};

class generator
{
    inja::Environment m_env;
    inja::json m_data;
    generator_options m_options;

public:
    explicit generator(const generator_options& options);

    bool generate();
};
} // namespace xgm
