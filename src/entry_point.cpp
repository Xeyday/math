#include "generator/generator.hpp"

#include "argparse/argparse.hpp"

int main(int argc, char* argv[])
{
    argparse::ArgumentParser program("xeyday.math.generator-cli");

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

    xgm::generator_options options;

    xgm::generator gen{ options };

    gen.generate();

    return 0;
}