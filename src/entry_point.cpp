#include "generator/generator.hpp"

#include "argparse/argparse.hpp"

// Default argparse's store_into function assumes that bools are flags
// and this behaviour is unwanted. Hence our own simple functor.
struct store_into
{
    bool& value;

    explicit store_into(bool& val) : value(val) {}

    void operator()(const std::string& s) const
    {
        if (s == "true" || s == "1")
            value = true;
        else if (s == "false" || s == "0")
            value = false;
    }
};

int main(int argc, char* argv[])
{
    xgm::generator_options options;

    argparse::ArgumentParser program("xeyday.math.generator-cli");

    program.add_argument("-i", "--input")
        .store_into(options.input_path)
        .help("Where to get templates to process from");

    program.add_argument("-o", "--output")
        .store_into(options.output_path)
        .help("The folder to output results to");

    program.add_argument("-nmsp", "--namespace")
        .store_into(options.namespace_name)
        .implicit_value("")
        .help("Customize the namespace. Use empty name to disable namespacing");

    program.add_argument("-xyzw", "--xyzw_only")
        .action(store_into{ options.xyzw_only })
        .implicit_value(true)
        .help("Only xyzw members, no rgba/stpq");

    program.add_argument("-swzl", "--swizzles")
        .action(store_into{ options.swizzles })
        .implicit_value(true)
        .help("Generate swizzle members");

    program.add_argument("-sngl", "--single_header")
        .action(store_into{ options.single_header })
        .implicit_value(true)
        .help("Put everything into single header");

    program.add_argument("-ho", "--header_only")
        .action(store_into{ options.header_only })
        .implicit_value(true)
        .help("Put the implementation in the headers too");

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& err)
    {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }

    xgm::generator gen{ options };

    if (!gen.generate())
    {
        std::cerr << "Failed to generate.";
        return 2;
    }

    return 0;
}
