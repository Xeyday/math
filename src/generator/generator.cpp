#include <filesystem>
#include <iostream>

#include "generator.hpp"

#include "git.h"

void print_git_info()
{
    std::cout << "xeyday.math.generator, build date: " << __TIMESTAMP__ << "\n";

    if (!git::IsPopulated())
        std::cout << "no git info";
    else
    {
        std::cout << "git branch[" << git::Branch() << "] commit[" << git::CommitSHA1() << "]";
        if (git::AnyUncommittedChanges())
            std::cout << " with uncommitted changes";
    }

    std::cout << std::endl;
}

namespace xgm
{
generator::generator(const generator_options& options /*= {}*/)
    : m_env{ options.input_path, options.output_path }, m_options{ options }
{
    print_git_info();

    // Try to make less confusements for C++ syntax hightligters
    m_env.set_expression("/*{", "}*/"); // Expressions     {{ }}
    m_env.set_statement ("/*%", "%*/"); // Statements      {% %} for many things
    m_env.set_comment   ("/*#", "#*/"); // Comments        {# #}

    m_env.set_line_statement("##");     // Line statements ##
    // One-liners use default ## opener
    // because Inja requires no indentation for them and
    // it's more natural for C++ to do no indentation for #

    // Export options to make them readable in the templates
    m_data["namespace"]       = options.namespace_name;
    m_data["swizzles"]        = options.swizzle_support;

    m_data["xyzw_only"]       = options.xyzw_only;
    m_data["swizzle_support"] = options.swizzle_support;
    m_data["single_header"]   = options.single_header;
    m_data["header_only"]     = options.header_only;

    /* Shortcut to copy and paste
    m_data[""] = options.;
    */
}

bool generator::generate()
{
    // Scan all files in the templates folder
    // Register all non .tpl files as includes
    // Process .tpl

    const std::filesystem::path input_path{ m_options.input_path };
    const std::filesystem::path output_path{ m_options.output_path };

    create_directory(output_path);

    for (auto const& entry : std::filesystem::directory_iterator{ input_path })
    {
        if (!entry.is_regular_file())
            continue;

        const auto file = entry.path().filename();
        const auto filename = file.stem().replace_extension(".h");

        m_env.write(file.string(), m_data, filename.string());
    }

    return false;
}
} // namespace xgm
