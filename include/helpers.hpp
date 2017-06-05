/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Header file for tiger's helper functions, which don't fit neatly into
 * any classes used by tiger.
 * Any helper functions will be placed in the Tiger::Helpers namespace.
 */

// Stdlib includes
#include <string>
#include <vector>

namespace Tiger {
    namespace Helpers {
        std::vector<std::string> convertArguments(int argumentCount,
                char *argumentValues[]);
    }
}
