/* TagFile.cpp
 * Provides operations related to the .tiger file used for storing tags,
 * and represents it as a class.
 */

/* Stdlib includes */
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

/* Namespaces */
using namespace std;

class TagFile {
    private:
        char *path;
    
    public:
        TagFile();
}

/* TagFile constructor. */
TagFile::TagFile(void) {
    // Get path of .tiger file
    path = getenv("HOME");
    
    if (path == NULL)
        path = (*getpwuid(getuid)).pw_dir;
}
