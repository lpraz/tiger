/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Header file for the Command class.
 */

namespace Tiger {
    class Command {
        private:
        
        public:
            /**
             * Represents the possible actions to be given in a command.
             */
            enum Action {
                HELP,
                TAG,
                SEARCH,
                LIST
            };
    }
}
