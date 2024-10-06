
#include <fcntl.h>
O_WRONLY: Open the file for writing only.
O_CREAT: Create the file if it does not exist.
O_TRUNC: Truncate the file to zero length if it exists (clear its contents).
O_RDWR: Specifies that the file should be opened for both reading and writing. You can perform read operations and write operations on the file using the returned file descriptor.
0644: Set the file permissions to read and write for the owner, and read-only for others.



-- SEARCH AND REPLACE IN VIM --
%s/word_to_search/word_to_replace/g (global)
s/word_to_search/word_to_replace/g (global but it work only in the same line)
s#/#word_to_replace/g (replace standard commands signs like /)

# FLAG
-Wxtra -Wall -Werro -g3 -fsanitize=adress
# Supossed to get leak in functions
