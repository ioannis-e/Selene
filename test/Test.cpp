#include <algorithm>
#include "tests.h"
#include <vector>

static std::vector<bool(*)()> tests = {
    test_function_no_args,
    test_add,
    test_multi_return,
    test_heterogeneous_return,
    test_call_c_function,
    test_call_c_fun_from_lua,
    test_call_lambda
};


int main() {
    int num_tests = tests.size();
    int passing = 0;
    std::for_each(tests.begin(), tests.end(),
                  [&passing](bool (*fun)()) {
                      if (fun()) passing += 1;
                  });
    std::cout << passing << " out of "
              << num_tests << " tests finished successfully." << std::endl;
}