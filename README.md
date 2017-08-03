# tiger
A command-line file tag keeper/organizer for Unix.

## Building and (Un)Installing
 * Building: On Linux systems, just `git clone` this repository, then
   `make`. You will need a C++11-compatible compiler (development was
   done on `gcc` 5.4.0).
 * Installing: After building, `make install`. Your binary will be
   installed to `/usr/bin/local/tiger` by default. If you don't like
   this, specify your own `PREFIX` and `INSTTARGET` variables through
   `make`.
 * Uninstalling: `make uninstall`.

## Usage
tiger is used through a set of several sub-commands, in the same vein
as git and apt, to name a few examples. In all sub-commands, the `-t`
and `-f` switches are used to alternate between specifying tags and
files, respectively (not all commands use this input, though).
 * `add`: Add the listed tags to the listed files.
 * `remove`: Remove the listed tags from the listed files.
 * `search`: Display all files with the listed tags, and all tags with
   the listed files.
 * `list`: List all of the tags, and all of the files with those tags,
   on your system.
 * `help`: Display a list of commands.

## Contributing
 * Feel free to add any bug reports, feature requests, etc. as an issue
   on this repository.
