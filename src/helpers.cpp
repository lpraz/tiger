/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Defines tiger's helper functions, which don't fit neatly into any
 * classes used by tiger.
 * Any helper functions will be placed in the Tiger::Helpers namespace.
 */

// Stdlib includes
#include <iostream>
#include <sstream>

// Include own header
#include "helpers.hpp"

namespace Tiger {
    namespace Helpers {
        /**
         * Converts a C-style list of command-line arguments to a vector.
         *
         * @param argumentCount The number of command-line arguments to
         *                      convert (or, the length of
         *                      argumentValues to convert all arguments).
         * @param argumentValues An array containing command-line arguments.
         */
        std::vector<std::string> convertArguments (int argumentCount,
                char *argumentValues[]) {
            std::vector<std::string> arguments;
            
            for (int index = 0; index < argumentCount; index++)
                arguments.push_back(argumentValues[index]);
            
            return arguments;
        }
     
        /**
         * Reads the next string surrounded by a pair of a specified character,
         * taking whitespace into account.
         *
         * @param stream The stream to read from.
         * @param delimiter The delimiter that surrounds the string.
         * @param reuse Whether the closing delimiter should be used as
         *              the starting delimiter for the next read. If true,
         *              the stream will be reversed one character.
         * @returns The string that was read.
         */
        std::string readDelimitedString(std::istream& stream, char delimiter,
                bool reuse) {
            stream >> std::noskipws;
            std::stringstream resultStream;
            char nextChar;
            
            while (stream >> nextChar)
                if (nextChar == delimiter)
                    break;
            
            while (stream >> nextChar) {
                if (nextChar == delimiter)
                    break;
                
                resultStream << nextChar;
                
                if (stream.eof())
                    break;
            }
            
            if (reuse)
                stream.seekg(-1, stream.cur);
            
            return resultStream.str();
        }
    }
}
