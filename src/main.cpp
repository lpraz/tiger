/* main.cpp
 * Provides top-level functions for tiger.
 */

/* Stdlib includes */
#include <cstring>
#include <vector>

/* Local includes */
#include "Tag.hpp"
#include "TagOperations.hpp"

/* Main function. */
int main(int argc, char* argv[]) {
    std::vector<Tag> tags;
    
    // TODO: fill tags from file
    
    // Do the expected action based on arguments
    TagOperations::parse_args(argc, argv);
    
    return 0;
}
