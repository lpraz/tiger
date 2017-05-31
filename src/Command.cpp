/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Defines methods for the Command class.
 */

// Stdlib includes
#include <algorithm>
#include <string>
#include <vector>

// Include own header
#include "Command.hpp"

namespace Tiger {
    /**
     * Constructs a Command given a vector of arguments.
     * Assumes the first argument will be the path to tiger's executable
     * file, the second is the "action" word (to be converted to an
     * Action in the newly-created Command), and all those thereafter
     * will be a combination of tags and file paths (toggled between with
     * -t and -f switches).
     *
     * @param arguments A vector of arguments. Must be converted from
     * a C-style array of arguments, as is passed into the program
     * when run.
     */
    Command::Command(std::vector<std::string> arguments) {
        // Make an iterator of arguments, seek to action
        auto iter = arguments.begin();
        
        // If no arguments (other than exec path) given, default to HELP
        iter++;
        if (iter == arguments.end())
            action = HELP;
        
        // Otherwise, convert first argument to Action
        std::string actionString = (*iter);
        std::transform(actionString.begin(), actionString.end(),
                actionString.begin(), ::tolower);
        
        if (actionString == "tag") {
            action = TAG;
        } else if (actionString == "search") {
            action = SEARCH;
        } else if (actionString == "list") {
            action = LIST;
        } else {
            action = HELP;
        }
        
        // Fill tags and files with remaining arguments
        bool fillTags = true;
        
        for (iter++; iter != arguments.end(); iter++) {
            if (*iter == "-t") {
                fillTags = true;
            } else if (*iter == "-f") {
                fillTags = false;
            } else if (fillTags) {
                tags.push_back(*iter);
            } else if (!fillTags) {
                files.push_back(*iter);
            }
        }
    }
    
    /**
     * Accessor method for the Command::action field.
     *
     * @return The current Action held in Command::action.
     */
    Command::Action Command::getAction(void) {
        return action;
    }
    
    /**
     * Accessor method for the Command::tags field.
     *
     * @return The current vector of strings held in Command::tags.
     */
    std::vector<std::string> Command::getTags() {
        return tags;
    }
    
    /**
     * Accessor method for the Command::files field.
     *
     * @return The current vector of strings held in Command::files.
     */
    std::vector<std::string> Command::getFiles() {
        return files;
    }
}
