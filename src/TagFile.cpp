/* TagFile.cpp
 * Provides operations related to the .tiger file used for storing tags,
 * and represents it as a class.
 */

/* Stdlib includes */
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <unordered_map>

/* Local includes */
#include "Tag.hpp"

/* Include self */
#include "TagFile.hpp"

/* Namespaces */
using namespace std;

/* TagFile constructor. */
TagFile::TagFile(void) {
    // Get path of .tiger file from environment variables
    path = getenv("HOME");
    
    // If that doesn't work, get it from password directory
    if (path == NULL)
        path = getpwuid(getuid())->pw_dir;
    
    // Now, open a file with our newfound path
    file.open(path);
}

/* TagFile destructor. */
TagFile::~TagFile(void) {
    file.close();
}

/* Gets all the tags in the file and returns them in a hash table. */
std::unordered_map<std::string, Tag> TagFile::getTags() {
    
}
