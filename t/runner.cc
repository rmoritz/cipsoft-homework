#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_FAST_COMPILE
#include <catch.hpp>

int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}
