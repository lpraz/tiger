# tiger
A command-line file tag keeper/organizer for Unix. Currently a work in
progress, and not yet usable.

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
as git and apt, to name a few examples.

## Contributing
 * Feel free to add any bug reports, feature requests, etc. as an issue
   on this repository.
