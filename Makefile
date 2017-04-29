#
# Variables
#

# Compiler options
CC = g++
#CFLAGS =

# Directories (build)
SRCDIR = src
INCLDIR = include
BUILDDIR = build

# Directories (install)
PREFIX = /usr/bin/local
INSTTARGET = bestfriend

# Extension
SRCEXT = cpp

# Specific files (build/install)
TARGET = bin/a.out
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

#
# Recipes
#

# Build binary from objects
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(TARGET)

# Build objects from source files
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) -I $(INCLDIR) -c -o $@ $<

# Install to $(PREFIX)
.PHONY: install
install: $(TARGET)
	cp $< $(DESTDIR)$(PREFIX)/$(INSTTARGET)

# Uninstall from $(PREFIX)
.PHONY: uninstall
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/$(INSTTARGET)

# Clean objects
.PHONY: clean
clean:
	rm -f $(BUILDDIR)/*.o
